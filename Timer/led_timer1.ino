

#include <avr/io.h>
#define led PIND7

int deger=0;

ISR(TIMER1_COMPA_vect){

  deger++;
  if(deger==1000)
  {
     PORTD ^=(1<<led);
     deger=0;
      //   PORTD ^=(1<<PIND4);
         
  }

  
   }




int main(void)
{


DDRD |=(1<<led);//LED1 OUTPUT

PORTD |=(1<<led);//LED1 YANAR



//CTC MOD VE PRESCALER AYARLARI.256 prescaler
TCCR1A &= ~(1<<WGM11);
TCCR1A &= ~(1<<WGM10);

TCCR1B &= ~(1<<WGM13);
TCCR1B |= (1<<WGM12);
TCCR1B |= (1<<CS12);
TCCR1B &= ~(1<<CS11);
TCCR1B &= ~(1<<CS10);


//CTC MOD VE PRESCALER AYARLARI.

OCR1A=61; // 1 snde bir ISR YE girer.62499
TIMSK1 |=(1<<OCIE1A);//interrupt aktif..
sei();

while(1)
{

}


}
