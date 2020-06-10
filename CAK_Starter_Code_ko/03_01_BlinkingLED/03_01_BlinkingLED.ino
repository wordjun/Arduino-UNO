/* Coding Array STARTER Kit for Arduino
 *   
 *  예제 03_01_BlinkingLED
 *  
 *  이 스케치는 디지털 13번 핀에 연결된 빨간 LED를 출력으로 설정하고
 *  디지털 출력을 나타내는 digitalWrite 함수와 
 *  명령을 지연시키는 delay 함수의 시간 설정에 따라
 *  1초동안 켜고, 1초동안 끄는 시행을 반복적으로 나타낸다. 
 *  이때 우노 보드 위의 'L' LED가 함께 깜박이는 것을 볼 수 있다. 
 *  이는 보드에 내장되어있는 이 LED가 13번 핀에 연결되어 있기 때문이다. 
 *  delay 함수의 1000 숫자를 바꾸어 LED가 깜박이는 속도를 조절해보자.
 *  
 *  made by Arduinostory
 *  we@arduinostory.com
 */
 
void setup() {
  pinMode(13,OUTPUT); // 13번을 출력핀(OUTPUT)로 설정
}

void loop() { 
  digitalWrite(13,HIGH); // 13번 핀에 디지털 신호 1 (HIGH) 을 준다. LED 켜짐 
  delay(1000);           // 1000밀리초 (=1초) 동안 기다린다. 
  digitalWrite(13,LOW);  // 13번 핀에 디지털 신호 0 (LOW) 을 준다. LED 꺼짐
  delay(1000);           // 1000밀리초 (=1초) 동안 기다린다. 
}
