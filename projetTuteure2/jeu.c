/*  Name : jeu.h
    Purpose : Ensemble des sous-programmes se rapportant
            à la gestion du jeu de devinette
    Authors : TCHAMIE Bindounow Gnimdou Jephté & AGBAKOSSI Ekoué Seyram Réné
    Date    : 29/11/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <math.h>


#include "jeu.h"

#define MAX_TENTATIVES 10
#define MAX_PSEUDO_LENGTH 20
#define FILENAME "tentatives.txt"


void afficher_menu() {
    printf("\n--MENU :\n\n");
    printf("1. Jouer\n");
    printf("2. Afficher les scores\n");
    printf("3. Supprimer l'historique des jeux\n");
    printf("4. Quitter\n");
    printf("\nVotre choix : ");
}


double calculer_ecart_type(int tentatives[], int nombre_tentatives) {
    double somme = 0.0, moyenne, ecart_type = 0.0;

    for (int i = 0; i < nombre_tentatives; i++) {
        somme += tentatives[i];
    }
    moyenne = somme / nombre_tentatives;

    for (int i = 0; i < nombre_tentatives; i++) {
        ecart_type += pow(tentatives[i] - moyenne, 2);
    }
    return sqrt(ecart_type / nombre_tentatives);
}

void afficher_menu_difficulte() {
    printf("\nNIVEAUX DE DIFFICULTÉ :\n\n");
    printf("1. Débutant (1 à 100)\n");
    printf("2. Intermédiaire (1 à 500)\n");
    printf("3. Expert (1 à 2000)\n");
    printf("4. Personnalisé\n");
    printf("\nVotre choix : ");
}
