/* Maker: Gaspoz Jonathan
 * Date: 26.11.16
 * Infos: Virtualwire-Transmitter,
 * Le code suivant contrôle un Servo sur la pin2 avec un potentiomètre en pin analogique 0.
*/
#include wirtualwire.h
//Pin affectation
int potX=A2;
int potY=A3;
int Zbtn=2;  //autorise the acceleration
int Cbtn=0;  //maintain the speed
int gear=0; //speed of the Board
vw_set_tx_pin(1); //Transmitter pin
vw_setup(9600); //transmittion speed

enum{Zero, Const, Acc};
State=Zero;

case (State)
{
	Zero: 	if(Zbtn==1)
			{State=Acc}
			else
			{
				if(gear!=0)
				{gear -= 1;}
				 vw_send(buff, gear);
			}
			 break;
	Acc:	if()
	

