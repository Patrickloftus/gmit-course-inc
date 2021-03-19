
#include <PID_v1.h>            // INCLUDING THE PID LIBARY


double Setpoint;               // PID Setpoint
double photocellReading;       // input
double ledBrightness;          // output
                                                                        // Tuning the PID LOOP
double kp = .1,                  ki = 10,                kd = .012;     // THESE VALUES WERE ALL AT ZERO AT THE BEGINNING UNTIL FOUND SUITABLE VALUES TO WORK SMOOTHLY

// proportional gain           // integral gain        // derivative gain           


//Pin definations

#define photocellPin 1
#define ledPin 5



#define PIN_Anologue A0 // defining the analog pin (lightsensor)
#define PIN_LED1 3   // defining the  LED pin
#define servoPin 9   // defining the servo pin     // NOT USED IN THIS PROJECT

#define RELAY1 4   // defining the relay


// setting up the PID

PID myPID (&photocellReading, &ledBrightness, &Setpoint, kp, ki, kd, DIRECT);


// CLASS VARIABLES DECLARATION

//Passes data to the class constructor

Blinker blink1 = Blinker(PIN_LED1, 10000, 10000);
LightSensor Light1 = LightSensor(PIN_Anologue, 10);
//ServoMotor servomotor1 = ServoMotor(servoPin,1);  // NOT USED IN THIS PROJECT
  
void setup() {
//sets the serial monitor to 9600 baud rate
Serial.begin(9600); 


Setpoint = 600; // VALUE FROM LIGHTSENSOR

myPID.SetMode(AUTOMATIC);
myPID.SetTunings (kp, ki, kd);
delay (1000);



}



void loop() {
//calls blinking led program  
  blink1.check();
//calls Light sensor program  
 Light1.DataConvert();

//Prints out the resulting voltage and analog readings to the screen on the serial monitor
 // Serial.print("Voltage :"); Serial.print(Light1.getvoltage());
 Serial.println(" ");Serial.print("Analog reading :");Serial.print(Light1.getsensorValue()); Serial.print(" ");


pinMode(RELAY1, OUTPUT);                   // TURNING ON / OFF RELAY DEPENDING ON THE VALUE OF THE LIGHTSENSOR

 if (Light1.getsensorValue () >=500){     // calling our sensor value from light sensor

  Serial.println("Light ON");             // displays the text LIGHT ON in serial monitor
  digitalWrite(RELAY1, HIGH);            // turns on relay 
 }
 else{
  Serial.println("Light OFF");            // displays the text LIGHT OFF in serial monitor
  digitalWrite(RELAY1, LOW);              // turns off relay
 }


photocellReading = analogRead (photocellPin);
myPID.Compute() ;
analogWrite (ledPin,ledBrightness);

Serial.print("Analog reading :");Serial.println(photocellReading);




delay(100);                               // scanning delay 






 
 }

 //calls servo motor control using depth sensor values          // NOT USED IN THIS PROJECT
  //servomotor1.ServoAngle(Depth1.getsensorValue());
