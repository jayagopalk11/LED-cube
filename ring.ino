void ring(int r, int g, int b) {
  // put your main code here, to run repeatedly:
  //int hue = 10000;
    //uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue));
    //strip.setPixelColor(10, rgbcolor);
    //strip.show();
    //for(int i=0;i<LED_COUNT;i++){
      //strip.setPixelColor(i, rgbcolor);
    //}
    int arr[] = {0,1,2,3,8,7,6,5};
    uint32_t rgbcolor = strip.gamma32(strip.Color(r,g,b));
    for(int m=0;m<8;m++){
        strip.setPixelColor(0+arr[m], rgbcolor);
        strip.setPixelColor(9+arr[m], rgbcolor);
        strip.setPixelColor(18+arr[m], rgbcolor);
        strip.show();
        delay(100);
        strip.clear();
        
    }
}
