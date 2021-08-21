#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN    15
#define LED_COUNT 27
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ400);

/* Put your SSID & Password */
const char* ssid = "Cube@(192.168.1.1)";  // Enter SSID here
const char* password = "Your_Secret_Sauce";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,2,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

bool LEDstatus = LOW;
int red = 0;
int green = 0;
int blue = 0;
int selectedOption = 0;

void setup() {

    // put your setup code here, to run once:
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(175); // Set BRIGHTNESS to about 1/5 (max = 255)
  
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.on("/", handle_OnConnect);
  /*
  server.on("/ledon", handle_ledon);
  server.on("/ledoff", handle_ledoff);
  */
  server.on("/action_page", handleForm);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
    switch (selectedOption) {
      
    case 20:
      Serial.println("option20");
      stable(red,green,blue);
      break;
    case 1:
      Serial.println("Option1");
      option1();
      break;
    case 2:
      Serial.println("option2");
      firefly();
      break;
    case 3:
      Serial.println("option3");
      ring(red,green,blue);
      break;
    case 4:
      Serial.println("option4");
      ring2(red,green,blue);
      break;
     case 5:
      Serial.println("option5");
      flag();
      break;
     case 6:
      Serial.println("option6");
      chaser();
      break;
     case 7:
      Serial.println("option7");
      chaser2(red,green,blue);
      break;
     case 8:
      Serial.println("option8");
      colorBurst(red,green,blue);
      break;

     case 9:
      Serial.println("option9");
      colorWipe(strip.Color(red,green,blue), 50); // Red
      break;
     case 10:
      Serial.println("option10");
      theaterChase(strip.Color(red,green,blue), 50); // White, half brightness
      break;
     case 11:
      Serial.println("option11");
      rainbow(5);
      break;
     case 12:
      Serial.println("option12");
      rainDrops(red,green,blue);
      break;
     
    default:
      Serial.println("optionXX");
      break;
  }
}

void handle_OnConnect() {
  //LEDstatus = LOW;
  server.send(200, "text/html", SendHTML(false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

void colorConverter(String hexValue)
{
    String hexstring = hexValue;
    long number = (long) strtol( &hexstring[1], NULL, 16);
    red = number >> 16;
    green = number >> 8 & 0xFF;
    blue = number & 0xFF;

    Serial.print("red is ");
    Serial.println(red);
    Serial.print("green is ");
    Serial.println(green);
    Serial.print("blue is ");
    Serial.println(blue);

}
void handleForm() {
 selectedOption = server.arg("selection").toInt(); 
 String color = server.arg("color"); 
 
 Serial.print("selectedOption:");
 Serial.println(selectedOption);

 Serial.print("color:");
 Serial.println(color);

 colorConverter(color);
 
 String s = "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><a href='/'> Back to Homepage </a>";
 server.send(200, "text/html", s); //Send web page
}


String SendHTML(uint8_t led){
  String ptr = "<!DOCTYPE html>\n";
  ptr +="<html>\n";
  ptr +="<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
  ptr +="<head>\n";
  ptr +="<title>LED Cube</title>\n";
  ptr +="</head>\n";
  ptr +="<body style=\"font-family:Calibri;\">\n";
  ptr +="<h1 style=\"font-family:Calibri;\">&#127873; Hi There &#128105;<br>\n";
  ptr +="<h3 style=\"font-family:Calibri;\"> Brighten up your day &#127774; by selecting one of the options &#128071; &#129303;</h3><br>\n";
  
  /*
  ptr +="<p></p>\n";
  ptr +="<form method=\"get\">\n";
  if(led)
  ptr +="<input type=\"button\" value=\"LED OFF\" onclick=\"window.location.href='/ledoff'\">\n";
  else
  ptr +="<input type=\"button\" value=\"LED ON\" onclick=\"window.location.href='/ledon'\">\n";

  */
  ptr +="<form action=\"/action_page\">\n";
  /*
  ptr +="First name:<br>\n";
  ptr +="<input type=\"text\" name=\"firstname\" value=\"Mickey\">\n";
  ptr +="<br>\n";
  ptr +="Last name:<br>\n";
  ptr +="<input type=\"text\" name=\"lastname\" value=\"Mouse\">\n";
  ptr +="<br><br>\n";
  */
  ptr +="Pick your colour:\n";
  ptr +="<input type=\"color\" name=\"color\" value=\"#ff0000\">\n";
  ptr +="<br><br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=20 checked> Stable Color<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=1> Rainbow<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=2> Firefly<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=3> Ring<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=4> Ring 2<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=5> Flag<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=6> Chaser<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=7> Chaser 2<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=8> color Burst<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=9> color Wipe<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=10> Theater Chase<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=11> Rainbow Flow<br>\n";
  ptr +="<input type=\"radio\" name=\"selection\" value=12> Rain drops<br>\n";
  
  ptr +="<br><br>\n";
  ptr +="<input type=\"submit\" value=\"Light Up\">\n";

  
  ptr +="</form>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
