/**************************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers
Pick one up today in the adafruit shop!
------> http://www.adafruit.com/category/63_98
This example is for a 128x32 pixel display using I2C to communicate
3 pins are required to interface (two I2C and one reset).
Adafruit invests time and resources providing this open
This example is for a 128x32 pixel display using I2C to communicate
source code, please support Adafruit and open-source
hardware by purchasing products from Adafruit!
Written by Limor Fried/Ladyada for Adafruit Industries,
with contributions from the open source community.
BSD license, check license.txt for more information
All text above, and the splash screen below must be
included in any redistribution.
**************************************************************************/
/*  이 스케치는 Adafruit 사의 라이브러리인 Adafruit_GFX와 Adafruit_SSD1306를 사용하여
*  반전 된 텍스트 표시
*  숫자 표시
*  기본 (16 진수, 12 진수) 숫자 표시
*  ASCII 기호 표시
*  수평 및 수직 스크롤 텍스트
*  디스플레이의 스크롤링 부분
* 등 을 OLED에 출력해 본다.
**************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED 가로 넓이, 픽셀 사이즈 
#define SCREEN_HEIGHT 64 // OLED 세로 넓이, 픽셀 사이즈

#define OLED_RESET -1 // 리셋핀 #(또는 -1 아두이노와 리셋핀을 연결하는 경우)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600); // 디버깅 메시지 출력을 위해 시리얼 모니터 활성화
  // SSD1306_SWITCHCAPVCC = 내부 3.3V 차지 펌프 회로를 켜둔다.
  // OLED 주소 0x3C 지정
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {   
      Serial.println(F("SSD1306 Not Connected"));
      for(;;);    // SSD1306에 주소할당이 되지 않으면 무한루프
  }

  // 버퍼 지움
  display.clearDisplay();

  // 텍스트 출력
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,27);
  display.println("Hello CodingArray!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // 텍스트 반전 표시
  display.setTextColor(BLACK, WHITE); 
  display.setCursor(0,27);
  display.println("Hello CodingArray!");
  display.display();
  delay(2000);
  display.clearDisplay(); 

  // 글꼴 크기 조정
  display.setTextColor(WHITE);
  display.setCursor(0,23);
  display.setTextSize(3);
  display.println("Hello!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // 숫자 표시
  display.setTextSize(1);
  display.setCursor(0,27);
  display.println(123456789);
  display.display();
  delay(2000);
  display.clearDisplay();

  // 숫자에 대한 포멧 지정
  display.setCursor(0,28);
  display.print("0x"); 
  display.print(0xFF, HEX); 
  display.print("(HEX) = ");
  display.print(0xFF, DEC);
  display.println("(DEC)"); 
  display.display();
  delay(2000);
  display.clearDisplay();

  // ASCII 기호표시
  display.setCursor(50,24);
  display.setTextSize(3);
  display.write(3); // 3 <-: 하트모양 
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // 전체화면 스크롤링
   display.setCursor(0,0);
  display.setTextSize(1);
  display.println("Full");
  display.println("Screen");
  display.println("Scrolling!");
  display.display();
  display.startscrollright(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  display.clearDisplay();

  // 특정부분 스크롤링
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("Scroll");
  display.println("Some part");
  display.println("Of the screen.");
  display.display();
  display.startscrollright(0x00, 0x00);

}

void loop() {}
