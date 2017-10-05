#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "read_data.h"
#include "structure.h"
#include "listechaines.h"
#include "hash.h"
#include "display.h"

int main(){
	HashListeArtiste ht; 
    init_ht(ht);
    Oeuvre* oldest = NULL;
    read_file(ht, &oldest);
	printf("--------------------------------------------------\n");
	printf("-- 		PROJET PROGRAMMATION	 	--\n");
	printf("--	DELOBELLE Matthieu - DUROT Anthony	--\n");
	printf("--		    IMA3 2017			--\n");
	printf("--------------------------------------------------\n");
	for(;;){
		printf("\nQue voulez vous faire ?\n");
		printf("\t1 - Liste de toutes les oeuvres\n");
		printf("\t2 [id] - Recherche d'un artiste\n");
		printf("\t3 [id] - Liste de toutes les oeuvres d'un artiste\n");
		printf("\t4 [id] - Nombre d'oeuvres d'un artiste\n");
		printf("\t5 - Nombre d'oeuvres par artiste\n");
		printf("\t6 - Oeuvre la plus vieille\n");
		printf("\t7 - Quitter\n\n");

		int choix;
		int id;
		scanf("%d", &choix);
		switch(choix){
			case 1:
				listeOeuvre(ht);
				break;
			case 2:
				printf("Pour quel ID ?\n");
				scanf("%d",&id);
				rechercheArtiste(id, ht);
				break;
			case 3:
				printf("Pour quel ID ?\n");
				scanf("%d",&id);
				listeOeuvreByArtist(id, ht);
				break;
			case 4:
				printf("Pour quel ID ?\n");
				scanf("%d",&id);
				nbOeuvreByArtist(id, ht);
				break;
			case 5:
				listeNbOeuvreByArtist(ht);
				break;
			case 6:
				oldestOeuvre(oldest);
				break;
			case 7:
				detruire_hash_table(ht);
				return 0;
			default:
				printf("Choix incorrect\n");

		}
	}
	return 0;
}
	
