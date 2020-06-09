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
/*  The sketch uses Adafruit_GFX and Adafruit_SSD1306, libraries in the company Adafruit.
* Draw and fill rectangles
* Draw and fill circles
* Draw and fill Triangle
* Print out on top of OLED.
**************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED width, pixel size 
#define SCREEN_HEIGHT 64 // OLED height, pixel size

#define OLED_RESET  -1 // Resetpin # (or -1 if you are connecting the aduino to the resetpin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600); // Enable serial monitor for debugging message output
  // SSD1306_SWITCHCAPVCC = Leave the internal 3.3 volt charge pump circuit on.
  // Specify OLED Address 0x3C
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {   
      Serial.println(F("SSD1306 Not Connected"));
      for(;;);    // If SSD1306 is not addressed, infinite loop
  }
  
  // Clear Buffer
  display.clearDisplay();


  // Draw rectangles
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Rectangle");
  display.drawRect(0, 15, 60, 40, WHITE);
  display.display();
  delay(2000);

  // fill rectangles
  display.clearDisplay();  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Filled Rectangle");
  display.fillRect(0, 15, 60, 40, WHITE);
  display.display();
  delay(2000);

  // Draw round rectangles
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Round Rectangle");
  display.drawRoundRect(0, 15, 60, 40, 8, WHITE);
  display.display();
  delay(2000);
  
  // fill round rectangles
  display.clearDisplay();  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Filled Round Rectang");
  display.fillRoundRect(0, 15, 60, 40, 8, WHITE);
  display.display();
  delay(2000);

  // Draw circles
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Circle");
  display.drawCircle(20, 35, 20, WHITE);
  display.display();
  delay(2000);
  
  // fill circles
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Filled Circle");
  display.fillCircle(20, 35, 20, WHITE);
  display.display();
  delay(2000);
  
  // Draw Triangle
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Triangle");
  display.drawTriangle(30, 15, 0, 60, 60, 60, WHITE);
  display.display();
  delay(2000);
  
  // fill Triangle
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
