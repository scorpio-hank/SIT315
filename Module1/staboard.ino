// Define the pins for the ultrasonic sensor and LED
const int trigPin = 3;
const int echoPin = 2;
const int ledPin = 13;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  
  // Set the pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pin and calculate the distance
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Turn on the LED if the distance is less than 1 meter (100 cm)
  if (distance < 100) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  // Wait for a short period before repeating the measurement
  delay(100);
}
