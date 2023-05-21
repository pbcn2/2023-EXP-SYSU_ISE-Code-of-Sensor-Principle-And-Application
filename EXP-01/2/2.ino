int redPin = 11;    // 将红色LED连接到数字引脚11
int greenPin = 10;  // 将绿色LED连接到数字引脚10
int val = 10;       // 初始化变量val为10

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);   // 设置红色LED引脚为输出模式
  pinMode(greenPin, OUTPUT); // 设置绿色LED引脚为输出模式
  Serial.begin(9600);        // 初始化串行通信，波特率设置为9600
}

void loop() {

  
  for(val = 255; val > 0; val--) {
    analogWrite(redPin, val);          // 设置红色LED亮度为val
    analogWrite(greenPin, 255 - val);  // 设置绿色LED亮度为255 - val
    Serial.println(val, DEC);          // 在串口监视器中打印当前val的值
    delay(30);                         // 延迟30毫秒
  }

  for(val = 0; val < 255; val++) {
    analogWrite(redPin, val);          // 设置红色LED亮度为val
    analogWrite(greenPin, 255 - val);  // 设置绿色LED亮度为255 - val
    Serial.println(val, DEC);          // 在串口监视器中打印当前val的值
    delay(30);                         // 延迟30毫秒
  }
}
