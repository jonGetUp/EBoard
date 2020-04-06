#include <SoftwareServo.h>
int potentiometer=A7;
int potval; //Sélection de la vitesse
int curval; //pente, delay

SoftwareServo ESC;

void setup() {
  
  pinMode(potentiometer, INPUT);
  ESC.attach(9);       //...  
  Serial.begin(9600);  
  curval=0;
  ESC.setMinimumPulse(800); //...fonction servo?
  ESC.setMaximumPulse(2000);
}

void loop() {

  potval=analogRead(potentiometer);
  potval=map(potval,0,1023,0,180); //10bits, 0 à 180d ?
  
  while(curval<potval){
    potval=analogRead(potentiometer);
    potval=map(potval,0,1023,0,180);
    curval=curval+1;
    ESC.write(curval);
    SoftwareServo::refresh(); //...?
    Serial.println(curval);
    delay(50);}

  while(curval>potval){
    potval=analogRead(potentiometer);
    potval=map(potval,0,1023,0,180);
    curval=curval-1;
    ESC.write(curval);
    SoftwareServo::refresh();
    Serial.println(curval);
    delay(50);}

    ESC.write(curval);
    SoftwareServo::refresh();
    Serial.println(curval);
}

