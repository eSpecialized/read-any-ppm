/*This program puts the servo values into an array,
 reagrdless of channel number, polarity, ppm frame length, etc...
 You can even change these while scanning!*/
//PPM_Pin: this must be 2 or 3 on older Arduinos with Atmega chips.
// On Uno Wifi Rev2 It can be any pin. ATSAMD21 M0 it can almost be any pin.
#define PPM_Pin 5
volatile int ppm[16];  //array for storing up to 16 servo signals
byte servo[] = {1,4,5,6,7,8,9,10};  //pin number of servo output
//#define servoOut  //comment this if you don't want servo output, it also appears to dead lock the program.
//#define DEBUG

void setup()
{
  Serial.begin(9600);
  Serial.println("ready");

  #if defined(servoOut)
  for(byte i=0; sizeof(servo)-1; i++) pinMode(servo[i], OUTPUT);
  #endif

#if defined(ARDUINO_ARCH_SAMD)
   pinMode(PPM_Pin, INPUT_PULLUP);
   attachInterrupt(PPM_Pin, read_ppm, RISING);
#else
  pinMode(PPM_Pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(PPM_Pin), read_ppm, RISING);
#endif
}

void loop()
{
  //You can delete everithing inside loop() and put your own code here
/*  int count = 0;
  while(ppm[count] != 0){  //print out the servo values
    Serial.print(ppm[count]);
    Serial.print("  ");
    count++;
  }
  Serial.println("");*/
  
  delay(100);  //you can even use delays!!!
}

void read_ppm(){  //leave this alone
  static byte channel;
  static unsigned long last_micros;

  static unsigned int pulsems;
  unsigned long microCount = micros();
  unsigned long counterMs = microCount - last_micros;
  
  if(counterMs > 2100){  //sync pulses over 2100us *multiplier
    channel = 0;

    #if defined(DEBUG)
    Serial.print("PPM Frame Len: ");
    Serial.println(microCount - last_micros);
    #endif
  }
  else{  //servo values between 710us and 2420us will end up here
    ppm[channel] = counterMs;

    #if defined(DEBUG)
    Serial.print(ppm[channel]);
    Serial.print("  ");
    #endif
    
    channel++;
  }
  
  last_micros = microCount;
}
