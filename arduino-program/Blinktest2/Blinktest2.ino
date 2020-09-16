/*
  Blinktest2

  LEDを点滅させる

  2020年1月17日作成
  坂本 元

*/

const int LED_PIN = 13;         // LEDを接続しているデジタルピン（13は基板上のLEDも兼用）

void setup() {
  pinMode(LED_PIN, OUTPUT);     // LED_PINを出力に設定
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED_PIN に HIGH を出力
  delay(1800);                  // 1.8秒待つ
  digitalWrite(LED_PIN, LOW);   // LED_PIN に LOW を出力
  delay(200);                   // 0.2秒待つ
}
