void chaser() {
  // put your main code here, to run repeatedly:
  int ar1[] = {14,0,1,2,12,26,25,24};
  int ar2[] = {12,8,7,6,14,18,19,20};
    for(int i=0;i<8;i++){
      
        strip.setPixelColor(ar1[i], 247,83,7);
        strip.setPixelColor(ar2[i], 7,247,35);
        strip.show();
        delay(100);
        strip.clear();
  
    }
    
}
