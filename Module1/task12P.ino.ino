// Define the pins for the ultrasonic sensor and LED
const int trigPin = 7;
const int echoPin = 6;
const int ledPin = 13;
const int buttonPin = 2;

volatile bool buttonPressed = false;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the pin modes
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Attach the interrupt to the button pin, triggering on a falling edge (button press)
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);
}

void loop() {
  if (buttonPressed) {
    buttonPressed = false; // Reset the flag

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
  }
}

// Interrupt service routine for the button press
void buttonISR() {
  buttonPressed = true;
}
