#include<Servo.h>  //数控制舵机运行
Servo myServo;  //新建一个舵机对象myServo
const int servoPin=12; //设置舵机的连接引脚为12
const int potPin=A2; //设置电位器的连接引脚为A0

void setup() {
  myServo.attach(servoPin); //使用舵机库功能函数attach()，该函数的功能是告诉Arduino舵机连接到12数字引脚
}
void loop() {
  int val = analogRead(potPin);
  val = map(val, 0, 1023, 0, 180); //将val从0~1023映射到0~180
  myServo.write(val);  //功能函数write(angle)功能是用于设定舵机旋转角度(angle)，角度范围为0°~180°
  delay(100); //延迟时间，让舵机转动到位
}
