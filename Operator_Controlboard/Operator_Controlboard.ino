#include <XInput.h>
// To upload to the board:
// Press the ‘Upload’ button in the IDE
// Wait until the status bar says “Uploading…”
// Press the reset button twice, quickly

//dgital
int aButton = 2;
int bButton = 3;
int xButton = 4;
int yButton = 5;
int lbButton = 6;
int rbButton = 7;
int backButton = 8;
//analog
int leftJoyX = A0;
int leftJoyY  = A1;
int rightJoyX = A2;
int rightJoyY = A3;
int leftTrigger = A4;

//smoothing
const int numReadings = 10;
int readingsLJX[numReadings];      // the readings from the analog input
int readIndexLJX = 0;              // the index of the current reading
int totalLJX = 0;                  // the running total
int averageLJX = 0;                // the average

int readingsLJY[numReadings];      // the readings from the analog input
int readIndexLJY = 0;              // the index of the current reading
int totalLJY = 0;                  // the running total
int averageLJY = 0;                // the average

int readingsRJX[numReadings];      // the readings from the analog input
int readIndexRJX = 0;              // the index of the current reading
int totalRJX = 0;                  // the running total
int averageRJX = 0;                // the average

int readingsRJY[numReadings];      // the readings from the analog input
int readIndexRJY = 0;              // the index of the current reading
int totalRJY = 0;                  // the running total
int averageRJY = 0;                // the average

int readingsTL[numReadings];      // the readings from the analog input
int readIndexTL = 0;              // the index of the current reading
int totalTL = 0;                  // the running total
int averageTL = 0;                // the average

//inverting Y axis
bool InvertLeftYAxis = false;
bool InvertRightYAxis = false;

void setup() {
  // put your setup code here, to run once:
  //buttons
  pinMode(aButton, INPUT_PULLUP);
  pinMode(bButton, INPUT_PULLUP);
  pinMode(xButton, INPUT_PULLUP);
  pinMode(yButton, INPUT_PULLUP);
  pinMode(lbButton, INPUT_PULLUP);
  //a switch
  pinMode(rbButton, INPUT_PULLUP);
  pinMode(backButton, INPUT_PULLUP);

  //Joystick/Triger valuses
  XInput.setTriggerRange(0, 1023);
  XInput.setJoystickRange(0, 1023);

  //smoothing
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readingsLJX[thisReading] = 0;
  }
   
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readingsLJY[thisReading] = 0;
  }
  
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readingsRJX[thisReading] = 0;
  }
   
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readingsRJY[thisReading] = 0;
  } 
  
 for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readingsTL[thisReading] = 0;
  }

  XInput.setAutoSend(false);
  XInput.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //buttons
  bool aState = !digitalRead(aButton);
  XInput.setButton(BUTTON_A, aState);

  bool bState = !digitalRead(bButton);
  XInput.setButton(BUTTON_B, bState);

  bool xState = !digitalRead(xButton);
  XInput.setButton(BUTTON_X, xState);

  bool yState = !digitalRead(yButton);
  XInput.setButton(BUTTON_Y, yState);

  bool lbState = !digitalRead(lbButton);
  XInput.setButton(BUTTON_LB, lbState);

  bool rbState = !digitalRead(rbButton);
  XInput.setButton(BUTTON_RB, rbState);

  bool backState = !digitalRead(backButton);
  XInput.setButton(BUTTON_BACK, backState);

//Joysticks
  bool invertLeftY = !InvertLeftYAxis;
  bool invertRightY = !InvertRightYAxis;

  // subtract the last reading:
  totalLJX = totalLJX - readingsLJX[readIndexLJX];
  // read from the sensor:
  readingsLJX[readIndexLJX] = analogRead(leftJoyX);
  // add the reading to the total:
  totalLJX = totalLJX + readingsLJX[readIndexLJX];
  // advance to the next position in the array:
  readIndexLJX = readIndexLJX + 1;
  // if we're at the end of the array...
  if (readIndexLJX >= numReadings) {
    // ...wrap around to the beginning:
    readIndexLJX = 0;
  }
  // calculate the average:
  averageLJX = totalLJX / numReadings;
  XInput.setJoystickX(JOY_LEFT, averageLJX);

  // subtract the last reading:
  totalLJY = totalLJY - readingsLJY[readIndexLJY];
  // read from the sensor:
  readingsLJY[readIndexLJY] = analogRead(leftJoyY);
  // add the reading to the total:
  totalLJY = totalLJY + readingsLJY[readIndexLJY];
  // advance to the next position in the array:
  readIndexLJY = readIndexLJY + 1;
  // if we're at the end of the array...
  if (readIndexLJY >= numReadings) {
    // ...wrap around to the beginning:
    readIndexLJY = 0;
  }
  // calculate the average:
  averageLJY = totalLJY / numReadings;
  XInput.setJoystickY(JOY_LEFT, averageLJY, invertLeftY);


  totalRJY = totalRJX - readingsRJX[readIndexRJX];
  // read from the sensor:
  readingsRJY[readIndexRJX] = analogRead(rightJoyX);
  // add the reading to the total:
  totalRJX = totalRJX + readingsRJX[readIndexRJX];
  // advance to the next position in the array:
  readIndexRJX = readIndexRJX + 1;
  // if we're at the end of the array...
  if (readIndexRJX >= numReadings) {
    // ...wrap around to the beginning:
    readIndexRJX = 0;
  }
  // calculate the average:
  averageRJX = totalRJX / numReadings;
  XInput.setJoystickX(JOY_RIGHT, averageRJX);

  totalRJY = totalRJY - readingsRJY[readIndexRJY];
  // read from the sensor:
  readingsRJY[readIndexRJY] = analogRead(rightJoyY);
  // add the reading to the total:
  totalRJY = totalRJY + readingsRJY[readIndexRJY];
  // advance to the next position in the array:
  readIndexRJY = readIndexRJY + 1;
  // if we're at the end of the array...
  if (readIndexRJY >= numReadings) {
    // ...wrap around to the beginning:
    readIndexRJY = 0;
  }
  // calculate the average:
  averageRJY = totalRJY / numReadings;
  XInput.setJoystickY(JOY_RIGHT, averageRJY, invertRightY);

 //Trigger
   totalTL = totalTL - readingsTL[readIndexTL];
  // read from the sensor:
  readingsTL[readIndexTL] = analogRead(leftTrigger);
  // add the reading to the total:
  totalTL = totalTL + readingsTL[readIndexTL];
  // advance to the next position in the array:
  readIndexTL = readIndexTL + 1;
  // if we're at the end of the array...
  if (readIndexTL >= numReadings) {
    // ...wrap around to the beginning:
    readIndexTL = 0;
  }
  // calculate the average:
  averageTL = totalTL / numReadings;
  XInput.setTrigger(TRIGGER_LEFT, averageTL);

  XInput.send();
}
