// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>


SYSTEM_MODE(AUTOMATIC);

#define PIXEL_COUNT 12
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
//Set timer for publishing event every 10 minutes
Timer timer(600000, trelloTimer);
int trellotall = 0;

    void setup(){
    timer.start();
    strip.begin();
    }
    
    void loop(){
    TrelloView();
    strip.show();    
    }
    
    //Publishing the event that triggers the webhook
    void trelloTimer(){
    Particle.publish("trello", "");
    }
    
    int TrelloComand(String command){
    //Converting to int
    int number = command.toInt();
    
    if(number != NULL){
        //Minus one because of troubles passing 0.
        number = number - 1;
        trellotall = number;
        return 1;
    }
    }
    
    void TrelloView(){
  int lysstart;
  lysstart = trellotall;
  if(trellotall <= 0){
   trellotall = 0;      
   for (int i=0; i <= 11; i++){
        strip.setPixelColor(i, strip.Color(0, 0, 0));
       
  }
  
  }
  
  
  if(trellotall > 0){
      for (int i=0; i <= 11; i++){
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        
  }
      for (int i=0; i <= lysstart; i++){
        strip.setPixelColor(i, strip.Color(255, 0, 255));
        
    }
  }
    
  
      
} 
