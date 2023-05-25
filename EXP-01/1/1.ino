int redPIN = 11;     // Variable to store the pin number for the red LED
int greenPIN = 10;   // Variable to store the pin number for the green LED
int val = 0;         // Variable to store the current value

void setup() {
  pinMode(redPIN, OUTPUT);     // Set the red LED pin as output
  pinMode(greenPIN, OUTPUT);   // Set the green LED pin as output
  Serial.begin(9600);          // Initialize the serial communication at 9600 baud rate
}

void loop() {
  // Fade in the red LED and fade out the green LED
  for (val = 255; val > 0; val--) {    // Loop from 255 to 0
    analogWrite(redPIN, val);          // Set the brightness of the red LED
    analogWrite(greenPIN, 255 - val);  // Set the brightness of the green LED (opposite of red)
    Serial.println(val, DEC);          // Print the current value to the serial monitor
    delay(30);                         // Delay for 30 milliseconds
  }

  // Fade in the red LED and fade out the red LED
  for (val = 255; val > 0; val--) {    // Loop from 255 to 0
    analogWrite(redPIN, val);          // Set the brightness of the red LED
    analogWrite(redPIN, 255 - val);    // Set the brightness of the red LED (opposite of previous value)
    Serial.println(val, DEC);          // Print the current value to the serial monitor
    delay(30);                         // Delay for 30 milliseconds
  }
}
