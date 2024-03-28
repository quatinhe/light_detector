// GPIO pin where the PIR sensor is connected
const int motionSensorPin = 5; // Change as per your ESP32 board's GPIO
const int ledPin = 2; // GPIO pin connected to the LED - Change if needed

void setup() {
  Serial.begin(9600); // Start the Serial communication to print the output
  pinMode(motionSensorPin, INPUT); // Initialize the PIR sensor pin as an input
  pinMode(ledPin, OUTPUT); // Initialize the LED pin as an output
  digitalWrite(ledPin, LOW); // Ensure LED is off
}

void loop() {
  int motionStatus = digitalRead(motionSensorPin); // Read the PIR sensor output

  if (motionStatus == HIGH) {
    // When motion is detected, sensor outputs HIGH
    Serial.println("Motion detected! LED is ON.");
    digitalWrite(ledPin, HIGH); // Turn LED on
  } else {
    // When no motion is detected, sensor outputs LOW
    Serial.println("No motion detected. LED is OFF.");
    digitalWrite(ledPin, LOW); // Turn LED off
  }
  
  // Adding a delay to avoid printing too many messages.
  delay(500);
}
