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
    int max_nombre, nombre_a_deviner, tentative, nombre_tentatives, choix, choix_difficulte;
    int max_tentatives; // Declare max_tentatives
    int tentatives[MAX_TENTATIVES];
    char pseudo[MAX_PSEUDO_LENGTH];
    char password[MAX_PSEUDO_LENGTH];
    char continuer = 'o';
    time_t start_time;

    setlocale(LC_CTYPE,"");
    srand(time(NULL));

    printf("\t\t\t\t\t\tJEU DE DEVINETTE\n\n");
    do {
        do {
            afficher_menu();
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    // Saisie et validation du pseudo et mot de passe
                    do {
                        printf("Entrez votre pseudo : ");
                        scanf("%s", pseudo);
                        printf("Entrez votre mot de passe : ");
                        scanf("%s", password);
                        if(pseudo_existe(pseudo)) {
                            if(!password_correct(pseudo, password)) {
                                printf("Mot de passe incorrect. R�essayez.\n");
                                continue;
                            }
                        } else {
                            enregistrer_pseudo(pseudo, password);
                        }
                        break;
                    } while (1);

                    // S�lection du niveau de difficult�
                    afficher_menu_difficulte();
                    scanf("%d", &choix_difficulte);

                    switch (choix_difficulte) {
                        case 1:
                            max_nombre = 100;
                            max_tentatives = 5;
                            break;
                        case 2:
                            max_nombre = 500;
                            max_tentatives = 10;
                            break;
                        case 3:
                            max_nombre = 2000;
                            max_tentatives = 20;
                            break;
                        case 4:
                            printf("Entrez le nombre maximum pour le niveau personnalis� : ");
                            scanf("%d", &max_nombre);
                            if (max_nombre <= 0) {
                                printf("Valeur invalide. Niveau d�butant s�lectionn� par d�faut.\n");
                                max_nombre = 100;
                                max_tentatives = 5;
                            } else {
                                max_tentatives = -1; // Unlimited attempts
                            }
                            break;
                        default:
                            printf("Choix invalide. Niveau d�butant s�lectionn� par d�faut.\n");
                            max_nombre = 100;
                            max_tentatives = 5;
                    }

                    nombre_tentatives = 0;
                    nombre_a_deviner = rand() % max_nombre + 1;

                    printf("Devinez le nombre (entre 1 et %d) :\n", max_nombre);

                    // Start the game session timer
                    start_time = time(NULL);

                    // Boucle de jeu
                    while ((max_tentatives == -1 || nombre_tentatives < max_tentatives) && difftime(time(NULL), start_time) < 300) {
                        printf("Tentative %d: ", nombre_tentatives + 1);
                        scanf("%d", &tentative);
                        tentatives[nombre_tentatives++] = tentative;

                        if (tentative == nombre_a_deviner) {
                            printf("\nF�licitations, vous avez devin� le nombre!\n");
                            break;
                        } else if (tentative < nombre_a_deviner) {
                            printf("Plus grand!\n");
                        } else {
                            printf("Plus petit!\n");
                        }
                    }

                    if (tentative != nombre_a_deviner) {
                        printf("Vous avez �puis� toutes vos tentatives ou le temps est �coul�. Le nombre �tait %d.\n", nombre_a_deviner);
                    }

                    // Messages de f�licitations en fonction du nombre de tentatives
                    if (nombre_tentatives <= 3) {
                        printf("Vous �tes un super voyant!\n");
                    } else if (nombre_tentatives <= 6) {
                        printf("Vous �tes un voyant!\n");
                    } else if (nombre_tentatives <= 9) {
                        printf("Vous �tes un apprenti voyant!\n");
                    } else {
                        printf("Vous �tes un voyant pusillanime!\n");
                    }

                    // Calcul de l'�cart-type des tentatives
                    double ecart_type = calculer_ecart_type(tentatives, nombre_tentatives);
                    printf("Ecart-type des tentatives: %.2f\n", ecart_type);

                    // Enregistrement des tentatives
                    enregistrer_tentatives(pseudo, tentatives, nombre_tentatives, ecart_type, choix_difficulte);

                    break;

                case 2:
                    afficher_scores();
                    break;

                case 3:
                    printf("Au revoir !\n");
                    return 0;

                case 4:
                    if (remove(FILENAME) == 0) {
                        printf("Historique supprim� avec succ�s.\n");
                    } else {
                        printf("Erreur lors de la suppression de l'historique.\n");
                    }
                    break;

                default:
                    printf("Choix invalide.\n");
            }
        } while (choix != 3);
        printf("Voulez-vous jouer encore ? (O/N) : ");
        scanf(" %c", &continuer);
    } while (continuer == 'o' || continuer == 'O');


    return 0;
}