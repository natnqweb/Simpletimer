#include "Simpletimer.h"

// callback function cant take anything and return anything
#define ledpin LED_BUILTIN

Simpletimer multicb{};
bool state = false;

void callback1();
void callback2();
void callback3();
void callback4();
void callback5();
void callback6();
void callback7();
void callback8();
void callback9();
void callback10();
void callback11();
void callback12();
void callback13();
void callback14();
void callback15();
void callback16();
void callback17();
void callback18();
void callback19();
void callback20();
void callback21();
void callback22();
void callback23();
void callback24();
void callback25();
void callback26();
void callback27();
void callback28();
void callback29();
void callback30();
void callback31();
void callback32();
void callback33();
void callback34();
void callback35();
void callback36();
void callback37();
void callback38();
void callback39();
void callback40();
void callback41();
void callback42();
void callback43();
void callback44();
void callback45();
void callback46();
void callback47();
void callback48();
void callback49();
void callback50();
void blink();



void blink() {
    state = !state;
}

static Simpletimer::callback all_callbacks[]
{
  callback1,  //-- 1
  callback2,  //-- 2
  callback3,  //-- 3
  callback4,  //-- 4
  callback5,  //-- 5
  callback6,  //-- 6
  callback7,  //-- 7
  callback8,  //-- 8
  callback9,  //-- 9
  callback10, //-- 10
  callback11, //-- 11
  callback12, //-- 12
  callback13, //-- 13
  callback14, //-- 14
  callback15, //-- 15
  callback16, //-- 16
  callback17, //-- 17
  callback18, //-- 18
  callback19, //-- 19
  callback20, //-- 20
  callback21, //-- 21
  callback22, //-- 22
  callback23, //-- 23
  callback24, //-- 24
  callback25, //-- 25
  callback26, //-- 26
  callback27, //-- 27
  callback28, //-- 28
  callback29, //-- 29
  callback30, //-- 30
  callback31, //-- 31
  callback32, //-- 32
  callback33, //-- 33
  callback34, //-- 34
  callback35, //-- 35
  callback36, //-- 36
  callback37, //-- 37
  callback38, //-- 38
  callback39, //-- 39
  callback40, //-- 40
  callback41, //-- 41
  callback42, //-- 42
  callback43, //-- 43
  callback44, //-- 44
  callback45, //-- 45
  callback46, //-- 46
  callback47, //-- 47
  callback48, //-- 48
  callback49, //-- 49
  callback50, //-- 50
  blink       //-- 51
};

static unsigned long timers[]
{
  1000, //callback1    -- 1
  400,  //callback2    -- 2
  200,  //callback3    -- 3
  3000, //callback4    -- 4
  1500, //callback5    -- 5
  1600, //callback6    -- 6
  5000, //callback7    -- 7
  6000, //callback8    -- 8
  7000, //callback9    -- 9
  8000, //callback10   -- 10
  9000, //callback11   -- 11
  9500, //callback12   -- 12
  9200, //callback13   -- 13
  9700, //callback14   -- 14
  2010, //callback15,  -- 15
  2100, //callback16,  -- 16
  2200, //callback17,  -- 17
  2300, //callback18,  -- 18
  2240, //callback19,  -- 19
  2222, //callback20,  -- 20
  2212, //callback21,  -- 21
  2412, //callback22,  -- 22
  2532, //callback23,  -- 23
  2432, //callback24,  -- 24
  2123, //callback25,  -- 25
  2119, //callback26,  -- 26
  2466, //callback27,  -- 27
  2431, //callback28,  -- 28
  2464, //callback29,  -- 29
  2599, //callback30,  -- 30
  2985, //callback31,  -- 31
  3260, //callback32,  -- 32
  3357, //callback33,  -- 33
  4607, //callback34,  -- 34
  5678, //callback35,  -- 35
  5357, //callback36,  -- 36
  4267, //callback37,  -- 37
  5809, //callback38,  -- 38
  6777, //callback39,  -- 39
  5555, //callback40,  -- 40
  6123, //callback41,  -- 41
  8788, //callback42,  -- 42
  8888, //callback43,  -- 43
  9133, //callback44,  -- 44
  1565, //callback45,  -- 45
  6666, //callback46,  -- 46
  8888, //callback47,  -- 47
  5444, //callback48,  -- 48
  4321, //callback49,  -- 49
  4333, //callback50,  -- 50
  500,  //Blink        -- 51
};

