#include <IRremote.h>


// C++ code
//

IRrecv irrecv(A0); 			   // pin with IR-reciver 
decode_results results;		   // result of IR	

int curr_led = 3;              // current no pin with led
  
void setup()
{
  irrecv.enableIRIn();		   // reciving the IR-signal
  
  for(int i = 3; i <= 13; i++) // set an output mode for LED
  {
    pinMode(i,OUTPUT);
  }
  
  pinMode(A0, INPUT);          // input mode for IR-reciver  
}

void loop()
{
  while(irrecv.decode(&results) or curr_led != 14)
  {
    digitalWrite(curr_led,1);
    curr_led++;
    delay(500);    
  }
}