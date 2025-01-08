/*  Name : sequentiel.h
    Purpose : Ensemble des sous-programmes se rapportant
            à la manipulation et la gestion du fichier .txt créé
    Authors : TCHAMIE Bindounow Gnimdou Jephté & AGBAKOSSI Ekoué Seyram Réné
    Date    : 29/11/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <math.h>


#include "random.h"

#define MAX_TENTATIVES 10
#define MAX_PSEUDO_LENGTH 20
#define FILENAME "tentatives.txt"

// Fonction pour vérifier si le pseudo existe déjà dans le fichier
int pseudo_existe(const char *pseudo) {
    FILE *fichier = fopen(FILENAME, "r");
    if (fichier == NULL) {
        return 0; // Le fichier n'existe pas encore, pas de doublon
    }

    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (strstr(ligne, pseudo) != NULL) {
            fclose(fichier);
            return 1; // Pseudo trouvé
        }
    }

    fclose(fichier);
    return 0; // Pseudo non trouvé
}

void afficher_scores() {
    FILE *fichier = fopen(FILENAME, "r");
    if (fichier == NULL) {
        printf("Aucun historique trouvé.\n");
        return;
    }

    char ligne[100];
    printf("Historique des parties :\n");
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);
    }

    fclose(fichier);
}

