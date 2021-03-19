//Pin definations

#define PIN_Anologue A0 // defining the analog pin (lightsensor)
#define PIN_LED1 3   // defining the  LED pin
#define servoPin 9   // defining the servo pin

#define RELAY1 4   // defining the relay



// CLASS VARIABLES DECLARATION

//Passes data to the class constructor
Blinker blink1 = Blinker(PIN_LED1, 10000, 10000);
LightSensor Light1 = LightSensor(PIN_Anologue, 10);
//ServoMotor servomotor1 = ServoMotor(servoPin,1);
  
void setup() {
//sets the serial monitor to 9600 baud rate
Serial.begin(9600); 
}



void loop() {
//calls blinking led program  
  blink1.check();
//calls Light sensor program  
 Light1.DataConvert();

//Prints out the resulting voltage and analog readings to the screen on the serial monitor
 // Serial.print("Voltage :"); Serial.print(Light1.getvoltage());
 Serial.println(" ");Serial.print("Analog reading :");Serial.print(Light1.getsensorValue()); Serial.print(" ");


pinMode(RELAY1, OUTPUT);

 if (Light1.getsensorValue () >=500){     // calling our sensor value from light sensor

  Serial.println("Light ON");             // displays the text LIGHT ON in serial monitor
  digitalWrite(RELAY1, HIGH);            // turns on relay 
 }
 else{
  Serial.println("Light OFF");            // displays the text LIGHT OFF in serial monitor
  digitalWrite(RELAY1, LOW);              // turns off relay
 }

delay(500);                               // scanning delay 
 
 }

 //calls servo motor control using depth sensor values
  //servomotor1.ServoAngle(Depth1.getsensorValue());
