void main(){
int x = 0, y = 0;
Pwm1_Init(500);
Pwm2_Init(500);
Pwm1_Start();
Pwm2_Start();
TRISC = 1;
TRISD = 0b11001111;

             while(1){
             Pwm1_Change_Duty(x);
             Pwm2_Change_Duty(y);
             y = y+5;
             x = x+5;
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

             }
}
