#include <m5.h>
#include <display.h>
#include <joy.h>

void setup() {
    setup_M5();
    setup_joy();
    setup_display();
}

void loop() {
    process_m5();
    process_joy();
    process_display(get_x_axis_joy(), get_y_axis_joy(), get_battery_percentage());
}