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
  timer1.run(1000);

}