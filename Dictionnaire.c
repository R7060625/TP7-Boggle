#include "Dictionnaire.h"
#include <string.h>
#include <stdlib.h>

static int sort_mots(const void* ptr1, const void* ptr2){

    char *a = (char*) ptr1;
    char *b = (char*) ptr2;

    return strcmp(a, b);
}

int cherche_mot(char* tab[], int taille, char* mot){
     
    int *val = bsearch( (void*) mot, (void*) tab, taille, sizeof(char*), &sort_mots);

    return val == NULL ? 0 : 1;
}




