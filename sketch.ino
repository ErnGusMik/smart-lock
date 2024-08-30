// Now turn this trash into treasure!

#include <Servo.h>
#include <Keypad.h>

// Constants
const int led_pins[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 14 };
int oldBtnVal = HIGH;

const uint8_t ROWS = 4;
const uint8_t COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

uint8_t colPins[COLS] = { 26, 22, 21, 20 }; // Pins connected to C1, C2, C3, C4
uint8_t rowPins[ROWS] = { 16, 17, 18, 19 }; // Pins connected to R1, R2, R3, R4

Keypad keypad = keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  Serial1.println("Hello, Raspberry Pi Pico W!");

  // LED strip
  for (int i = 0; i < 9; i++) {
    pinMode(led_pins[i], OUTPUT);
  }
  pinMode(led_pins[9], OUTPUT);

  // Button
  pinMode(15, INPUT_PULLUP);

  // Buzzer
  pinMode(28, OUTPUT);

  // Servo
  servo.attach(27);
  servo.write(0);
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

  if (newBtnVal == LOW) {
    // Serial1.println("Btn pressed!");
  } else {
    // Serial1.println("Btn not pressed");
  }

  oldBtnVal = newBtnVal;

  // Buzzer
  // tone(pin, Hz, ms)

  // Servo
  // servo.write(deg)

  // Keypad
  char key = keypad.getKey();

  if (key != NO_KEY) {
    Serial1.println(key);
  }
}
