/* Coding Array STARTER Kit for Arduino
 *   
 *  예제 12_02_Photoresistor_Calibration
 *  이 스케치는 주변 환경에 따라 조도센서 입력 값을 보정하는 방법에 대해 알아본다. 
 *  조도 센서가 연결된 아날로그 A1 핀의 값을 5초 동안 읽어 최댓값과 최솟값을 저장하고
 *  저장된 최솟값은 0으로, 최댓값은 255로 map함수를 통해 변환된다.
 *  코드를 업로드 한 후 조도센서를 손으로 가린 후 리셋 버튼을 누른다.
 *  5초 동안 조도 센서에서 점점 손을 멀리하면서 최솟값과 최댓값을 저장할 수 있게 한다.
 *  이 후 조도 센서 주위로 손을 움직여 RGB LED의 푸른색 밝기 변화를 확인해본다.
 *  
 *  made by Arduinostory
 *  we@arduinostory.com
 */

// LCD 사용을 위한 설정 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // LCD I2C 주소를설정한다. 16칸2줄LCD 사용
                                    // 0x27 대신 스캐닝 된 주소를 넣는다.

// 변수 설정
const int photoresistorPin=A1;  // A1핀에 조도 센서 연결
const int redLED=13;            // 보정 알림 LED를 13번 핀에 연결
const int bluePin=11;           // 센서 값에 따른 밝기표현용  LED를 11번에 연결

int sensorValue =0;         // 조도 센서 값을 저장
int sensorMin =1023;        // 센서 최솟값을 1023으로 설정
int sensorMax =0;           // 센서 최댓값을 0으로 설정


void setup() {
  
  // 보정 알림 LED 출력 설정
  pinMode(redLED, OUTPUT);
  digitalWrite(redLED, HIGH);
  
  // LCD 설정
  lcd.init();
  lcd.backlight();                // 백라이트를켠다. (lcd.noBacklight() 는 백라이트 끈다.)
  lcd.clear();
  lcd.setCursor(0,0);                 // 첫 번째 줄 첫째 칸
  lcd.print("Calibration");              // 메세지 출력
  lcd.setCursor(0,1);                 // 첫 번째 줄 첫째 칸
  lcd.print("START");              // 메세지 출력
  
 // 센서값 보정
  while(millis() < 5000) {                     // 5초동안
    sensorValue = analogRead(photoresistorPin);           //센세 값을 읽어 저장

    if(sensorValue > sensorMax) {                  //센서 값이 최댓값 보다 크면
      sensorMax = sensorValue;                           // 최댓값으로 재설정
    }

    if(sensorValue < sensorMin) {                  //센서 값이 최솟값 보다 작으면
      sensorMin = sensorValue;                           // 최솟값으로 재설정
    }
  }
  
// 보정 끝.  LED 끄고 LCD 화면에 메세지 출력
  digitalWrite(redLED,LOW);                            
  
  lcd.clear();
  lcd.setCursor(0,0);                 // 첫 번째 줄 첫째 칸
  lcd.print("Calibration");              // 메세지 출력
  lcd.setCursor(0,1);                 // 첫 번째 줄 첫째 칸
  lcd.print("END");                     // 메세지 출력
}


void loop() {

  sensorValue = analogRead (photoresistorPin);   //아날로그 센서값 읽어 변수에 저장

  // 센서값을 읽어 0~255 값으로 변환
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // 센서값이 보정 범위를 벗어나면 제한
  sensorValue = constrain(sensorValue, 0, 255);

  // 센서값으로 파란색 LED 밝기를 조절
  analogWrite(bluePin,sensorValue);    

}
