// Define the GPIO pin that the photoresistor A0 pin is connected to
const int photoresistorPin = 34; // ADC1 channel
const int motionSensorPin = 5; // Change as per your ESP32 board's GPIO
const int ledPin = 2;

void setup() {
  // Start serial communication at a baud rate of 115200
  Serial.begin(9600);
  // Initialize GPIO 34 as an input
  pinMode(motionSensorPin, INPUT);
  pinMode(photoresistorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read the analog value from photoresistor
  int analogValue = analogRead(photoresistorPin);
  int motionStatus = digitalRead(motionSensorPin);
  if(analogValue <500 && motionStatus == HIGH){
    analogWrite(ledPin, 100);  
  }else{
    analogWrite(ledPin, 0);
  }
  // Print the analog value to the Serial Monitor
  Serial.print("Analog reading: ");
  Serial.println(analogValue);
  // Wait for a bit before reading again
  delay(500);
}
