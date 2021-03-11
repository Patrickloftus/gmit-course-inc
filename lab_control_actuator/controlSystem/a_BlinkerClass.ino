

class Blinker {

private:
byte pinLED;

boolean ledState = LOW;
unsigned long timeLedOn;
unsigned long timeLedOff;

unsigned long nextChangeTime = 0;

public:
Blinker(byte pinLEDTmp, unsigned long timeLedOnTmp, unsigned long timeLedOffTmp)
{
      pinLED = pinLEDTmp;
      timeLedOn = timeLedOnTmp;
      timeLedOff = timeLedOffTmp;

pinMode (pinLED, OUTPUT);

}

//checks when it is time to turn on or off the LED

void check (){
  unsigned long currentTime = millis();

  if(currentTime >= nextChangeTime) {

    if(ledState) {
                            // if the LED is on then turn off the LED
      ledState = LOW;
      nextChangeTime = currentTime + timeLedOff;
      
    }
    else{                   // if the LED is off then turn ON the LED
    ledState = HIGH;
    nextChangeTime = currentTime + timeLedOn;
  }

  digitalWrite (pinLED, ledState);

  }

}


};
