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
/*  But : Afficher les différents niveaux de difficulté
    Parametres: Aucun
    Return: Rien
*/

void choisir_difficulte(int *max_nombre, int *max_tentatives);
/*  But : Gère le choix de la difficulté
    Parametres: *max_nombre, *max_tentatives
    Return: Rien
*/

void boucle_de_jeu(int max_nombre, int max_tentatives, int nombre_a_deviner, int *tentatives, int *nombre_tentatives);
/*  But : Gère la comparaison du nombre choix par l'utilisateur et le nombre à deviner
    Parametres: max_nombre, max_tentatives, nombre_a_deviner, *tentatives, *nombre_tentatives
    Return: Rien
*/

void saisir_et_valider_pseudo(char *pseudo, char *password);
/*  But : Gère la vérification du pseudo et du mot de passe
    Parametres: *pseudo, *password
    Return: Rien
*/
