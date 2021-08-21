void firefly() {
  // put your main code here, to run repeatedly:
  int hue = 10000;
  
    //uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue));
    //strip.setPixelColor(10, rgbcolor);
    //strip.show();
    //for(int i=0;i<LED_COUNT;i++){
      //strip.setPixelColor(i, rgbcolor);
    //}
    int x = random(0, 27);
    for (int i=0;i<200;i++){
      uint32_t rgbcolor = strip.ColorHSV(hue, 255, i);
      strip.setPixelColor(x, rgbcolor);
      strip.show();
      delay(5);
    }
    for (int i=199;i>0;i--){
      uint32_t rgbcolor = strip.ColorHSV(hue, 255, i);
      strip.setPixelColor(x, rgbcolor);
      strip.show();
      delay(10);
    }
    strip.clear();
    delay(random(100, 1000));
  
}
