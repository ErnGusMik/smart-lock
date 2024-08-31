// Now turn this trash into treasure!

#include <Servo.h>

// Constants
const int led_pins[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 14 };

const uint8_t ROWS = 4;
const uint8_t COLS = 4;

const uint8_t keypadRows[ROWS] = { 20, 21, 22, 26 };
const uint8_t keypadCols[COLS] = { 16, 17, 18, 19 };

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

int oldBtnVal = HIGH;



Servo servo;


void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  Serial1.println("Hello, Raspberry Pi Pico W!");

  // // LED strip
  // for (int i = 0; i < 9; i++) {
  //   pinMode(led_pins[i], OUTPUT);
  // }
  // pinMode(led_pins[9], OUTPUT);

  // Button
  pinMode(15, INPUT_PULLUP);

  // // Buzzer
  // pinMode(28, OUTPUT);

  // Servo
  // servo.attach(27);
  // servo.write(0);

  // // RGB light
  // pinMode(11, OUTPUT);
  // pinMode(12, OUTPUT);
  // pinMode(13, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  delay(500); // this speeds up the simulation (0.5sec)

  // LED strip
  // for (int i = 0; i < 9; i++) {
  //   if (digitalRead(led_pins[i]) == HIGH) {
  //     digitalWrite(led_pins[i], LOW);
  //     Serial1.println("Setting LOW");
  //   } else {
  //     digitalWrite(led_pins[i], HIGH);
  //     Serial1.println("Setting HIGH");
  //   }
  // }

  // Button & buzzer
  const int newBtnVal = digitalRead(15);

  // Buzzer
  // tone(pin, Hz, ms)

  // Servo
  // servo.write(deg)

  if (newBtnVal != oldBtnVal && newBtnVal == LOW) {
    tone(28, 1000, 50);
    // servo.write(90);
    delay(100);


    digitalWrite(led_pins[0], HIGH);
    digitalWrite(led_pins[1], HIGH);

    for (int i = 0; i < 5; i++) {
      for (int j = 2; j < 10 - i*2; j++) {
       digitalWrite(led_pins[j], HIGH);
      }

      analogWrite(11, 255);
      delay(1000);
      analogWrite(11, 0);
      delay(500);
      for (int j = 2; j < 10; j++) {
       digitalWrite(led_pins[j], LOW);
      }
    }

    digitalWrite(led_pins[0], LOW);
    digitalWrite(led_pins[1], LOW);

    // servo.write(0);
    tone(28, 500, 25);
    delay(100);
    tone(28, 500, 25);
    analogWrite(11, 0);
  }

  oldBtnVal = newBtnVal;
}
