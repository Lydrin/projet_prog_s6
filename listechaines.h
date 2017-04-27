#ifndef STRUCTURE_H
    #include"structure.h"
#endif

#ifndef HASH_H
    #include "hash.h"
#endif

#define LISTECHAINES_H 

void init_lchain(ListeOeuvre* list);

void afficher_liste(ListeOeuvre* list);

void ajout_tete_oeuvre(ListeOeuvre *,int id, char* title, int year);

void ajout_tete_artist(ListeArtiste *,char* artistId, char* nom);

void supp_tete(ListeOeuvre * list);

void ajout_oeuvre_annee(ListeOeuvre* pl,int id, char* title, int year);

void ajout_artist_colision(ListeArtiste* pl, char* artistId, char* nom);

void detruire_liste(ListeOeuvre* list); 
