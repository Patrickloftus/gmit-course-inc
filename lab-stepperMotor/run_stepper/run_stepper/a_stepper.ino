// Name  : Patrick Loftus
// Lab   : Instrumentation & Control Final 
// Date  : 23-04-21
// Title : Stepper Control Lab 



// declaring our pins used for control of stepper

#define PinA 8
#define PinB 9
#define PinC 10
#define PinD 11
            
// declaring the analog pin used for speed control

#define SpeedControlPot A1
            
// declaring the pins used for moving the stepper in the forward direction and backwards direction

#define DirectionForwardPushButton 6
#define DirectionReversePushButton 7
                        
#define NUMBER_OF_STEPS_PER_REV 512

  


        int MotorSpeed = 0;
        int DirectionForwardPushButtonState = 0;
        int DirectionReversePushButtonState = 0;

        astepper motorStep = astepper(PinA ,PinB ,PinC ,PinD);

 void setup() {

        pinMode(DirectionForwardPushButton,INPUT);
        pinMode(DirectionReversePushButton,INPUT);

  }


 void loop() {

        // checking the status of the Forward and Reverse pushbuttons
        
        DirectionForwardPushButtonState = digitalRead(DirectionForwardPushButton);
        DirectionReversePushButtonState = digitalRead(DirectionReversePushButton);

       

        //If the pushbutton is pressed ButtonState goes High

        if(DirectionForwardPushButtonState == HIGH){

         //Motor runs in Forward Direction for no of steps (512)

        for(int i = 0;i < NUMBER_OF_STEPS_PER_REV; ++i){

              MotorSpeed = analogRead(SpeedControlPot);

              float Speed = MotorSpeed * (5.0/1023);

              motorStep.StepForward(Speed);

          }

        }

       
        //If the pushbutton is not pressed ButtonState goes Low

        if(DirectionReversePushButtonState == HIGH){

        
        //Motor runs in Reverse Direction for no of steps (512)

        for(int i = 0;i < NUMBER_OF_STEPS_PER_REV; ++i){

              MotorSpeed = analogRead(SpeedControlPot);

              float Speed = MotorSpeed * (5.0/1023);

              motorStep.StepReverse(Speed);   

          }

        }

  }
