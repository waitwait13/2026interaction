// week09_3_arduino_2048_three_PCM_sound
// Q6. 剛剛的week09_1 week09_2 都成功了 接下來試著用 Processing 寫個小遊戲(2048, 有方向鍵)
// 利用 USB 的 Serial 傳到MakerUNO 發出對應的3個聲音(移動、消掉、跳出新的數字) 

#include "PCM.h"
#include "sounddata.h"

const byte QUEUE_CAP = 48;
char events[QUEUE_CAP];
byte qHead = 0, qTail = 0;
bool playing = false;
unsigned long soundEnd = 0;

void enqueue(char ch) {
  byte next = (qTail + 1) % QUEUE_CAP;
  if (next == qHead) return;  // queue full: discard latest
  events[qTail] = ch;
  qTail = next;
}

void playEvent(char ch) {
  const unsigned char *clip = NULL;
  int len = 0;
  if (ch == 'M') { clip = move_data; len = move_length; }
  if (ch == 'C') { clip = merge_data; len = merge_length; }
  if (ch == 'N') { clip = spawn_data; len = spawn_length; }
  if (!clip) return;
  startPlayback(clip, len);
  soundEnd = millis() + (unsigned long)(len + 7) / 8;
  playing = true;
}

void setup() {
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  Serial.begin(115200);
  startPlayback(move_data, move_length);
  delay(200);
  startPlayback(merge_data, merge_length);
  delay(200);
  startPlayback(spawn_data, spawn_length);
  delay(200);
}

void loop() {
  // Serial.read() is fast and non-blocking; processing continues during audio.
  while (Serial.available() > 0) {
    char ch = (char)Serial.read();
    if (ch == 'M' || ch == 'C' || ch == 'N') enqueue(ch);
  }

  if (playing && (long)(millis() - soundEnd) >= 0) {
    stopPlayback();
    playing = false;
  }
  if (!playing && qHead != qTail) {
    char ch = events[qHead];
    qHead = (qHead + 1) % QUEUE_CAP;
    playEvent(ch);
  }
}
