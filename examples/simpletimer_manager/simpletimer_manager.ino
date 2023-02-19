#include "Simpletimer.h"

Simpletimer multiple_cb{};
SimpletimerManager cb_manager{ &multiple_cb };
void callback1() {//0
    Serial.println("entry every 1 sec");
}
void callback2() {//1
    Serial.println("entry every 2 sec");
}

void callback3() {//2
    Serial.println("entry every 3 sec");
}

void callback4() {//3
    Serial.println("entry every 4 sec");
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
    2000, // 1
    3000, // 2
    4000  // 3
    //size 4
};
static bool all_callbacks_on = false;
void setup() {
    Serial.begin(9600);
    multiple_cb.register_multiple_callbacks(all_callbacks, all_timers, sizeof(all_timers) / sizeof(all_timers[0]));
    cb_manager.limit_all_tasks_run_counts(0); // this will basically turn off all tasks
    // turn on only callback1
    cb_manager.get_timer(0)->reset_run_limit();
}

void loop() {
    //lets run only 1 of registered callbacks for example callback1 (callback1 has index 0)
    // but lets select other timing for our task for example 2sec so it will be all_timers[1]
    if (!all_callbacks_on) {
        cb_manager.get_timer(0)->run(all_timers[1]);
        if (cb_manager.get_timer(0)->get_run_count() == 4) {
            //after 4 entries in callback1 we will turn on all callbacks
            all_callbacks_on = true;
            cb_manager.restart_all_run_counts();
            Serial.println("turning on all callbacks now!");
        }
    }
    else {
        multiple_cb.run();
    }
}