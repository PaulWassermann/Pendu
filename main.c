#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Jeu.h"
#include "Fonctions.h"

int main(int argc, char* argv[])
{
    printf("\t\t\t\t\t======= LE JEU DU PENDU =======\n");
    printf("\nTu t'appretes a jouer au meilleur pendu du monde. Es-tu pret.e?\n");
    printf("\nL'ordinateur va alors choisir un mot au hasard, a toi de le retrouver!\n");
    Jeu();
    return 0;
}
