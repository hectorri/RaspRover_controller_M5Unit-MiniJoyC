#include <M5StickCPlus.h>

TFT_eSprite tftSprite = TFT_eSprite(&M5.Lcd);

void setup_display(){
    M5.lcd.setRotation(4);  // Rotate the screen. 将屏幕旋转
    tftSprite.createSprite(135, 240);
}