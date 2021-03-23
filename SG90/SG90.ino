
#include<Arduino.h>


void setup()
{

  //SG90 50 Hz de.
    DDRB |=(1<<PB1);//PB1 çıkış olarak ayarlandı.Bu pin OC1A pini.Digital Pin 9.
    TCNT1=0;
    ICR1=4999;//TOP Değeri 20 ms 50 hz için.
    TCCR1A=(1<<WGM11) | (1<<COM1A1);//OC1A pinin oldğu yer.
    TCCR1B=(1<<WGM13) | (1<<WGM12) |(1<<CS11) | (1<<CS10);

}


void loop()
{

  //16mhz/64(prescaler)=250khz=4us
  //0,6 ms -90 derece için pulse width.600 us
  OCR1A=150;//600/4 
  delay(1000);//1,5ms 0 derece için.1500/4 ;Aynı formülde bu değer konulur.
  OCR1A=375;
  delay(1000);
  OCR1A=600;//2,4 ms 90 derece.2400/4
  delay(1000);
  
  
}
