void main(){
int x = 0, y = 0;
Lcd_Init(&PORTB);         // Initialize LCD connected to PORTB
Lcd_Cmd(Lcd_CLEAR);       // Clear display
Lcd_Cmd(Lcd_CURSOR_OFF);  // Turn cursor off
Pwm1_Init(500);
Pwm2_Init(500);
Pwm1_Start();
Pwm2_Start();
TRISB = 1;
TRISC = 1;
TRISD = 0b11001111;

             while(1){
             Lcd_Out(1, 1, "O");
             Pwm1_Change_Duty(x);
             Pwm2_Change_Duty(y);
             delay_ms(30);
             if(PORTD.F6 == 0){
             PORTD.F4 = 1;
             }
             else{
             PORTD.F4 = 0;
             }
             if(PORTD.F7 == 0){
             PORTD.F5 = 1;
             }
             else{
             PORTD.F5 = 0;
             }
             if(PORTC.F6 = 1){

             }else{
              x=x+5;
             }
             if(PORTC.F7 = 1){

             }else{
             y=y+5;
             }
             }
}