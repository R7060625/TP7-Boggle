#include "Grille.c"
#include <stdio.h>
#include <time.h>

int main(void){

    // Initialiser le générateur de nombres aléatoires
    srand(time(0));

    Grille grille;
    initialiser_grille(grille);

    return 0;
}