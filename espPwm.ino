#include <analogWrite.h>
#include <iostream>
#include <string>
#include <sstream>

#define PWM 26
#define C1 27
#define C2 14
#define DEBUG_LED 2

const int freq = 50;
const int ledChannel = 0;
const int resolution = 10;

void setup() {
	pinMode(PWM, OUTPUT);
	pinMode(C1, OUTPUT);
	pinMode(C2, OUTPUT);

	pinMode(DEBUG_LED, OUTPUT);
	Serial.begin(115200);

	ledcSetup(ledChannel, freq, resolution);

	ledcAttachPin(DEBUG_LED, ledChannel);
	ledcAttachPin(C1, ledChannel);

	int brightness = 0;
	int fadeAmount = 5;
}
void loop() 
{
	auto res = pulseIn(34, true);
	Serial.println(res);
	ledcWrite(ledChannel, res);

}
