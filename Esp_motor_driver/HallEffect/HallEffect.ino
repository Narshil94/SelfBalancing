/*
 Name:		HallEffect.ino
 Created:	6/19/2021 11:19:40 AM
 Author:	Nash
*/

int halleffect_d1 = 15;
int halleffect_d2 = 2;

void IRAM_ATTR isr_1() {

}

void IRAM_ATTR isr_2() {

}


// the setup function runs once when you press reset or power the board
void setup() {

	pinMode(halleffect_d1, INPUT_PULLUP);
	pinMode(halleffect_d2, INPUT_PULLUP);

	attachInterrupt(halleffect_d1, isr_1, FALLING);
	attachInterrupt(halleffect_d2, isr_2, FALLING);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
