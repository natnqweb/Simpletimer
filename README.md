
# Simpletimer
a timer based on micros that will make your coding a lot easier

timer() 
as simple as that you can perform action every amount of time you feed to function for example

    Simpletimer timer1;	
    timer1.timer(1000)
    {
    //entry every 1000ms
    }
    i use it as a tool in my projects so i don't need to repeat myself creating timers
from Version 2.0 up you can register callbacks now only 'void functions(void)'

# callback example
    #include "Simpletimer.h"
    // callback function cant take anything and return anything
    Simpletimer timer1;
    void callback1(){
      Serial.println("entry every 1 sec");
    }

    void setup(){
    Serial.begin(9600);
    timer1.register_callback(callback1);
    }
    void loop(){
      timer1.call_callback(1000);

    }
version 2.1
# multiple callbacks example
    #include "Simpletimer.h"
    // callback function cant take anything and return anything
    #define ledpin 8

    Simpletimer multicb;

    void callback1();
    void callback2();
    void callback3();
    void blink();
    void callback1(){
      Serial.println(F("entry every 1 sec"));
    }
    void callback2(){
      Serial.println(F("entry every 0.5 sec"));
    }
    void callback3(){
      Serial.println(F("entry every 0.2 sec"));
    }
    volatile bool state=false;
    void blink(){
    state=!state;
    }
    void setup(){
        pinMode(ledpin,OUTPUT);
        size_t number_of_callbacks=4;
        Simpletimer::callback all_callbacks[4]={callback1,callback2,callback3,blink};
        unsigned long timers[4]={1000,500,200,199};

    Serial.begin(115200);
    multicb.register_multiple_callbacks(all_callbacks,timers,number_of_callbacks);
    Serial.println(F("program started"));

    }
    void loop(){



        multicb.run();
        digitalWrite(ledpin,state);


    }
## perform tasks only once in loop
    #include <Simpletimer.h>
    // callback function cant take anything and return anything

    Simpletimer::RunOnce Once;
    int i=1;
    void callback1(){
      Serial.println(F("entry once"));
      i++;
    }

    void callback2(){
         Serial.println(F("other method"));
         i++;
         Serial.println("number of tasks performed : "+String(i));
    }

    void setup(){

    Serial.begin(115200);



    }
    void loop(){
        //static Simpletimer::RunOnce DoSomething([&](){ here goes your code that need to run once});
        // perform  task once in loop
        static Simpletimer::RunOnce DoSomething;
        DoSomething.Run([&](){callback1(); Serial.println(F("you can place here anything "));});
        // reset previous task in anotherone and then it can perform second time
        static Simpletimer::RunOnce reset_previous_task;
        reset_previous_task.Run([&](){DoSomething.Reset(); Serial.println("task 1 RESET being called now");});
        //another way to perform task once you can always reset calling Once.Reset();
        Once.Run(callback2);







    }

