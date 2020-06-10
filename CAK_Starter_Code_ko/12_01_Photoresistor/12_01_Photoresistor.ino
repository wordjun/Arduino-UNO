/* Coding Array STARTER Kit for Arduino
 *   
 *  예제 12_01_Photoresistor
 *  이 스케치는 조도센서를 이용해 빛의 밝기를 측정한다.
 *  조도센서에 연결된 A1 아날로그 입력핀에 저항값에 따른 0~5V 사이의 전압 값이 들어오게 되고
 *  이를 0~1023 사이의 값으로 변환하여 나타내게 된다.
 *  0~1023 값은 map 함수를 통해 0~3 4단계로 나뉘어 switch-case에 이용된다.
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

const int sensorMin =0;      // 실험을 통해 발견된 최소 센서값, 수정할 수 있다.
const int sensorMax =700;    // 실험을 통해 발견된 최대 센서값, 수정할 수 있다.


void setup() {
    
  // LCD 초기화
  lcd.init();
  lcd.backlight();                // 백라이트를켠다. (lcd.noBacklight() 는 백라이트 끈다.)
   
  // 시리얼 통신 설정
  Serial.begin(9600);            // 9600속도로 시리얼 통신 시작
}

void loop() {

// 센서값 읽어 범위 맵핑
  int sensorReading = analogRead(photoresistorPin);   // A2핀에서 조도 센서값을 읽는다
  Serial.println(sensorReading);                                     
  int range = map (sensorReading,sensorMin,sensorMax,0,3);   // 센서값을 0~3까지 4가지로 맵핑한다.

// 센서 범위에 따라 메세지 출력  
  switch(range) {                 // 0~3 범위에 따라
    case 0:                        // 센서위에 손을 대고 센서 값이 0이 되면
      Serial.println("DARK");             // 시리얼창에 dark프린트하고 줄바꿈
      //LCD창에 거리 나타내기
      lcd.clear();
      lcd.setCursor(0,0);                 // 첫 번째 줄 첫째 칸
      lcd.print("Range : ");              // 메세지 출력
      lcd.print(range);
      lcd.setCursor(0,1);                 // 두 번째 줄 첫째 칸
      lcd.print("DARK");                // DARK 출력
      break;
      
    case 1:                       // 센서위에 손을 가까이 대고 센서 값이 1이 되면
      Serial.println("DIM");              // 시리얼창에 dim프린트하고 줄바꿈
      //LCD창에 거리 나타내기
      lcd.clear();
      lcd.setCursor(0,0);                 // 첫 번째 줄 첫째 칸
      lcd.print("Range : ");              // 메세지 출력
      lcd.print(range);
      lcd.setCursor(0,1);                 // 두 번째 줄 첫째 칸
      lcd.print("DIM");                 // DIM 출력
      break;
      
    case 2:                       // 센서위에 손을 멀리하며 센서 값이 2가 되면
      Serial.println("MEDIUM");           // 시리얼창에 medium프린트하고 줄바꿈
      //LCD창에 거리 나타내기
      lcd.clear();
      lcd.setCursor(0,0);                 // 첫 번째 줄 첫째 칸
      lcd.print("Range : ");              // 메세지 출력
      lcd.print(range);
      lcd.setCursor(0,1);                 // 두 번째 줄 첫째 칸
      lcd.print("MEDIUM");              // MEDIUM 출력      
      break;
      
    case 3:                      // 센서에 근처에 손을 대지 않고 센서값이 3이 되면
      Serial.println("BRIGHT");         // 시리얼창에 bright프린트하고 줄바꿈
      //LCD창에 거리 나타내기
      lcd.clear();
      lcd.setCursor(0,0);                 // 첫 번째 줄 첫째 칸
      lcd.print("Range : ");              // 메세지 출력
      lcd.print(range);
      lcd.setCursor(0,1);                 // 두 번째 줄 첫째 칸
      lcd.print("BRIGHT");              // BRIGHT 출력      
      break;
  }

  delay(500);                      // 안정적으로 값을 읽기 위해 50밀리초 지연
}
