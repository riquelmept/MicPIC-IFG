void main(){
int x = 0, y = 0, por = 0,pory = 0, c, d, u, cy, dy, uy;
ADCON1=15;
Lcd_Init(&PORTB);
Lcd_Cmd(Lcd_CLEAR);
Lcd_Cmd(Lcd_CURSOR_OFF);
Pwm1_Init(500);
Pwm2_Init(500);
Pwm1_Start();
Pwm2_Start();
TRISB = 0;
TRISC = 1;
TRISD = 0b11001111;
      LCD_OUT(1,1,"M1= ");
      LCD_OUT(1,7,"% ");
      LCD_OUT(2,1,"M2= ");
      LCD_OUT(2,7,"% ");
      LCD_OUT(1,9,"S= ");
      LCD_OUT(2,9,"S=");

             while(1){

             Pwm1_Change_Duty(x);
             Pwm2_Change_Duty(y);
             delay_ms(30);
                          por=(x*100)/255;
                          c=(por/10)/10;
                          d=(por/10)%10;
                          u=(por%10);

                          LCD_CHR(1,4, c+48);
                          LCD_CHR(1,5, d+48);
                          LCD_CHR(1,6, u+48);
                          
                          pory=(y*100)/255;
                          cy=(pory/10)/10;
                          dy=(pory/10)%10;
                          uy=(pory%10);

                          LCD_CHR(2,4, cy+48);
                          LCD_CHR(2,5, dy+48);
                          LCD_CHR(2,6, uy+48);
             
             if(PORTD.F6 == 0){
             PORTD.F4 = 1;
             LCD_OUT(1,11,"H");
             }
             else{
             PORTD.F4 = 0;
             LCD_OUT(1,11,"A");
             }
             if(PORTD.F7 == 0){
             PORTD.F5 = 1;
             LCD_OUT(2,11,"H");
             }
             else{
             PORTD.F5 = 0;
             LCD_OUT(2,11,"A");
             }
             if(PORTC.F6 = 1){

             }else{
              x=x+10;
             }
             if(PORTC.F7 = 1){

             }else{
             y=y+10;
             }
             }
}