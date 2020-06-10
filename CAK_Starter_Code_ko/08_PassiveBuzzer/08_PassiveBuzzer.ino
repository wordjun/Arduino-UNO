/* Coding Array STARTER Kit for Arduino
 *   
 * 예제 08_PassiveBuzzer
 *  
 *  이 스케치는 부저를 통해 음을 연주한다. 
 *  tone() 함수는 pitches.h 헤더파일을 불러와 주어진 주파수 음을 내게 한다. 
 *  우리에게 익숙한 '학교종' 노래를 연주한다. 
 *  이 스케치에서는 setup 부분에 코드를 넣어 한 번만 연주가 되지만
 *  loop 부분에 코드를 넣으면 연주가 반복될 수 있다.
 *  
 *  made by Arduinostory
 *  we@arduinostory.com

 */
 
#include "pitches.h"

int buzzer=6;            //피에조 부저를 6번에 연결

                         //연주할 음계
int melody[] ={NOTE_G7,NOTE_G7,NOTE_A7,NOTE_A7,NOTE_G7,
                NOTE_G7,NOTE_E7,NOTE_G7,NOTE_G7,NOTE_E7,
                NOTE_E7,NOTE_D7,0,NOTE_G7,NOTE_G7,NOTE_A7,
                NOTE_A7,NOTE_G7,NOTE_G7,NOTE_E7,NOTE_G7,
                NOTE_E7,NOTE_D7,NOTE_E7,NOTE_C7,0
               };
                            //음의길이, 4 = 4분음표, 2 = 2분음표
int noteDurations[] ={4,4,4,4,4,4,2,4,4,4,4,3,1,4,4,4,4,4,4,2,4,4,4,4,3,1};

void setup() {
  for(int thisNote =0; thisNote <26; thisNote++)
  {
    int noteDuration =1000 /noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);       //6번핀에 피에조 부저 연결
    int pauseBetweenNotes =noteDuration *1.30;          //음표 구분 시간
    delay(pauseBetweenNotes);                           //delay

    noTone(buzzer);                               //음악 재생을 멈춤
  }
}

void loop() {
}

