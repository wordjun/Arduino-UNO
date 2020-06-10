/* Coding Array STARTER Kit for Arduino
 *   
 *  예제 09_05_I2C_1602LCD_CustomCharacters
 *  이 스케치는   http://www.arduino.cc/en/Tutorial/LiquidCrystalCustomCharacter 예제를 재구성
 *  
 *  이 스케치는 I2C 통신을 이용한 1602 LCD에
 *  특수 문자나 그림을 설정하여 LCD 첫 줄에 "I ♥! Array Kit !"와 웃는 얼굴
 *  둘째 줄에 팔을 들었다 내렸다를 반복하는 사람의 모양을 
 *  A0 가변저항 값만큼 지속되도록 나타내는 방법에 대해 알아본다. 

 *  made by Arduinostory
 *  we@arduinostory.com
 */
 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // LCD I2C 주소를설정한다. 16칸2줄LCD 사용
                                    // 0x27 대신 스캐닝 된 주소를 넣는다.


//특수문자 만들기
byte heart[8] ={
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] ={
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] ={
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] ={
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] ={
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

                                    
void setup(){
  lcd.init();
  lcd.backlight();                // 백라이트를켠다. (lcd.noBacklight() 는 백라이트 끈다.)
  
  // 새로운 문자 정의
  lcd.createChar(0,heart);                   
  lcd.createChar(1,smiley); 
  lcd.createChar(2,frownie);
  lcd.createChar(3,armsDown);
  lcd.createChar(4,armsUp);

  lcd.setCursor(0,0);                 // 첫 번째 줄 첫째 칸
  
  
  // LCD에 문자 쓰기
  lcd.print("I ");
  lcd.write(byte(0));                           // 0바이트에 저장된 heart를 쓴다.
  lcd.print(" Array Kit! ");
  lcd.write((byte)1);                           // 1바이트에 저장된 smiley를 쓴다.

}

void loop(){

  
  int sensorReading = analogRead(A0);       // A0의 가변저항값을 읽는다.
 
  int delayTime = map(sensorReading,0,1023,200,1000);  // 저항값을 200 – 1000으로 맵핑
  
  lcd.setCursor(4,1);                       //하단 5번째 위치에 커서를 설정
  
  lcd.write(3);                             // 3번에 저장된 팔 아래 내린 사람 그린다.
  delay(delayTime);                         // 가변저항 값만큼 지연
  lcd.setCursor(4,1);                       //하단 5번째 위치에 커서를 설정
 
  //lcd.write(4);                             // 4번에 저장된 팔 위로 든 사람 그린다.
  delay(delayTime);                         // 가변저항 값만큼 지연
}
