 /*  This sketch scans addresses to use I2C OLEDs using I2C
 *   communication and shows results on serial monitors.
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
