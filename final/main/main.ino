#include <Wire.h>                 //引入库文件
#include <LiquidCrystal_I2C.h>
#include<Servo.h>  //数控制舵机运行

int step = 1;
int val = 0;

Servo myServo;  //新建一个舵机对象myServo
const int servoPin=12; //设置舵机的连接引脚为12
const int potPin=A2; //设置电位器的连接引脚为A0

LiquidCrystal_I2C lcd(0x27,16,2); //定义lcd对象
int TrigPin = 2;                  //定义超声波传感器引脚
int EchoPin = 3;
float distance;                   //定义距离变量
void setup()
{
  Serial.begin(9600);             //开启串口
  lcd.init();                     //初始化lcd
  lcd.backlight();                //开启lcd背光
  pinMode(TrigPin, OUTPUT);       //设置超声波传感器引脚模式
  pinMode(EchoPin, INPUT);
  
  lcd.setCursor(0,0);             //设置光标位置
  lcd.print("Distance test");     //显示内容

  myServo.attach(servoPin); //使用舵机库功能函数attach()，该函数的功能是告诉Arduino舵机连接到12数字引脚
}
void loop()
{
  if(val % 10 == 0)
  {
    get_dis();                      //获取距离函数
    lcd_display();
  }

  // int val = analogRead(potPin);
  // val = map(val, 0, 1023, 0, 180); //将val从0~1023映射到0~180

  val += step;
  if(val == 180)  step = - step;
  else if(val == 0)  step = - step;
  myServo.write(val);  //功能函数write(angle)功能是用于设定舵机旋转角度(angle)，角度范围为0°~180°
  delay(10);
}

void get_dis()                    //获取距离子函数
{
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  distance = pulseIn(EchoPin, HIGH) / 58.0; 
  Serial.print(distance);
  Serial.println("cm");
}

void lcd_display()                //lcd显示子函数
{
  int dis = int(distance);
  
  lcd.setCursor(0,1);
  if(dis >= 0 && dis < 1000)
  {
    lcd.print("Dis:");
    lcd.print(dis);
  }
  
  if(dis < 100) lcd.print(' ');
  
  lcd.setCursor(8,1);
  lcd.print("cm");
}
