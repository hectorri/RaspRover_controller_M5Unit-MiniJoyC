#include <m5.cpp>
#include <display.cpp>
#include <joy.cpp>

void setup() {
    setup_M5();
    setup_joy();
    setup_display();
}

void loop() {
    m5_update();
}