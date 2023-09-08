int teclado();
void main()
{
int digito, cont = 0, u, num,y,d,num1;
ADCON1 =15;
TRISD = 0b00011111;
TRISC = 0;
LCD_INIT(&PORTB);
LCD_CMD(LCD_CURSOR_OFF);
LCD_OUT(1,1,"T=  s");
LCD_OUT(2,1,"Motor DESLIGADO");
while(1)
{

digito = teclado();  if(digito!= 13)
{
cont++;
if(cont == 1)
{
d = digito;
LCD_CHR(1,3,d+48);
}
if(cont == 2)
{
u = digito;
LCD_CHR(1,4,u+48);
}
if(cont == 3 && digito == 11)
{
num = (d*10) + u;         PORTC.F7 = 1;         for(y = num; y>= 0; y = y-1)
{
LCD_OUT(2,1,"MOTOR LIGADO    ");
u = y % 10;            d = y / 10;            delay_ms(150);
LCD_CHR(1,4,u+48);
LCD_CHR(1,3,d+48);
  if(y == 0){
  LCD_OUT(2,1,"MOTOR DESLIGADO");
  LCD_OUT(1,1,"TEMPO: 000s");
  }
}
PORTC.F7 = 0;
PORTC.F5 = 1;
PORTC.F4 = 0;
}

}

}
}
int teclado()
{
int tecla = 13;
delay_ms(20);
PORTD.F5 = 0;
PORTD.F6 = 1;
PORTD.F7 = 1;
while(PORTD.F1 == 0)
tecla = 1;
while(PORTD.F2 == 0)
tecla = 4;
while(PORTD.F3 == 0)
tecla = 7;
while(PORTD.F4 == 0)
tecla = 10;
PORTD.F5 = 1;
PORTD.F6 = 0;
PORTD.F7 = 1;
while(PORTD.F1 == 0)
tecla = 2;
while(PORTD.F2 == 0)
tecla = 5;
while(PORTD.F3 == 0)
tecla = 8;
while(PORTD.F4 == 0)
tecla = 0;
PORTD.F5 = 1;
PORTD.F6 = 1;
PORTD.F7 = 0;
while(PORTD.F1 == 0)
tecla = 3;
while(PORTD.F2 == 0)
tecla = 6;
while(PORTD.F3 == 0)
tecla = 9;
while(PORTD.F4 == 0)
tecla = 11;
return(tecla);
}
