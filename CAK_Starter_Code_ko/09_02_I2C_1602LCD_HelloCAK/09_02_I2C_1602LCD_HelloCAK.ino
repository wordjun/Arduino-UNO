/* Coding Array STARTER Kit for Arduino
 *   
 * 예제 09_02_I2C_1602LCD_HelloCAK
 *    
 *  이 스케치는 I2C 통신을 이용한 1602 LCD에
 *  Hello !!  Coding Array Kit
 *  이라는 문자열을 보여주고, scrollDisplayRight와 scrollDisplayLeft 메소드를 사용하여
 *  좌우 스크롤 되는 결과를 보여준다. 
 *  noDisplay와 dispaly 메서드를 사용하여 화면을 깜박여
 *  한 루프가 완료됨을 알려준다.
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
  lcd.setCursor(0,0);                 // 첫 번째 줄 첫째 칸
  lcd.print("Hello ! ^_^ !");
  lcd.setCursor(0,1);                // 두 번째 줄 첫째 칸
  lcd.print("Coding Array Kit");
  delay(1000);
}

void loop(){
/*
  // 문자열의 길이 16개를 왼쪽으로 스크롤              
  for(int positionCounter = 0; positionCounter < 16; positionCounter++) {
                                              
    lcd.scrollDisplayLeft();                           // 한 위치씩 왼쪽으로 스크롤
                                                       
    delay(200);                                        // 200밀리초간
  }

  // 문자열의 길이 16+열수 16 총 32개 위치를 오른쪽으로 스크롤
  for(int positionCounter = 0; positionCounter < 32; positionCounter++) {
                         
    lcd.scrollDisplayRight();                          // 한 위치씩 오른쪽으로 스크롤
                                                       
    delay(200);                                       // 200밀리초간
  }

  // 왼쪽으로 16개 위치 스크롤하여 중심으로 이동
  for(int positionCounter = 0; positionCounter < 16; positionCounter++) {
    
    lcd.scrollDisplayLeft();                          // 한 위치씩 왼쪽으로 스크롤
    // wait a bit:
    delay(200);                                       // 200밀리초간
  }

  delay(1000);                             // 한 루프 돌면 1초 기다린다      


  // noDisplay와 dispaly
  lcd.noDisplay();   // 화면 끄기
  delay(500);       // 0.5초 동안
 
  lcd.display();      // 화면 켜기
  delay(500);        // 0.5초 동안
*/
}
