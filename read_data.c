#include "structure.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FICHIER "./data/tate_artwork.csv"
#define MAX_STR_LEN 20000
char* parse(char* s);

bool read_file(Collection* ptrCollection)
{ 
    FILE* fp;
    int i = 0;
    char* chaine = (char*)malloc(MAX_STR_LEN * sizeof(char));
    if ((fp = fopen(FICHIER, "r")) == NULL) {
        printf("Impossible d'ouvrir le fichier, introuvable ?\n");
    }
    fgets(chaine, MAX_STR_LEN,fp); //On passe la première ligne useless
    while (fgets(chaine, MAX_STR_LEN, fp) != NULL) {
        Oeuvrefull* current = &(ptrCollection->liste_oeuvre[i]);
        current->id = atoi(parse(chaine));
        current->accession_number = strdup((parse(NULL)));
        current->artist = strdup(parse(NULL));
        current->artistRole = strdup(parse(NULL));
        current->artistId = atoi((parse(NULL)));
        current->title = strdup(parse(NULL));
        current->dateText = strdup(parse(NULL));
        current->medium = strdup(parse(NULL));
        current->creditLine = strdup(parse(NULL));
        current->year = atoi(parse(NULL));
        current->acquisitionYear = atoi(parse(NULL));
        current->dimText = strdup(parse(NULL));
        current->width = atoi(parse(NULL));
        current->height = atoi(parse(NULL));
        current->depth = atoi(parse(NULL));
        current->unit = strdup(parse(NULL));
        current->inscription = strdup(parse(NULL));
        current->thumbnailCopyright = strdup(parse(NULL));
        current->thumbnailURL = strdup(parse(NULL));
        current->url = strdup(parse(NULL));
        i++;
        ptrCollection -> dernier +=1;
    }
    free(chaine);
    chaine = NULL;
    return true;
}

void afficher_oeuvre(Oeuvrefull oeuvre)
{

    printf("ID : %d\n", oeuvre.id);
    printf("accession_number : %s\n", oeuvre.accession_number);
    printf("artist : %s\n", oeuvre.artist);
    printf("artisteRole : %s\n", oeuvre.artistRole);
    printf("artistId : %d\n", oeuvre.artistId);
    printf("title : %s\n", oeuvre.title);
    printf("dateText : %s\n", oeuvre.dateText);
    printf("medium : %s\n", oeuvre.medium);
    printf("creditLine : %s\n", oeuvre.creditLine);
    printf("year : %d\n", oeuvre.year);
    printf("acquisitionYear : %d\n", oeuvre.acquisitionYear);
    printf("dimensions : %s\n", oeuvre.dimText);
    printf("width : %d\n", oeuvre.width);
    printf("height : %d\n", oeuvre.height);
    printf("depth : %d\n", oeuvre.depth);
    printf("units : %s\n", oeuvre.unit);
    printf("inscription : %s\n", oeuvre.inscription);
    printf("thumbnailURL : %s\n", oeuvre.thumbnailURL);
    printf("url : %s\n", oeuvre.url);
}

int main(void)
{
    Collection* ptrCollection = (Collection*)malloc(sizeof(Collection));
    ptrCollection -> dernier = -1;
    read_file(ptrCollection);
    //int i;
    //for(i=0;i<=ptrCollection->dernier;i++){
     //  afficher_oeuvre(ptrCollection->liste_oeuvre[i]);
    //}
    return 0;
}
