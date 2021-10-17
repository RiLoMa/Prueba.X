/*
 * File:   newmain.c
 * Author: rilopezm
 *
 * Created on 16 de octubre de 2021, 04:34 PM
 */
  
#define F_CPU  1000000UL
#include <xc.h>
#include <stdint.h>
#include <util/delay.h>

#define PUERTO_FILA     PORTC
#define PUERTO_COLUMNA	PORTD	

#define true     0x01
#define false    0x00 

int main(void)
{
   DDRD = 255;
   DDRC = 255;
      
   uint8_t k,j,n,salida,E0[2][7];
      
   E0[0][0] = 255;
   E0[0][1] = 0;
   E0[0][2] = 255;
   E0[0][3] = 0;
   E0[0][4] = 0;
   E0[0][5] = 0;
   E0[0][6] = 0;
   E0[0][7] = 255;
   
   E0[1][0] = 255;
   E0[1][1] = 0;
   E0[1][2] = 0;
   E0[1][3] = 255;
   E0[1][4] = 0;
   E0[1][5] = 0;
   E0[1][6] = 0;
   E0[1][7] = 255;
   
   E0[2][0] = 255;
   E0[2][1] = 0;
   E0[2][2] = 0;
   E0[2][3] = 0;
   E0[2][4] = 255;
   E0[2][5] = 0;
   E0[2][6] = 0;
   E0[2][7] = 255;
   
   while (1)
   {
      for (n = 0;!(n>2);n++)
      {
         for (j = 0; !(j>220);j++)
         {
            for (k = 0;!(k>7);k++)
            {
               PUERTO_COLUMNA = (uint8_t)(1U << k);
               PUERTO_FILA = E0[n][k];
               _delay_us(500);
               PUERTO_FILA = 0;
            }
         }
      }
      salida = false;
      if (salida == true) break;
   }
   return 0;
}
