/* Coding Array STARTER Kit for Arduino

    예제 14_01_Thermistor_SH
    이 스케치는 A4에 연결된 써미스터에 분배된 전압을 저항으로 환산하고
    저항값을 온도로 변화시키는 방법 중 하나인
    Steinhart-Hart 식을 이용하여 온도 계산을 해본다.
    A4 핀과 I2C LCD 모듈은 함께 사용할 수 없으므로 점퍼로 사용 모듈을 선택해야 한다.

    made by Arduinostory
    we@arduinostory.com
*/

#include <math.h>


const int thermistorPin = A4;   // A4핀에 써미스터 연결


//파라미터는모듈에따라값을변화시킬수있다.
double ParamA = 0.001129148;
double ParamB = 0.000234125;
double ParamC = 0.0000000876741;


void setup() {
  // 9600속도로 시리얼 통신 시작
  Serial.begin(9600);

}


void loop() {

  int readVal = analogRead(thermistorPin);
  double temp = Thermistor(readVal);                 // 온도측정 함수를 불러옴

  double tempC = temp - 273.15;                     //절대온도를 섭씨온도로 환산
  double tempF = (tempC * 9.0) / 5.0 + 32.0;         //섭씨온도를 화씨온도로 환산

  // 시리얼 모니터 출력
  //Serial.println(readVal);
  
  Serial.print(tempC);      // 온도 표시
  Serial.println(" C");

  delay (500);
}

// Steinhart-Hart 식 온도 측정 함수 설정

double Thermistor(int RawADC)
{
  double Temp;
  Temp = log (10000.0 * ((1024.0 / RawADC - 1)));
  Temp = 1 / (ParamA + ( ParamB + (ParamC * Temp * Temp )) * Temp );
  
  return Temp;
}
