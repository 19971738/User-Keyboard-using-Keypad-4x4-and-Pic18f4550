/*
 Created by> Juan De Dios de Luna Ponce on the 14th, Nov, 2020.
 * IMPORTANT INFORMATION:
 * In my program the key ON/C works as the one which cleans the screen
 * they key = works as the one which jumps to the next line.
 * The key DIVISION works as the one which prints the INT value which is previously saved on the program.
 * The key MULTIPLICATION works as the one which prints the float value, which previously is saved also in the program. 
 */

#include <xc.h>
#include <pic18f4550.h>
#include <stdio.h>
#include "Configuration_Header_File.h"
#include "16x2_LCD_4bit_File.h"


int Secuence1(),Secuence2(),Secuence3(),Secuence4();
#define _XTAL_FREQ 20000000      /* define macros to use internal __delay_us function = 8 Mhz */
#define Trigger_Pulse LATD0     /* PORTD.0 pin is connected to Trig pin of HC-SR04 */
int duty_cicle = 0, b=1,c=0,d=0,f=0;
float e = 10.718;
unsigned int a;
void main()
{
    int Distance;
    int Time;
    int Total_distance[10];
    float Total_distance2[10];
    // Inicio de Programa de el ultrasonico
    OSCCON=0x72;            /* use internal oscillator with * MHz frequency */  
    
    TRISD = 0;              /* define PORTD as Output port*/
    //INTCON2bits.RBPU=0;     /*enable PORTB Pull-ups */
    LCD_Init();
    while(1){
    LCD_Clear();
    while(c==0){
    LCD_String_xy(1,0,"Introduce valor: ");
    Secuence1();
    Secuence2();
    Secuence3();
    Secuence4();
    }
    LCD_Clear();
    while(c>=1 && f == 0){
    Secuence1();
    Secuence2();
    Secuence3();
    Secuence4();
    __delay_us(900);
    Distance = (a*1);           /* distance = (velocity x Time)/2 */
    sprintf(Total_distance,"%d",Distance);
    LCD_String_xy(b,c-1,Total_distance);
    MSdelay(50);
    }
    while(f==1){
        Secuence1();
        Secuence2();
        Secuence3();
        Secuence4();
        sprintf(Total_distance,"%0.3f",e);
        LCD_String_xy(1,0,Total_distance);
        c=1; // Para cuando salga del bucle tenga inicio la nueva cadena (Parece un bug)
    }

}

}
int Secuence1(){
    TRISBbits.RB1 = 0; //SalidA
    TRISC=0xff;
    //TRISB1= 0;  
    RB1=1;
    if(RC0==1 && d == 0){
        d=1;
        f=0;
        __delay_ms(100);
        if(RC0==0 && d==1){
        d=0;
        RB1=0; 
        a = 7;
        c++;
        RC0=0;
        
        }
    }
    else if(RC1==1 && d==0){
        d=1;
        __delay_ms(100);
        if(RC1==0 && d==1){
        d=0;
        f=0;
        RB1=0; 
        a=8; 
         c++;
        RC1=0;
        
    }
    }
    else if(RC2==1 && d==0){
        d=1;
        __delay_ms(100);
        if(RC2==0 && d==1){
        d=0;
        f=0;
        RB1=0; 
        a= 9;
        c++;
         RC2=0;
        }
    }
    else if(RC4==1 && d==0){
        d=1;
        __delay_ms(100);
        if(RC1==0 && d==1){
          f=0;
          d=0;
          RB1=0;
          a = 1;
          c++;
          f=1;
          RC4=0;
        }
    }
    else{ RB1 = 0;
        TRISBbits.RB1 = 1;
          TRISC=0x00;
          d=0;
          
    }
    RB1 = 0;
    TRISBbits.RB1 = 1;
    TRISC=0x00;
}

