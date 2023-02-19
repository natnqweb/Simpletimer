#include <Simpletimer.h>
// callback function cant take anything and return anything
#define ledpin LED_BUILTIN
#define ARR_LEN(ARR) (sizeof(ARR)/sizeof(ARR[0]))
Simpletimer multicb{};
SimpletimerManager cbmanager{ &multicb };
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



static Simpletimer::callback all_callbacks[]
{
  callback1,  //-- 1, index = 0
  callback2,  //-- 2, index = 1
  callback3,  //-- 3, index = 2
  blink       //-- 4, index = 3
};

static unsigned long timers[]
{
  1000, //callback1   -- 1, index = 0
  500,  //callback2   -- 2, index = 1
  200,  //callback3   -- 3, index = 2
  1000  // blink      -- 4, index = 3
};


static const unsigned int BLINK_CALLBACK_INDEX = 3;
static const unsigned int NUMBER_OF_BLINKS_LIMIT = 100;
static const unsigned int BLINK_SPEED_UP = 20; //ms

void blink() {
    state = !state;
    //every time we change state speedup blinking
    if (timers[BLINK_CALLBACK_INDEX] - BLINK_SPEED_UP > 0U)
    {
        timers[BLINK_CALLBACK_INDEX] -= BLINK_SPEED_UP;
    }
}

void setup() {
    pinMode(ledpin, OUTPUT);

    Serial.begin(115200);

    multicb.register_multiple_callbacks(all_callbacks, timers, ARR_LEN(all_callbacks));
    // after you registered callbacks you can constrain each callback for how many times the callback will run
    // for example let's constrain callback1 and limit calls to the callback to 4 calls (entries)
    // index of callback1 is 0 because callback1 is first in array callback2 index is 1 and so on...

    cbmanager.limit_number_of_calls_to_callback(0 /*index of callback1*/, 4/*number of calls limit*/);

    //we will also constrain number of blinks we will limit number of blinks to 100 
    //we will make led blink faster and faster until we reach 100 blinks
    cbmanager.limit_number_of_calls_to_callback(BLINK_CALLBACK_INDEX, NUMBER_OF_BLINKS_LIMIT * 2);

    // you can also limit all callbacks using this
    // cbmanager.limit_all_tasks_run_counts(4); // all tasks will run only 4 times

    Serial.println(F("program started"));
}
void loop() {
    multicb.run();
    digitalWrite(ledpin, state);
}