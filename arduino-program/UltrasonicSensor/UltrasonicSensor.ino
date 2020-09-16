/*
  UltrasonicSensor

  超音波距離センサで距離を測る

  2020年1月17日作成
  坂本 元

*/

// 超音波距離センサのVCCピンを  5Vに接続
// 超音波距離センサのTrigピンを Arduinoのデジタルピン12に接続
// 超音波距離センサのEchoピンを Arduinoのデジタルピン11に接続
// 超音波距離センサのGndピンを  GNDに接続

const int TRIG_PIN = 12;       // Trigピンを接続しているデジタルピン
const int ECHO_PIN = 11;       // Echoピンを接続しているデジタルピン

const int PULSE_TIMEOUT = 150000;  // タイムアウト0.15[s]

void setup() {
  Serial.begin(9600);           // シリアル通信初期化、通信速度9600bps

  pinMode(TRIG_PIN, OUTPUT);    // TRIG_PINを出力に設定
  pinMode(ECHO_PIN, INPUT);     // ECHO_PINを入力に設定
}

void loop() {
  long duration = 0;      // 測定したパルス幅（マイクロ秒[us]）を記憶する変数
  float distance = 0;     // パルス幅から距離（センチ[cm]）を計算した値を記憶する変数

  digitalWrite(TRIG_PIN, LOW);    // TRIG_PINをLOWにする
  delayMicroseconds(2);           // 2マイクロ秒待つ

  // TRIG_PINに10usのパルスを出力する
  digitalWrite(TRIG_PIN, HIGH);   // TRIG_PINをHIGHにする
  delayMicroseconds(10);          // 10マイクロ秒待つ
  digitalWrite(TRIG_PIN, LOW);    // TRIG_PINをLOWにする
  delayMicroseconds(2);           // 2マイクロ秒待つ

  duration = pulseIn(ECHO_PIN, HIGH, PULSE_TIMEOUT);   // ECHO_PINのパルス幅を測定する(単位[μs])
  distance = duration*0.017;            //  パルス幅から距離（cm）を計算する
                                        // 音速340[m/s]=34000[cm/s]、距離=速度x時間、
                                        //  duration*1e-6*34000/2=duration*0.017（/2は往復のため）

  Serial.print(duration);               // 測定したパルス幅をシリアル通信で出力
  Serial.print("[us] ");

  Serial.print(distance);               // 距離をシリアル通信で出力
  Serial.print("[cm] ");

  if (distance >= 2 && distance <= 400){  // 測定した距離が2～400cm（センサの測定範囲内）にある場合
    Serial.println("OK");      		// メッセージをシリアル通信で出力
  }
  else {                                  // そうでない場合
    Serial.println("NG");         // メッセージをシリアル通信で出力
  }

  delay(500);                             // 0.5秒待つ
}
