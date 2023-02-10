 /**
  @file   main.c, projet:
  @author 
  @date   
  @brief  
  
  Environnement:
      Développement: MPLAB X IDE (version 6.05)
      Compilateur: XC8 (version 2.40)
      Matériel: PIC 18F458,
 */

/****************** Liste des INCLUDES ****************************************/
#include <xc.h>
#include "Lcd4Lignes.h"
#include "serie_458.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/********************** CONSTANTES *******************************************/
#define _XTAL_FREQ 16000000 //Constante utilisée par __delay_ms(x). Doit = fréq interne du uC
#define AXE_X 6  //sur AN6
#define AXE_Y 7  //sur AN7
#define NB_CHIFFRE 4 //nombre de chiffres à choisir pour la loto
/********************** PROTOTYPES *******************************************/
void initialisation(void);

unsigned int lectureADC(unsigned char canal);//Lit la valeur analogique du canal (0 à 7) reçu en paramètre. //Retourne la valeur numérique sur 10bits (0 à 1023)
unsigned char trouveChiffre(unsigned int anX, unsigned int anY);//Trouve le chiffre (entre 1 et 9) correspondant à la position de la manette.

/****************** VARIABLES GLOBALES ****************************************/
const unsigned char msg[] = "Lab3 MarcG";
extern bool g_int0;   //flag indiquant que l'interruption int0 s'est produite
extern bool g_int1;   //flag indiquant que l'interruption int1 s'est produite
unsigned char g_mesChiffres[NB_CHIFFRE];  //les chiffres choisis par l'usager
int g_indexChiffre=0;  //index pour le tableau mesChiffres
unsigned char g_loto[NB_CHIFFRE] = {1,2,3,4};  //Chiffres à trouver

void main(void) 
{
    
    initialisation();
    init_serie();
    lcd_init();
    lcd_putMessage(msg); 

    while (1)
    {
        
    }
} //du main

/**
 * @brief Initialisation des différents regesitres du PIC.
 */
void initialisation(void)
{
    TRISD = 0; //Tout le port D en sortie
    TRISC = 0; //Tout le port C en sortie
    TRISB=1;//Tout le port B en entré
    ADCON1=7;
    //InteruptGlobal
    INTCONbits.GIE = 1; //Permettre les interruptions globales
    //Interupt0
    INTCONbits.INT0IF = 0; //Reset flag d'interruption d'INT0 (pour s'assurer de ne pas avoir d'interruption au départ)    
    INTCONbits.INT0IE = 1; //Permettre les interruptions d'INT0
    INTCON2bits.INTEDG0 = 0; //Choisir le front de l'interruption INT0
    //Interrupt1 
    INTCON3bits.INT1IE = 1;//Permettre les interruptions d'INT1
    INTCON3bits.INT1IF = 0; //Reset flag d'interruption d'INT1 (pour s'assurer de ne pas avoir d'interruption au départ)    
    INTCON2bits.INTEDG1 = 0; //Choisir le front de l'interruption INT1
}

