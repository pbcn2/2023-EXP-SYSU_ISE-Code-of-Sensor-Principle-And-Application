const int ledPin = 13;
int sensorPin = A0;    
int digitalPin=7;  

int sensorValue = 0;
boolean digitalValue=0;

void setup() 
{
  pinMode(digitalPin,INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() 
{ 
  sensorValue = analogRead(sensorPin); 
  digitalValue=digitalRead(digitalPin);  
  Serial.print("Sensor Value "); 
  Serial.println(sensorValue);
  Serial.print("Digital Value "); 
  Serial.println(digitalValue);
  if( digitalValue==HIGH )
  {
    digitalWrite(ledPin,LOW);
  }
  if( digitalValue==LOW)
  {
    digitalWrite(ledPin,HIGH);
  }
  delay(200);
}
