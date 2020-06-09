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
**************************************************************************/
/*  The sketch uses Adafruit_GFX and Adafruit_SSD1306, libraries in the company Adafruit.
*  Show Inverted Text
*  Numerical display
*  Basic (hexadecimal,Decimal) numeric display
*  Show ASCII Symbols
*  Horizontal and Vertical Scroll Text
*  Scrolling part of the display
*  Print out on top of OLED.
**************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED width, pixel size 
#define SCREEN_HEIGHT 64 // OLED height, pixel size

#define OLED_RESET -1 // Resetpin # (or -1 if you are connecting the aduino to the resetpin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600); // Enable serial monitor for debugging message output
  // SSD1306_SWITCHCAPVCC = Leave the internal 3.3 volt charge pump circuit on.
  // Address 0x3D
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {   
      Serial.println(F("SSD1306 Not Connected"));
      for(;;);    // If SSD1306 is not addressed, infinite loop
  }

  // Clear Buffer
  display.clearDisplay();

  // Text Output
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,27);
  display.println("Hello CodingArray!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // Show Inverted Text
  display.setTextColor(BLACK, WHITE); 
  display.setCursor(0,27);
  display.println("Hello CodingArray!");
  display.display();
  delay(2000);
  display.clearDisplay(); 

  // Resize Font
  display.setTextColor(WHITE);
  display.setCursor(0,23);
  display.setTextSize(3);
  display.println("Hello!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // Numerical display
  display.setTextSize(1);
  display.setCursor(0,27);
  display.println(123456789);
  display.display();
  delay(2000);
  display.clearDisplay();

  // Specify Formats for Numbers
  display.setCursor(0,28);
  display.print("0x"); 
  display.print(0xFF, HEX); 
  display.print("(HEX) = ");
  display.print(0xFF, DEC);
  display.println("(DEC)"); 
  display.display();
  delay(2000);
  display.clearDisplay();

  // Show ASCII Symbols
  display.setCursor(50,24);
  display.setTextSize(3);
  display.write(3); // 3 <-: heart shapes
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // Scrolling full screen
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

  // Scrolling specific parts
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("Scroll");
  display.println("Some part");
  display.println("Of the screen.");
  display.display();
  display.startscrollright(0x00, 0x00);

}

void loop() {}
