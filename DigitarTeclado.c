int teclado();
 void main ()
 {
 int digito;
 ADCON1=15;
 TRISD=0b00011111;
 LCD_INIT(&PORTB);

 while(1)
 {
 digito=teclado();
 if(digito!=13)
 {
 LCD_CHR(1,1,digito+48);
 }
 }

 }

 int teclado()
 {
 int tecla=13;
 delay_ms(20);
 PORTD.F5=0;
 PORTD.F6=1;
 PORTD.F7=1;
 while(PORTD.F1==0)tecla=1;
 while(PORTD.F2==0)tecla=4;
 while(PORTD.F3==0)tecla=7;
 while(PORTD.F4==0)tecla=10;

 PORTD.F5=1;
 PORTD.F6=0;
 PORTD.F7=1;
 while(PORTD.F1==0)tecla=2;
 while(PORTD.F2==0)tecla=5;
 while(PORTD.F3==0)tecla=8;
 while(PORTD.F4==0)tecla=0;

 PORTD.F5=1;
 PORTD.F6=1;
 PORTD.F7=0;
 while(PORTD.F1==0)tecla=3;
 while(PORTD.F2==0)tecla=6;
 while(PORTD.F3==0)tecla=9;
 while(PORTD.F4==0)tecla=11;

 return(tecla);
 }