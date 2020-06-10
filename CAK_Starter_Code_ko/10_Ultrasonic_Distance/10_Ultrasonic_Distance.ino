/*  ArduinoStory CodingArrayKit_Level_1
 *   
 *  예제 10_Utrasonic_Distance
 *   *  
 *  이 스케치는 초음파 센서를 
 *  
 *  사용해 거리를 측정해 본다. 
 *  triger 핀은 아두이노의 5번에 연결되어 있다. triger 핀은 초음파를 발생한다.
 *  echo 핀은 아두이노의 4번에 연결되어있다. echo 핀은 반사된 초음파를 감지한다. 
 *  측정된 거리는 시리얼 창과, LCD 창에 모두 나타내어본다.
 *  측정 거리가 설정값 이상이면 초록 LED를, 
 *  측정 거리가 설정값 초과면 빨간 LED를 켜본다. 
 *  주차장의 자리 비어있음/차있음을 초록등과 빨간등으로 알리는 원리를 알 수 있다. 
 */
 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // LCD I2C 주소를설정한다. 16칸2줄LCD 사용
                                    // 0x27 대신 스캐닝 된 주소를 넣는다.

int redLED = 13;                 // 빨간 LED 13번에 연결                  
int greenPin=10;                 // 초록 LED 10번에 연결

int threshold = 15;              // 거리 임계값 설정

void setup() {
 
  // 초음파 핀모드 설정  
 // pinMode(4,OUTPUT);     // 4번에triger핀연결
 // pinMode(5,INPUT);      // 5번 핀에 echo핀 연결

 pinMode(5,OUTPUT);     // 5번에triger핀연결
 pinMode(4,INPUT);      // 4번 핀에 echo핀 연결


  //LED 출력 설정
  pinMode(redLED,OUTPUT);      // 13번 핀을 출력으로 설정
  pinMode(greenPin, OUTPUT);   // 10번 핀을 출력으로 설정  

  // 시리얼 통신 설정
  Serial.begin(9600);            // 9600속도로 시리얼 통신 시작
     
  // LCD 설정
  lcd.init();
  lcd.backlight();                // 백라이트를켠다. (lcd.noBacklight() 는 백라이트 끈다.)
  lcd.clear();
}


void loop() {

//  초음파 센서로 거리 측정

  float Duration, Distance;
  digitalWrite(5, HIGH);                                     // 초음파 쏜다.
  delayMicroseconds(10);                                      // 10마이크로초 동안
  digitalWrite(5, LOW);                                      // 초음파 끈다.
  Duration =pulseIn(4, HIGH);                                // echo핀이 HIGH 유지한 시간 저장
  Distance =((float)(340 *Duration) /10000) /2;              // 거리를 cm로환산


// 측정한 거리 출력
  
  Serial.print(Distance);                     // 시리얼 창에 줄바꿈 없이 거리 출력
  Serial.println("cm");                       // 단위 출력


  if (Distance < threshold){           // 측정거리가 임계값 미만이면 빨간 LED 켠다.
    
     digitalWrite(redLED,HIGH);
     digitalWrite(greenPin,LOW);     
     
     //LCD창에 거리 나타내기
     
    lcd.clear();
    lcd.setCursor(0,0);                 // 첫 번째 줄 첫째 칸
    lcd.print(Distance,2);                // 측정된 거리 출력    
    lcd.print("[cm]");   // 단위출력
    //lcd.setCursor(0,1);                  // 두 번째 줄 첫째 칸
    //lcd.println(" Occupied");

  
  }
  else {                           //측정값이 임계값보다 크면 초록 LED를 켠다.
    
     digitalWrite(redLED,LOW);
     digitalWrite(greenPin,HIGH);     
     
     //LCD창에 거리 나타내기

    lcd.clear();
    lcd.setCursor(0,0);                 // 첫 번째 줄 첫째 칸
    lcd.print(Distance,2);                 // 측정된 거리 출력    
    lcd.print("[cm]");     // 단위출력
 //   lcd.setCursor(0,1);                // 두 번째 줄 첫째 칸
  //  lcd.println(" Empty");    
  }

  
  delay(2000);                      // 안정적으로 값을 읽기 위해 2000밀리초 지연
}
