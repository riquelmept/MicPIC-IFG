void main() {
  int x=1;
  int y=0;
  int z=0;
  int w=0;
  TRISA = 0;
  PORTA = 0;
  TRISB = 0;
  PORTB = 0;
  TRISD = 0;
  PORTD = 0;

  while(1)
  {
     PORTA = x;
     x=x*2;
     y=y+1;
     delay_ms(150);
     if(x == 16) x=1;
            if(y == 200){
            y=0;
            z++;
            PORTB = z;
              if(z > 9){
              z = 0;
              w++;
              PORTD = w;
              PORTB = z;
              }
            }
  }
}