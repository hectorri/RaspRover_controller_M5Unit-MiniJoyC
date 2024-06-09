#include "UNIT_MiniJoyC.h"

#define POS_X 0
#define POS_Y 1

UNIT_JOYC joy;

int8_t joy_x;
int8_t joy_y;
bool joy_button;
bool joy_mode;
bool joy_button_pushed;
bool joy_button_pushing;

void setup_joy(){
    joy.begin(&Wire, JoyC_ADDR, 0, 26, 100000UL);
}

void select_joy_mode() {
    if (joy_button_pushed && !joy_button_pushing) {
        joy_mode = !joy_mode;
        joy_button_pushing = true;
    } else if (!joy_button_pushed) {
        joy_button_pushing = false;
    }
}

void read_joy(){
    joy_x = joy.getPOSValue(POS_X, _8bit);
    joy_x = constrain(joy_x, -100, 100);
    joy_y = joy.getPOSValue(POS_Y, _8bit);
    joy_y = constrain(joy_y, -100, 100);
    joy_button = joy.getButtonStatus();
    select_joy_mode();
}

int8_t get_x_axis_joy() {
    return joy.getPOSValue(POS_X, _8bit);
}

int8_t get_y_axis_joy() {
    return joy.getPOSValue(POS_Y, _8bit);
}

void process_joy(){
    const int updateTime = 20;  // milisegundos entre cada ciclo de temporización
    static unsigned long lastUpdate;
    if ((millis() - lastUpdate) > updateTime) {
        lastUpdate = millis();
        read_joy();
    }
}