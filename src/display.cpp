#include <M5StickCPlus.h>

TFT_eSprite tftSprite = TFT_eSprite(&M5.Lcd);

void setup_display(){
    M5.lcd.setRotation(4);
    tftSprite.createSprite(135, 240);
}

void process_display(){

}