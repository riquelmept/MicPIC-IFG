void main() {
  TRISB = 0b00000000;
  TRISD = 0b10000000;
  PORTB = 0;

  while(1) {
    PORTB=255;
    delay_ms(150);
    PORTB=0;
    delay_ms(150);
  }
}