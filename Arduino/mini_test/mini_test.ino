#include <IRremote.h>

#define  LIGHTON  1752382022
#define  LIGHTOFF  3863406368
#define  FANON  2491031974
#define  FANOFF  3600444111

int IRpin = 14;
int LED1 = 10;
int LED2 = 11;
IRrecv irrecv(IRpin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, 0);
  digitalWrite(LED1, 0);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
  {
    switch (results.value) {
      case LIGHTON:
        digitalWrite(LED1, 1);
        break;
      case LIGHTOFF:
        digitalWrite(LED1, 0);
        break;
      case FANON:
        digitalWrite(LED2, 1);
        break;
      case FANOFF:
        digitalWrite(LED2, 0);
        break;
    }
    Serial.println(results.value, DEC); // Print the Serial 'results.value'
    irrecv.resume();   // Receive the next value
  }
}
