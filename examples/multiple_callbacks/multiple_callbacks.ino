#include <Simpletimer.h>
// callback function cant take anything and return anything
#define ledpin LED_BUILTIN

Simpletimer multicb{};
bool state = false;

void callback1();
void callback2();
void callback3();
void blink();

void callback1() {
	Serial.println(F("entry every 1 sec"));
}

void callback2() {
	Serial.println(F("entry every 0.5 sec"));
}

void callback3() {
	Serial.println(F("entry every 0.2 sec"));
}

void blink() {
	state = !state;
}

static const unsigned int number_of_callbacks = 4;
static Simpletimer::callback all_callbacks[number_of_callbacks]
{
  callback1,  //-- 1
  callback2,  //-- 2
  callback3,  //-- 3
  blink       //-- 4
};
static unsigned long timers[number_of_callbacks]
{
  1000, //callback1   -- 1
  500,  //callback2   -- 2
  200,  //callback3   -- 3
  2000  // blink      -- 4
};

void setup() {
	pinMode(ledpin, OUTPUT);

	Serial.begin(115200);

	multicb.register_multiple_callbacks(all_callbacks, timers, number_of_callbacks);

	Serial.println(F("program started"));
}
void loop() {
	multicb.run();
	digitalWrite(ledpin, state);
}