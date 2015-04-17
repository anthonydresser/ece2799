#include <IRremote.h>

#define  LIGHTON  3616899642
#define  LIGHTOFF  3101042659
#define  LIGHTTOGGLE  03
#define  FANON  3084265038
#define  FANOFF  1404231385
#define  FANTOGGLE  05

int IRpin = P2_4;
int LED1 = 9;
int LED2 = 10;
IRrecv irrecv(IRpin);
decode_results results;
int lightState;
int fanState;

void setup()
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, 0);
  lightState = 0;
  digitalWrite(LED1, 0);
  fanState = 0;
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
  {
    switch (results.value) {
    case LIGHTON:
      digitalWrite(LED1, 1);
      lightState = 1;
      digitalWrite(LED2, fanState);
      break;
    case LIGHTOFF:
      digitalWrite(LED1, 0);
      lightState = 0;
      digitalWrite(LED2, fanState);
      break;
    case FANON:
      digitalWrite(LED2, 1);
      fanState = 1;
      digitalWrite(LED1, lightState);
      break;
    case FANOFF:
      digitalWrite(LED2, 0);
      fanState = 0;
      digitalWrite(LED1, lightState);
      break;
    case LIGHTTOGGLE:
      if(lightState = 1)
        lightState = 0;
      else
        lightState = 1;
      digitalWrite(LED1, lightState);
    case FANTOGGLE:
      if(fanState = 1)
        fanState = 0;
      else
        fanState = 1;
    }
    Serial.println(results.value, DEC); // Print the Serial 'results.value'
    irrecv.resume();   // Receive the next value
  }
}




