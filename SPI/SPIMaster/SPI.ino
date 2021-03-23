//trsnsmitter

#define DDR_SPI DDRB
#define DD_SS PINB2 //Master ss digital pin 10
#define DD_SCK PINB5
#define DD_MISO PINB4
#define DD_MOSI PINB3
 

#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>

void SPI_Master(void);
void SPI_Master_Gonder(unsigned char data);


int main(void)
{
SPI_Master();

while(1)
{
   PORTB &=~(1<<DD_SS);
    SPI_Master_Gonder('0');
    _delay_ms(1000);
     SPI_Master_Gonder('1');
    _delay_ms(1000);
    PORTB |=(1<<DD_SS);
    _delay_ms(1000);
    
}

}

void SPI_Master()
{
    DDR_SPI |=(1<<DD_MOSI)| (1<<DD_SCK)|(1<<DD_SS)|(1<<CPHA);
    DDR_SPI &=~(1<<DD_MISO);
    DDR_SPI &=~(1<<SPIE);
    DDR_SPI &=~(1<<DORD);
    DDR_SPI &=~(1<<CPOL);
    SPCR=(1<<SPE) | (1<<MSTR) | (1<<SPR0);//SPR0 FOSC/16
    PORTB |=(1<<DD_SS);//SS HİGH
   
}
void SPI_Master_Gonder(unsigned char data) 
{
    SPDR=data;
    while(!(SPSR & (1<<SPIF)));
}
