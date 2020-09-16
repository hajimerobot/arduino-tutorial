/*
  PassiveBuzzer

  パッシブブザーをドレミファソラシドの音階で鳴らす

  2020年1月17日作成
  坂本 元

*/

#include "pitches.h"            // 音階と周波数の定義ファイルを読み込む
                                // pitches.hをPassiveBuzzer.inoと同じディレクトリに入れておく
                                
// ブザーの+ピンをArduinoのデジタルピン8に接続
// ブザーの-ピンをGNDに接続

const int BUZZER_PIN = 8;       // ブザーを接続しているデジタルピン
int duration = 500;             // tone命令で出力する時間500ミリ秒（0.5秒）

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);    // BUZZER_PINを出力に設定
}

void loop() {
  tone(BUZZER_PIN, NOTE_C5, duration);  // 音階NOTE_C5「ド」を鳴らす
  delay(1000);                          // 1秒待つ

  tone(BUZZER_PIN, NOTE_D5, duration);  // 音階NOTE_D5「レ」を鳴らす
  delay(1000);                          // 1秒待つ

  tone(BUZZER_PIN, NOTE_E5, duration);  // 音階NOTE_E5「ミ」を鳴らす
  delay(1000);                          // 1秒待つ

  tone(BUZZER_PIN, NOTE_F5, duration);  // 音階NOTE_F5「ファ」を鳴らす
  delay(1000);                          // 1秒待つ

  tone(BUZZER_PIN, NOTE_G5, duration);  // 音階NOTE_G5「ソ」を鳴らす
  delay(1000);                          // 1秒待つ

  tone(BUZZER_PIN, NOTE_A5, duration);  // 音階NOTE_A5「ラ」を鳴らす
  delay(1000);                          // 1秒待つ

  tone(BUZZER_PIN, NOTE_B5, duration);  // 音階NOTE_B5「シ」を鳴らす
  delay(1000);                          // 1秒待つ

  tone(BUZZER_PIN, NOTE_C6, duration);  // 音階NOTE_C6「ド」を鳴らす
  delay(2000);                          // 2秒待つ
}
