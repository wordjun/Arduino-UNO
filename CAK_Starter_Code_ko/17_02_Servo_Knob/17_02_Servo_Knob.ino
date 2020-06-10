/*  ArduinoStory CodingArrayKit_Level_1
 *   
 *  예제 15_02_Servo_Knob
 *  이 스케치는 servo 라이브를 사용하여
 *  가변 저항 값에 따라 서보모터를 0 ~ 180 도 사이로
 *  축을 움직여 본다. 
 */
 
#include <Servo.h>         // 서보 라이브러리 포함

Servo myservo;            // 서보를 제어하기 위한 객체 myservo 생성, 최대 12개 생성 가능

int position =0;                // 서보의 위치를 저장. 초기값 0
int potPin=A0;                  // 가변 저항을 A1핀에 연결

void setup() {
  myservo.attach(3);            // 3번 핀에 서보 모터 부착
}


void loop() {

  int val =analogRead(potPin);         // 가변 저항 값 읽어 저장 ( 0 ~ 1023)
  int servoVal =map(val,0,1023,0,180);          // 가변 저항 값을 0~180도 서보 모터 회전각으로 맵핑
  myservo.write(servoVal);                  // 맵핑된서보의 위치 설정
  delay(15);                                // 서보가 도착할 때 까지 기다린다.
  
  int pitchVal=map(val, 0, 1023,120,1500);   // 가변 저항 값을 120~1500 Hz 소리 주파수로 맵핑
  tone(6, pitchVal, 10);                     // 6번 핀에 연결된 수동부저에 10밀리초간 맵핑된 소리값 출력
  
  delay (1);                                // 안전성을 위해 1밀리초 지연

}


