/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

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
