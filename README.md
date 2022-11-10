
# Simpletimer

a timer based on micros that will make your coding a lot easier

timer()
as simple as that you can perform action every amount of time you feed to function for example

``` C++
    Simpletimer timer1{}; 
    timer1.timer(1000)
    {
    //entry every 1000ms
    }
```

from Version 2.0 up, you can register callbacks now only 'void functions(void)'

# callback example

``` C++

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
    
```

version 2.1

# multiple callbacks example

``` C++

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

```

## perform tasks only once in loop

``` C++

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

```
