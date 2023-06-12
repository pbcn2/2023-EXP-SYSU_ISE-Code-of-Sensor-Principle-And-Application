#include <Wire.h>                 //引入库文件
#include <LiquidCrystal_I2C.h>

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
}
void loop()
{
  get_dis();                      //获取距离函数
  lcd_display();                  //lcd显示函数
  delay(200);                     //延时
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
