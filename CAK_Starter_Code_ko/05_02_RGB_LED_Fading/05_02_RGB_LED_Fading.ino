/* Coding Array STARTER Kit for Arduino
 *   
 * 예제 05_02_RGB_LED_Fading
 *  
 *  본 예제에서는 공통 음극 RGB LED를 사용 
 *  RGB LED는 빨강, 녹색, 파랑 빛의 3원색을 혼합하여 다양한 색상을 방출할 수 있다. 
 *  9,10, 11번 핀은 각각 빨강, 녹색, 파랑 LED를 제어하는 핀에 연결되어 있으며
 *  PWM (Pulse-Width Modulation,펄스 폭 변조) 기능을 사용하여 LED의 밝기를 조절할 수 있고, 
 *  'random'명령을 통해 RGB 세가지 색의 밝기를 조절하여 다양한 색 혼합을 가능하게 할 수 있다. 
 */
 
const int redPin =9;           // 빨간 LED 9번에 연결
const int greenPin = 10;       // 초록 LED 10번에 연결
const int bluePin=11 ;         // 파란 LED 11번에 연결
 
int delayTime=30;           // 지연 시간 설정

int redV;                     // 빨간 LED 아날로그 값 설정 (0~255)
int greenV;                   // 초록 LED 아날로그 값 설정 (0~255)
int blueV;                    // 파란 LED 아날로그 값 설정 (0~255)

int fadeAmount =5;            // fade 저장 변수 

void setup() {
  
   pinMode(redPin, OUTPUT);   // 9번 핀을 출력으로 설정
   pinMode(greenPin, OUTPUT); // 10번 핀을 출력으로 설정   
   pinMode(bluePin, OUTPUT);  // 11번 핀을 출력으로 설정

}


void loop() {
  //빨간  LED 밝기 조절
  greenV=0;                   
  blueV=0;                 
  for(redV =0; redV <=255;redV +=5) {  
                                               // 0 ~ 255 까지 값을 5씩 늘리면서 
    analogWrite(redPin,redV);                    // 점점 밝게 LED 켜라
    analogWrite(greenPin,greenV);     
    analogWrite(bluePin,blueV); 
    delay(delayTime);                           // 30밀리초 기다림
  }

  for(int redV=255 ;redV >=0; redV -=5) {
                                               // 255 ~ 0 까지 값을 5씩 줄이면서 
    analogWrite(redPin,redV);                   // 점점 어둡게 LED 켜라
    analogWrite(greenPin,greenV);     
    analogWrite(bluePin,blueV);    
    delay(delayTime);                          // 30밀리초 기다림
  }

  
  //초록 LED 밝기 조절
   redV=0;                   
   blueV=0;  
  
  for(greenV=0  ; greenV <=255; greenV +=5) {  
                                               // 0 ~ 255 사이의 값을 5씩 늘리면서 
    analogWrite(redPin,redV);                     // 점점 밝게 LED 켜라
    analogWrite(greenPin,greenV);     
    analogWrite(bluePin,blueV);                           
    delay(delayTime);                            // 30밀리초 기다림
  }

  for(int greenV =255 ; greenV >=0; greenV -=5) {
                                               // 255 ~ 0 사이의 값을 5씩 줄이면서 
    analogWrite(redPin,redV);                   // 점점 어둡게 LED 켜라
    analogWrite(greenPin,greenV);     
    analogWrite(bluePin,blueV);    
    delay(delayTime);                          // 30밀리초 기다림
  }
  
  
  //파란 LED 밝기 조절
  redV=0;                   
  greenV=0;  
  for(blueV=0 ; blueV <=255; blueV +=5) {  
                                               // 0 ~ 255 사이의 값을 5씩 늘리면서 
    analogWrite(redPin,redV);                    // 점점 밝게 LED 켜라
    analogWrite(greenPin,greenV);     
    analogWrite(bluePin,blueV);               
              
    delay(delayTime);                                    // 30밀리초 기다림
  }

  for(int blueV=255 ;blueV >=0; blueV -=5) {
                                               // 255 ~ 0 사이의 값을 5씩 줄이면서 
    analogWrite(redPin,redV);                   // 점점 어둡게 LED 켜라
    analogWrite(greenPin,greenV);     
    analogWrite(bluePin,blueV);    
    delay(delayTime);                          // 30밀리초 기다림
  }  
  
//랜덤색 20가지 나오기
  for (int i=0; i<20; i++){
    analogWrite(redPin,random(0,255));                   
    analogWrite(greenPin,random(0,255));     
    analogWrite(bluePin,random(0,255));    
    delay(1000);
  }
}
