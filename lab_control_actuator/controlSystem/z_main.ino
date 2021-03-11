

//DECLARATION OF PINS

#define PIN_LED 4
#define PIN_ID A1
#define PIN_SERVO 9

//DECLARATION OF CLASSES

Blinker blinker = Blinker (PIN_LED, 500, 500);
depthSensor testDepthSensor(PIN_ID,50);
servoActuator testServo = servoActuator (PIN_SERVO,50);


void setup() {
  Serial.begin (9600);    // opens the comms for serial port at 9600 bps
}


void loop(){

  blinker.check();        //  Runs the flashing LED proram, BlinkerClass
  
  testDepthSensor.check(); // Runs the Depth Sensor program, depthSensor

  testServo.setAngle(testDepthSensor.getValue());  // runs the servo motor program, servo
  
  Serial.println(testDepthSensor.getDepth());
  Serial.print(" ");


   int val = analogRead(1);
  val = map(val, 1023, 0, 0, 255);
  
  delay (200);
  analogWrite(9, val); 

  
}
