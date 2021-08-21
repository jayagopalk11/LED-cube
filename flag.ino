void flag() {
  // put your main code here, to run repeatedly:
    for(int i=0;i<3;i++){
      for(int j=0;j<9;j++){
        if(i==0){
          strip.setPixelColor(0+j, 247,83,7);
        }else if(i==1){
          strip.setPixelColor(9+j, 175,175,175);
        }else{
          strip.setPixelColor(18+j, 7,247,35);
        }
        strip.setPixelColor(13, 7,75,247);
      }
      
      
    }
    strip.show();
    //delay(200);
}
