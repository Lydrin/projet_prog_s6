#include <stdio.h>
#include<string.h>
#include "display.h"
#include "hash.h"
#include "structure.h"


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
	printf("List of pieces from %s (id = %d)\n",ptArtist->nom,ptArtist->artisteId);
	int cpt = 0;
	while(pOeuvre != NULL){
		cpt++;
		printf("\t[%d] %s\n",cpt,pOeuvre->title);
		pOeuvre = pOeuvre->next;
	}
}

void listeOeuvreByArtist(int idArtist, HashListeArtiste liste){
	int h = hash_int(idArtist);
	Artiste * ptArtist = liste[h];
	while(ptArtist != NULL){
		if(ptArtist->artisteId==idArtist){
			displayOeuvre(ptArtist);
			return;
		}
		else{
			ptArtist = ptArtist->next;
		}
	}
	printf("Error : this artist doesn't exist\n");
}

void displayNbOeuvre(Artiste * ptArtist){
	printf("The artist id:%d (%s) has %d pieces\n",ptArtist -> artisteId,ptArtist->nom, ptArtist->nombreOeuvre);
}

void nbOeuvreByArtist(int idArtist, HashListeArtiste liste){
	int h = hash_int(idArtist);
	Artiste * ptArtist = liste[h];
	while(ptArtist != NULL){
		if(ptArtist->artisteId==idArtist){
			displayNbOeuvre(ptArtist);
			return;
		}
		else{
			ptArtist = ptArtist->next;
		}
	}
	printf("Error : this artist doesn't exist\n");
}


void listeNbOeuvreByArtist(HashListeArtiste liste){
	int i;
	Artiste*  ptArtist;
	for(i=0;i<TABLE_SIZE;i++){
		ptArtist = liste[i];
		while(ptArtist != NULL){
			displayNbOeuvre(ptArtist);
			ptArtist = ptArtist->next;
		}
	}
}

void oldestOeuvre(Vieille * oldest){
	printf("The oldest piece is \"%s\" (%d) from %s\n",(oldest->PtOeuvre)->title,(oldest->PtOeuvre)->year,(oldest->PtArtiste)->nom);
}


