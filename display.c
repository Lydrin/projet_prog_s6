#ifndef STDIO_H
     #include <stdio.h>
#endif

#ifndef DISPLAY_H
	#include "display.h"
#endif

#ifndef HASH_H
	#include "hash.h"
#endif

#ifndef STRUCTURE_H
	#include "structure.h"
#endif


void listeOeuvre(HashListeArtiste liste){
	int i;
	Artiste * ptArtist;
	for(i=0;i<TABLE_SIZE;i++){
		ptArtist = liste[i];
		while(ptArtist != NULL){
			displayOeuvre(ptArtist);
			ptArtist = ptArtist->next;
		}
	}
}

void displayOeuvre(Artiste * ptArtist){
	Oeuvre * pOeuvre = ptArtist->PtOeuvre;
	printf("List of pieces from %s (id = %d)\n",ptArtist->nom,ptArtist->artistId);
	int cpt = 0;
	while(pOeuvre != NULL){
		cpt++;
		printf("\t[%d] %s\n",cpt,pOeuvre->title);
		pOeuvre = pOeuvre->next;
	}
}

void listeOeuvreByArtist(int idArtist, HashListeArtiste liste){
	int h = hash(idArtist);
	Artiste * ptArtist = liste[h];
	while(ptArtist != NULL){
		if(ptArtist->artistId == idArtist){
			displayOeuvre(ptArtist);
		}
		else{
			ptArtist = ptArtist->next;
		}
	}
	printf("Error : this artist doesn't exist\n");
}

void displayNbOeuvre(Artiste * ptArtist){
	printf("The artist id:%d (%s) has %d pieces\n",idArtist,ptArtist->nom, ptArtist->nombreOeuvre);
}

void nbOeuvreByArtist(int idArtist, HashListeArtiste liste){
	int h = hash(idArtist);
	Artiste * ptArtist = liste[h];
	while(ptArtist != NULL){
		if(ptArtist->artistId == idArtist){
			displayNbOeuvre(ptArtist);
		}
		else{
			ptArtist = ptArtist->next;
		}
	}
	printf("Error : this artist doesn't exist\n");
}


void listeNbOeuvreByArtist(ListeArtiste liste){
	int i;
	Artiste * ptArtist;
	for(i=0;i<TABLE_SIZE;i++){
		ptArtist = liste[i];
		while(ptArtist != NULL){
			displayNbOeuvre(ptArtist);
			ptArtist = ptArtist->next;
		}
	}
}

void oldestOeuvre(Vieille * oldest){
	printf("The oldest piece is \"%s\" (%d) from %s\n",(oldest->PtOeuvre)->nom,(oldest->PtOeuvre)->date,(oldest->PtArtiste)->nom);
}


