

#include <avr/io.h>


bool deger=false;
int basilma_suresi=0;
int birakilma_suresi=0;

int main()
{

 DDRD &=~(1<<PIND2);
 PORTD &=~(1<<PIND2);

 
 DDRD |=(1<<PIND3);
 DDRD |=(1<<PIND4);
 

 
EICRA |=(1<<ISC01);
EICRA  |=(1<<ISC00);//RİSİNG.

EIMSK |=(1<<INT0);//INT0 AKTİF.

//SREG |=(1<<7);
sei();


 while(1)
 {




 if(!deger)//false
 {
  PORTD |=(1<<PIND3);
  PORTD &=~(1<<PIND4);
   
  
  

 }

 else//true
 {
  PORTD |=(1<<PIND4);
  PORTD &=~(1<<PIND3);
 
 }
   
 
 
 




}
}

ISR(INT0_vect)
{

 basilma_suresi++;
 birakilma_suresi=0;
 if(basilma_suresi>=500)
 {
   if(!deger)
   {}
 }
 


 switch(deger)
 {
  case true:
   deger=false;
   break;

   case false:
   deger=true;
   break;
 }
  
 

  

}
