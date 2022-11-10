#include "Simpletimer.h"

Simpletimer timer1{};

// callback function cant take anything and return anything
void callback1() {
  Serial.println("entry every 1 sec");
}

void setup() {
  Serial.begin(9600);
  timer1.register_callback(callback1);
}

void loop() {
  timer1.run(1000);
}