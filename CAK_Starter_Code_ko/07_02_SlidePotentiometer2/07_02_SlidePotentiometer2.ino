/* Coding Array STARTER Kit for Arduino

   예제 07_SlidePotentiometer2

  가변저항의 값이 증가함에 따라 RGB LED의 색을 빨강-> 초록-> 파랑으로 바꾸어 본다.

    made by Arduinostory
    we@arduinostory.com
*/

int potPin = A0;           // 가변저항의 출력은 아날로그핀 A0에 연결
int potVal = 0;           // 가변저항에서 읽은 아날로그 (0~1023)값을 저장하는 변수

const int redPin = 9;          // 빨간 LED 9번에 연결
const int greenPin = 10;       // 초록 LED 10번에 연결
const int bluePin = 11 ;       // 파란 LED 11번에 연결

int redV = 0;                   // 빨간 LED 아날로그 값 설정 (0~255)
int greenV = 0;                 // 초록 LED 아날로그 값 설정 (0~255)
int blueV = 0;                  // 파란 LED 아날로그 값 설정 (0~255)

void setup() {
  pinMode(redPin, OUTPUT);   // 9번 핀을 출력으로 설정
  pinMode(greenPin, OUTPUT); // 10번 핀을 출력으로 설정
  pinMode(bluePin, OUTPUT);  // 11번 핀을 출력으로 설정
}

void loop() {
  potVal = analogRead(potPin);              // 가변저항의 아날로그 출력값을 A0핀에서 읽어들인다.(0~1023)
  int ledLevel = map(potVal, 0, 1023, 0, 255); // 아날로그 입력값 (0~1023)을  LED를 켜기 위한 아날로그 출력값 (0-255)에 맞추어 환산

  if (potVal < 341){  // 가변저항의 값을 3단계로 나눈 첫 번째 단계의 값일 때 (0-340)
    redV = 255 - ledLevel;      // 빨간색이 점점 옅어짐
    greenV = ledLevel;          // 초록색이 점점 짙어짐
    blueV = 1;                  // 파란색은 영향 없음
  }

  else if (potVal < 682) { // 가변저항의 값을 3단계로 나눈 두 번째 단계의 값일 때 (341-681)
    redV = 1;                           // 빨간색 영향 없음
    greenV = 255 - ledLevel;            //초록색 점점 옅어짐
    blueV = ledLevel;                   // 파란색 점점 짙어짐
  }

  else { // 가변저항의 값을 3단계로 나눈 세 번째 단계의 값일 때 (682-1023)
    redV = ledLevel;                     // 빨간색 점점 짙어짐
    greenV = 1;                          // 초록색 영향 없음
    blueV = 255 - ledLevel;              // 파란색 점점 옅어짐
  }

  analogWrite(redPin, redV);            // Write values to LED pins
  analogWrite(greenPin, greenV);
  analogWrite(bluePin, blueV);
}
