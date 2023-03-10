#include <WebUSB.h>

/**
 * Creating an instance of WebUSBS will add an additional USB interface to
 * the device that is marked as vendor-specific (rather than USB CDC-ACM) and
 * is therefore accessible to the browser.
 *
 * The URL here provides a hint to the browser about what page the user should
 * navigate to to interact with the device.
 */
WebUSB WebUSBS(0 /* https:// */, "webusb.github.io/arduino/demos/console");

#define S WebUSBS

const int ledPin = 13;
char temp[3][10];

void setup() {
  Serial.begin(9600);
  while (!S) {
    ;
  }
  S.begin(9600);
  S.write("Sketch begins.\r\n> ");
  S.flush();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (S && S.available()) {
    int byte = S.read();
    int i = 0;
    int j = 0;
    S.write(byte);
    if(byte != '\t')
    {
      temp[j][i] = byte;
      i = i + 1;
    }
    else if(byte == '\t')
    {
      j = j + 1;
    }
    Serial.print(temp[j]);
    if (byte == 'H') {
      S.write("\r\nTurning LED on.");
      digitalWrite(ledPin, HIGH);
    } else if (byte == 'L') {
      S.write("\r\nTurning LED off.");
      digitalWrite(ledPin, LOW);
    }
    S.write("\r\n> ");
    S.flush();
  }
}