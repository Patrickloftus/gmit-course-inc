 class depthSensor {​​​​

  private:

    byte pinID;

    unsigned long timeOn;

    unsigned long nextChangeTime = 0;

    int val = 0;  // variable to store the value read

    float voltage= 0;

    float  distance =0;

  public:

  //Constructor for class

    depthSensor(byte pinVal,unsigned long interval) {​​​​

      this->pinID = pinVal;

      this->timeOn = interval;       pinMode(pinID, INPUT);

    }​​​​     //Calculations

    void check() {​​​​

      unsigned long currentTime = millis(); //system clock 

      //check the interval of time has passed, 50ms

      if(currentTime >= nextChangeTime) {​​​​

          val = analogRead(pinID);  // read the input pin

          // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

          voltage = val * (5.0 / 1023.0);

          distance =-22*voltage+60;

          //update the next time var

          nextChangeTime = currentTime + timeOn;

      }​​​​

    }​​​​     float getValue(){​​​​

        return voltage;

     }​​​​     float getDepth(){​​​​

        return distance;

     }​​​​       

}​​​​;
