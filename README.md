# Simpletimer
a timer based on millis that will make your coding a lot easier
there is only one function 
timer() 
as simple as that you can perform action every amount of time you feed to function for example


### example 
    #include <Simpletimer.h>
    Simpletimer timer1;
    void setup(){
    Serial.begin(9600);
    }
    void loop(){
    if (timer1.timer(1000)){
    Serial.println("entry every 1 sec");
    }
    }
