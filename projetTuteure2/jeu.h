/*  Name : jeu.h
    Purpose : Structure et prototypes des fonctions se rapportant
            à la gestion du jeu de devinette
    Authors : TCHAMIE Bindounow Gnimdou Jephté & AGBAKOSSI Ekoué Seyram Réné
    Date    : 29/11/2024
*/

void afficher_menu();
/*  But : Afficher les différentes options du Menu de Jeu
    Parametres: Aucun
    Return: Rien
 */


double calculer_ecart_type(int tentatives[], int nombre_tentatives);
/*  But : Calcul l'écart type du jeu
    Parametres: nombre de tentative, tentative entrer par l'utilisateur
    Return: Le calcul de l'ecart type
 */

 void afficher_menu_difficulte();
/*  But : Afficher les diff�rents niveaux de difficulté
    Parametres: Aucun
    Return: Rien
 */
