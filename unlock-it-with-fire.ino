/* 
Sketch Name:    Unlock it with Fire (unlock-it-with-fire.ino)
Author:         alexdglover (alexdglover@gmail.com, @alexdglover)
Description:    A sketch to control a 12v door latch based on the presence/absence of a flame
                This is combined with a cigar box to make a lock box that can only be opened by 
                using a flame as the "key."
Date:           11-July-2015

*/

// Set the relay pin to 8
const int relayPin = 8;
// Set the sensor pin for the infrared sensor to A0, which is 14 on the ATmega328
const int sensorPin = 14;

// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum



void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);
  // initialize the relay pin for controlling the relay
  pinMode(relayPin, OUTPUT);
}
void loop() {
  // read the sensor on analog A0:
  int sensorReading = analogRead(sensorPin);
  Serial.println(sensorReading);

  // Open relay (lock the box)
  digitalWrite(relayPin, HIGH);  

  // If a flame is present, close the relay (closing the circuit and unlocking the box) and pause for one second
  // Adjust this value below as necessary for your sensor's sensitivity
  if(sensorReading <= 50) 
  {
    digitalWrite(relayPin, LOW);
    Serial.println("Detected fire!");
    delay(1000);
  }
  delay(100);  // delay between reads
}
