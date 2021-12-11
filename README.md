
# Simpletimer
a timer based on millis that will make your coding a lot easier
there is only one function 
timer() 
as simple as that you can perform action every amount of time you feed to function for example

    Simpletimer timer1;	
    timer1.timer(1000)
    {
    //entry every 1000ms
    }
    i use it as a tool in my projects so i don't need to repeat myself creating timers
in Version 2.0 you can register callbacks now only 'void functions(void)'

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
