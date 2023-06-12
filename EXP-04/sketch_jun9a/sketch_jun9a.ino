const int buzzerPin = 7;
int fre;
int volume = 5000; // 音量值，可以根据需要调整

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

int speakerPin = 7;


void loop() {
  // put your main code here, to run repeatedly:
  int notes[] = {261, 294, 330, 349, 392, 440, 494, 523};  // 音符数组，可以根据需要扩展
  int durations[] = {500, 500, 500, 500, 500, 500, 500, 500};  // 音符持续时间数组，可以根据需要调整
  
  for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++) {
    tone(speakerPin, notes[i], volume);
    delay(durations[i]);
  }
  
  delay(2000);  // 在每个音符序列之间添加一段延迟
  
  for (int i = sizeof(notes) / sizeof(notes[0]) - 1; i >= 0; i--) {
    tone(speakerPin, notes[i], volume);
    delay(durations[i]);
  }
  
  delay(2000);
}

