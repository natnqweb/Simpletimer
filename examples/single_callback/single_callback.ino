#include "Simpletimer.h"
// callback function can't take anything and return anything

Simpletimer timer{};

void callback1() {
  Serial.println(F("entry every 1 sec"));
}

unsigned long callbacksleep = 1000;
Simpletimer::callback cb = callback1;

void setup() {
  Serial.begin(115200);

  timer.register_multiple_callbacks(&cb, &callbacksleep);
  Serial.println(F("program started"));
}
void loop() {
  timer.run();
}