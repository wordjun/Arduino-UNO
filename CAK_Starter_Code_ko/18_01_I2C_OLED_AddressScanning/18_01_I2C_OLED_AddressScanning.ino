 /*  이 스케치는 I2C 통신을 이용한 I2C OLED 를 사용하기 위해
 *  주소를 스캐닝 하여 시리얼 모니터에 결과를 보여준다.
 */

 
 #include <I2CScanner.h>

I2CScanner scanner;

void setup() 
{
	Serial.begin(9600);
	while (!Serial) {};

	scanner.Init();
}

void loop() 
{
	scanner.Scan();
	delay(5000);
}
