/*
  SwitchIn

  押しボタンスイッチの状態を読み取り、その状態に応じてLEDを点灯／消灯させる

  2020年1月17日作成
  坂本 元

*/

const int BUTTON_PIN = 2;     // 押しボタンスイッチを接続しているデジタルピン
const int LED_PIN =  13;      // LEDを接続しているデジタルピン（13は基板上のLEDも兼用）

int buttonState = 0;          // 押しボタンスイッチの状態を記憶する変数

void setup() {
  pinMode(LED_PIN, OUTPUT);               // LED_PINを出力に設定
//  pinMode(BUTTON_PIN, INPUT);             // BUTTON_PINを入力に設定
  pinMode(BUTTON_PIN, INPUT_PULLUP);      // BUTTON_PINをプルアップ抵抗付き入力に設定
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);  // 押しボタンスイッチの状態を読み取る
                                          //（5VのときHIGH、0VのときLOW）

  if (buttonState == LOW) {       // 入力がLOWのとき実行される
    digitalWrite(LED_PIN, HIGH);  // LED点灯
  } else {                        // 入力がHIGHのとき実行される
    digitalWrite(LED_PIN, LOW);   // LED消灯
  }
}


/*
条件分岐のif文の解説

if(1<2){
  正しいので実行される
}
else{
  正しいので実行されない
}

if(1>2){
  間違いなので実行されない
}
else{
  間違いなので実行される
}
*/
