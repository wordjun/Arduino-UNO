/* Coding Array STARTER Kit for Arduino
 * 
 *  예제 15_MIC_Clap_ONOFF
 *   
 * 이 스케치는 박수를 두 번 치면 LED가 켜지고
 * 다시 두 번 치면 LED가 켜지는 것을 보여준다.
 * 
 *  made by Arduinostory
 *  we@arduinostory.com
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C 주소를 설정한다. 16칸2줄LCD 사용

const int sampleWindow = 125; // 샘플링 주기 밀리초 (125 mS = 8Hz)
int ledPin = 13;
int soundValue = 0;         // 소리 센서 값을 저장
int clapCounter = 0;        // 박수 소리 카운트 저장
double threshold = 2.0;         // 박수 소리 임계 전압 값 설정

void setup() 
{
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
  
lcd.init();                       // LCD 초기화 
lcd.backlight();                  // 백 라이트를 켠다. (lcd.noBacklight()는 백 라이트 끈다.)
lcd.clear();                      // LCD 화면 지움
lcd.setCursor(0, 0);                // 첫 번째 줄 첫째 칸
lcd.print("LED OFF");                  // 메세지 출력
lcd.setCursor(0, 1);                // 두 번째 줄 첫째 칸
lcd.print("CLAP TWICE~");              // 메세지 출력

  
}

void loop() 
{
  unsigned long start= millis();  // 샘플링 시작
  unsigned int peakToPeak = 0;    // 진폭값
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;


 // 125밀리초동안 데이터를 수집한다.
 while (millis() - start < sampleWindow)
 {
      soundValue = analogRead(3);
      if (soundValue < 1024)  //ADC 최대값(1024=10bit) 까지 데이터 판독한다
      {
         if (soundValue > signalMax)
         {
           signalMax = soundValue;  // 소리 최대값을 변수(signalMax)에 저장한다
         }
         else if (soundValue < signalMin)
         {
           signalMin = soundValue;  // 소리 최소값을 변수(signalMin)에 저장한다.
         }
     }
 }
 peakToPeak = signalMax - signalMin;  // 피크 대 피크 진폭을 계산한다
 double volts = (peakToPeak * 5) / 1024; // ADC값을 전압값으로 변환한다. 

 Serial.println(volts);
 if (volts >=threshold)
 {
   clapCounter ++;
   Serial.println(soundValue);      // soundValue 값을 시리얼 모니터에 출력
   Serial.println(clapCounter);     // 박수 친 횟수를 시리얼 모니터에 출력
   delay(50);
   // 박수 두번이면 LED 켜기
   if(clapCounter == 2)
   {
      digitalWrite(ledPin, HIGH);             // 빨간색 LED 켠다.
      Serial.println("LED ON" );              // 시리얼 모니터에 메세지 출력
      // LCD 출력
      lcd.clear();
      lcd.setCursor(0, 0);                    // 첫 번째 줄 첫째 칸
      lcd.print("LED ON");                    // 메세지 출력
      lcd.setCursor(0, 1);                    // 두 번째 줄 첫째 칸
      lcd.print("CLAP TWICE  ");              // 메세지 출력
    }
    // 박수 네 번이면 LED 끄기
    if (clapCounter == 4) 
    {
      digitalWrite(ledPin, LOW);                // 빨간색 LED 끈다
      Serial.println("LED OFF");            // 시리얼 모니터에 메세지 출력

      // LCD 출력
      lcd.clear();
      lcd.setCursor(0, 0);                   // 첫 번째 줄 첫째 칸
      lcd.print("LED OFF");                  // 메세지 출력
      lcd.setCursor(0, 1);                   // 두 번째 줄 첫째 칸
      lcd.print("CLAP TWICE  ");             // 메세지 출력
      clapCounter = clapCounter % 2;         // 2로 나눈 나머지 0을 저장 (박수 카운트 초기화)
     }
  }             
}
