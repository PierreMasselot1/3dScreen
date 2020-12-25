#include <Arduino_FreeRTOS.h>
int ledPin =  13;     
int ledState = LOW; 
int stepperState =LOW;
unsigned long previousMicro = 0;
unsigned long previousMicro1 = 0;
long OnTime = 750;          
long OffTime = 750;
long xrefreshrate=10000;
long delaystepper=10000;
int x=0;
float xpos=0;
int xt =0;
int xabs=0;
char data[10];
const int stepPin = 3; 
const int dirPin = 4; 
void TaskBlink( void *pvParameters );
void TaskAnalogRead( void *pvParameters );
void setup() {
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT); 
  digitalWrite(dirPin,HIGH);  
  while (!Serial) {
    ; 
  }
  xTaskCreate(
    TaskBlink
    ,  (const portCHAR *)"Blink"   
    ,  128  
    ,  NULL
    ,  2  
    ,  NULL );
  xTaskCreate(
    TaskAnalogRead
    ,  (const portCHAR *) "AnalogRead"
    ,  128  
    ,  NULL
    ,  2  
    ,  NULL );
}
void loop()
{
 
}

void TaskBlink(void *pvParameters)  
{
  (void) pvParameters;
  for (;;) 
  {
     unsigned long currentMicro = micros();
if(currentMicro-previousMicro1 >= xrefreshrate){
previousMicro1 = currentMicro;
String input;
int i = 0;
while (i < 10)
{ while (!Serial.available()> 0) {}
 data[i++] = Serial.read();
 x = atol(data);
}
 
if (x<-10){
  digitalWrite(dirPin,LOW);}
  
if (x>10){
  digitalWrite(dirPin,HIGH);}
  }

  }
}

void TaskAnalogRead(void *pvParameters) 
{
  (void) pvParameters;


  for (;;)
  { unsigned long currentMicro = micros();
  if(x>50||x<-50){
//xabs=abs(x);
//xpos=50000/xabs;
//delaystepper=long(xpos);
//xt=xpos*20;
//delaystepper=long(xt);
if((stepperState == HIGH) && (currentMicro - previousMicro >= delaystepper))
  {
    stepperState = LOW;  
    previousMicro = currentMicro;  
    digitalWrite(stepPin, stepperState); 
  }
  else if ((stepperState == LOW) && (currentMicro - previousMicro >= delaystepper))
  {
    stepperState = HIGH; 
    previousMicro = currentMicro;   
    digitalWrite(stepPin, stepperState);   
  }}
  }}



