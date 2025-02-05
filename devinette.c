/*  Name : devinette.c
    Purpose : Fichier principal du jeu de devinette
    Authors : TCHAMIE Bindounow Gnimdou Jephté & AGBAKOSSI Ekoué Seyram Réné
    Date    : 29/11/2024
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#include "random.h"
#include "sequentiel.h"
#include "jeu.h"

#define MAX_TENTATIVES 10
#define MAX_PSEUDO_LENGTH 20
#define FILENAME "tentatives.txt"




int main() {
    int max_nombre, nombre_a_deviner, nombre_tentatives, choix, choix_difficulte = 0;
    int max_tentatives;
    int tentatives[MAX_TENTATIVES];
    char pseudo[MAX_PSEUDO_LENGTH];
    char password[MAX_PSEUDO_LENGTH];
    char continuer = 'o';

    setlocale(LC_ALL,"");
    setlocale(LC_CTYPE,"");
    srand(time(NULL));

    printf("\t\t\t\t\t\t\t--------------------\n\n");
    printf("\t\t\t\t\t\t\t| JEU DE DEVINETTE |\n\n");
    printf("\t\t\t\t\t\t\t--------------------\n\n");
    do {
        do {
            afficher_menu();
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    // Saisie et validation du pseudo et mot de passe
                    saisir_et_valider_pseudo(pseudo, password);

                    // Sélection du niveau de difficulté
                    choisir_difficulte(&max_nombre, &max_tentatives);

                    nombre_tentatives = 0;
                    nombre_a_deviner = rand() % max_nombre + 1;

                    // Boucle de jeu
                    boucle_de_jeu(max_nombre, max_tentatives, nombre_a_deviner, tentatives, &nombre_tentatives);

                    // Calcul de l'écart-type des tentatives
                    double ecart_type = calculer_ecart_type(tentatives, nombre_tentatives);
                    printf("Ecart-type des tentatives: %.2f\n", ecart_type);

                    // Enregistrement des tentatives
                    enregistrer_tentatives(pseudo, tentatives, nombre_tentatives, ecart_type, choix_difficulte);

                    break;

                case 2:
                    afficher_scores();
                    break;

                case 3:
                    if (remove(FILENAME) == 0) {
                        printf("\nHistorique supprimer avec succes.\n");
                    } else {
                        printf("\nErreur lors de la suppression de l'historique.\n");
                    }
                    break;

                case 4:
                    printf("Au revoir !\n");
                    return 0;
                default:
                    printf("Choix invalide.\n");
            }
        } while (choix != 3);
        printf("\nVoulez-vous jouer encore ? (O/N) : ");
        scanf(" %c", &continuer);
    } while (continuer == 'o' || continuer == 'O');

    return 0;
}
