/************************************
 * 项目名字：继电器实验
 * 接口列表：
 *  Relay         Arduino Uno R3
 *   DC+               5V
 *   DC-               GND
 *   IN                 7
 *                          
 ************************************/
const int relayPin=7;//定义7脚为信号引脚
void setup() 
{
  pinMode(relayPin,OUTPUT);//定义输出端口
}
void loop() 
{
  digitalWrite(relayPin,HIGH);//输出高电平
  delay(1000);//延时1秒
  digitalWrite(relayPin,LOW);//输出低电平
  delay(1000);
}
