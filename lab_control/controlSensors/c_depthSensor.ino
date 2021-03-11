


/*
 * BLINKER CLASS DEFINITION
 
class DepthSensor 
{
  private:
    byte pin_Analog;

    boolean ledState = LOW;

    unsigned long timeOn;
    unsigned long nextChangeTime = 0;

    int value = 0;
    


  public:
  
    DepthSensor(byte pin_val, unsigned long sampletime)
    {
      this->pin_Analog = pin_val;
      this->timeOn = sampletime;
      

      pinMode(pin_Analog, INPUT);
    }




// the loop routine runs over and over again forever:
void depth () {



   int sensorValue = analogRead(A0);              // we are reading in our signal from the distance sensor into analog pin 0
   float voltage = sensorValue * (5.0 / 1023.0);  // we are converting our analog sensorvalue from ADC to voltage
    
    // y = mx + c  // formula for slope of line
    
   float distance = -22.883*voltage+62.143;  // we are doing this formula to calibrate our distance sensor
                                            // voltage is now been converted to a distance
                                            
   
   Serial.print("X,"); Serial.print(distance); Serial.print("  ");   
   Serial.println(" ");
   delay(200);
   
  // note that if you change the serial print to sensorValue you can see the real value from the sensor
  // note also to add the delay and notice changes on input speed 
  // after calibration there was a much steadier reading on the serial plotter
  // noticed how as you move the sensor closer to the material i was hitting a deadzone


  // this was a interesting online lab, thanks stephen
}




    // Checks whether it is time to turn on or off the LED.
    void check() {
      unsigned long currentTime = millis();

      if(currentTime >= nextChangeTime) 
      
      {

          // Read Sensor value
          
          nextChangeTime = currentTime + timeOn;
          
        }

      
           
        

        
      
    }  
};

*/
