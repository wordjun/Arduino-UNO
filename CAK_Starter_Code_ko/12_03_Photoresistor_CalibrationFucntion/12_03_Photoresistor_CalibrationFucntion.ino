/* Coding Array STARTER Kit for Arduino
 *
 * 예제 12_02_Photoresistor_CalibrationFunction
 *
 * 이 스케치는 디지털 8번 핀에 연결된 버튼 스위치를 누르는 동안 while 문이 실행되고
 * calibrate () 함수를 호출하여
 * 조도 센서가 연결된 아날로그 A1 핀의 최댓값고 최솟값을 찾는다.
 * 버튼을 누르지 않으면 메인 루프로 돌아간다.
 * 이 방법은 주변 밝기 조건이 변경될 때 조도 센서의 최댓값과 최솟값을 재설정 할 수 있다.
 * 
 * made by Arduinostory
 * we@arduinostory.com
 */

//LCD 사용을 위한 설정
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C 주소를설정한다. 16칸2줄LCD 사용
                                      // 0x27 대신 스캐닝 된 주소를 넣는다.

// 변수 설정
const int photoresistorPin = A1; // A1핀에 조도 센서 연결
const int redLED = 13;          // 보정 알림 LED를 13번 핀에 연결
const int bluePin = 11;         // 센서 값에 따른 밝기표현용  LED를 11번에 연결
const int Button = 8;        // 2번핀에 버튼 스위치 연결

int sensorValue = 0;        // 조도 센서 값을 저장
int sensorMin = 1023;       // 센서 최솟값을 1023으로 설정
int sensorMax = 0;          // 센서 최댓값을 0으로 설정


void setup() {

  // 보정 알림 LED 출력 설정
  pinMode(redLED, OUTPUT);

  // 밝기 나타내는 LED 출력 설정
  pinMode(bluePin, OUTPUT);

  // 버튼 핀을 풀업 저항을 이용해 입력 설정
  pinMode(Button, INPUT);

  // LCD 설정
  lcd.init();
  lcd.backlight();                // 백라이트를켠다. (lcd.noBacklight() 는 백라이트 끈다.)

}



void loop() {

  while (digitalRead(Button) == HIGH) {     // 버튼 스위치가 눌려져 있으면
    calibrate();                                 // calibrate( )함수를 호출해서 보정

    digitalWrite(bluePin, LOW);                   // 보정중 파란LED 끈다.

    lcd.clear();
    lcd.setCursor(0, 0);                // 첫 번째 줄 첫째 칸
    lcd.print("Calibration");              // 메세지 출력
    lcd.setCursor(0, 1);                // 첫 번째 줄 첫째 칸
    lcd.print("START");                     // 메세지 출력

  }

  digitalWrite(redLED, LOW);        // 보정이 끝나면 빨간 LED를 끈다

  lcd.clear();
  lcd.setCursor(0, 0);                // 첫 번째 줄 첫째 칸
  lcd.print("Calibration");              // 메세지 출력
  lcd.setCursor(0, 1);                // 첫 번째 줄 첫째 칸
  lcd.print("END");                     // 메세지 출력

  sensorValue = analogRead(photoresistorPin);                   // 조도 센서값을 읽어 저장
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255); //센서값을 0~255로 보정
  sensorValue = constrain(sensorValue, 0, 255);                 // 센서값이 보정 범위를 벗어나면 제한

  analogWrite(bluePin, sensorValue);   // 보정된 값으로 LED 밝기를 조절한다.
}



// calibrat() 함수 설정 : 주위 밝기에 따라 센서의 최댓값, 최솟값을 재설정한다.

void calibrate() {

  // 보정 알림 빨간 LED를 켜라
  digitalWrite(redLED, HIGH);

  // LCD 출력
  lcd.clear();
  lcd.setCursor(0, 0);                // 첫 번째 줄 첫째 칸
  lcd.print("Calibration");         // 메세지 출력
  lcd.setCursor(0, 1);                // 첫 번째 줄 첫째 칸
  lcd.print("START");               // 메세지 출력

  sensorValue = analogRead(photoresistorPin);             // 조도 센서의 값을 읽어 저장

  if (sensorValue > sensorMax) {              // 조도 센서의 값이 1023보다 크면
    sensorMax = sensorValue;                       // 센서 값을 읽어 sensorMax에 저장
  }

  if (sensorValue < sensorMin) {             // 조도 센서의 값이 0보다 작으면
    sensorMin = sensorValue;                       // 센서 값을 읽어 sensorMin에 저장
  }
}
