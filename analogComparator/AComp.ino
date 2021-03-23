

#include <avr/io.h>

#include<Arduino.h>
#include <util/delay.h>


volatile boolean tetiklendi_mi=false;

ISR(ANALOG_COMP_vect)
{
    tetiklendi_mi=true;
}



int main(void)
{
ADCSRB=0;
ACSR &=~(1<<ACI);
ACSR |=(1<<ACIE);
ACSR |=(1<<ACIS1);//Düşen Kenar.
Serial.begin(9600);

 while(1)
 {
     if(tetiklendi_mi)
     {
         Serial.println("Tetiklendi.")
         tetiklendi_mi=false;
     }
   
 }


}