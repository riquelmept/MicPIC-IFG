void main(){
int x = 0;
Pwm1_Init(500);
Pwm1_Start();
TRISC = 1;
TRISD = 1;
             while(1){
             Pwm1_Change_Duty(x);
             x=x+5;
             delay_ms(30);
             PORTD.F4 = 1;
             }
}