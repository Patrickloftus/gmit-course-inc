
#define PIN_LED1  3
#define PIN_LED2  4
#define PIN_ANALOG  A0


Blinker blink1 = Blinker (PIN_LED1,100,100);
Blinker blink2 = Blinker (PIN_LED2,200,200);
DepthSensor  ;

float getValue  ;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}


void depth (); 

void loop (){

   blink1.check ();
   blink2.check ();
 
}
