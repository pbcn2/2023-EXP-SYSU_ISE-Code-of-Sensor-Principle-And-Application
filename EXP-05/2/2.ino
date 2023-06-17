const int photoPin = 7;
const int ledPin = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(photoPin,INPUT);
pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
boolean Value = digitalRead(photoPin);
if (Value == HIGH){
  digitalWrite (ledPin,LOW);
}
else{
  digitalWrite(ledPin,HIGH);
}
}