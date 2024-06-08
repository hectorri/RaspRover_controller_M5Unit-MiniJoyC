#include <M5StickCPlus.h>

const int PIN_BUTTON_A = GPIO_NUM_37;
const int PIN_BUTTON_B = GPIO_NUM_39;

void setup_M5() {
    M5.begin();
    Serial.begin(115200);
}

void process_m5(){
    M5.update();
}