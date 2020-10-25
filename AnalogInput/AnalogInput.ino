/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/

int sensorPinx = 36;    // select the input pin for the potentiometer
int sensorPiny = 39;    // select the input pin for the potentiometer
int ledPin = 2;      // select the pin for the LED
int sensorValuex = 0;  // variable to store the value coming from the sensor
int sensorValuey = 0;  // variable to store the value coming from the sensor



// parameters for reading the joystick:
int range = 12;               // output range of X or Y movement
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range / 4;    // resting threshold
int center = range / 2;       // resting position value


void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // read the value from the sensor:
  sensorValuex = analogRead(sensorPinx);
//sensorValuex=readAxis(sensorPinx);
//  delay(sensorValuex);
//  Serial.print("sensor = ");
//  Serial.print(sensorValuex);
//  Serial.print("\t output = ");
  sensorValuey = analogRead(sensorPiny);
//sensorValuey=readAxis(sensorPiny);
//  delay(sensorValuey);
  Serial.print("sensor = ");
  Serial.print((sensorValuex-1800)/10);
  Serial.print("\t  = ");
  Serial.print((sensorValuey-1900)/10);
  Serial.print("\n output = ");
  // turn the ledPin on
//  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
//  delay(sensorValue);
//  Serial.print("sensor = ");
//  Serial.print(sensorValue);
//  Serial.print("\t output = ");
  // turn the ledPin off:
//  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(500);
}

int readAxis(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, -1023, 1023, 0, range);

  // if the output reading is outside from the rest position threshold, use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }

  // return the distance for this axis:
  return distance;
}
