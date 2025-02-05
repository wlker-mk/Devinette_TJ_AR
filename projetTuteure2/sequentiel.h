/*  Name : sequentiel.h
    Purpose : Structure et prototypes des fonctions se rapportant
            � la cr�ation du fichier .txt cr��
    Authors : TCHAMIE Bindounow Gnimdou Jepht� & AGBAKOSSI Ekou� Seyram R�n�
    Date    : 29/11/2024
*/

void enregistrer_tentatives(const char *pseudo, const int *tentatives, int nombre_tentatives, double ecart_type, int difficulte);
/*  But : Cr� et enr�gistre les pseudos et les scores
    Parametres: le pseudo, le nombre de tentative, les tentatives entr�es, l'�cart type
    Return: Rien
 */

void enregistrer_pseudo(const char *pseudo, const char *password);