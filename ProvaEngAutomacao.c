int teclado();

void main() {

int digito, cont=0, c=0, d=0, u=0, y=0, num=0, sen1, sen2, sen3, sen4, ent = 0, senha = 4321, cont1=0, digit1;
ADCON1=15;
TRISA = 0b00000001;
TRISD=0b00011111;
TRISC=0b0000000;
PORTC.F7 = 0;
LCD_INIT(&PORTB);
LCD_CMD(LCD_CURSOR_OFF);
LCD_OUT(1,1,"SENHA:    ");
LCD_OUT(2,1,"M1 LIGADO");

                while(1)
                {
                if(PORTA.F0 == 1){
                PORTC.F5 = 0;
                PORTC.F1 = 0;
                LCD_OUT(1,1,"Chave Aberta      ");
                LCD_OUT(2,1,"Pressione *");
                PORTC.F7 = 1;
                }
                else{
                PORTC.F7 = 0;
                PORTC.F1 = 1;
                PORTC.F5 = 1;
                digito=teclado();
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
                  LCD_OUT(2,1,"M1 LIGADO");
                  LCD_OUT(1,1,"SENHA:    ");
        }
        if(digito == 11){
        ent = sen1*1000+sen2*100+sen3*10+sen4;
           if(ent == senha){
           Lcd_Cmd(Lcd_CLEAR);
           PORTC.F2 = 1;
           PORTC.F5 = 1;
           PORTC.F6 = 1;
           LCD_OUT(1,1, "M1 LIGADO");
           LCD_OUT(2,1,"M2 LIGADO");
           }
           else{
           Lcd_Out(2,1,"Senha incorreta!");
           }

}
}}
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