void setup() {
pinMode(13,OUTPUT);                          // 13번을 출력 핀(OUTPUT)로 설정
}
 
void loop() { 
digitalWrite(13,HIGH);                       // 13번 핀에 디지털 신호 1 (HIGH)을 준다. LED 켜짐 
delay(1000);                                 // 1000밀리초 (=1초) 동안 기다린다.  
digitalWrite(13,LOW);                        // 13번 핀에 디지털 신호 0 (LOW)을 준다. LED 꺼짐
delay(1000);                                 // 1000밀리초 (=1초) 동안 기다린다. 
}
