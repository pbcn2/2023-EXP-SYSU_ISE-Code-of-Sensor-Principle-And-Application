/**********************************************
*项目名称：RGB-LED实验
*接口列表：
 * 接口列表：
 * RGB-LED        Arduino Uno R3
 *    R                 11
 *    G                 10
 *    B                 9  
 *   GND               GND   
 *编写：南友*************************************/

const int redPin=11;//引脚的定义
const int greenPin=10;
const int bluePin=9;

void setup()        
 {
  pinMode(redPin,OUTPUT); //引脚分配
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

 }
void loop() 
 {
  //基本的3种颜色：红、绿、蓝
  color(255,0,0);//R:255,G:0,B:0********红色
  delay(1000);//延时一秒
  color(0,255,0);//R:0,G:255,B:0********绿色
  delay(1000);
  color(0,0,255);//R:0,G:0,B:255********蓝色
  delay(1000);//延时3秒
 //由三种光形成的色谱
  color(255,0,0);//R:255,G:0,B:0**********红色
  delay(1000);
  color(255,255,0);//R:255,G:255,B:0******黄色
  delay(1000);
  color(0,255,0);//R:0,G:255,B:0**********绿色
  delay(1000);
  color(0,255,255);//R:0,G:255,B:255******青色
  delay(1000);
  color(0,0,255);//R:0,G:0,B:255**********蓝色
  delay(1000);
  color(255,0,255);//R:255,G:0,B:255******紫色
  delay(1000);
  color(255,255,255);//R:255,G:255,B:255**白色
  delay(1000);
 }
void color(unsigned char red,unsigned char green,unsigned char blue)//函数功能声明
{
    analogWrite(redPin,red);
    analogWrite(greenPin,green);
    analogWrite(bluePin,blue);
}