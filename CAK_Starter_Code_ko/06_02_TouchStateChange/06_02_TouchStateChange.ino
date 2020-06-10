/* Coding Array STARTER Kit for Arduino

    예제 06_02_TouchSensor2

    이 스케치는 터치센서를
    1, 2, 3번 터치할 때 마다 초록 LED 밝기가 밝아지고
    4번 터치하면 LED가 꺼지는 것을 보여준다.
    이를 이용하면 터치센서를 이용하여 원하는 밝기의 무드 등을 설정할 수 있다.

     made by Arduinostory
     we@arduinostory.com
*/

#define Touch 7             // 정정식 터치 센서를 7번에 연결

const int greenPin = 10 ;       // 초록 LED 10번에 연결

int touchCounter = 0;         // 터치 센서를 누른 횟수를 저장하는 변수
int lastTouchState = 0;         // 이전 터치 센서 상태를 읽어 저장

int alanlogValue;               //  LED 의 아날로그 값 설정 (0~255)


void setup() {

  pinMode(Touch, INPUT);     // 7번핀에 연결된 터치 센서를 입력으로 설정
  pinMode(greenPin, OUTPUT);  // 11번 핀을 출력으로 설정
  Serial.begin(9600);       // 9600속도로 시리얼 통신 시작

}


void loop() {
  int touchState = digitalRead(Touch); // 터치 센서 스위치 값을 읽어 touchState에 저장

  if (touchState != lastTouchState) { // 터치 센서 상태가 바뀌었으면
    if (touchState == HIGH) {              //

      touchCounter ++;                                 // 터치 센서누른 횟수를 증가
      Serial.println("TOUCHED");                          // 시리얼 창에 “TOUCHED” 쓰고 줄바꿈
      Serial.print("number of touch sensor pushes: ");    // 시리얼 창에 “~: ” 쓰고
      Serial.println(touchCounter);                   // 연결해서 터치 센서 누른 횟수 쓰고 줄바꿈

      //현재 touchState를 다음 루프에서 lastTouchState로 사용
      lastTouchState = touchState;

      if (touchCounter % 4 == 0) {   // 터치 센서 누른 횟수가 0이면
        alanlogValue = 0;
        Serial.println("OFF");
      }

      if (touchCounter % 4 == 1) {   // 터치 센서 누른 횟수가 1이면
        alanlogValue = 85;
        Serial.println("First level");
      }

      if (touchCounter % 4 == 2) {   // 터치 센서 누른 횟수가 2면
        alanlogValue = 170;
        Serial.println("Second level");
      }

      if (touchCounter % 4 == 3) {   // 터치 센서 누른 횟수가 3이면
        alanlogValue = 255;
        Serial.println("Third level");
      }

      //RGB LED를 터치센서를 눌러 변화한 아날로그 값 밝기로 켠다.
      analogWrite(greenPin, alanlogValue);

    } else {                                              // 터치 센서가 TOUCHED에서 not touched으로 바뀌었으면

      Serial.println("not touched");                     // 시리얼 창에 “not touched” 쓰고 줄바꿈
    }
    delay(100);
  }

  //현재 touchState를 다음 루프에서 lastTouchState로 사용
  lastTouchState = touchState;
}
