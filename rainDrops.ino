void rainDrops(int r,int g,int b) {

  int x = random(0, 9);
  //rgb(26, 140, 255)
  uint32_t rgbcolor = strip.gamma32(strip.Color(r, g, b));
  strip.clear();
  
  strip.setPixelColor(x, rgbcolor);
  strip.show();
  delay(50);
  strip.clear();
  
  strip.setPixelColor(x+9, rgbcolor);
  strip.show();
  delay(50);
  strip.clear();
  
  strip.setPixelColor(x+18, rgbcolor);
  strip.show();
  delay(50);
  strip.clear();
  
  delay(200);
}
