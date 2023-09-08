void main(){
int x;
int y;
TRISB = 0;
TRISD = 1;
TRISC = 1;
ADCON1 = 15;

 LCD_Init(&PORTB);
 LCD_Cmd(LCD_CURSOR_OFF);

 while(1){
 if( PORTC = 0 ){
  LCD_Out(1,1,"Chave Aberta");
     }
 else{
 LCD_Out(1,1,"Chave Fechada");
 }


 }
}