#include <stdlib.h>
#include <stdio.h>
#include "Grille.h"

char lettre_random(){

    // Choix aléatoire d'un nombre entre 0 et 1
    double r = (double)rand() / (double)RAND_MAX;
    char lettre_tiree = ' ';

    for (int i = 0; i < 26; i++){
        if (r <= lettres[i].cumul) {
            lettre_tiree = lettres[i].lettre;
            break;
        }
    }
    return lettre_tiree;
}

void initialiser_grille(Grille grille){
    for (int i = 0; i < NB_LIGNES; i++){
        for (int j = 0; j < NB_COLONNES; j++){
            char lettre = lettre_random();
            grille.cases[i][j] = lettre;
            // printf("%c ", lettre);
        }
        // printf("\n");
    }   
}

int est_voisine(Case case_courante, int x, int y){
    for (int i = 0; i < 8; i++){
        if (case_courante.x + directions[i].dx == x &&
            case_courante.y + directions[i].dy == y &&
            x >= 0 && x < 4 && y >= 0 && y < 4){
                return 1;
            }
    }
    return 0;
}

