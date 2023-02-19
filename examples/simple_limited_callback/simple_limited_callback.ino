#include "Simpletimer.h"

Simpletimer timer1{};
Simpletimer timer2{};
void callback1() {
    Serial.println("entry every 1 sec");
}


void setup() {
    Serial.begin(9600);
    timer1.register_callback(callback1);
    timer1.set_run_limit(4); // callback will run only 4

}

void loop() {
    //after 10s timer2 will be triggered end reset timer1 run limit and process will repeat
    if (timer2.timer(10000)) {
        timer1.reset_run_limit();
    }

    timer1.run(1000);
}