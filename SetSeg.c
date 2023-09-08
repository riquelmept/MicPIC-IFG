void main() {
int x,y,z;
ADCON1=15;
TRISA=0;
TRISB=0;
TRISD=0;
while(1){
     for(z = 0; z <= 9; z++){
     PORTD=z;
     delay_ms(250);
         for(y = 0; y <= 9; y++){
         PORTB=y;
         delay_ms(250);
            for(x = 0; x <= 9; x++){
            PORTA=x;
            delay_ms(250);
            }
         PORTA=0;                      }
     }PORTB=0;
}PORTD=0;
}