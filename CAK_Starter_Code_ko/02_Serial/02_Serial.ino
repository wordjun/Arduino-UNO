/*  ArduinoStory CodingArrayKit_STARTER
 *   
 *  예제 02_Serial
 *  이 스케치는 컴퓨터와 아두이노의 시리얼 통신을 위한
 *  가장 기본적인 틀을 보여준다. 
 *  통신을 시작하기 위해 반드시 setup 에서 통신 시작을 알린다. 
 *  시리얼 통신은 결과 값을 나타내거나, 프로그램 디버깅에 많이 사용된다.
 */
 
void setup() { 
  Serial.begin(9600);            //시리얼 통신을 준비한다. 통신 속도는 9600으로 맞춘다.
 
}

void loop() { 
  Serial.println("Hello Coding Array Kit ~!");   //시리얼 창에 Hello Coding Array Kit ~!를 출력한다. 
  delay(1000);                               //1000밀리초 (=1초) 동안 기다린다. 
}
