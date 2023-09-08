void main ()
{
int x = 0;
PWM1_Init(500);
PWM1_Start();
TRISC = 0;
TRISD = 0;
              while(1){
              PWM1_Change_Duty(x);
              x = x + 5;
              delay_ms(30);
              }
}