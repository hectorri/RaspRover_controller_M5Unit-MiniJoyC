#include "UNIT_MiniJoyC.h"

#define POS_X 0
#define POS_Y 1

#define SAMPLE_TIMES 100
#define XY_CAL_TIMES 10

#define X_DEFAULT_MIN 500
#define X_DEFAULT_MAX 3600
#define Y_DEFAULT_MIN 500
#define Y_DEFAULT_MAX 3600
#define MID_DEFAULT   2000

UNIT_JOYC sensor;

void setup_joy(){
    while (!(sensor.begin(&Wire, JoyC_ADDR, 0, 26, 100000UL))) {
        delay(100);
        Serial.println("I2C Error!\r\n");
    }
}

void process_joy(){
}