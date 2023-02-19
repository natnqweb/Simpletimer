#include "Simpletimer.h"

Simpletimer multicb{};
SimpletimerManager cbmanager{ &multicb };
Simpletimer timer2{};
void callback1() { //0
    Serial.println("entry every 1s");
}
void callback2() { //1
    Serial.println("entry every 1.5s");
}
void callback3() { //2
    Serial.println("entry every 500ms");
}
void callback4() { //3
    Serial.println("entry every 400ms");
}

static Simpletimer::callback all_callbacks[]{
    callback1, //0
    callback2, //1
    callback3, //2
    callback4  //3
    // size 4
};
static unsigned long all_timers[]{
    1000, // 0
    1500, // 1
    500,  // 2
    400   // 3
    //size 4
};


void setup() {
    Serial.begin(9600);
    multicb.register_multiple_callbacks(all_callbacks, all_timers, sizeof(all_timers) / sizeof(all_timers[0]));
    cbmanager.limit_all_tasks_run_counts(5);// every registered task will run only 4 times
    timer2.timer(10000); // first call fills buffer;
}

void loop() {
    //after 10s timer2 will be triggered end reset all timers
    if (timer2.timer(10000)) {
        cbmanager.restart_all_run_counts();
    }

    multicb.run();
}