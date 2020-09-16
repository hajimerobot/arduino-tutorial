/*
  LCDPrint

  液晶ディスプレイ（LCD）に文字と秒数を表示する

  2020年1月17日作成
  坂本 元

*/
// LiquidCrystalライブラリの詳細は以下
// https://www.arduino.cc/en/Reference/LiquidCrystal


#include <LiquidCrystal.h>

// LCDのVSSを GNDに接続
// LCDのVDDを 5Vに接続
// LCDのV0を  ポテンショメータに接続
// LCDのRSを  Arduinoのデジタルピン7に接続
// LCDのR/Wを GNDに接続
// LCDのEを   Arduinoのデジタルピン8に接続
// LCDのD4を  Arduinoのデジタルピン9に接続
// LCDのD5を  Arduinoのデジタルピン10に接続
// LCDのD6を  Arduinoのデジタルピン11に接続
// LCDのD7を  Arduinoのデジタルピン12に接続
// LCDのAを   5Vに接続
// LCDのKを   GNDに接続

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // LCDの変数宣言と初期化

void setup() {
  lcd.begin(16, 2);               // LCDの画面サイズを16桁x2行に設定する

  lcd.print("Hello");                 // LCDに文字を出力する
//  lcd.print("\xb1\xb2\xb3\xb4\xb5");	// LCDに文字ｱｲｳｴｵを出力する
}

void loop() {
  lcd.setCursor(0, 1);            // カーソル位置を（桁,行）で設定する。1は2行目
  lcd.print(millis() / 1000);     // LCDに秒を表示する。millis()は起動してからのミリ秒。
}
