//=====================================================================================================//
//===================== DIGITAL SOUND FILTER and MPU6050 DMP VALUES ===================================//
//================================= ARDUINO TO STM32F4VG ==============================================//
//=====================================================================================================//                        
// PIN-PIN ARDUINO TO MPU6050 : 
// 1. VCC -> VCC
// 2. GND -> GND
// 3. A5 -> SCL
// 4. A4 -> SDA
// 5. D2 -> INT
#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"
//#include "MPU6050.h" // not necessary if using MotionApps include file

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for SparkFun breakout and InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 mpu;
//MPU6050 mpu(0x69); // <-- use for AD0 high

// uncomment "OUTPUT_READABLE_YAWPITCHROLL" if you want to see the yaw/
// pitch/roll angles (in degrees) calculated from the quaternions coming
// from the FIFO. Note this also requires gravity vector calculations.
// Also note that yaw/pitch/roll angles suffer from gimbal lock (for
// more info, see: http://en.wikipedia.org/wiki/Gimbal_lock)
#define OUTPUT_READABLE_YAWPITCHROLL

#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards
#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)

//AUTO-CALIBRATION ARRAY
#define PRESENT_VAL  0
#define PREVIOUS_VAL 1
#define TEMPORARY    2

bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
int yaw;
int pitch;
int roll;
int MULTIPLY_COUNTER;

unsigned int IMU_CMD[8]={0,0,0,0,0,0,0,0};

//RECEIVED DATA FROM MAIN CONTROLLER
int START_BUTTON    = 0x53;
int BUTTON_A        = 0x41;
int BUTTON_B        = 0x42;
int CMD_COMPLETED   = 0x58;
int CMD_IDLE        = 0x5E;

//COMMAND FLAG FROM MAIN CONTROLLER
unsigned int COMMAND_FLAG_A = 0x3C;
unsigned int COMMAND_FLAG_B = 0x3E;
const unsigned int COMMAND_COMPLETED = 0x7C;

//MANDATORY COMMAND HYBRID IMU PROCESSOR
const int IMU_CMD_SEND_RAW              = 49; //CHANGED
const int SOUNDCHECK                    = 50;
const int HYBRID_CMD_SEND_CONCLUSION    = 0x43;
const int BW_SOUND_ACTIVATED            = 0x77;

const int TCS3200_CMD_SAVE_EEPROM       = 0x5A;
int COMMAND_MODE=1;

//==========================    DIGITAL SOUND RECEIVER VARIABLES   =======================================//
int hitung_on=0,hitung_off=0;

//clipping indicator variables
boolean clipping = 0;

//data storage variables
byte newData = 0;
byte prevData = 0;
unsigned int time = 0;//keeps time and sends vales to store in timer[] occasionally
int timer[10];//sstorage for timing of events
int slope[10];//storage for slope of events
unsigned int totalTimer;//used to calculate period
unsigned int period;//storage for period of wave
byte index = 0;//current storage index
float frequency;//storage for frequency calculations
int maxSlope = 0;//used to calculate max slope as trigger point
int newSlope;//storage for incoming slope data

//variables for decided whether you have a match
byte noMatch = 0;//counts how many non-matches you've received to reset variables if it's been too long
byte slopeTol = 3;//slope tolerance- adjust this if you need
int timerTol = 10;//timer tolerance- adjust this if you need

//variables for amp detection
unsigned int ampTimer = 0;
byte maxAmp = 0;
byte checkMaxAmp;
byte ampThreshold = 30;//raise if you have a very noisy signal
// ================================================================
// ===               INTERRUPT DETECTION ROUTINE                ===
// ================================================================

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}



// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    
    Serial.begin(38400);//
    while (!Serial); 
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);
    devStatus = mpu.dmpInitialize();

    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); // 1688 factory default for my test chip

    // make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        mpu.setDMPEnabled(true);
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
    } 
    // configure LED for output
    pinMode(LED_PIN, OUTPUT);

 //=======================================   DIGITAL SOUND RECEIVER SETUP   =========================================//
  pinMode(12,OUTPUT);//output pin
  pinMode(3,OUTPUT);
  cli();//diable interrupts
  
  //set up continuous sampling of analog pin 0 at 38.5kHz
 
  //clear ADCSRA and ADCSRB registers
  ADCSRA = 0;
  ADCSRB = 0;
  
  ADMUX |= (1 << REFS0); //set reference voltage
  ADMUX |= (1 << ADLAR); //left align the ADC value- so we can read highest 8 bits from ADCH register only
  
  ADCSRA |= (1 << ADPS2) | (1 << ADPS0); //set ADC clock with 32 prescaler- 16mHz/32=500kHz
  ADCSRA |= (1 << ADATE); //enabble auto trigger
  ADCSRA |= (1 << ADIE); //enable interrupts when measurement complete
  ADCSRA |= (1 << ADEN); //enable ADC
  ADCSRA |= (1 << ADSC); //start ADC measurements
  
  sei();//enable interrupts
}

