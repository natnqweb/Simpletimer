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