/* Coding Array STARTER Kit for Arduino
 *   
 * 예제 05_01_RGB_DigitalMixing
 *  
*  RGB LED는 빨강, 녹색, 파랑 빛의 3원색을 혼합하여 다양한 색상을 방출할 수 있다. 
 *  9,10, 11번 핀은 각각 빨강, 녹색, 파랑 LED를 제어하는 핀에 연결되어 있다. 
 *  본 예제에서는 공통 음극 RGB LED를 사용하여 디지털 출력으로 빛의 삼원색 혼합을 알아본다.  
 *  
 *  빨강+초록=노랑
 *  빨강+파랑 = 자주 (Magenta)
 *  초록+파랑=청록 (Cyan)
 *  빨강+초록+파랑=흰색 (White)
 *  
 *  made by Arduinostory
 *  we@arduinostory.com  
 */
 

const int redPin =9;           // 빨간 LED 9번에 연결
const int greenPin = 10;       // 초록 LED 10번에 연결
const int bluePin=11 ;         // 파란 LED 11번에 연결
 
void setup() {

   pinMode(redPin, OUTPUT);   // 9번 핀을 출력으로 설정
   pinMode(greenPin, OUTPUT); // 10번 핀을 출력으로 설정   
   pinMode(bluePin, OUTPUT);  // 11번 핀을 출력으로 설정

  Serial.begin(9600);         // 9600속도로시리얼통신시작
  
}


void loop() {
   Serial.println("RED on");        // 빨간색 LED 켜짐
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
    delay(1000);                    // 1초 동안

    Serial.println("GREEN on");       // 초록색 LED 켜짐
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
    digitalWrite(bluePin,LOW);
    delay(1000);                      // 1초 동안

    Serial.println("BLUE on");        // 파란색 LED 켜짐
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,HIGH);
    delay(1000);                     // 1초 동안    

    Serial.println("Yellow on");      // 노란색 LED 켜짐
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,HIGH);
    digitalWrite(bluePin,LOW);
    delay(1000);                      // 1초 동안 

    Serial.println("Magenta on");     // 자주색 LED 켜짐
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,HIGH);
    delay(1000);                      // 1초 동안 

   Serial.println("Cyan on");         // 청록색 LED 켜짐
   digitalWrite(redPin,LOW);
   digitalWrite(greenPin,HIGH);
   digitalWrite(bluePin,HIGH);
   delay(1000);                       // 1초 동안 

   Serial.println("White on");        // 흰색 LED 켜짐
   digitalWrite(redPin,HIGH);
   digitalWrite(greenPin,HIGH);
   digitalWrite(bluePin,HIGH);
   delay(1000);                       // 1초 동안 
}

