/*
 Name:		HallEffect.ino
 Created:	6/19/2021 11:19:40 AM
 Author:	Nash
*/

#include <atomic>
#include <chrono>
#include "string.h"

uint8_t halleffect_d1 = 15;
uint8_t halleffect_d2 = 2;

uint8_t pin1 = 0;
uint8_t pin2 = 4;

unsigned int counter = 0;
hw_timer_t* freqTimer = nullptr;
std::chrono::steady_clock::time_point last_time;

void setDirection(int dir);

void IRAM_ATTR isr_1() {
	counter++;
}

void IRAM_ATTR isr_2() {

}

void onTimer()
{
	
}


// the setup function runs once when you press reset or power the board
void setup() {

	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);
	setDirection(0);

	pinMode(halleffect_d1, INPUT_PULLUP);
	pinMode(halleffect_d2, INPUT_PULLUP);

	attachInterrupt(halleffect_d1, isr_1, FALLING);
	attachInterrupt(halleffect_d2, isr_2, FALLING);


	Serial.begin(115200);
	//freqTimer = timerBegin(0, 80, true);
	//timerAttachInterrupt(freqTimer, &onTimer, true);
	//
	//const uint64_t TIMERALARM = 1e6;
	//
	//timerAlarmWrite(freqTimer, TIMERALARM, true);
	//timerAlarmEnable(freqTimer);

	last_time = std::chrono::steady_clock::now();
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	int direction = 0;

	if (counter < 335)
	{
		direction = 1;
	}
	else
	{
		direction = 0;
	}


	setDirection(direction);

	if (std::chrono::steady_clock::now() - last_time > std::chrono::seconds(2))
	{
		String message = "Counts in 2 seconds: " + String(counter);
		Serial.println(message);
		last_time = std::chrono::steady_clock::now();
	}
}

void setDirection(int dir)
{
	if (dir == 0)
	{
		digitalWrite(pin1, LOW);
		digitalWrite(pin2, LOW);
	}
	else if (dir == 1)
	{
		digitalWrite(pin1, HIGH);
		digitalWrite(pin2, LOW);
	}
	else if (dir == -1)
	{
		digitalWrite(pin1, LOW);
		digitalWrite(pin2, HIGH);
	}
}