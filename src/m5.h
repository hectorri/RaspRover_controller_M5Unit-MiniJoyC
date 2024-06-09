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
    float volt = M5.Axp.GetBatVoltage();
    float min_volt = 3.20;
    float max_volt = 4.20;
    float min_capacity = 0;
    float max_capacity = 100;

    if (volt < min_volt) {
        return 0;
    }

    if (volt > max_volt) {
        return 100;
    }

    // Calcular la capacidad utilizando una relación lineal
    float capacity = (volt - min_volt) / (max_volt - min_volt) * (max_capacity - min_capacity) + min_capacity;

    return std::round(capacity);
}
