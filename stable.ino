void stable(int r,int g,int b) {
  // put your main code here, to run repeatedly:
    uint32_t rgbcolor = strip.gamma32(strip.Color(r,g,b));
    //strip.setPixelColor(10, rgbcolor);
    //strip.show();
    for(int i=0;i<LED_COUNT;i++){
      strip.setPixelColor(i, rgbcolor);
    }
    strip.show();
  
}
