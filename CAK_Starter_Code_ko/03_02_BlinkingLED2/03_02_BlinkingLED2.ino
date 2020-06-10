/*  Coding Array STARTER Kit for Arduino
 *   
 *  예제 03_BlinkingLED2
 *  
 *  이 스케치는 변수를 이용하여 핀번호를 나타내본다.
 * 
 *  void 이전 프로그램 상단에 변수가 선언되면 
 *  프로그램의 모든 부분에서 해당 변수를 사용할 수 있다.
 *  이런 변수를 전역변수라 한다.
 *  
 *  made by Arduinostory
 *  we@arduinostory.com

 */
 
int redLED = 13;    // 13번에 빨간 LED 연결

void setup() {
  pinMode(redLED,OUTPUT);   // 13번을 출력핀(OUTPUT)으로 설정
}

void loop() { 
  // 빨간 LED 켜짐
  digitalWrite(redLED, HIGH);  // 13번 핀에 디지털 신호 1 (HIGH) 을 준다. 빨간 LED 켜짐 
  delay(1000);                 // 1000밀리초 (=1초) 동안 기다린다. 

  // 빨간 LED는 꺼짐
  digitalWrite(redLED, LOW);   // 13번 핀에 디지털 신호  0 (LOW) 을 준다. 빨간 LED 꺼짐 
  delay(1000);                 // 1000밀리초 (=1초) 동안 기다린다. 
}

