/* Coding Array STARTER Kit for Arduino
 *   
 *  예제 14_02_Thermistor_BParameter
 *  이 스케치는 A4에 연결된 써미스터에 분배된 전압을 저항으로 환산하고
 *  저항값을 온도로 변화시키는 방법 중 하나인
 *  B 파라미터 식을 이용하여 온도 계산을 해본다. 
 *  
 *  made by Arduinostory
 *  we@arduinostory.com
 *   
 */
 
#include <math.h>

                                   
const int thermistorPin=A4;     // A4핀에 써미스터 연결


//B parameter
float ParmB=3435.0;

void setup() {
  // 9600속도로 시리얼 통신 시작
  Serial.begin(9600);
  
  }


void loop() {
 
  float readVal =analogRead(thermistorPin);
 
  //온도 계산
  float resistor =(1023.0*10000)/readVal-10000;
  float tempC =(ParmB/(log(resistor/10000)+(ParmB/(273.15+25)))) -273.15;

  
// 시리얼 모니터 출력
 // Serial.println(readVal);      //A4에서 읽은 아날로그 값 출력
  Serial.print(tempC);          // 온도 출력
  Serial.println(" C");         // 단위 출력

  delay(1000);                       //1 초 지연

}
