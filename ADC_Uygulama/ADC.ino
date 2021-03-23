
#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>
int ADC_fonksiyon(void);

int main(void)
{

    DDRD |=(1<<PIND7);//LED 
    ADCSRA |=(1<<ADEN) ;//ENABLE AKTİF.
    ADCSRA |=(1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);//128 PRESCALER .16 000 000/50 000=320 ;16 000 000/200 000=80  80 ile 320 arası olmalı.
    ADMUX |=(1<<REFS0); //voltaj referans seçimi.
    ADMUX |= 0x00;// 0000  A0 pini.

while(1)
{
 int deger= ADC_fonksiyon();

 if(deger>600)
 PORTD |=(1<<PIND7);
 else
  PORTD &=~(1<<PIND7);
  
  
   
}



}

int ADC_fonksiyon()
{
     ADCSRA |=(1<<ADSC);//DÖNÜŞÜM BAŞLADI.
     while(ADCSRA & (1<<ADSC));//0 OLDUĞUNDA DÖNÜŞÜM BİTER.
     return ADCW;//10 bit.ADCH+ADCL

}
