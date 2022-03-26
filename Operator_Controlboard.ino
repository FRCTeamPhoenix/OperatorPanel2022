#include <XInput.h>
// To upload to the board:
// Press the ‘Upload’ button in the IDE
// Wait until the status bar says “Uploading…”
// Press the reset button twice, quickly

int aButton = 2;
int bButton = 3;
int xButton = 4;
int yButton = 5;
int lbButton=6;
int rbButton = 7;

void setup() {
  // put your setup code here, to run once:
  XInput.begin();

  pinMode(aButton, INPUT_PULLUP);
  pinMode(bButton, INPUT_PULLUP);
  pinMode(xButton, INPUT_PULLUP);
  pinMode(yButton, INPUT_PULLUP);
  pinMode(lbButton, INPUT_PULLUP);
  //awitch
  pinMode(rbButton, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
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
  XInput.setButton(BUTTON_LB, rbState);
}
