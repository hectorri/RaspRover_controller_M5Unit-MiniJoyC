#include <M5StickCPlus.h>

const int PIN_BUTTON_A = GPIO_NUM_37;
const int PIN_BUTTON_B = GPIO_NUM_39;
const int PIN_LED = GPIO_NUM_10;

void setup_M5() {
    M5.begin();
    Serial.begin(115200);
}

void process_m5(){
    M5.update();
}

void led_on(){
    digitalWrite(PIN_LED, HIGH);
}

void led_off(){
    digitalWrite(PIN_LED, LOW);
}

int get_battery_percentage() {
    return map(constrain(((M5.Axp.GetBatVoltage()) * 1000), 3400, 4200), 3400, 4200, 0, 100);
}