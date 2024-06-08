#include <M5StickCPlus.h>

TFT_eSprite header_sprite = TFT_eSprite(&M5.Lcd);
TFT_eSprite joy_sprite = TFT_eSprite(&M5.Lcd);
TFT_eSprite footer_sprite = TFT_eSprite(&M5.Lcd);

const int joy_square_dimension = 100;

void setup_display(){
    M5.Lcd.setRotation(0);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextSize(2);
    M5.Lcd.println("Mini JoyC");
}

void init_header_sprite(){
    header_sprite.createSprite(135, 35);
    header_sprite.setRotation(0);
    header_sprite.setTextSize(2);
}

void init_footer_esprite() {
    footer_sprite.createSprite(135, 35);
    footer_sprite.setRotation(0);
    footer_sprite.setTextSize(2);
}

void init_joy_sprite() {
    joy_sprite.createSprite(joy_square_dimension, joy_square_dimension);
    joy_sprite.setRotation(0);
    joy_sprite.setTextSize(2);
}

void update_header_sprite() {
    header_sprite.fillScreen(BLACK);
    header_sprite.setCursor(0, 0);
    header_sprite.print("   ");
    header_sprite.print(M5.Axp.GetBatVoltage(), 2);
    header_sprite.println(" v");
    header_sprite.print("  ");
    header_sprite.print("Modo: ");
    header_sprite.println("TODO: modoJoy");
    header_sprite.pushSprite(0, 25);
}

void update_joy_sprite() {
    const int origenCuadranteJoystickX = 20;
    const int origenCuadranteJoystickY = 95;
    const int colorCuadranteJoystick = RED;
    const int sizeCenterCross = 25;
    const int radioCuadrante = 10;
    int coordenadaCirculoX = map(joy_square_dimension/2, -100, 100, 0, 100);
    int coordenadaCirculoY = map(joy_square_dimension/2, -100, 100, 100, 0);

    joy_sprite.fillScreen(BLACK);
    joy_sprite.drawRoundRect(0, 0, joy_square_dimension, joy_square_dimension, radioCuadrante, colorCuadranteJoystick);
    joy_sprite.drawCircle(coordenadaCirculoX, coordenadaCirculoY, radioCuadrante, colorCuadranteJoystick);
    joy_sprite.drawFastHLine(joy_square_dimension/2 - sizeCenterCross, joy_square_dimension/2, sizeCenterCross * 2, colorCuadranteJoystick);  // linea horizontal de la cruz central
    joy_sprite.drawFastVLine(joy_square_dimension/2, joy_square_dimension/2 - sizeCenterCross, sizeCenterCross * 2, colorCuadranteJoystick);  // linea vertical de la cruz central
    joy_sprite.pushSprite(origenCuadranteJoystickX, origenCuadranteJoystickY);
}

void update_footer_sprite() {
    footer_sprite.fillScreen(BLACK);
    footer_sprite.setCursor(35, 2);
    footer_sprite.print(millis());
    footer_sprite.pushSprite(0, 220);
}

void update_display() {
    update_header_sprite();
    update_joy_sprite();
    update_footer_sprite();
}

void process_display(){
    update_display();
}