void chaser2(int r, int g, int b) {
  // put your main code here, to run repeatedly:
  int ar1[] = {0,1,2,3,8,7,6,5};
  int ar2[] = {26,25,24,23,18,19,20,21};
    for(int i=0;i<8;i++){
      
        strip.setPixelColor(ar1[i], r,g,b);
        strip.setPixelColor(ar2[i], r,g,b);
        strip.setPixelColor(13, r,g,b);
        //strip.setPixelColor(ar2[i], 7,247,35);
        strip.show();
        delay(100);
        strip.clear();
  
    }
    
}
