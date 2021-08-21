void colorBurst(int r, int g, int b) {
  // put your main code here, to run repeatedly:
  int hue = 10000;
  
    //uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue));
    //strip.setPixelColor(10, rgbcolor);
    //strip.show();
    //for(int i=0;i<LED_COUNT;i++){
      //strip.setPixelColor(i, rgbcolor);
    //}
    uint32_t rgbcolor;
    int x = 13;
    for (int i=0;i<200;i++){
      rgbcolor = strip.ColorHSV(hue, 255, i);
      strip.setPixelColor(x, rgbcolor);
      strip.show();
      delay(5);
    }
    rgbcolor = strip.ColorHSV(hue, 255, 0);
    strip.setPixelColor(13, rgbcolor);

    for (int i=0;i<200;i++){
      rgbcolor = strip.ColorHSV(hue, 255, i);
      strip.setPixelColor(0,rgbcolor);
      strip.setPixelColor(2,rgbcolor);
      strip.setPixelColor(8,rgbcolor);
      strip.setPixelColor(6,rgbcolor);
      strip.setPixelColor(18,rgbcolor);
      strip.setPixelColor(20,rgbcolor);
      strip.setPixelColor(24,rgbcolor);
      strip.setPixelColor(26,rgbcolor);
      strip.show();
      delay(5);
    }

    for (int i=199;i>0;i--){
      rgbcolor = strip.ColorHSV(hue, 255, i);
      strip.setPixelColor(0,rgbcolor);
      strip.setPixelColor(2,rgbcolor);
      strip.setPixelColor(8,rgbcolor);
      strip.setPixelColor(6,rgbcolor);
      strip.setPixelColor(18,rgbcolor);
      strip.setPixelColor(20,rgbcolor);
      strip.setPixelColor(24,rgbcolor);
      strip.setPixelColor(26,rgbcolor);
      strip.show();
      delay(5);
    }
    
    delay(100);
    strip.clear();
    
  
}
