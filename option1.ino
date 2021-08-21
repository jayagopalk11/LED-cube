void option1() {
  // put your main code here, to run repeatedly:
  int hue = 0;
  for(int i=0;i<655;i++){
    uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue));
    //strip.setPixelColor(10, rgbcolor);
    //strip.show();
    for(int i=0;i<LED_COUNT;i++){
      strip.setPixelColor(i, rgbcolor);
    }
    strip.show();
    delay(5);
    hue += 100;
  }
}
