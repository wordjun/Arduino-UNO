
/* Coding Array STARTER Kit for Arduino
 * 예제 11_HallEffect
 *  
 *  이 스케치는 아날로그 A2번에 연결된 Hall Effect 모듈을 사용하여
 *  주변의 자기장에 따라 변화되는 아날로그 센서값을 읽어
 *  전압으로 변환하여 자기장의 세기를 측정한다.
 *  이 센서 모듈은 N극이 다가올수록 출력전압이 높아지고, 
 *  S극이 다가올수록 출력 전압이 낮아진다.
 *  
 *  결과 값을 엑셀에 쉽게 옮기기 위해 쉼표로 구분하여 시리얼 메세지를 출력한다. 
 *  시리얼창에 나타난 메세지를 복사하여 메모장에 붙여넣고 ".CSV" 확장자로 저장하여 
 *  엑셀에서 불러올 수 있는 파일을 만들 수 있다. 
 *  
 *  made by Arduinostory
 *  we@arduinostory.com

*/


// LCD  사용을 위한 설정

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C 주소를설정한다. 16칸2줄LCD 사용
// 0x27 대신 스캐닝 된 주소를 넣는다.

//홀 센서를A2핀에 연결
const int hallPin = A2;


// 변수 설정
int sensorReading;                        // 아날로그 센서 값을 저장
int voltage;                            // 전압으로 변환된 값 저장



void setup() {
  // 9600으로 통신 속도설정
  Serial.begin(9600);

  // LCD 초기화
  lcd.init();
  lcd.backlight();                // 백라이트를켠다. (lcd.noBacklight() 는 백라이트 끈다.)

  Serial.println("sensorReading, Voltage (mv)");      // 시리얼 창에 csv 파일을 위한 메세지 출력
  delay(1000);
}

void loop()
{
    
  sensorReading = analogRead(hallPin);         // 센서의 아날로그값을 읽어 저장
  voltage = (int) sensorReading * (5.0 / 1024.0) * 1000; // 아날로그 값을 전압0~5000mV 변환

  /* 일반적인 시리얼 프린트 메세지
    Serial.print("sensorReading");
    Serial.println(sensorReading);
    Serial.print("Voltage:");
    Serial.print(voltage);
    Serial.print("mV");
    Serial.println("---------------------------------------");
  */

  // csv (쉼표로 분리된 텍스트 형식으로 데이터를 받고자 할 때)
  Serial.print(sensorReading);
  Serial.print(",");
  Serial.println(voltage);

  //LCD 창에 메세지 출력
    lcd.clear();
    lcd.setCursor(0, 0);                // 첫 번째 줄 첫째 칸
    lcd.print("Anlaog_V :");
    lcd.print(sensorReading);
    lcd.setCursor(0, 1);                // 두 번째 줄 첫째 칸
    lcd.print(voltage);
    lcd.print("mV");
  delay(500);
}
