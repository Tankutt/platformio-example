#include <Arduino.h>

char *strings[3];
char *ptr = NULL;
String recievedMessage="";
String firstPart="";
String secondPart="";
unsigned long previousMillis = 0;
int interval;
int led1=8;

void setup() 
{
  pinMode(led1,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if(Serial.available()>0)
  {
    recievedMessage = Serial.readString();
    unsigned long currentMillis = millis();

    int index=0;
    char reserve[10];
    String cloneRecievedMessage;

    recievedMessage.toCharArray(reserve,10);
    ptr = strtok(reserve,",");

    while(ptr != NULL)
    {
      strings[index] =ptr;
      index++;
      ptr = strtok(NULL,",");
    }

    firstPart=strings[0];
    secondPart=strings[1];

    if(firstPart == "L")
    {
      if(secondPart== "1")
      {
        digitalWrite(led1,HIGH);
        Serial.println("ON");     
      }
      else if (secondPart == "0" )
      {
        digitalWrite(led1,LOW);
        Serial.println("OFF");  
      }
    }
    else if(firstPart == "T")
    {
      interval=secondPart.toInt();
      if (currentMillis - previousMillis >= interval)
      {
        previousMillis = currentMillis;
      }
      Serial.println("feedback"); 
    }
  
 
}