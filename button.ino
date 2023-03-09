#include "Keyboard.h"

//declaring button pins
const int buttonPin_1 = 4;
const int buttonPin_2 = 5;
const int buttonPin_3 = 6; //Pins - 4, 5, 6
char options[3][7] = {"Google", "Yahoo", "Proton"};
char passwords[3][11] = {"Test", "1234", "Test1234"}; 
int counter = 0;

int previousButtonState_1 = HIGH; 
int previousButtonState_2 = HIGH; 
int previousButtonState_3 = HIGH; 

void setup() {
  Serial.begin(9600); // debug

  //declare the buttons as input_pullup
  pinMode(buttonPin_1, INPUT_PULLUP);  
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(buttonPin_3, INPUT_PULLUP);  
  Keyboard.begin();
}

void loop() {
  //checking the state of the button
  int buttonState_1 = digitalRead(buttonPin_1);
  int buttonState_2 = digitalRead(buttonPin_2);
  int buttonState_3 = digitalRead(buttonPin_3);
  
 //replaces button press with UP arrow
  if (buttonState_1 == LOW && previousButtonState_1 == HIGH) {
    // and it's currently pressed:
    // Keyboard.press(97);.0
    delay(100);
  }

  if (buttonState_2 == LOW && previousButtonState_2 == HIGH) {
    // and it's currently pressed:
    // Keyboard.press(97);.0
    delay(100);
  }

  if (buttonState_3 == LOW && previousButtonState_3 == HIGH) {
    // and it's currently pressed:
    // Keyboard.press(97);.0
    delay(100);
  }

  if (buttonState_1 == HIGH && previousButtonState_1 == LOW) {
    // and it's currently released:
    if(counter > 0)
    {
      counter = counter - 1;
    }
    //Keyboard.print(options[counter]);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(100);

    Serial.print(options[counter]); // debug
  }
  
  if (buttonState_2 == HIGH && previousButtonState_2 == LOW) {
    // and it's currently released:
    if(counter < 3)
    {
      counter = counter + 1;
    }
    //Keyboard.print(options[counter]);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(100);

    Serial.print(counter); // debug
  }

  if (buttonState_3 == HIGH && previousButtonState_3 == LOW) {
    // and it's currently released:
    Keyboard.print(passwords[counter]);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(100);

    Serial.print("button3 released"); // debug
  }
 
  previousButtonState_1 = buttonState_1;
  previousButtonState_2 = buttonState_2;
  previousButtonState_3 = buttonState_3;

}