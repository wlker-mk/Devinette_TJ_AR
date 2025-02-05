/*  Name : sequentiel.c
    Purpose : Ensemble des sous-programmes se rapportant
            � la cr�ation du fichier .txt cr��
    Authors : TCHAMIE Bindounow Gnimdou Jepht� & AGBAKOSSI Ekou� Seyram R�n�
    Date    : 29/11/2024
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <math.h>


#include "sequentiel.h"

#define MAX_TENTATIVES 10
#define MAX_PSEUDO_LENGTH 20
#define FILENAME "tentatives.txt"

void enregistrer_pseudo(const char *pseudo, const char *password) {
    FILE *fichier = fopen("pseudos.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier pseudos.txt\n");
        return;
    }
    fprintf(fichier, "%s %s\n", pseudo, password);
    fclose(fichier);
}

// Fonction pour enregistrer les tentatives dans un fichier
void enregistrer_tentatives(const char *pseudo, const int *tentatives, int nombre_tentatives, double ecart_type, int difficulte) {
    FILE *fichier = fopen(FILENAME, "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", FILENAME);
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(fichier, "Pseudo: %s\n", pseudo);
    fprintf(fichier, "Niveau de difficult�: %d\n", difficulte);
    fprintf(fichier, "Date et heure: %02d-%02d-%04d %02d:%02d:%02d\n", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min, t->tm_sec);
    fprintf(fichier, "Nombre de tentatives: %d\n", nombre_tentatives);
    fprintf(fichier, "Tentatives: ");
    for (int i = 0; i < nombre_tentatives; i++) {
        fprintf(fichier, "%d ", tentatives[i]);
    }
    fprintf(fichier, "\nEcart-type: %.2f\n", ecart_type);
    fprintf(fichier, "----------------------------------------\n");

    fclose(fichier);
}