/* Coding Array STARTER Kit for Arduino
 *   
 * 예제 09_04_I2C_1602LCD_TextDirection
 * 이 스케치는  http://www.arduino.cc/en/Tutorial/LiquidCrystalTextDirection 를 재구성
 * 
 *  이 스케치는 I2C 통신을 이용한 1602 LCD에
 *  a부터 Z까지 알파벳을 하나씩 보여준다.
 *  'a ~ l’ 은 왼쪽에서 오른쪽으로 글씨가 나타나며
 *  'm ~ r’ 은 오른쪽에서 왼쪽으로 글씨가 나타나고
 *  's ~ z’ 는 다시 왼쪽에서 오른쪽으로 텍스트가 나오게 한다. 
 *  
 *  made by Arduinostory
 *  we@arduinostory.com *  
 */
 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // LCD I2C 주소를설정한다. 16칸2줄LCD 사용
                                    // 0x27 대신 스캐닝 된 주소를 넣는다.
                                    
int thisChar ='a';                                     // thisChar에 a저장                                    

void setup(){
  lcd.init();
  lcd.backlight();                // 백라이트를켠다. (lcd.noBacklight() 는 백라이트 끈다.)
  lcd.cursor();                  // 커서를 켠다.
}

void loop(){

  if(thisChar =='m') {                   // thisChar 가 m이면 방향을 바꾸어
    lcd.rightToLeft();                           // 다음 글자부터 왼쪽으로 나타내라
  }

  if(thisChar =='s') {                  // thisChar 가 s이면
    // go left for the next letter              
    lcd.leftToRight();                          // 다음 글자부터 오른쪽으로 나타내라
  }

  if(thisChar >'z') {                    // thisChar 가 z를 벗어나면
    // go to (0,0):
    lcd.home();                                 // (0,0)으로 가라
    thisChar ='a';                              // 초기부터 다시 시작
  }

  lcd.write(thisChar);                 // thisChar 값을 LCD에 나타내어라
  
  delay(1000);                         // 1초동안
  
  thisChar++;                          // thisChar 값을 하나씩 증가
}

