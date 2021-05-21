char temp,tickets=100;
void show(void);
void display(void);
void ISSUE() iv IVT_ADDR_INT0 ics ICS_AUTO 
{
    tickets--;
    do
    {
        display();
    }while(UDRE_BIT==0);
    UDR=tickets;
    do
    {
        display();
    }while(TXC_BIT==0);
}

void UPDATE() iv IVT_ADDR_USART_RXC ics ICS_AUTO 
{
    tickets=UDR;
}
void main() 
{
    PORTD=0XFF;
    DDRD=0X00;
    PORTA=0X00;
    DDRA=0XFF;
    PORTB=0XFF;
    DDRB=0X0F;
    
    UBRRH=0X00;  //Value for a Baud rate=9600 with 16MHz Crystal
    UBRRL=0X67;
    //  0B10011000 indicates binary value
    //RXCIE TXCIE UDRIE RXEN TXEN UCSZ2 RXB8 TXB8
    UCSRB=0B10011000;
    //URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL
    UCSRC=0X86;
    //Enable INT0
    GICR=0X40;
    //Enable external interrupt INT 0 for High to Low transition
    MCUCR=0X02;
    
    SREG_I_BIT=1;
    
    while(1)
    {
        display();
    }
}

void display(void)
{
    temp=tickets/1000;
    PORTB=0X07;
    show();
    Delay_ms(1);
    PORTA=0X00;
    
    temp=(tickets%1000)/100;
    PORTB=0X0B;
    show();
    Delay_ms(1);
    PORTA=0X00;
    
    temp=(tickets%100)/10;
    PORTB=0X0D;
    show();
    Delay_ms(1);
    PORTA=0X00;
    
    temp=tickets%10;
    PORTB=0X0E;
    show();
    Delay_ms(1);
    PORTA=0X00;
}

void show(void)
{
    switch(temp)
    {
        case 0:{
                   PORTA=0X3F;
               }break;
        case 1:{
                   PORTA=0X06;
               }break;
        case 2:{
                   PORTA=0X5B;
               }break;
        case 3:{
                   PORTA=0X4F;
               }break;
        case 4:{
                   PORTA=0X66;
               }break;
        case 5:{
                   PORTA=0X6D;
               }break;
        case 6:{
                   PORTA=0X7D;
               }break;
        case 7:{
                   PORTA=0X07;
               }break;
        case 8:{
                   PORTA=0X7F;
               }break;
        case 9:{
                   PORTA=0X6F;
               }break;
    }
}
