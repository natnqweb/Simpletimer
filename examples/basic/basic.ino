#include "Simpletimer.h"
Simpletimer timer1{};
void setup() {
    Serial.begin(9600);
}
void loop() {
    if (timer1.timer(1000)) {
        Serial.println("entry every 1 sec");
    }
}
