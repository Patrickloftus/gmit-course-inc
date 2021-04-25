// Name  : Patrick Loftus
// Lab   : Instrumentation & Control Final Lab
// Date  : 23-04-21
// Title : Stepper Control Lab 



// Creating a class for controlling the Stepper Motor

class astepper {

  private:

          byte pinA;
          byte pinB;
          byte pinC;
          byte pinD;

  public:

   astepper(byte pinA, byte pinB, byte pinC, byte pinD){

          this->pinA = pinA;
          this->pinB = pinB;
          this->pinC = pinC;
          this->pinD = pinD;

          pinMode(pinA,OUTPUT);
          pinMode(pinB,OUTPUT);
          pinMode(pinC,OUTPUT);
          pinMode(pinD,OUTPUT);
          
      }

 
// Reverse pins layout
 
void Reverse(int d,int c,int b,int a){

          digitalWrite(pinA,a);
          digitalWrite(pinB,b);
          digitalWrite(pinC,c);
          digitalWrite(pinD,d);
  }

 // Forward pins layout
 
void Forward(int a,int b,int c,int d){

          digitalWrite(pinA,a);
          digitalWrite(pinB,b);
          digitalWrite(pinC,c);
          digitalWrite(pinD,d);
  }

 
// Clockwise Direction

void StepForward(int DelayTime){ 

// Seq 1          A,B,C,D
          Forward(1,0,0,0);

          delay(DelayTime);
          
// Seq 2          A,B,C,D
          Forward(1,1,0,0);

          delay(DelayTime);
          
// Seq 3          A,B,C,D
          Forward(0,1,0,0);

          delay(DelayTime);
          
// Seq 4          A,B,C,D
          Forward(0,1,1,0);

          delay(DelayTime);
          
// Seq 5          A,B,C,D
          Forward(0,0,1,0);

          delay(DelayTime);
          
// Seq 6          A,B,C,D
          Forward(0,0,1,1);

          delay(DelayTime);
          
// Seq 7          A,B,C,D
          Forward(0,0,0,1);

          delay(DelayTime);
          
// Seq 8          A,B,C,D
          Forward(1,0,0,1);

          delay(DelayTime);

  }

// Counter Clockwise Direction

   void StepReverse(int DelayTime){ 
    
// Seq 1          A,B,C,D
          Reverse(1,0,0,0);

          delay(DelayTime);
          
// Seq 2          A,B,C,D
          Reverse(1,1,0,0);

          delay(DelayTime);
          
// Seq 3          A,B,C,D
          Reverse(0,1,0,0);

          delay(DelayTime);
          
// Seq 4          A,B,C,D
          Reverse(0,1,1,0);

          delay(DelayTime);
          
// Seq 5          A,B,C,D
          Reverse(0,0,1,0);

          delay(DelayTime);
          
// Seq 6          A,B,C,D
          Reverse(0,0,1,1);

          delay(DelayTime);

// Seq 7          A,B,C,D
          Reverse(0,0,0,1);

          delay(DelayTime);
          
// Seq 8          A,B,C,D
          Reverse(1,0,0,1);

          delay(DelayTime);

  }

  };
