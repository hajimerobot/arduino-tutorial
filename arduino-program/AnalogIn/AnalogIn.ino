/*
  AnalogIn

  アナログ電圧を読み取り、シリアル通信で出力する

  2020年1月17日作成
  坂本 元

*/

void setup() {
  Serial.begin(9600);                             // シリアル通信初期化、通信速度9600bps
}

void loop() {
  int sensorValue = analogRead(A0);               // アナログ電圧入力（0～1023）
  float voltage = sensorValue * (5.0 / 1024.0);   // 電圧(0V～5V)に換算
  float percent = sensorValue * (100.0 / 1024.0); // パーセント(0～100%)に換算
  Serial.print(sensorValue);                      // シリアル通信で生データを出力
  Serial.print("[bit], ");
  Serial.print(voltage);                          // シリアル通信で電圧を出力
  Serial.println("[V]");
  Serial.print(percent);                          // シリアル通信でパーセントを出力
  Serial.print("[%], ");
}
