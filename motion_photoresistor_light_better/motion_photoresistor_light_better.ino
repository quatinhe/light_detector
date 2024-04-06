bool isLedPreviouslyOn = false; // Global flag to track LED state

void loop() {
  // Read the analog value from the photoresistor
  int analogValue = analogRead(photoresistorPin);
  int motionStatus = digitalRead(motionSensorPin);

  // Conditions to turn the LED on
  if (analogValue < 500 && motionStatus == HIGH) {
    analogWrite(ledPin, 100);
    isLedPreviouslyOn = true; // LED is now on
  } else if (analogValue > 600 && isLedPreviouslyOn) {
    // Keep the LED on if it was on previously and analogValue is now > 600
    analogWrite(ledPin, 100);
  }// else {
    // Turn the LED off otherwise
    //analogWrite(ledPin, 0);
    //isLedPreviouslyOn = false; // LED is now off
  //}

  // Print the analog value to the Serial Monitor
  Serial.print("Analog reading: ");
  Serial.println(analogValue);

  // Wait for a bit before reading again
  delay(500);
}

