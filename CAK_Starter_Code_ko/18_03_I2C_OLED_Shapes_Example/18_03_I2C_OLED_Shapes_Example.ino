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
* 직사각형 그리기 및 채우기
* 원 그리기 및 채우기
* 삼각형 및 채우기
* 등 을 OLED에 출력해 본다.
**************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED 가로 넓이, 픽셀 사이즈 
#define SCREEN_HEIGHT 64 // OLED 세로 넓이, 픽셀 사이즈

#define OLED_RESET  -1 // 리셋핀 #(또는 -1 아두이노와 리셋핀을 연결하는 경우)
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


  // 직사각형 그리기
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Rectangle");
  display.drawRect(0, 15, 60, 40, WHITE);
  display.display();
  delay(2000);

  // 직사각형 채우기  
  display.clearDisplay();  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Filled Rectangle");
  display.fillRect(0, 15, 60, 40, WHITE);
  display.display();
  delay(2000);

  // 둥근 직사각형 그리기
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Round Rectangle");
  display.drawRoundRect(0, 15, 60, 40, 8, WHITE);
  display.display();
  delay(2000);
  
  // 둥근 직사각형 채우기
  display.clearDisplay();  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Filled Round Rectang");
  display.fillRoundRect(0, 15, 60, 40, 8, WHITE);
  display.display();
  delay(2000);

  // 원 그리기
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Circle");
  display.drawCircle(20, 35, 20, WHITE);
  display.display();
  delay(2000);
  
  // 원 채우기
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Filled Circle");
  display.fillCircle(20, 35, 20, WHITE);
  display.display();
  delay(2000);
  
  // 삼각형 그리기
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Triangle");
  display.drawTriangle(30, 15, 0, 60, 60, 60, WHITE);
  display.display();
  delay(2000);
  
  // 삼각형 채우기
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Filled Triangle");
  display.fillTriangle(30, 15, 0, 60, 60, 60, WHITE);
  display.display();
  delay(2000);


}

void loop() {}