ISR(ADC_vect) {//when new ADC value ready
  
  PORTB &= B11101111;//set pin 12 low
  prevData = newData;//store previous value
  newData = ADCH;//get value from A0
  if (prevData < 127 && newData >=127)
  {//if increasing and crossing midpoint
    newSlope = newData - prevData;//calculate slope
    if (abs(newSlope-maxSlope)<slopeTol){//if slopes are ==
      //record new data and reset time
      slope[index] = newSlope;
      timer[index] = time;
      time = 0;
      if (index == 0){//new max slope just reset
        PORTB |= B00010000;//set pin 12 high
        noMatch = 0;
        index++;//increment index
      }
      else if (abs(timer[0]-timer[index])<timerTol && abs(slope[0]-newSlope)<slopeTol){//if timer duration and slopes match
        //sum timer values
        totalTimer = 0;
        for (byte i=0;i<index;i++){
          totalTimer+=timer[i];
        }
        period = totalTimer;//set period
        //reset new zero index values to compare with
        timer[0] = timer[index];
        slope[0] = slope[index];
        index = 1;//set index to 1
        PORTB |= B00010000;//set pin 12 high
        noMatch = 0;
      }
      else{//crossing midpoint but not match
        index++;//increment index
        if (index > 9){
          reset();
        }
      }
    }
    else if (newSlope>maxSlope){//if new slope is much larger than max slope
      maxSlope = newSlope;
      time = 0;//reset clock
      noMatch = 0;
      index = 0;//reset index
    }
    else{//slope not steep enough
      noMatch++;//increment no match counter
      if (noMatch>9){
        reset();
      }
    }
  }
    
  if (newData == 0 || newData == 1023){//if clipping
    PORTB |= B00100000;//set pin 13 high- turn on clipping indicator led
    clipping = 1;//currently clipping
  }
  
  time++;//increment timer at rate of 38.5kHz
  
  ampTimer++;//increment amplitude timer
  if (abs(127-ADCH)>maxAmp){
    maxAmp = abs(127-ADCH);
  }
  if (ampTimer==1000){
    ampTimer = 0;
    checkMaxAmp = maxAmp;
    maxAmp = 0;
  }
  
}

void reset(){//clea out some variables
  index = 0;//reset index
  noMatch = 0;//reset match couner
  maxSlope = 0;//reset slope
}


void checkClipping(){//manage clipping indicator LED
  if (clipping){//if currently clipping
    PORTB &= B11011111;//turn off clipping indicator led
    clipping = 0;
  }
}

void SOUND_RECEIVE();
void READ_IMU_DATA();
void Get_CMD();
void CMD_ACTUATE();

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    // if programming failed, don't try to do anything
    if (!dmpReady) return;

    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize) {
    }

    // reset interrupt flag and get INT_STATUS byte
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
//        Serial.println(F("FIFO overflow!"));

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
    } else if (mpuIntStatus & 0x02) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

        #ifdef OUTPUT_READABLE_YAWPITCHROLL
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
//            SOUND_RECEIVE();
            Get_CMD();                                                            // FUNGSI MENERIMA COMMAND DARI STM
            CMD_ACTUATE();                                                        // HOLD UNTUK SATU FUNGSI
            
        #endif

        // blink LED to indicate activity
        blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState);
    }
}
void Get_CMD()
{
  IMU_CMD[TEMPORARY] = Serial.read();
  
    if(IMU_CMD[TEMPORARY]!=CMD_IDLE)
    {
        IMU_CMD[1] = IMU_CMD[0];
        IMU_CMD[0] = IMU_CMD[TEMPORARY]; 
    }
    switch(IMU_CMD[0])
    {
        case SOUNDCHECK:
            {
              SOUND_RECEIVE();
              COMMAND_MODE=1;
            }break;  
        case IMU_CMD_SEND_RAW:
            { 
              READ_IMU_DATA();
              COMMAND_MODE=2;
            }break;
        default:break;
    }
}

void CMD_ACTUATE()
{
  switch(COMMAND_MODE)
  {
    case 1:
    {
     SOUND_RECEIVE();
    }break;
    case 2:
    {
      READ_IMU_DATA();
      delay(100);
    }break;
  }  
}

void READ_IMU_DATA()
{
            Serial.write(COMMAND_FLAG_A);
            Serial.write(COMMAND_FLAG_B);
            
            yaw = ypr[0] * 180/M_PI;
            if(yaw<0)
            {
              yaw+=360;
            }
            MULTIPLY_COUNTER=0;                                 
            if(yaw>255)
            {
              while(yaw>255)
              {
                yaw-=255;
                MULTIPLY_COUNTER++;
              }
            }     
            Serial.write(MULTIPLY_COUNTER);  
            Serial.write(yaw);
            
            pitch = ypr[1] * 180/M_PI;
            if(pitch<0)pitch=pitch+180;
            Serial.write(pitch);
            
            roll = ypr[2] * 180/M_PI;
            if(roll<0)roll=roll+180;
            Serial.write(roll);  
}

void SOUND_RECEIVE()
{
  checkClipping();
  
  if (checkMaxAmp>ampThreshold){
    frequency = 38462/float(period);//calculate frequency timer rate/period
  
    //print results
//    Serial.print(frequency);
//    Serial.println(" hz");
  }
  
  delay(100);//delete this if you want

  
  if(frequency>3750 && frequency<=3850)
  {
     hitung_on++;
     hitung_off=0;
  }
  else
  {
    hitung_off++;
  }

  
 if(hitung_on>=5 && hitung_off==0)
 {  
//    Serial.println("SOUND ACTIVATED");
    Serial.write(COMMAND_FLAG_A);
    Serial.write(COMMAND_FLAG_B);  
    Serial.write(BW_SOUND_ACTIVATED);
    COMMAND_MODE=2;
 }
 else if(hitung_off>=5)
 {
    hitung_on=0;
 }
}
