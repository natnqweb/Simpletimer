#include "Simpletimer.h"

Simpletimer timer1{};
Simpletimer timer2{};
void callback1() { //0
    Serial.println("entry every 1s");
}

void setup() {
    Serial.begin(9600);
    timer1.register_callback(callback1);
    timer1.set_run_limit(4); // callback1 will run only 4 times
    timer2.timer(10000); // to avoid first entry becouse buffer is empty at start
}

void loop() {
    //after 10s timer2 will be triggered end reset timer1
    if (timer2.timer(10000)) {
        timer1.reset_run_limit();
    }

    timer1.run(1000);
}