int Secuence2(){
    TRISBbits.RB2 = 0; //SalidA
    TRISC=0xff;
    RB2=1;
   if(RC0==1 && d == 0){
        d=1;
        __delay_ms(100);
        if(RC0==0 && d==1){
        f=0;
        d=0;
        c++;
        RB1=0; 
        a = 4;
       // numberT[a] = 10;
        RC0=0;
        
        }
    }
   else if(RC1==1 && d==0){
        d=1;
        __delay_ms(100);
        if(RC1==0 && d==1){
        f=0;
        d=0;
        c++;
        RB1=0; 
        a=5;  
        RC1=0;
        }
    }
    else if(RC2==1 && d==0){
        d=1;
        
        __delay_ms(100);
        if(RC2==0 && d==1){
        f=0;
        c++;
        d=0;
        RB1=0; 
        a= 6;
         RC2=0;
         
        }
    }
    else if(RC4==1 && d==0){
        d=1;
        c++;
        __delay_ms(100);
        if(RC1==0 && d==1){
          f=0;
          c=1;
          LCD_Clear();
          d=0;
          RB1=0;
          a = 1000;
          RC4=0;
          
        }
    }
     else{ 
        RB2=0;TRISBbits.RB2 = 1; //Entrada
          TRISC=0x00;
          d=0;
          
    }
    RB2=0;TRISBbits.RB2 = 1; //Entrada
    TRISC=0x00;
}
 
int Secuence3(){
    TRISBbits.RB4 = 0; //SalidA
    TRISC=0xff;
    RB4=1;
     if(RC0==1 && d == 0){
        d=1;
        __delay_ms(100);
        if(RC0==0 && d==1){
        f=0;
        d=0;
        c++;
        RB4=0; 
        a = 1;
       // numberT[a] = 10;
         __delay_us(300);
        RC0=0;
        }
    }
    else if(RC1==1 && d==0){
        d=1;
        __delay_ms(100);
        if(RC1==0 && d==1){
        f=0;
        d=0;
        c++;
        RB4=0; 
        a=2; 
        __delay_us(300); 
        RC1=0;
        
        }
    }
    else if(RC2==1 && d==0){
        d=1;
        __delay_ms(100);
        if(RC2==0 && d==1){
        f=0;
        d=0;
        c++;
        RB4=0;
        a= 3;
         __delay_us(300);
         RC2=0;
         
        }
    }
    else if(RC4==1 && d==1){
        d=1;
        __delay_ms(100);
        if(RC1==0 && d==1){
          f=0;
          d=0;
          c++;
          RB4=0;
          //a = 13;
          __delay_us(300);
          RC4=0;
        }
    }
     else{ 
        RB4=0;
        TRISBbits.RB4 = 1; //Entrada
          TRISC=0x00;
          
    }
    RB4=0;
    TRISBbits.RB4 = 1;
    TRISC=0x00;
    d=0;
}
int Secuence4(){
    TRISBbits.RB5 = 0; //SalidA
    TRISC=0xff;
    RB5=1;
   if(RC0==1 && d == 0){
        d=1;
        __delay_ms(100);
        if(RC0==0 && d==1){
        f=0;
        d=0;
        LCD_Clear();
        a = 0;
        c = 0; //Reiniciar Y
        LCD_Clear();
        RB5=0; 
        //a = 20; //ON/C *
       // numberT[a] = 10;
        RC0=0;
        }
    }
    else if(RC1==1 && d==0){
        d=1;
        __delay_ms(100);
        if(RC1==0 && d==1){
        f=0;
        RB5=0; 
        a=0;
        c++;
        RC1=0;
        }
    }
    else if(RC2==1 && d==0){
        d=1;
        __delay_ms(100);
        if(RC2==0 && d==1){
        f=0;
        d=0;
        RB5=0;
        LCD_Clear();
      
        if(b==1){
            b=2;
            c=0;
            LCD_Clear();
            
        }
        else b=1;
         RC2=0;
         c=0;
         LCD_Clear();
        }
    }
    else if(RC4==1 && d==1){
        d=1;
        __delay_ms(100);  
        if(RC1==0 && d==1){
          f=0;
          d=0;
          RB5=0;
          __delay_us(300);
          RC4=0;
        }
    }
     else{ 
        RB5=0;
        TRISBbits.RB5 = 1;
          TRISC=0x00;
          
    }
    RB5=0;
    TRISBbits.RB5 = 1;
    TRISC=0x00;
}
