/*  ArduinoStory CodingArrayKit_Level_1
 *   
 *  예제 15_01_Servo_Sweep
 *  이 스케치는 servo 라이브를 사용하여
 *  서보모터를 0 -> 180 도 움직이고
 *  다시 180 - >0 도 위치로 움직이도록 한다. 
 *  서보 모터는 360도 회전할 수 없음을 유의한다.
 */
 
#include <Servo.h>         // 서보 라이브러리 포함

Servo myservo;            // 서보를 제어하기 위한 객체 myservo 생성

int position =0;                // 서보의 위치를 저장. 초기값 0

void setup() {
  myservo.attach(3);      // 3번 핀에 서보 모터 부착
}


void loop() {
  myservo.write(90);  // 서보 모터 축 가운데 (90도) 위치
  delay (1000);

  myservo.write(0);   // 서보 모터 축 0도 위치
  delay (1000);

  myservo.write(180);   // 서보 모터 축 180도 위치
  delay (1000);

  myservo.write(90);  // 서보 모터 축 가운데 위치
  delay (1000);
  /*
  for(position = 0; position <= 180; position += 1) {     // 0 ~180 도 까지 1도 씩 증가하면서
    myservo.write(position);                                    // 지정된 각도로 움직여라
    delay(30);                                                  // 서보가 도착할 때 까지 기다린다.
  }

  for(position = 180; position >= 0; position -= 1) {     // 180 ~ 0 도 까지 1도 씩 감소하면서
    myservo.write(position);                                   // 지정된 각도로 움직여라
    delay(30);                                                 // 서보가 도착할 때 까지 기다린다.
    }
     */
}
