
#define DDR_SPI DDRB
#define DD_MISO PINB4
#define DD_MOSI PINB3
#define DD_SCK PINB5
#define DD_SS PINB2
unsigned char data;
#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>

void SPI_Slave(void);
unsigned char  SPI_Slave_Al(void);



int main(void)
{
DDRD |=(1<<PIND7); //led output.
SPI_Slave();


while(1)
{
 
 data= SPI_Slave_Al();

 if(data=='1')
 {
   PORTD |=(1<<PIND7);
 }
 else if(data=='0')
 {
   PORTD &=~(1<<PIND7);
 }
 

}

}

void SPI_Slave()
{
    DDR_SPI |=(1<<DD_MISO);
    DDR_SPI &=~(1<<DD_MOSI);
    DDR_SPI &=~(1<<DD_SCK);
    DDR_SPI &=~(1<<DORD);
    DDR_SPI &=~(1<<MSTR);
    DDR_SPI &=~(1<<CPOL);
    DDR_SPI &=~(1<<DD_SS);//SS İNPUT.
    SPCR |=(1<<SPE)|(1<<SPR1)|(1<<SPI2X);//|(1<<SPR0)
 
}
unsigned char SPI_Slave_Al()
{
 
     while(!(SPSR & (1<<SPIF)));
     return SPDR;
}
