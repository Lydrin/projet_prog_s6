#ifndef LISTECHAINES_H
#define LISTECHAINES_H
#include"structure.h"
void init_lchain(ListeOeuvre * list);
void ajout_tete_oeuvre(ListeOeuvre* list,int id,char* title,int year);
void ajout_tete_artist(ListeArtiste* list,int artistId,char* nom);
void supp_tete(ListeOeuvre * list);
void detruire_liste_oeuvre(ListeOeuvre* list);
void detruite_liste_artiste(ListeArtiste* list);
#endif
