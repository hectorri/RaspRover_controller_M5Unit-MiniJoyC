#include <m5.cpp>
#include <display.cpp>
#include <joy.cpp>

void setup() {
    setup_M5();
    setup_joy();
    setup_display();
}

void loop() {
    process_m5();
    process_joy();
    process_display();
}