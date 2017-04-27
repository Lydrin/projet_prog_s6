#ifndef STDIO_H
    #include <stdio.h>
#endif

#ifndef STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef STDLIB_H
    #include <stdlib.h>
#endif

#ifndef STRING_H
    #include <string.h>
#endif

#ifndef STRUCTURE_H
    #include"structure.h"
#endif

#ifndef LISTECHAINES_H 
    #include "listechaines.h"
#endif

#ifndef HASH_H
    #include "hash.h"
#endif



void init_lchain(ListeOeuvre * list){ //Init new list
	*list = NULL;
}

void ajout_tete_oeuvre(ListeOeuvre* list,int id,char* title,int year){
	Oeuvre* newOeuvre = (Oeuvre*)malloc(sizeof(Oeuvre));
    newOeuvre->id = id;	
    newOeuvre->title = strdup(title);
    newOeuvre->year = year;	
	(*newOeuvre).next = *list;
	*list = newOeuvre;
}

void ajout_tete_artist(ListeArtiste* list,char* artistId,char* nom){
     Artiste* newArtist = (Artiste*)malloc(sizeof(Artiste));
     newArtist->artistId = artistId;
     newArtist->nom = nom;
     newArtist->PtOeuvre =(Oeuvre*)malloc(sizeof(Oeuvre));
     newArtist->nombreOeuvre = 0;
     (*newArtist).next = *list;
     *list = newArtist;
}


void supp_tete(ListeOeuvre * list){ //Fonction générique
    Oeuvre* tmp = *list;
	*list = (*tmp).next;
	free(tmp);
}


void detruire_liste(ListeOeuvre* list){ //Pareil
    Oeuvre* next;
    Oeuvre* current = *list;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

void ajout_oeuvre_annee(ListeOeuvre *pl,int id, char* title, int year){
       ajout_tete_oeuvre(pl,id,title,year); 
}
