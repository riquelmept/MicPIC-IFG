int teclado();
int temporizador();
void main()
{

      int digito;
      int num, sen1, sen2, sen3, sen4, ent = 0, senha = 4321;
      int cont=0;
      ADCON1 = 15;
      TRISD = 0b00011111;
      TRISA = 0b00000001;
      TRISC = 0b00000000;
      LCD_Init (&PORTB);
      Lcd_Cmd(Lcd_CLEAR);
      Lcd_Cmd(Lcd_CURSOR_OFF);
      Lcd_Out(1,1,"Senha:    ");

      while(1)
      {
      if(PORTA.F0 == 0){
      PORTC.F1 = 1;
      }
      else{
      PORTC.F1 = 0;
      }
      digito = teclado();

      if(digito!=13){
        cont++;
        if(cont==1){
                  Lcd_Out(1,7,"*");
                  sen1=digito;
        }
        if(cont==2){
                  Lcd_Out(1,8,"*");
                  sen2=digito;
        }
        if(cont==3){
                  Lcd_Out(1,9,"*");
                  sen3=digito;
        }
        if(cont==4){
                  Lcd_Out(1,10,"*");
                  sen4=digito;
        }
        if(digito == 10){
                  cont = 0;
                  PORTC.F2 = 0;
                  Lcd_Cmd(Lcd_CLEAR);
                  LCD_OUT(1,1,"Senha:    ");
        }
        if(digito == 11){
        ent = sen1*1000+sen2*100+sen3*10+sen4;
           if(ent == senha){
           PORTC.F2 = 1;
           Lcd_Out(2,1,"Senha correta!");
           digito = 0;
           }
           else{
           Lcd_Out(2,1,"Senha incorreta!");
           }
        }
      }
      }
    }

int teclado()
{
   int tecla;
   tecla = 13;
   delay_ms(20);
   PORTD.F5= 0;  // Verifica a coluna 1
   PORTD.F6 = 1;
   PORTD.F7 = 1;
   while ( PORTD.F1 == 0 ) tecla = 1;
   while ( PORTD.F2 == 0 ) tecla = 4;
   while ( PORTD.F3 == 0 ) tecla = 7;
   while ( PORTD.F4 == 0 ) tecla = 10;  // " * "

   PORTD.F5 = 1;
   PORTD.F6 = 0; // Verifica a coluna 2
   while ( PORTD.F1 == 0) tecla = 2;
   while ( PORTD.F2 == 0) tecla = 5;
   while ( PORTD.F3 == 0) tecla = 8;
   while ( PORTD.F4 == 0) tecla = 0;


   PORTD.F6 = 1;
   PORTD.F7 = 0;  // Verifica a coluna 3
   while ( PORTD.F1 == 0) tecla = 3;
   while ( PORTD.F2 == 0) tecla = 6;
   while ( PORTD.F3 == 0) tecla = 9;
   while ( PORTD.F4 == 0) tecla = 11;  // " # "
   return (tecla);

}
int temporizador()
{
 digito = teclado();
  if(digito != 13 && PORTC.F0 == 0){
     if(PORTC.F7 == 1)
     {PORTC.F5=1;}


                           cont++;


                           if(cont==1 && digito<=9)
                           {
                           c=digito;
                           LCD_CHR(1,8, c+48);
                           }

                           if(cont==2 && digito==10)
                           {
                           cont = 0;
                           c = 0;
                           LCD_OUT(1,8, c+48);
                           }

                           if(cont==2 && digito<=9)
                           {
                           d=digito;
                           LCD_CHR(1,9, d+48);
                           }

                           if(cont==3 && digito==10)
                           {
                           cont=1;
                           d=0;
                           LCD_OUT(1,9, d+48);
                           }


                           if(cont==3 && digito<=9)
                           {
                           u=digito;
                           LCD_CHR(1,10,u+48);
                           }

                           if(cont==4 && digito==10)
                           {
                           cont=2;
                           LCD_OUT(1,10,u+48);
                           }

                           if(cont==4 && digito<=9)
                           {
                           cont=3;
                           }

                           num = (c*100)+(d*10)+u;

                           if(PORTC.F0 == 1)
                           {
                           num=0;
                           cont=0;
                           }
                           if(digito == 10){
                           cont=0;
                           LCD_OUT(1,1,"TEMPO:    s ");
                           LCD_OUT(2,1, "MOTOR DESLIGADO");
                           PORTC.F7 = 0;
                           }

                           if(cont==4 && digito==11 && PORTC.F0==0)
                           {

                           PORTC.F7 = 1;
                           PORTC.F4 = 1;
                           PORTC.F5 = 0;
                           LCD_OUT(2,1, "MOTOR LIGADO    ");

                            for(y=num; y>=0; y--)
                            {

                            if(PORTC.F0 == 1)
                             {
                            break;
                            }

                            c=(y/10)/10;
                            d=(y/10)%10;
                            u=(y%10);

                            LCD_CHR(1,8, c+48);
                            LCD_CHR(1,9, d+48);
                            LCD_CHR(1,10, u+48);

                            }
                            }

                            PORTC.F7 = 0;
                            PORTC.F4 = 0;
                            PORTC.F5 = 1;
                            LCD_OUT(2,1, "MOTOR DESLIGADO    ");
                      }
                      }