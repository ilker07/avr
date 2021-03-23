#include <avr/io.h>
#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU / (9600 * 16UL))) - 1)

unsigned char gelen_data;
uint8_t a,b,c;

void USART0Init(void)
{
UBRR0H=(uint8_t)(UBRR_VALUE>>8);
UBRR0L=(uint8_t)UBRR_VALUE;
UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);//8 bit veri için
UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
}
void USART0SendByte(unsigned char  u8Data)
{
while(!(UCSR0A&(1<<UDRE0))){}
UDR0 = u8Data;
}
unsigned char   USART0ReceiveByte()
{
while(!(UCSR0A&(1<<RXC0))){}
return UDR0;
}
int main (void)
{
DDRD |=(1<<PIND7);
USART0Init();

//char harf=a/10+'0';

//char harf2=a%10+'0';

//USART0SendByte(gelen_data);
while(1)
{
  
USART0SendByte('1');
_delay_ms(1000);
USART0SendByte('0');
_delay_ms(1000);

/*
sprintf(gelen_data, "%d  ",atoi(USART0ReceiveByte())); 
USART0SendByte(gelen_data);*/

//USART0SendByte(harf2);

}
}
