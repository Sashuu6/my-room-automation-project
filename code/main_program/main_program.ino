//  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄         ▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄ 
// ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌
// ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀ 
// ▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌          
// ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄ 
// ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌
//  ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌
//           ▐░▌▐░▌       ▐░▌          ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌
//  ▄▄▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌ ▄▄▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌
// ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌
//  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀ 
// Name: Sashwat K
// Code: Home automation using particle.io and IFTTT
// Created on: 15 Nov 2018
// Revision: 2
// Variables used
// relayTubelight (Tube Light) - integer - D0 (GPIO4)
// relayBulb (Bulb) - integer - D1 (GPIO17)
// vinTube - boolean - on/off states for tubelight
// vinBulb - boolean - on/off states for bulb
                                                                                           
int relayTubelight = D0; //pin to which relay is connected
int relayBulb = D1;
bool vinTube = HIGH; //a virtual boolean variable
bool vinBulb = HIGH; //a virtual boolean variable

// setup() is run only once, it's where we set up GPIO and initialise peripherals
void setup() {
    
  // Setup GPIO
  pinMode(relayTubelight,OUTPUT); // relay pin is set as output
  digitalWrite(relayTubelight,LOW);
  
  pinMode(relayBulb,OUTPUT); // relay pin is set as output
  digitalWrite(relayBulb,LOW);
  // Subscribe to events published by IFTTT using Particle.subscribe
  Particle.subscribe("eventTubeLightOn", tubeOffHandler); //turning tube light on function declaration
  Particle.subscribe("eventTubeLightOff", tubeOnHandler); //turning tube light off function declaration
  
  Particle.subscribe("eventBulbOn", bulbOffHandler); //turning bulb on function declaration
  Particle.subscribe("eventBulbOff", bulbOnHandler); //turning bulb off function declaration
}

// loop() runs continuously, it's our infinite loop.
void loop() {
     if (vinTube==HIGH) {
         digitalWrite(relayTubelight,LOW); // make light off
     }
else if (vinTube==LOW) {
         digitalWrite(relayTubelight,HIGH);
     }
     if (vinBulb==HIGH) {
         digitalWrite(relayBulb,LOW);
     }
else if (vinBulb==LOW) {
         digitalWrite(relayBulb,HIGH);
     }

}

//our events are called when IFTTT applets are triggered
void tubeOffHandler(const char *event, const char *data) {
    vinTube=LOW;
}
void tubeOnHandler(const char *event, const char *data) {
     vinTube=HIGH;
}

void bulbOffHandler(const char *event, const char *data) {
    vinBulb=LOW;
}
void bulbOnHandler(const char *event, const char *data) {
     vinBulb=HIGH;
}