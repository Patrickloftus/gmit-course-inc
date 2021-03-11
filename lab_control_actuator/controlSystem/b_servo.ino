
#include <Servo.h>

class servoActuator {
  private:
    byte pinID;
    unsigned long timeOn;

Servo testServo;
     
  public:
 
    servoActuator(byte pinVal,unsigned long interval) {
      this->pinID = pinVal;
      this->timeOn = interval;
      pinMode(pinID, OUTPUT);
    }
 
    void setAngle(int angle){
     //Set values

testServo.attach (pinID);
angle = map(angle,0,1023,0,180);
testServo.write(angle);
delay (timeOn);

     
     }
};
