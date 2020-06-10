/*  ArduinoStory CodingArrayKit_STARTER
 *   
 * 예제 04_Button_Debounce
 * 이 스케치는 https://www.arduino.cc/en/Tutorial/Debounce 예제를 재구성
 * 
 *  버튼 스위치가 열리고 닫힐 때 종종 기계적 및 물리적 문제로 잘못된 신호를 발생한다.
 *  이러한 상황은 프로그램을 속일 수 있는 매우 짧은 시간에 여러 번 눌러 읽는 방법으로 방지할 수 있는데
 *  이 과정을 디바운싱이라 한다.
 */
 
const int Button =8;     // 버튼 스위치 핀을 8번으로 설정
const int redLED = 13;      // LED 핀을 13번으로 설정 

int ledState =HIGH;          // 출력핀을 HIGH로 설정
int buttonState;             // 현재 버튼 스위치 상태를 읽어 저장하는 변수
int lastButtonState =HIGH;    // 이전 버튼 스위치 상태를 읽어 저장. LOW로 초기화

unsigned long lastDebounceTime =0;    // 출력핀이 마지막으로 전환된 시간 저장.
unsigned long debounceDelay =50;      // 안정된 상태가 될 때까지 기다리는 시간 (밀리초) 

void setup() {
  pinMode(redLED, OUTPUT);                    // 빨간색 LED 핀을 출력으로 설정
  //pinMode(Button, INPUT_PULLUP);           // 버튼스위치 핀을 입력으로 설정
  pinMode(Button, INPUT); 
  digitalWrite(redLED,ledState);       // ledState에 따라 LED를 켜고 끈다 
}


void loop() {
 
  int reading = digitalRead(Button);   // 버튼 상태를 읽어 reading 변수에 저장

  if(reading != lastButtonState) {     // 노이즈 또는 누르기로 버튼 상태가 변경되면
    
    lastDebounceTime =millis();          // debouncing timer를 재설정하고
  }
    
  // 읽은 값이 무엇이든 debounce 지연보다 오래 있었으면
  if((millis() -lastDebounceTime) > debounceDelay) { 
    if(reading != buttonState) {             // 버튼 상태가 바뀌면
      buttonState =reading;                 // 버튼 상태를 저장하고

      if(buttonState ==LOW) {                       // 새로운 버튼 상태가 HIGH면
        ledState =!ledState;                         // LED 상태를 바꾼다 
      }
    }
  }
 
  digitalWrite(redLED,ledState);         // ledState에 저장된 값으로 LED를 on/off 

  // reading변수의 값을 lastButtonState (다음 loop에서 사용)에 저장 
  lastButtonState =reading;
}

