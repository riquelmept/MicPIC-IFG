void main(){

int tensao;
float aux;
char dado[13];
TRISA = 255;
TRISC = 0;
TRISD = 0;
PORTC = 0;
PORTD = 0;
ADCON1 = 0b00001110;
adcon2 = 0b10000000;
ADCON0.CHS3 = 0;
ADCON0.CHS2 = 0;
ADCON0.CHS1 = 0;
ADCON0.CHS0 = 0;
ADCON0.ADON = 1;

           LCD_INIT(&PORTD);
           LCD_CMD(LCD_CURSOR_OFF);
           while(1)
           {
                   ADCON0.GO_DONE = 1;
                   while(ADCON0.GO_DONE);
                   
                   tensao = ((ADRESH << 8) + ADRESL);

                   if(tensao>512) PORTC.F7 = 1;
                   else PORTC.F7 = 0;
                   
                   IntToStr(tensao,dado);
                   LCD_OUT(1,1,dado);
                   
                   aux = (tensao*5.0)/1024;
                   
                   FloatToStr(aux,dado);
                   dado[5] = 0;
                   LCD_OUT(2,1,dado);
                   
          }
}