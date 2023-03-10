#include "Keyboard.h"
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
#include <WebUSB.h>

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

// Define proper RST_PIN if required.
#define RST_PIN -1
#define MAX 10

WebUSB WebUSBS(0 /* https:// */, "webusb.github.io/arduino/demos/console");

#define Web WebUSBS

SSD1306AsciiAvrI2c oled;

// declaring button
// pins - 4, 5, 6, 7
const int buttonPin_1 = 4;
const int buttonPin_2 = 5;
const int buttonPin_3 = 6;
const int buttonPin_4 = 7;

int previousButtonState_1 = HIGH; 
int previousButtonState_2 = HIGH; 
int previousButtonState_3 = HIGH; 
int previousButtonState_4 = HIGH;

int mode = 0; // 0 - password manager, 1 - web usb setup

char options[10][20];
char passwords[10][20];
int current = 0;
int address = 0;
int input = 0; // 0 - option, 1 - password
int index = 0;


void setup() {
  Serial.begin(9600); // debug

  while (!Web) {
    ;
  }

  #if RST_PIN >= 0
  oled.begin(&Adafruit128x32, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  oled.begin(&Adafruit128x32, I2C_ADDRESS);
#endif // RST_PIN >= 0
  // Call oled.setI2cClock(frequency) to change from the default frequency.

  oled.setFont(Adafruit5x7);

  uint32_t m = micros();

  oled.clear();

  char msg[] = "Keyboard connected...\r\n";
  oled.println(msg);

  // declare the buttons as input_pullup
  pinMode(buttonPin_1, INPUT_PULLUP);  
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(buttonPin_3, INPUT_PULLUP);
  pinMode(buttonPin_4, INPUT_PULLUP);
}

void loop() {
  //checking the state of the button
  int buttonState_1 = digitalRead(buttonPin_1);
  int buttonState_2 = digitalRead(buttonPin_2);
  int buttonState_3 = digitalRead(buttonPin_3);
  int buttonState_4 = digitalRead(buttonPin_4);

  if (buttonState_4 == HIGH && previousButtonState_4 == LOW) {
    // currently released:
    delay(100);
    if (mode == 0) {
      mode = 1;
      char msg[] = "Web USB connected...\r\n";

      // stop keyboard
      Keyboard.end();

      // start web usb
      Web.begin(9600);
      Web.write(msg);
      Web.flush();

      input = 0;
      index = 0;

      oled.clear();
      oled.print(msg);
    }
    else {
      mode = 0;
      char msg[] = "Keyboard connected...\r\n";

      // stop web usb
      Web.write(msg);
      Web.flush();
      Web.end();

      // start keyboard
      Keyboard.begin();

      oled.clear();
      oled.print(msg);
    }
  }  

  if (mode == 0) {
    if (buttonState_1 == HIGH && previousButtonState_1 == LOW) {
      if (current > 0)
      {
        current = current - 1;
      }
      oled.clear();
      oled.print(String(current));
      oled.print(" -> ");
      oled.println(options[current]);
      delay(200);
    }
    
    if (buttonState_2 == HIGH && previousButtonState_2 == LOW) {
      if(current + 1 < address)
      {
        current = current + 1;
      }
      oled.clear();
      oled.print(String(current));
      oled.print(" -> ");
      oled.println(options[current]);
      delay(200);
    }

    if (buttonState_3 == HIGH && previousButtonState_3 == LOW) {
      Keyboard.print(passwords[current]);
      delay(100);
      Keyboard.release(KEY_RETURN);
      delay(100);
    }
  }
  
  if (mode == 1) {    
    if (Web && Web.available()) {
      int byte = Web.read();

      if (byte == '\r') {
        input = 0;
        index = 0;
        address = address + 1;

        Web.write("\r\n[Done]\r\n");
        Web.flush();        
      }
      else if (byte == '\t') {
        if (input == 0) {
          input = 1;
        }
        else {
          input = 0;
          
          Web.write("\r\n[Canceled]\r\n");
          Web.flush();          
        }
        index = 0;

        Web.write("\r\n");
        Web.flush();        
      }
      else {
        if (input == 0)
        {
          options[address][index] = byte;
          index = index + 1;
        }
        else if (input == 1) {
          passwords[address][index] = byte;
          index = index + 1;
        }
        Web.write(byte);
        Web.flush();
      }
    }
  }
 
  previousButtonState_1 = buttonState_1;
  previousButtonState_2 = buttonState_2;
  previousButtonState_3 = buttonState_3;
  previousButtonState_4 = buttonState_4;
}