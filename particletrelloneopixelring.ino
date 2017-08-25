#include "neopixel.h"


SYSTEM_MODE(AUTOMATIC);
#define PIXEL_COUNT 36
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2812B
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


int trellotall = 0;
Timer timer(600000, trelloTimer);

void setup() {
Particle.function("TrelloComand", TrelloComand);
strip.begin();
timer.start();
}

void loop() {
TrelloView();
strip.show();
}


void trelloTimer()
{
 Particle.publish("trello", "");
}



int TrelloComand(String command){
    int number = command.toInt();
    
    if(number != NULL){
        //Minus one because of troubles passing 1.
        number = number - 1;
        trellotall = number;
        return 1;
    }
}

void TrelloView(){
  int lysstart;
  lysstart = 0 + trellotall;
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
