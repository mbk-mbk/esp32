/**
 * This example turns the ESP32 into a Bluetooth LE mouse that continuously moves the mouse.
 */
#include <BleMouse.h>

// set pin numbers for switch, joystick axes, and LED:
const int switchPin = 39;      // switch to turn on and off mouse control
const int mouseButton = 36;    // input pin for the mouse pushButton
const int xAxis = 34;         // joystick X axis
const int yAxis = 35;         // joystick Y axis
const int ledPin = 2;         // Mouse control LED

// parameters for reading the joystick:
int range = 12;               // output range of X or Y movement
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range / 4;    // resting threshold
int center = range / 2;       // resting position value

bool mouseIsActive = true;    // whether or not to control the mouse
int lastSwitchState = LOW;        // previous switch state

BleMouse bleMouse;

void setup() {
  pinMode(switchPin, INPUT);       // the switch pin
  pinMode(ledPin, OUTPUT);         // the LED pin
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
}

void loop() {
  if(bleMouse.isConnected()) {

    unsigned long startTime;

    
  int switchState = digitalRead(switchPin);
  // if it's changed and it's high, toggle the mouse state:
  if (switchState != lastSwitchState) {
    if (switchState == HIGH) {
      mouseIsActive = !mouseIsActive;
      // turn on LED to indicate mouse state:
      digitalWrite(ledPin, mouseIsActive);
    }
  }
  // save switch state for next comparison:
  lastSwitchState = switchState;

  // read and scale the two axes:
//  int xReading = readAxis(34);
//  int yReading = readAxis(35);

    int xReading = (analogRead(34)-1800)/100;
    int yReading = (analogRead(35)-1900)/100;
    



 Serial.println("Scroll up");
    startTime = millis();
    while(millis()<startTime+200) {
//       if (mouseIsActive) {
      bleMouse.move(xReading, yReading);
      delay(50);
//       }
    }




//
// if (digitalRead(mouseButton) == HIGH) {
//    // if the mouse is not pressed, press it:
//    if (!Mouse.isPressed(MOUSE_LEFT)) {
//      Mouse.press(MOUSE_LEFT);
//    }
//  }
//  // else the mouse button is not pressed:
//  else {
//    // if the mouse is pressed, release it:
//    if (Mouse.isPressed(MOUSE_LEFT)) {
//      Mouse.release(MOUSE_LEFT);
//    }
//  }

  delay(responseDelay);




  

//    Serial.println("Scroll up");
//    startTime = millis();
//    while(millis()<startTime+2000) {
//      bleMouse.move(0,0,1);
//      delay(100);
//    }
//    delay(500);
//
//    Serial.println("Scroll down");
//    startTime = millis();
//    while(millis()<startTime+2000) {
//      bleMouse.move(0,0,-1);
//      delay(100);
//    }
//    delay(500);
//
//    Serial.println("Scroll left");
//    startTime = millis();
//    while(millis()<startTime+2000) {
//      bleMouse.move(0,0,0,-1);
//      delay(100);
//    }
//    delay(500);
//
//    Serial.println("Scroll right");
//    startTime = millis();
//    while(millis()<startTime+2000) {
//      bleMouse.move(0,0,0,1);
//      delay(100);
//    }
//    delay(500);
//
//    Serial.println("Move mouse pointer up");
//    startTime = millis();
//    while(millis()<startTime+2000) {
//      bleMouse.move(0,-1);
//      delay(100);
//    }
//    delay(500);
//
//    Serial.println("Move mouse pointer down");
//    startTime = millis();
//    while(millis()<startTime+2000) {
//      bleMouse.move(0,1);
//      delay(100);
//    }
//    delay(500);
//
//    Serial.println("Move mouse pointer left");
//    startTime = millis();
//    while(millis()<startTime+2000) {
//      bleMouse.move(-1,0);
//      delay(100);
//    }
//    delay(500);
//
//    Serial.println("Move mouse pointer right");
//    startTime = millis();
//    while(millis()<startTime+2000) {
//      bleMouse.move(1,0);
//      delay(100);
//    }
//    delay(500);

  }
}


int readAxis(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);

  // if the output reading is outside from the rest position threshold, use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }

  // return the distance for this axis:
  return distance;
}
