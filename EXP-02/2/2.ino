const int analogPin = A0;
const int ledPin = 13;
int inputValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  inputValue = analogRead(analogPin);
  digitalWrite(ledPin,HIGH);
  delay(inputValue);
  digitalWrite(ledPin,LOW);
  delay(inputValue);
}
