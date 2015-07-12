/* Flame Sensor analog example.
Code by Reichenstein7 (thejamerson.com)

Flame Sensor Ordered from DX ( http://www.dx.com/p/arduino-flame-sensor-for-temperature-
detection-blue-dc-3-3-5v-118075?tc=USD&gclid=CPX6sYCRrMACFZJr7AodewsA-Q#.U_n5jWOrjfU )

To test view the output, point a serial monitor such as Putty at your arduino. 
*/

// Set the relay pin to 2
const int relayPin = 8;
// Set the sensor pin for the infrared sensor to A0, which is 14
const int sensorPin = 14;

// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum



void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);
  // initialize the pin 13 for controlling the relay
  pinMode(relayPin, OUTPUT);
}
void loop() {
  // read the sensor on analog A0:
  int sensorReading = analogRead(sensorPin);
  Serial.println(sensorReading);

  // Open relay (lock the box) and set the LED to red
  digitalWrite(relayPin, HIGH);  

  // If a flame is present, close the relay (unlock the box), set the LED to green, and pause for one second
  if(sensorReading <= 50) 
  {
    digitalWrite(relayPin, LOW);
    Serial.println("Fire!");
    delay(1000);
  }
  delay(100);  // delay between reads
}