void callback1() {
    Serial.println(F("callback1: entry every 1 sec"));
}

void callback2() {
    Serial.println(F("callback2: entry every 0.4 sec"));
}

void callback3() {
    Serial.println(F("callback3: entry every 0.2 sec"));
}

void callback4() {
    Serial.println(F("callback4: entry every 3 sec"));
}

void callback5() {
    Serial.println(F("callback5: entry every 1.5 sec"));
}

void callback6() {
    Serial.println(F("callback6: entry every 1.6 sec"));
}

void callback7() {
    Serial.println(F("callback7: entry every 5 sec"));
}

void callback8() {
    Serial.println(F("callback8: entry every 6 sec"));
}

void callback9() {
    Serial.println(F("callback9: entry every 7 sec"));
}

void callback10() {
    Serial.println(F("callback10: entry every 8 sec"));
}

void callback11() {
    Serial.println(F("callback11: entry every 9 sec"));
}

void callback12() {
    Serial.println(F("callback12: entry every 9.5 sec"));
}

void callback13() {
    Serial.println(F("callback13: entry every 9.2 sec"));
}

void callback14() {
    Serial.println(F("callback14: entry every 9.7 sec"));
}
void callback15() {
    Serial.println(F("callback14: entry every 9.7 sec"));
}

void callback16() {
    Serial.println(F("callback16: entry"));
}

void callback17() {
    Serial.println(F("callback17: entry"));
}

void callback18() {
    Serial.println(F("callback18: entry"));
}

void callback19() {
    Serial.println(F("callback19: entry"));

}

void callback20() {
    Serial.println(F("callback20: entry"));
}

void callback21() {
    Serial.println(F("callback21: entry"));
}

void callback22() {
    Serial.println(F("callback22: entry"));
}
void callback23() {
    Serial.println(F("callback23: entry"));
}

void callback24() {
    Serial.println(F("callback24: entry"));
}

void callback25() {
    Serial.println(F("callback25: entry"));
}

void callback26() {
    Serial.println(F("callback26: entry"));
}
void callback27() {
    Serial.println(F("callback27: entry"));
}
void callback28() {
    Serial.println(F("callback28: entry"));
}
void callback29() {
    Serial.println(F("callback29: entry"));
}

void callback30() {
    Serial.println(F("callback30: entry"));
}

void callback31() {
    Serial.println(F("callback31: entry"));
}

void callback32() {
    Serial.println(F("callback32: entry"));
}
void callback33() {
    Serial.println(F("callback33: entry"));
}

void callback34() {
    Serial.println(F("callback34: entry"));
}

void callback35() {
    Serial.println(F("callback35: entry"));
}

void callback36() {
    Serial.println(F("callback36: entry"));
}
void callback37() {
    Serial.println(F("callback37: entry"));
}
void callback38() {
    Serial.println(F("callback38: entry"));
}
void callback39() {
    Serial.println(F("callback39: entry"));
}

void callback40() {
    Serial.println(F("callback40: entry"));
}

void callback41() {
    Serial.println(F("callback41: entry"));
}

void callback42() {
    Serial.println(F("callback42: entry"));
}
void callback43() {
    Serial.println(F("callback43: entry"));
}

void callback44() {
    Serial.println(F("callback44: entry"));
}

void callback45() {
    Serial.println(F("callback45: entry"));
}

void callback46() {
    Serial.println(F("callback46: entry"));
}
void callback47() {
    Serial.println(F("callback47: entry"));
}
void callback48() {
    Serial.println(F("callback48: entry"));
}
void callback49() {
    Serial.println(F("callback49: entry"));
}
void callback50() {
    Serial.println(F("callback50: entry"));
}

void setup() {
    pinMode(ledpin, OUTPUT);

    Serial.begin(115200);

    multicb.register_multiple_callbacks(all_callbacks, timers, sizeof(timers) / sizeof(timers[0]));
    Serial.print(F("Registered : "));
    Serial.print(sizeof(timers) / sizeof(timers[0]));
    Serial.println(F(" Callbacks"));
    Serial.println(F("program started"));
}
void loop() {
    multicb.run();
    digitalWrite(ledpin, state);
}