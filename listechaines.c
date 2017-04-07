#include "listechaines.h"
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

void ajout_artist_colision(ListeArtiste *pl, char* artistId, char* nom){
    if( (*pl=NULL) || (strcmp(nom,(*pl) -> nom) < 1)){
            ajout_tete_artist(pl,artistId,nom);
    }
    else if(strcmp(nom,(*pl)->nom)>1){
        ajout_artist_colision(&(*pl)->next,artistId,nom);
    }
}
void ajout_oeuvre_annee(ListeOeuvre *pl,int id, char* title, int year){
    if( (*pl=NULL) || (year <= (*pl) -> year)){
       ajout_tete_oeuvre(pl,id,title,year); 
    }
    else if(year > (*pl) -> year){
        ajout_oeuvre_annee(&(*pl)->next,id,title,year);
    }


}

int taille(ListeOeuvre list){
    int i = 0;
    while(list!=NULL){
        i++;
        list = list -> next;
    }
    return i;
}
