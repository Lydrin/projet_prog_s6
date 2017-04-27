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

#define FICHIER "./data/tate_artwork.csv"
#define MAX_STR_LEN 20000
char* parse(char* s);

bool read_file()
{ 
    FILE* fp;
    int i = 0;
    char* chaine = (char*)malloc(MAX_STR_LEN * sizeof(char));
    if ((fp = fopen(FICHIER, "r")) == NULL) {
        printf("Impossible d'ouvrir le fichier, introuvable ?\n");
    }
    fgets(chaine, MAX_STR_LEN,fp); //On passe la première ligne useless
    while (fgets(chaine, MAX_STR_LEN, fp) != NULL){
        char* idOeuvre;
        char* accession_number;
        char* artistName;
        char* artistId;
        char* title;
        int year;
        idOeuvre = strdup(parse(chaine));
        accession_number = strdup((parse(NULL)));
        artistName = strdup(parse(NULL));
        parse(NULL); //Pass artistRole
        artistId = strdup((parse(NULL)));
        title = strdup(parse(NULL));
        parse(NULL); //Pass dateText
        parse(NULL);   //Pass medium
        parse(NULL); //Pass creditLine
        year = atoi(parse(NULL)); 
        parse(NULL);//Pass acquisitionYear
        parse(NULL); //Pass dimText
        parse(NULL); //Pass width
        parse(NULL); //Pass height
        parse(NULL); //Pass depth
        parse(NULL); //Pass unit
        parse(NULL); //Pass inscription
        parse(NULL); //Pass thumbnailCopyright
        parse(NULL); //Pass thumbnailURL
        parse(NULL); //Pass url
        i++;
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
    HashListArtist ht;
    init_ht(ht);
    read_file(ht);
    //int i;
    //for(i=0;i<=ptrCollection->dernier;i++){
     //  afficher_oeuvre(ptrCollection->liste_oeuvre[i]);
    //}
    return 0;
}
