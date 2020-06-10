/*  ArduinoStory CodingArrayKit_Level_1
 *   
 *  예제 15_01_Servo_Sweep
 *  이 스케치는 servo 라이브를 사용하여
 *  서보모터를 0 -> 180 도 움직이고
 *  다시 180 - >0 도 위치로 움직이도록 한다. 
 *  서보 모터는 360도 회전할 수 없음을 유의한다.
 */
 
#include <Servo.h>         // 서보 라이브러리 포함

Servo servo;            // 서보를 제어하기 위한 객체 myservo 생성

void setup() {
servo.attach(3);      // 3번 핀에 서보 모터 부착
Serial.begin(9600);
servo.write(90); 
}

void loop() {


}
