/* Coding Array STARTER Kit for Arduino
 *  
 * 예제 04_01_Button
 * 
 * 이 스케치는 버튼 스위치 모듈 내부의 풀다운 저항을 사용하여
 *    버튼 스위치의 디지털 입력값에 따라 LED에 디지털 출력 명령을 내린다.
 *   풀다운 저항에 버튼 스위치가 연결되어 있을 경우
 *   평소 회로, 즉 버튼이 열여있을 때 LOW(0) 신호다.
 *
 *   if 조건문을 이용하여
 *   버튼 스위치를 누르면 회로가 연결되어 HIGH (1) 값이 반환되어 LED를 켜고
 *   버튼 스위치가 안 눌리면 회로가 열려 LOW (0) 값이 반환되어 LED를 끄는 시행을 해본다.
 *
 *   made by Arduinostory
 *   we@arduinostory.com
 */

int redLED = 13;       //  빨간 LED pin을 13번으로 설정.
int Button = 8;        // 버튼 스위치 pin를 8번으로 설정

void setup() {
  pinMode(Button, INPUT);                 // 버튼 핀을 입력으로 설정
  pinMode(redLED, OUTPUT);                //  redLED핀을 출력으로 설정

  Serial.begin(9600);                    // 9600 속도로 시리얼 통신 시작

}

void loop() {

  int sensorVal = digitalRead(Button);  // sensorVal 변수에 버튼 입력 값을 받는다. void 함수안에 넣은 변수는 지역변수

  Serial.println(sensorVal);          // 버튼의 값을 시리얼 창에 한 줄씩 나타내라.
  // Pull-down 저항이 연결되어 있으면 버튼이 열려있을 때 LOW(0), 눌렸을 때 HIGH (1) 값을 준다.
  // pull-up 저항은 버튼이 열려있을 때 HIGH (1)값을, 눌렀을 때 LOW(0)값을 준다.


  if (sensorVal == LOW) {         // 버튼이 열려있으면
    digitalWrite(redLED, LOW);          // redLED끄고
  }

  else {                        // 버튼이 눌려있으면
    digitalWrite(redLED, HIGH);        // redLED를 켜라.
  }
  delay(10);
}

