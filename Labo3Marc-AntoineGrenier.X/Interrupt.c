/*
 * File:   Interrupt.c
 * Author: Marc-
 *
 * Created on 9 f�vrier 2023, 17:02
 */


/****************** Liste des INCLUDES ****************************************/
#include <xc.h>
 
/********************** CONSTANTES *******************************************/
#define _XTAL_FREQ 1000000 //Constante utilis�e par __delay_ms(x). Doit = fr�q interne du uC
 
/****************** VARIABLES GLOBALES ****************************************/
 
/******************************************************************************/
/* Interrupt Service Routines                                                         */
/******************************************************************************/
 
/* High-priority interrupt service routine */
void __interrupt(high_priority) high_isr(void)
{
    if(INTCONbits.INT0IF)   //interruption INT0?
    {
        //printf("AllO");
       // __delay_ms(200); //debounce SW1 (pour ne pas changer d'�tat lors des rebonds hardware)
        INTCONbits.INT0IF = 0;  //Remise � z�ro du flag d'interruption
 
    }
      if(INTCON3bits.INT1IF)   //interruption INT1?
    {
 
        INTCON3bits.INT1IF = 0;  //Remise � z�ro du flag d'interruption
 
    }
}