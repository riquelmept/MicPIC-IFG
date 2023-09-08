void interrupt()
{
if (INTCON.INT0IF)
{
PORTC= ~PORTC;
INTCON.INT0IF=0;
}
}
           void main()
           {
           ADCON1 = 15;
           TRISC = 0;
           TRISB = 0b00000001;
           INTCON = 0b10010000;
           INTCON2.INTEDG0 = 1;

                while(1)
                {
                
                }
           }
                
