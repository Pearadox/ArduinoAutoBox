#include <Joystick.h>

/*
 *  1, btn1: 1
 *  2, btn2: 0
 *  3, btn3: 2
 *  
 *  Switch 2:
 *  1, btn4: 3
 *  2, btn5: 4
 *  3, btn6: 5
 *  
 *  Switch 3:
 *  1, btn7: 6
 *  2, btn8: 7
 *  3, btn9: 8
 *  
 *  Switch 4:
 *  1, btn10: 10
 *  2, btn11: 16
 *  3, btn12: 14
 */

Joystick_ joy;

int pinArr[12] = {1,0,2,3,4,5,6,7,8,10,16,14};
int btnArr[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
int lastBtnArr[12];

void setup() {
  // put your setup code here, to run once:
  pinMode(1, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);

  joy.begin();

  for(int i = 0; i < 12; i++) {
    lastBtnArr[i] = 0;
  }

  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 12; i++) {
    int currentState = !digitalRead(pinArr[i]);
//    if(currentState != lastBtnArr[i]) {
      joy.setButton(btnArr[i], currentState);
//      lastBtnArr[i] = currentState;
//    }
  }
  delay(10);
}
