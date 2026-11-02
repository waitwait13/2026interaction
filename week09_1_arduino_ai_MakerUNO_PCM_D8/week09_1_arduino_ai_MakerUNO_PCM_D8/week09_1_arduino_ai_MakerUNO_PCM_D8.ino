// week09_1_arduino_ai_MakerUNO_PCM_D8
// 想要讓 MakerUNO 發出更多元的聲音, 不要只是用單調的 tone()
// 老師要示範, 用 AI 一步步找出答案
// Q1. MakerUNO 本身可以用 pin8 的 buzzer 利用 tone() 來發單調的聲音，有辦法發出比較精彩的聲音嗎? ex. wav or mp3
// Q2. 請幫我找 PCM 相關的 libraries 我想試試看
// Q3. 如何修改 PCM library 讓他利用 pin8 的軟體 PWM 或其他輸出技術播放PCM
// 這時, AI 給我們修改後的 MakerUNO_PCM_D8.zip 解開來, 把 MakerUNO_PCM_D8.zip
// Q4. 我在編譯時, 出現 PCM.h 的錯誤. 訊息如下...
// A: 請把 PCM.cpp PCM.h sounddata.h 都放在你的目錄 week09_1_arduino_ai_MakerUNO_PCM_D8

// Maker UNO: turn ON the onboard BUZZER slide switch.
// Board selection: Arduino Uno / ATmega328P / 16 MHz.
// This sketch uses the local modified PCM.cpp, NOT the original D11 library.
#include "PCM.h"
#include "sounddata.h"

void setup() {
  startPlayback(sounddata_data, sounddata_length);
}

void loop() {
  // One-shot sample plays for 1 second. Press RESET to play again.
}
