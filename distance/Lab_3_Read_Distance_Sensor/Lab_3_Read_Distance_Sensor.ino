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

   int sensorValue = analogRead(A0);     
   float voltage = sensorValue * (5.0 / 1023.0);  
   Serial.print("X,"); Serial.print(voltage); Serial.print("  ");   
   Serial.println(" ");
   delay(200);
  // note that if you change the serial print to sensorValue you can see the real value from the sensor
 // note also to add the delay and notice changes on input speed 
}
