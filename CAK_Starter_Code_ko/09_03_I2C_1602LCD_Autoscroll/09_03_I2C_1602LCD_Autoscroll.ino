/* Coding Array STARTER Kit for Arduino
 *   
 * 예제 09_03_I2C_1602LCD_Autoscroll
 *  이 스케치는  http://www.arduino.cc/en/Tutorial/LiquidCrystalAutoscroll 를 재구성
 *
 *  이 스케치는 I2C 통신을 이용한 1602 LCD에
 *  0 부터 9까지의 숫자를 화면에 나타내고, 
 *  autoscroll( ) 및 noAutoscroll( ) 메소드를 사용하여 
 *  모든 문자열을 왼쪽이나 오른쪽으로 이동하는 방법을 보여준다.
 *  
 *  made by Arduinostory
 *  we@arduinostory.com

 */
 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // LCD I2C 주소를설정한다. 16칸2줄LCD 사용
                                    // 0x27 대신 스캐닝 된 주소를 넣는다.
void setup(){
  lcd.init();
  lcd.backlight();                // 백라이트를켠다. (lcd.noBacklight() 는 백라이트 끈다.)
  
}


void loop() {
  
  lcd.setCursor(0,0);                         // 커서를 (0,0) 좌측 상단에 위치시킨다.
  
  for(int thisChar = 0; thisChar <10; thisChar++) {     
    lcd.print(thisChar);                      // 0~9 까지 숫자를 LCD에 나타낸다.
    delay(500);                               // 0.5초 동안
  }

  lcd.setCursor(16,1);                       // 커서를 (16,1) 우측하단에 위치 시킨다.
  
  lcd.autoscroll();                          // 자동 스크롤하도록 설정
  
  for(int thisChar = 0; thisChar <10; thisChar++) {
    lcd.print(thisChar);                     // 0~9 까지 숫자를 LCD에 나타낸다.
    delay(500);                              // 0.5초 동안
  }
 
  lcd.noAutoscroll();                        // 자동 스크롤 해지

  lcd.clear();                                // 다음 루프로 가기 전 화면을 지운다.


}
