/* FSR testing sketch. 
 
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */
 
int fsrAnalogPin0 = 0; // FSR is connected to analog 0
int fsrAnalogPin1 = 1; // FSR is connected to analog 1
int fsrAnalogPin2 = 2; // FSR is connected to analog 2
int fsrAnalogPin3 = 3; // FSR is connected to analog 3
int fsrAnalogPin4 = 4; // FSR is connected to analog 4
int fsrAnalogPin5 = 5; // FSR is connected to analog 5

int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;      // the analog reading from the FSR resistor divider
int fsrReading1;      // the analog reading from the FSR resistor divider
int fsrReading2;      // the analog reading from the FSR resistor divider
int fsrReading3;      // the analog reading from the FSR resistor divider
int fsrReading4;      // the analog reading from the FSR resistor divider
int fsrReading5;      // the analog reading from the FSR resistor divider
int LEDbrightness;
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);
}
 
void loop(void) {
  fsrReading = analogRead(fsrAnalogPin0);

  //Input thing I.D.
  Serial.print("fsr-388e,");

  Serial.print(fsrReading);
 
  Serial.print(',');
  
  fsrReading1 = analogRead(fsrAnalogPin1);
  Serial.print(fsrReading1);

  
  Serial.print(',');
  
  fsrReading2 = analogRead(fsrAnalogPin2);
  Serial.print(fsrReading2);

  Serial.print(',');

    fsrReading3 = analogRead(fsrAnalogPin3);
  Serial.print(fsrReading3);
  
  Serial.print(',');

    fsrReading4 = analogRead(fsrAnalogPin4);
  Serial.print(fsrReading4);
  
  Serial.print(',');
  
  fsrReading5 = analogRead(fsrAnalogPin5);
  Serial.println(fsrReading5);

  Serial.print('\n');
  
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  analogWrite(LEDpin, LEDbrightness);
 
  delay(50);
}
