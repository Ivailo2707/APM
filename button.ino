#include "Keyboard.h"

//declaring button pins
const int buttonPin_1 = 4;
const int buttonPin_2 = 5;
const int buttonPin_3 = 6; //Pins - 4, 5, 6

   

int previousButtonState = HIGH; 

void setup() {
  Serial.begin(9600); // debug

  //declare the buttons as input_pullup
  pinMode(buttonPin_3, INPUT_PULLUP);  
  Keyboard.begin();
}

void loop() {
  //checking the state of the button
  int buttonState = digitalRead(buttonPin_3);
  
 //replaces button press with UP arrow
  if (buttonState == LOW && previousButtonState == HIGH) {
    // and it's currently pressed:
    // Keyboard.press(97);.0
    delay(100);
  }

  if (buttonState == HIGH && previousButtonState == LOW) {
    // and it's currently released:
    Keyboard.print("PASSWORD");
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(100);

    Serial.print("button released"); // debug
  }
 
  previousButtonState = buttonState;

}