#include "Simpletimer.h"
// callback function cant take anything and return anything

Simpletimer::RunOnce Once{};

int i = 1;

void callback1() {
	Serial.println(F("entry once"));
	i++;
}

void callback2() {
	Serial.println(F("other method"));
	i++;
	Serial.println("number of tasks performed : " + String(i));
}

void setup() {
	Serial.begin(115200);
}

void loop() {
	//static Simpletimer::RunOnce DoSomething([&](){ here goes your code that need to run once});
	// perform  task once in loop
	static Simpletimer::RunOnce DoSomething;
	DoSomething.Run([&]() {callback1(); Serial.println(F("you can place here anything "));});
	// reset previous task in anotherone and then it can perform second time
	static Simpletimer::RunOnce reset_previous_task;
	reset_previous_task.Run([&]() {DoSomething.Reset(); Serial.println("task 1 RESET being called now");});
	//another way to perform task once you can always reset calling Once.Reset();
	Once.Run(callback2);
}