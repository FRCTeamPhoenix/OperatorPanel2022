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

  int leftJoystickX = analogRead(leftJoyX);
  XInput.setJoystickX(JOY_LEFT, leftJoystickX);

  int leftJoystickY = analogRead(leftJoyY);
  XInput.setJoystickY(JOY_LEFT, leftJoystickY, invertLeftY);

  int rightJoystickX = analogRead(rightJoyX);
  XInput.setJoystickX(JOY_RIGHT, rightJoystickX);

  int rightJoystickY = analogRead(rightJoyY);
  XInput.setJoystickY(JOY_RIGHT, rightJoystickY, invertRightY);

 //Trigger
  int triggerLeft = analogRead(leftTrigger);
  XInput.setTrigger(TRIGGER_LEFT, triggerLeft);

  XInput.send();
}
