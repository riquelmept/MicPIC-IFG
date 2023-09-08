void main(){
int x =0;;
TRISB = 0;
ADCON1 = 15;
TRISC = 0b00000011;
PORTC = 0;
LCD_Init (&PORTB);
LCD_Cmd (LCD_CURSOR_OFF);

while (1)
{
    LCD_CHR(1,3,(x%10) +48);
    LCD_CHR(1,2,((x/10)%10) +48);
    LCD_CHR(1,1,((x/10)/10) +48);
    if(PORTC.rc1 == 0) {
        PORTC.rc7 = 1;
        PORTC.rc4 = 1;
        PORTC.RC6 = 0;
    }
    else {
      PORTC.rc7 = 0;
      PORTC.rc4 = 0;
      PORTC.rc5 = 0;
    }
  if(PORTC.rc7 == 1) {
  PORTC.RC6 = 1;
    if(PORTC.rc0 == 0) {
        PORTC.rc5 = 1;
        delay_ms(150);
        x++;
    }
    else {
    PORTC.rc5 = 0;
    PORTC.RC6 = 0;}
    }
  }
}