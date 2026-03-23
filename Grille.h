#ifndef GRILLE_H
#define GRILLE_H

#define NB_LIGNES 4
#define NB_COLONNES 4

typedef struct {
    int ligne;
    int colonne;
    int cases[NB_LIGNES][NB_COLONNES];
} Grille;

typedef struct {
    int x;
    int y;
} Case;

typedef struct { int dx; int dy; } Direction;

const Direction directions[8] = {
    { 0, -1}, { 0,  1}, {-1,  0}, { 1,  0},  
    {-1, -1}, { 1, -1}, {-1,  1}, { 1,  1}   
};

typedef struct {
    char lettre;
    double cumul;
} Probabilite;

const Probabilite lettres[26] = {
        {'E', 0.11},
        {'T', 0.19},
        {'A', 0.26}, {'I', 0.33}, {'N', 0.40}, {'O', 0.47}, {'S', 0.54},
        {'R', 0.60},
        {'H', 0.65},
        {'D', 0.69}, {'L', 0.73},
        {'C', 0.76}, {'M', 0.79}, {'U', 0.82},
        {'B', 0.84}, {'F', 0.86}, {'G', 0.88}, {'P', 0.90}, {'W', 0.92}, {'Y', 0.94},
        {'J', 0.95}, {'K', 0.96}, {'Q', 0.97}, {'V', 0.98}, {'X', 0.99}, {'Z', 1.00}
    };

/* Initialise la grille Grille avec des lettres générées aléatoirement */
void initialiser_grille(Grille grille);

char lettre_random();

/* Retourne 1 si la case à la position (x,y) 
 * de la grille est une case voisine de la case courante 
 * case_courante et 0 sinon */
int est_voisine(Case case_courante, int x, int y);

#endif