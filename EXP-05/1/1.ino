const int photocellPin = A0;
const int ledPin = 13;
const int relayPin = 8;
int outputValue  = 0;
void setup() {
  // put your setup code here, to run once:
 pinMode(relayPin,OUTPUT);
 pinMode(ledPin,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 outputValue = analogRead(photocellPin);
 Serial.println(outputValue);
 if (outputValue >=400){
   digitalWrite(ledPin,HIGH);
   digitalWrite(relayPin,LOW);
 }
 else{
   digitalWrite(ledPin,LOW);
   digitalWrite(relayPin,HIGH);
 }
 delay(1000);
}