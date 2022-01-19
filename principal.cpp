//************************ ENTÊTE DE FICHIER ************************************//
/**
* @file   	principal.cpp
* @author	N. Huppe
* @date		janvier 2019
* @version	1.0 : 	Première version
* @version	1.1 : 	Révision C. Richard (10 décembre 2020) correction du brief,
					ajout des commentaires de sections et ajustement boucle.
* @version	1.2 :   Révision C. Richard (29 décembre 2021) ajout d'une section
                    détails dans l'entête pour décrire ce qu'il faut effectuer
                    comme modification pour tester son environnment de prog.
*
* @brief	Programme qui affiche "Hello World !", affiche un compteur
*			à toutes les secondes et quitte le programme si une touche
*			du clavier est appuyée.
*
* @details Afin de tester la configuration, aller à la ligne 52 et modifier le
           texte à afficher par le cout pour une version française du message.
*/      
//*******************************************************************************//


//*******************************************************************************//
//*							SECTION DES INCLUDES								*//
//*******************************************************************************//

#include <iostream>     // fichiers sources pour cout
#include <conio.h>      // fichiers sources de kbhit()
#include <unistd.h>     // fichiers sources de sleep()
using namespace std;    // afin d'utiliser cout


//*******************************************************************************//
//*							VARIABLES GLOBALES									*//
//*******************************************************************************//

int g_boucle = true;    // pour gérer la boucle
             

//*******************************************************************************//
//*							PROGRAMME PRINCIPAL									*//
//*******************************************************************************//
int main()
{
    int cpt;   // déclaration de la variable compteur pour le nombre d'itérations
 
    while(g_boucle)  // répétition à l'infini tant que g_boucle est vrai (true)
    {   
      	cpt = 0; // remise a zero du compteur

        // affichage de l'information
        cout << "Hello World ! " << endl;
                                
        //  boucle répétée 10 fois si boucle == true
        while(cpt < 11 && g_boucle)
        {
            cout << '\r' << cpt << "s"  << "  ";	// '\r' sert de retour au debut de ligne
            sleep(1); //Pause de 1 seconde
            cpt = cpt + 1;    //Incrément du compteur
                  
            // si une touche est pressée kbhit() sera vrai, la boucle sera ainsi terminée
            if(kbhit())
            {
				g_boucle = false;
			}
        }
        cout << endl << endl; // sauts de ligne pour améliorer l'affichage
    }
    return 0;
}
