#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "random.h"
#include "sequentiel.h"
#include "jeu.h"

#define MAX_TENTATIVES 10
#define MAX_PSEUDO_LENGTH 20
#define FILENAME "tentatives.txt"

int main() {
    int max_nombre, nombre_a_deviner, tentative, nombre_tentatives, choix, choix_difficulte;
    int tentatives[MAX_TENTATIVES];
    char pseudo[MAX_PSEUDO_LENGTH];
    char continuer = 'o';

    setlocale(LC_CTYPE,"");
    srand(time(NULL));

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------- JEU DE DEVINETTE -----------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");


        do {
            afficher_menu();
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    // Saisie et validation du pseudo
                    do {
                        printf("Entrez votre pseudo : ");
                        scanf("%s", pseudo);
                        if(pseudo_existe(pseudo)) {
                            printf("Ce pseudo existe déjà. Choisissez-en un autre.\n");
                        } else {
                            break;
                        }
                    } while (1);

                    // Sélection du niveau de difficulté
                    afficher_menu_difficulte();
                    scanf("%d", &choix_difficulte);

                    switch (choix_difficulte) {
                        case 1:
                            max_nombre = 100;
                            break;
                        case 2:
                            max_nombre = 500;
                            break;
                        case 3:
                            max_nombre = 2000;
                            break;
                        case 4:
                            printf("Entrez le nombre maximum pour le niveau personnalisé : ");
                            scanf("%d", &max_nombre);
                            if (max_nombre <= 0) {
                                printf("Valeur invalide. Niveau débutant sélectionné par défaut.\n");
                                max_nombre = 100;
                            }
                            break;
                        default:
                            printf("Choix invalide. Niveau débutant sélectionné par défaut.\n");
                            max_nombre = 100;
                    }

                    nombre_tentatives = 0;
                    nombre_a_deviner = rand() % max_nombre + 1;

                    printf("Devinez le nombre (entre 1 et %d) :\n", max_nombre);

                    // Boucle de jeu
                    while (nombre_tentatives < MAX_TENTATIVES) {
                        printf("Tentative %d: ", nombre_tentatives + 1);
                        scanf("%d", &tentative);
                        tentatives[nombre_tentatives++] = tentative;

                        if (tentative == nombre_a_deviner) {
                            printf("\nFélicitations, vous avez deviné le nombre!\n");
                            break;
                        } else if (tentative < nombre_a_deviner) {
                            printf("Plus grand!\n");
                        } else {
                            printf("Plus petit!\n");
                        }
                    }

                    // Messages de félicitations en fonction du nombre de tentatives
                    if (nombre_tentatives <= 3) {
                        printf("Vous êtes un super voyant!\n");
                    } else if (nombre_tentatives <= 6) {
                        printf("Vous êtes un voyant!\n");
                    } else if (nombre_tentatives <= 9) {
                        printf("Vous êtes un apprenti voyant!\n");
                    } else {
                        printf("Vous êtes un voyant pusillanime!\n");
                    }

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
                        printf("Historique supprimé avec succès.\n");
                    } else {
                        printf("Erreur lors de la suppression de l'historique.\n");
                    }
                    break;

                case 4:
                    printf("Au revoir !\n");
                    return 0;
                    break;

                default:
                    printf("Choix invalide.\n");
            }
        } while (choix != 3);


    return 0;
}
