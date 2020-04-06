
#include <SoftwareServo.h>
//affecatation des pins
int potentiometer=A2;
int button1=2;
int button2=0;
//déclaration des variables globales
int potval;
int curval;  //commande ESC
int deadt;  //temps mort
SoftwareServo ESC;

void setup() 
{
  //Initialisation du port
  DDRB=B00000010; //output:MISO
  curval=0;
  deadt=1;
  ESC.attach(1);
  ESC.setMinimumPulse(800);
  ESC.setMaximumPulse(2000);
}

void loop()
{
  while (digitalRead(button1)==HIGH)  //btn1 autorise l'accélération
  {    
    potval=analogRead(potentiometer);
    potval=map(potval,0,1023,0,180);
    
    while(curval<potval)  //accélère
    {
      potval=analogRead(potentiometer);
      potval=map(potval,0,1023,0,180);
      curval=curval+1;
      ESC.write(curval);
      SoftwareServo::refresh();
      delay(deadt);
      
      while(digitalRead(button2)==HIGH) //maintient de la vitesse
      {
        ESC.write(curval);
        SoftwareServo::refresh();
      }
    }
  
    while(curval>potval)  //décélère
    {
      potval=analogRead(potentiometer);
      potval=map(potval,0,1023,0,180);
      curval=curval-1;
      ESC.write(curval);
      SoftwareServo::refresh();
      delay(deadt);
      
      while(digitalRead(button2)==HIGH) //maintient la vitesse
      {
        ESC.write(curval);
        SoftwareServo::refresh();}
      } 
    ESC.write(curval);
    SoftwareServo::refresh();
  }
  //décélération si le btn1 est relaché
  potval=0; 
  while(curval>potval)
  {
    curval=curval-1;
    ESC.write(curval);
    SoftwareServo::refresh();
    delay(deadt);
  }
  ESC.write(curval);
  SoftwareServo::refresh();
}
    

  




