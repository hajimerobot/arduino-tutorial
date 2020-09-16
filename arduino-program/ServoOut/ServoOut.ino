/*
  ServoOut

  サーボモータを0～180度の範囲で回転させる

  2020年1月17日作成
  坂本 元

*/
// Servoライブラリの詳細は以下
// https://www.arduino.cc/en/reference/servo


#include <Servo.h>      // サーボライブラリ用のヘッダファイル

const int SERVO_PIN = 9;        // サーボモータを接続しているピン

Servo myservo;          // サーボモータの変数宣言

void setup() {
  myservo.attach(SERVO_PIN);    // サーボモータをSERVO_PINに設定
}

void loop() {
  // サーボモータのwrite関数で設定できる範囲は0～180度である。
  // サーボモータの種類によっては、
  // ストッパーに当たるものがあり、モータが壊れる恐れがある。
  // ここでは20～160度に制限しておく。

  myservo.write(90);    // サーボモータを90度に回転する
// myservo.writeMicroseconds(1520); // 1520マイクロ秒のPWMパルスを出力する

  delay(3000);          // 3秒待つ

  myservo.write(160);   // サーボモータを160度に回転する
// myservo.writeMicroseconds(1920); // 1920マイクロ秒のPWMパルスを出力する

  delay(1000);          // 1秒待つ

  myservo.write(20);    // サーボモータを20度に回転する
// myservo.writeMicroseconds(1120); // 1120マイクロ秒のPWMパルスを出力する

  delay(1000);          // 1秒待つ
}
