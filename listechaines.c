#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include"structure.h"
#include "listechaines.h"
#include "hash.h"

void init_lchain(ListeOeuvre * list){ //Init new list
	*list = NULL;
}

void ajout_tete_oeuvre(ListeOeuvre* list,int id,char* title,int year){
	Oeuvre* newOeuvre = (Oeuvre*)malloc(sizeof(Oeuvre));
    newOeuvre->id = id;	
    newOeuvre->title = strdup(title);
    strcpy(newOeuvre->title,title);
    newOeuvre->year = year;	
	newOeuvre->next = *list;
	*list = newOeuvre;
}

void ajout_tete_artist(ListeArtiste* list,int artistId,char* nom){
     Artiste* newArtist = (Artiste*)malloc(sizeof(Artiste));
     newArtist->artisteId = artistId;
     newArtist->nom=strdup(nom);
     newArtist->PtOeuvre = NULL;
     newArtist->nombreOeuvre = 0;
     newArtist->next = *list;
     *list = newArtist;
}


void supp_tete(ListeOeuvre * list){ //Fonction générique
    Oeuvre* tmp = *list;
	*list = tmp->next;
	free(tmp);
}


void detruire_liste_oeuvre(ListeOeuvre* list){ //Pareil
    Oeuvre* next;
    Oeuvre* current = *list;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

void detruite_liste_artiste(ListeArtiste* list){
    Artiste* next;
    Artiste* current = *list;
    while(current != NULL){
        detruire_liste_oeuvre(&(current->PtOeuvre));
        next = current -> next;
        free(current);
        current = next;
    }
}

