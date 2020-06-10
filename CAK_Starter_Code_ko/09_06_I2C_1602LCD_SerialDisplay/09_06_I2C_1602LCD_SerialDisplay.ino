/* Coding Array STARTER Kit for Arduino

   예제 09_06_I2C_1602LCD_SerialDisplay

/*  이 스케치는 I2C 통신을 이용한 1602 LCD에
    시리얼 창에서 입력받은 문자를 출력해 본다.

    made by Arduinostory
    we@arduinostory.com
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C 주소를설정한다. 16칸2줄LCD 사용
// 0x27 대신 스캐닝 된 주소를 넣는다.

void setup() {
  lcd.init();
  lcd.backlight();                // 백라이트를켠다. (lcd.noBacklight() 는 백라이트 끈다.)
  lcd.write(12);
  Serial.begin(9600);                        // 9600 속도로 시리얼 통신 시작
}

void loop() {

  if (Serial.available()) {   // 시리얼 통신으로 문자가 도착하면

    delay(100);                // 전체 메시지가 도착할 때 까지 0.1초동안 기다린다.

    lcd.clear();               // 화면을 지운다.

    while (Serial.available() > 0) { // 문자가 들어오는 동안

      lcd.write(Serial.read());        // 읽은 문자를 LCD에 써라.
     
    }
  }

}
