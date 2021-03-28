#ifndef FONCTIONS_INCLUDED
#define FONCTIONS_INCLUDED

#define FACILE '1'
#define INTERMEDIAIRE '2'
#define DIFFICILE '3'

int Saisie_Caractere();
int Cherche_Lettre(const char *Chaine, const char Lettre);
int Mot_Aleatoire(char Difficulte, char *Mot);
int Compte_Mots(FILE* Fichier);
char Choix_Difficulte(char Difficulte, int *Nombre_De_Coups);

#endif // FONCTIONS_INCLUDED
