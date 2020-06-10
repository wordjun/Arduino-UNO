
/* Coding Array STARTER Kit for Arduino
* 
*  예제 13_FlameSensor
* 
*  이 스케치는 아날로그 A5번에 연결된 불꽃센서 모듈을 사용하여
*  주변의 불꽃 세기를 감지하고 (라이터를 준비해 모듈 근처에 불꽃을 가져다 댄다)
*  설정한 임계값을 넘으면 경보음을 발생한다. 
*  
*/

#define PI 3.141592       // 원주율 PI 값을 설정

int flameSensor =A5;                 // 불꽃감지 센서를 아날로그핀 A5에 연결
int Buzzer =6;                       // 피에조부저를 6번핀에 연결
int sensorReading =0;               // 센서 출력값을 저장하는 변수
int threshold = 1000;

void setup() {
  pinMode(Buzzer, OUTPUT);           // 피에조부저 핀을 출력설정
  pinMode(flameSensor, INPUT);       // 불꽃 센서 핀을 입력으로 설정
  Serial.begin(9600);               // 9600속도로 시리얼통신 시작
}


void loop() {
  sensorReading = analogRead(flameSensor);  //불꽃감지 센서 아날로그 값을 읽어 저장

  Serial.println(sensorReading);        //불꽃감지 센서 값을 시리얼 창에 프린트

  if(sensorReading >=threshold) {            // 불꽃 감지 센서 값이 1000 이상이면
 
    Serial.println("Fire !!");           // Fire !! 를 화면에 출력
    playTone();                          // 경보음 발생

  } else {                            // 불꽃 감지 센서 값이 1000 미만이면
    noTone(Buzzer);                      //피에조부저 끔
  }

  delay(500);                       // 0.5초 간격
}


// 경보음 함수 설정

void playTone() {
  float sinVal;           // sin파 값 저장
  int toneVal;            // 경보음 발생을 위한 값 저장
 
  for(int i =0 ; i < 180; i++) {
    sinVal =sin(i * PI/180);                 //각도를 라디안 값으로 바꿔 sin 값 계산
    toneVal = 2000+(int(sinVal * 1000));      //경보음을 주파수로 변환
    tone(Buzzer,toneVal);                   //피에조 스피커에서 주파수 발생
    delay(10);                              //경보음 주파수 변화속도 조정
  }
}


