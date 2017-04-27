#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"

void init_lchain(ListeOeuvre* list);

void afficher_liste(ListeOeuvre* list);

void ajout_tete_oeuvre(ListeOeuvre *,int id, char* title, int year);

void ajout_tete_artist(ListeArtiste *,char* artistId, char* nom);

void supp_tete(ListeOeuvre * list);

void ajout_oeuvre_annee(ListeOeuvre* pl,int id, char* title, int year);

void ajout_artist_colision(ListeArtiste* pl, char* artistId, char* nom);

void detruire_liste(ListeOeuvre* list); 
