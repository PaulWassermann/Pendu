#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include "Fonctions.h"

int Saisie_Caractere() //Permet de récupérer les lettres saisies par l'utilisateur
{
    int Caractere_Saisi = 0;
    Caractere_Saisi = getchar();
    Caractere_Saisi = toupper(Caractere_Saisi);
    while (getchar() != '\n');
    return Caractere_Saisi;
}

int Cherche_Lettre(const char *Chaine, const char Lettre) //Permet de tester la présence d'une
{                                                         //lettre dans le mot mystère
    int i = 0;
    for (i = 0; i < strlen(Chaine); i++)
    {
        if (Chaine[i] == Lettre)
        {
            return 1;
        }
    }
    return 0;
}

int Compte_Mots(FILE *Fichier) //Compte le nombre de mots dans un fichier
{
    int Nombre_Lignes = 0;
    char Chaine[20] = "";
    rewind(Fichier);
    while(fgets(Chaine, 20, Fichier) != NULL)
    {
        Nombre_Lignes ++;
    }
    rewind(Fichier);
    return Nombre_Lignes;
}

int Mot_Aleatoire(char Difficulte, char *Mot) //Renvoie un mot aléatoire contenu dans le fichier
{
    srand(time(NULL));
    int Nombre_De_Mots = 0, Numero_Ligne_Aleatoire = 0, i = 0;
    char Chaine[20] = "";
    FILE *Fichier = NULL;
    if (Difficulte == FACILE)
    {
        Fichier = fopen("Facile.txt", "r");
        if (Fichier == NULL)
        {
            printf("\nEchec d'ouverture de fichier, le programmeur ne doit pas etre tres bon...\n");
            exit(0);
        }
    }
    if (Difficulte == INTERMEDIAIRE)
    {
        Fichier = fopen("Intermediaire.txt", "r");
        if (Fichier == NULL)
        {
            printf("\nEchec d'ouverture de fichier, le programmeur ne doit pas etre tres bon...\n");
            exit(0);
        }
    }
     if (Difficulte == DIFFICILE)
    {
        Fichier = fopen("Difficile.txt", "r");
        if (Fichier == NULL)
        {
            printf("\nEchec d'ouverture de fichier, le programmeur ne doit pas etre tres bon...\n");
            exit(0);
        }
    }
    rewind(Fichier);
    Nombre_De_Mots = Compte_Mots(Fichier);
    Numero_Ligne_Aleatoire = rand() % Nombre_De_Mots;
    for (i = 0; i < Numero_Ligne_Aleatoire; i++)
    {
        fgets(Chaine, 20, Fichier);
    }
    fgets(Mot, 20, Fichier);
    //printf("Le mot mystere est %s", Mot);
    Mot[strlen(Mot) - 1] = '\0';
    fclose(Fichier);
    return 1;
}

char Choix_Difficulte(char Difficulte, int *Nombre_De_Coups)
{
    do
    {   printf("\nChoisis le niveau de difficulte:\t1.Facile\t2.Intermediaire \t3.Difficile\t4.Manuel d'utilisation\n\n");
        Difficulte = Saisie_Caractere();
        while(Difficulte != FACILE && Difficulte != INTERMEDIAIRE && Difficulte != DIFFICILE && Difficulte != '4')
        {
            printf("\nTu peux choisir un chiffre valide boloss? Merci.\n");
            Difficulte = Saisie_Caractere();
        }
        if(Difficulte == '4')
        {
            printf("\nAnd I see you're a (wo)man of culture as well...\n"
                   "\n===== COMMENT JOUER? (POUR LES NULS) =====\n"
                   "\nApres avoir choisi le niveau de difficulte, le mot mystere apparaitra comme par magie!\n"
                   "Pour saisir une lettre, appuie sur la bonne touche du clavier (en minuscule ou en majuscule peu importe). "
                   "Il n'y a pas de caracteres speciaux.\n"
                   "Enfin, l'affichage de texte est mieux gere en plein ecran mais a toi de voir.\n"
                   "\n===== NIVEAUX DE DIFFICULTE =====\n"
                   "\n1.Facile\n"
                   "\nPour ce niveau de difficulte, tu rencontreras des mots allant de 5 a 7 lettres et "
                   "tu pourras faire jusqu'a 9 erreurs avant de perdre lamentablement\n(c'est quand meme cense etre facile, bref). "
                   "Ce mode est parfait pour une premiere partie ou pour t'echauffer avant de level up!\n"
                   "\n2.Intermediaire\n"
                   "\nDans ce mode plus difficile, tu te confronteras a des mots de 6 a 9 lettres (oulala), et "
                   "tu n'auras plus droit qu'a 7 erreurs (sympa le mec non?).\nSi t'es pas capable de trouver "
                   "les mots que te propose ce mode, interroge-toi sur tes choix de vie...\n"
                   "\n3.Difficile\n"
                   "\nBon, la ca rigole clairement plus. Le gouvernement tient a ce que l'etendue du nombre de lettres "
                   "des mots du mode difficile reste confidentielle.\nOn m'a autorise a dire que tu ne pourras faire que 5 erreurs. "
                   "Pour trouver les mots proposes, tu devras faire preuve de courage et bien entendu, d'intelligence.\n"
                   "\nAssez bavasse, maintenant tu peux retourner au choix du niveau de difficulte.\n");
        }
    }while(Difficulte == '4');
    if(Difficulte == FACILE)
    {
        *Nombre_De_Coups = 9;
    }
    if(Difficulte == INTERMEDIAIRE)
    {
        *Nombre_De_Coups = 7;
    }
    if(Difficulte == DIFFICILE)
    {
        *Nombre_De_Coups = 5;
    }
    return Difficulte;
}
