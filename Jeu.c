#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Fonctions.h"


void Jeu()
{
    char Rejouer = '1';
    do
    {
        int Trouve = 0, Nombre_De_Coups = 0, Nombre_De_Tours = 0;
        char Mot_Mystere[100] = {0}, *Mot_Affiche = NULL, Lettres_Saisies[30] = {0};
        char Difficulte = 0;
        Difficulte = Choix_Difficulte(Difficulte, &Nombre_De_Coups);
        if(Mot_Aleatoire(Difficulte, Mot_Mystere) != 1)
        {
            printf("Echec du choix d'un mot.");
            exit(0);
        }
        int Taille_Mot = strlen(Mot_Mystere), i = 0, j = 0;
        Mot_Affiche = malloc(Taille_Mot * sizeof(char));
        if (Mot_Affiche == NULL)
        {
            exit(0);
        }
        for (i = 0; i < Taille_Mot; i++)
        {
            Mot_Affiche[i] = '*';
        }
        Mot_Affiche[Taille_Mot] = '\0';
        printf("\nLe mot mystere est compose de %d lettres!\n", Taille_Mot);
        do
        {
            printf("\nVoici les lettres que tu as trouvees (ou pas): %s", Mot_Affiche);
            printf("\t\tLettres deja saisies: %s", Lettres_Saisies);
            printf("\nSaisis une lettre! Il te reste %d coup%s avant la defaite.\n\n", Nombre_De_Coups, (Nombre_De_Coups >1) ? "s" : "");
            char Caractere_Saisi = 0;
            Caractere_Saisi = Saisie_Caractere();
            if(Cherche_Lettre(Lettres_Saisies, Caractere_Saisi) == 1)
            {
                printf("\nT'as deja essaye cette lettre, je suis sympa je fais genre j'ai rien vu.\n");
            }
            else
            {
                Lettres_Saisies[Nombre_De_Tours] = Caractere_Saisi;
                Lettres_Saisies[Nombre_De_Tours + 1] = '\0';
                if(Cherche_Lettre(Mot_Mystere, Caractere_Saisi) == 1)
                {
                    for (j = 0; Mot_Mystere[j] != '\0'; j++)
                    {
                        if (Mot_Mystere[j] == Caractere_Saisi)
                        {
                            Mot_Affiche[j] = Caractere_Saisi;
                        }
                    }
                    if(strcmp(Mot_Mystere, Mot_Affiche) == 0)
                    {
                        Trouve = 1;
                        printf("\nOuah! Tu as trouve le mot mystere, c'etait bien %s!\n", Mot_Mystere);
                    }
                    else
                    {
                        printf("\nBien joue! Tu as trouve une lettre!\n");
                    }
                }
                else
                {
                    Nombre_De_Coups -= 1;
                    printf("\nHAHA, RATE!\n");
                }
                Nombre_De_Tours ++;
            }
        if (Nombre_De_Coups == 0)
        {
            printf("\nOn dirait bien que tu n'es pas le couteau le plus aiguise du tiroir... Il fallait trouver %s!\n", Mot_Mystere);
        }
        }while (Trouve == 0 && Nombre_De_Coups > 0);
        free(Mot_Affiche);
        printf("\nC'est deja termine :( . Veux-tu rejouer?\n\n0.Non\t1.Oui\n\n");
        Rejouer = Saisie_Caractere();
        while(Rejouer != '0' && Rejouer != '1')
        {
        printf("\nAlala, on peut plus rien pour toi... Faut taper 0 ou 1!\n");
        Rejouer = Saisie_Caractere();
        }
    }while(Rejouer == '1');
    printf("\nMerci d'avoir joue! J'espere que tu as aime!\n");
}
