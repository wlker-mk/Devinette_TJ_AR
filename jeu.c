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
#include <stdbool.h>

#include "jeu.h"
#include "sequentiel.h"
#include "random.h"

#define MAX_TENTATIVES 10
#define MAX_PSEUDO_LENGTH 20
#define FILENAME "tentatives.txt"


void afficher_menu() {
    //printf("\n--------------");
    printf("\n-----MENU-----\n\n");
    //printf("\n--------------\n\n");
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
    printf("\n-----NIVEAUX DE DIFFICULTE-----\n\n");
    printf("1. Debutant (1 - 100)\n");
    printf("2. Intermediaire (1 - 500)\n");
    printf("3. Expert (1 - 2000)\n");
    printf("4. Personnalise\n");
    printf("\nVotre choix : ");
}

void choisir_difficulte(int *max_nombre, int *max_tentatives) {
    int choix_difficulte = 0;

    afficher_menu_difficulte();
    scanf("%d", &choix_difficulte);

    switch (choix_difficulte) {
        case 1:
            *max_nombre = 100;
            *max_tentatives = 5;
            break;
        case 2:
            *max_nombre = 500;
            *max_tentatives = 10;
            break;
        case 3:
            *max_nombre = 2000;
            *max_tentatives = 20;
            break;
        case 4:
            printf("Entrez le nombre maximum pour le niveau personnalise : ");
            scanf("%d", max_nombre);
            if (*max_nombre <= 0) {
                printf("Valeur invalide. Niveau debutant selectionner par defaut.\n");
                *max_nombre = 100;
                *max_tentatives = 5;
            } else {
                *max_tentatives = -1; // tentative illimitées
            }
            break;
        default:
            printf("Choix invalide. Niveau debutant selectionner par defaut.\n");
            *max_nombre = 100;
            *max_tentatives = 5;
    }
}


void boucle_de_jeu(int max_nombre, int max_tentatives, int nombre_a_deviner, int *tentatives, int *nombre_tentatives) {
    time_t start_time = time(NULL);
    int tentative;
    bool nbre_trouver = false;

    printf("Devinez le nombre (entre 1 et %d) :\n", max_nombre);

    // Boucle de jeu
    while ((max_tentatives == -1 || *nombre_tentatives < max_tentatives) && difftime(time(NULL), start_time) < 300) {
        printf("Tentative %d: ", *nombre_tentatives + 1);
        scanf("%d", &tentative);
        tentatives[(*nombre_tentatives)++] = tentative;

        if (tentative == nombre_a_deviner) {
            printf("\nFelicitations, vous avez deviner le nombre!\n");
            nbre_trouver = true;
            break;
        } else if (tentative < nombre_a_deviner) {
            printf("Plus grand!\n");
        } else {
            printf("Plus petit!\n");
        }
    }

    // Message de fin de jeu
    if (!nbre_trouver && (max_tentatives != -1 && *nombre_tentatives >= max_tentatives)) {
        printf("Vous avez epuiser toutes vos tentatives. Le nombre etait %d.\n", nombre_a_deviner);
    }

    if (nbre_trouver) {
        if (*nombre_tentatives <= 3) {
            printf("\n--Vous etes un super voyant!--\n");
        } else if (*nombre_tentatives <= 6) {
            printf("\n--Vous etes un voyant!--\n");
        } else if (*nombre_tentatives <= 9) {
            printf("\n--Vous etes un apprenti voyant!--\n");
        } else {
            printf("\n--Vous etes un voyant pusillanime!--\n");
        }
    }
}


void saisir_et_valider_pseudo(char *pseudo, char *password) {
    bool valid = false; // Boolean flag to control the loop
    int choix;

    while (!valid) {
        printf("1. Verifier si votre pseudo existe\n");
        printf("2. Creer un nouveau pseudo\n");
        printf("\nVotre choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            printf("Entrez votre pseudo : ");
            scanf("%s", pseudo);
            if (pseudo_existe(pseudo)) {
                printf("Entrez votre mot de passe : ");
                scanf("%s", password);
                if (password_correct(pseudo, password)) {
                    printf("\nConnexion reussie.\n");
                    valid = true; // Set the flag to exit the loop
                } else {
                    printf("Mot de passe incorrect. Reessayez.\n");
                }
            } else {
                printf("Pseudo non trouver. Reessayez ou creez un nouveau pseudo.\n");
            }
        } else if (choix == 2) {
            printf("Entrez votre nouveau pseudo : ");
            scanf("%s", pseudo);
            if (pseudo_existe(pseudo)) {
                printf("Ce pseudo existe deja. Reessayez.\n");
            } else {
                printf("Entrez votre mot de passe : ");
                scanf("%s", password);
                enregistrer_pseudo(pseudo, password);
                printf("Pseudo creer avec succes.\n");
                valid = true; // Set the flag to exit the loop
            }
        } else {
            printf("Choix invalide. Reessayez.\n");
        }
    }
}
