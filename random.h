/*  Name : sequentiel.h
    Purpose : Structure et prototypes des fonctions se rapportant
            � la manipulation et la gestion du fichier .txt cr��
    Authors : TCHAMIE Bindounow Gnimdou Jepht� & AGBAKOSSI Ekou� Seyram R�n�
    Date    : 29/11/2024
*/

int pseudo_existe(const char *pseudo);
/*  But : V�rifie si le pseudo entr� existe d�ja
    Parametres: le pseudo
    Return: La valeur 0
 */

int password_correct(const char *pseudo, const char *password);
/*  But : V�rifie si le mot de passe entr� est correct
    Parametres: le pseudo, le mot de passe
    Return: La valeur 0
 */

void afficher_scores();
/*  But : Affiche l'historique des pseudo et des utilisateurs
    Parametres: le pseudo, le nombre de tentative, les tentatives entr�es, l'�cart type
    Return: Rien
 */