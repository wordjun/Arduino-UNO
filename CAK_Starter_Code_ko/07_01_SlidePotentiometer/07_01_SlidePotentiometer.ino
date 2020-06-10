/* Coding Array STARTER Kit for Arduino

/*  예제 07_01_SlidePotentiometer
 
    가변저항을 좌우로 밀면서 저항 값이 바뀐다.
    저항이 변함에 따라 0~1023 아날로그 값이 A0 핀으로 입력된다.
    아날로그 값을 전압으로 환산하여 시리얼 모니터에 값으로 나타내거나
    시리얼 플로터를 이용해 그래프로 표현해 볼 수 있다.

    made by Arduinostory
    we@arduinostory.com
*/

const int potentiometerPin = A0;  // 가변저항의 출력값을 A0에서 읽어들임
const int redLED = 13;
const int threshold = 400;

void setup() {
  pinMode (redLED, OUTPUT); //빨간 LED를 출력으로 설정
  Serial.begin(9600);      // 9600 속도로 시리얼 통신 시작
  // 아날로그 입출력 핀은 선언하지 않아도 된다.
}

void loop() {

  int analogValue = analogRead(potentiometerPin);    // 가변저항의 아날로그값을 읽어 analogValue에 저장
  // analogValue에는 0~1023 범위의 정수 값이 저장

  float voltage = analogValue * (5.0 / 1023.0);   //아날로그 판독 값을 전압 0~5V 로 변환
  // 연산 결과 값이 실수형이므로 float 변수에 저장

  //Serial.print("Analog Value : ")
  //Serial.println(analogValue);                    // analogValue의 값을 시리얼 창에 한 줄씩 나타내라
  Serial.print("Voltage : ");
  Serial.println(voltage);                        // 환산한 전압값을 시리얼 창에 한 줄씩 프린트

  if (analogValue > threshold) {    // analogValue에 저장된 값이 400보다 크면
    digitalWrite(redLED, HIGH);     // LED를 켜고
  } else {                          // analogValue에 저장된 값이 400보다 작거나 같으면
    digitalWrite(redLED, LOW);      // LED를 꺼라

    delay(1);                        // 안정적으로 읽을 수 있게 1밀리초 기다림

  }
}

