void ring2(int r, int g, int b) {
  // put your main code here, to run repeatedly:
  int hue = 10000;
  
    //uint32_t rgbcolor = strip.gamma32(strip.ColorHSV(hue));
    //strip.setPixelColor(10, rgbcolor);
    //strip.show();
    //for(int i=0;i<LED_COUNT;i++){
      //strip.setPixelColor(i, rgbcolor);
    //}
    int arr[4][2] = {{0,8},{1,7},{2,6},{3,5}};
    uint32_t rgbcolor = strip.gamma32(strip.Color(r,g,b));
    uint32_t whitecolor = strip.gamma32(strip.ColorHSV(hue,0,0));
    for(int m=0;m<4;m++){
        strip.setPixelColor(0+arr[m][0], rgbcolor);
        strip.setPixelColor(9+arr[m][0], rgbcolor);
        strip.setPixelColor(18+arr[m][0], rgbcolor);
        strip.setPixelColor(0+arr[m][1], rgbcolor);
        strip.setPixelColor(9+arr[m][1], rgbcolor);
        strip.setPixelColor(18+arr[m][1], rgbcolor);

        strip.setPixelColor(0+4, 175,175,175);
        strip.setPixelColor(9+4, 175,175,175);
        strip.setPixelColor(18+4, 175,175,175);
        
        strip.show();
        delay(200);
        strip.clear();
        
    }
    /*
    for(int m=0;m<9;m++){
      strip.setPixelColor(0+m, rgbcolor);
      strip.setPixelColor(9+m, rgbcolor);
      strip.setPixelColor(18+m, rgbcolor);
      strip.show();
      delay(400);
      strip.clear();
      if(m==9){
        m=0;
      }
    }
    */
}
