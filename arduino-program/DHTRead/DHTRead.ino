/*
  DHTRead

  DHTセンサから湿度と温度を読み取り、シリアル通信で出力する

  2020年1月17日作成
  坂本 元

*/
// このプログラムにはライブラリが必要
// スケッチ -> ライブラリをインクルード -> ライブラリを管理 から
// DHT sensor library by Adafruit
// をインストールしておく
// ライブラリの詳細は以下
// https://github.com/adafruit/DHT-sensor-library


#include "DHT.h"    // DHTセンサライブラリ用のヘッダファイル

// DHTセンサのVCCを  5Vに接続
// DHTセンサのDATAを Arduinoのデジタルピン2に接続
// DHTセンサのGNDを  GNDに接続

#define DHTPIN 2    // DHTセンサを接続しているデジタルピン

DHT dht(DHTPIN, DHT11); // DHTセンサの変数宣言と初期化

void setup() {
  Serial.begin(9600);     // シリアル通信初期化、通信速度9600bps

  dht.begin();            // DHTセンサ初期化
}

void loop() {
  delay(2000);                        // 2秒待つ

  float h = dht.readHumidity();       // DHTセンサから湿度を読む
  float t = dht.readTemperature();    // DHTセンサから温度を読む

  if (isnan(h) || isnan(t)) {         // 湿度と温度がともに正しく読み取れたか調べる
                                      // 非数であれば失敗
    Serial.println("NG");             // シリアル通信でNGを出力
    return;							              // このloopを終了し、次のloopから始める
  }

  Serial.print(" 湿度: ");
  Serial.print(h);                    // シリアル通信で湿度を出力
  Serial.print(F("% 温度: "));
  Serial.print(t);                    // シリアル通信で温度を出力
  Serial.println("度");
}
