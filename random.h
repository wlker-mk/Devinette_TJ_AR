/*  Name : sequentiel.h
    Purpose : Structure et prototypes des fonctions se rapportant
            à la manipulation et la gestion du fichier .txt créé
    Authors : TCHAMIE Bindounow Gnimdou Jephté & AGBAKOSSI Ekoué Seyram Réné
    Date    : 29/11/2024
*/

int pseudo_existe(const char *pseudo);
/*  But : Vérifie si le pseudo entré existe déja
    Parametres: le pseudo
    Return: La valeur 0
 */

int password_correct(const char *pseudo, const char *password);
/*  But : Vérifie si le mot de passe entré est correct
    Parametres: le pseudo, le mot de passe
    Return: La valeur 0
 */

void afficher_scores();
/*  But : Affiche l'historique des pseudo et des utilisateurs
    Parametres: le pseudo, le nombre de tentative, les tentatives entrées, l'écart type
    Return: Rien
 */
