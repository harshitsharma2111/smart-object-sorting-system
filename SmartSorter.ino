#include <Servo.h>
#include <LiquidCrystal.h>

// Pins: RS=12, E=11, DB4=5, DB5=4, DB6=3, DB7=2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo sorterServo;

const int sigPin = 7;
long duration;
int distance;

void setup() {
  sorterServo.attach(10);
  sorterServo.write(0); // Neutral Position (0 degrees)

  lcd.begin(16, 2);
  lcd.print("System Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Send trigger pulse on Pin 7
  pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sigPin, LOW);

  // Read echo pulse on Pin 7
  pinMode(sigPin, INPUT);
  duration = pulseIn(sigPin, HIGH);
  distance = duration * 0.034 / 2; // Calculate distance in cm

  // Display distance on Line 1
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  // Actuate Servo based on 10 cm threshold
  if (distance > 0 && distance <= 10) {
    lcd.setCursor(0, 1);
    lcd.print("Action: SORT    ");
    sorterServo.write(90); // Rotate 90 degrees to sort
    delay(2000);
    sorterServo.write(0);  // Reset arm
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Action: CLEAR   ");
    sorterServo.write(0);
  }

  delay(200);
}
