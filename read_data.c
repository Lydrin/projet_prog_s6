#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structure2.h"

#define FICHIER "./data/tate_artwork.csv"
#define MAX_STR_LEN 2000 
#define MAX_FIELD_LEN 100

bool read_file(Collection * ptrCollection){ //On prefere passer le pointeur
    FILE* fp;
    char c;
    char* chaine = (char *)malloc(MAX_STR_LEN*sizeof(char));
    bool quotes = false;
    const int taille[20]={80,70,1210,250,50,3250,760,1210,8220,40,40,2490,40,40,40,30,150,9850,580,135000000};
    int i = 0; 
    int j =0;
    if((fp=fopen(FICHIER,"r"))==NULL){
        printf("Impossible d'ouvrir le fichier, introuvable ?\n");
    }
    fgets(chaine,MAX_STR_LEN, fp);
    char *str=(char*)malloc(taille[0]*sizeof(char));
    strcpy(str,"");
    while((c=fgetc(fp))!=EOF){
        if(c=='\r'){
            ptrCollection->liste_oeuvre[i].url = strdup(str);
            free(str);
            j=0;
            i++;
            c = fgetc(fp);
            quotes = false;
            str = (char*)malloc(taille[j]*sizeof(char));
            strcpy(str,"");
        }
        else if(c=='"')
            quotes = !quotes;
        else if(c==',' && !quotes){
            Oeuvre* current = (Oeuvre*)malloc(sizeof(Oeuvre));
            current = &(ptrCollection->liste_oeuvre[i]);
            switch(j){
                case 0:
                    current->id = atoi(str);
                break;
                case 1:
                    current->accession_number = strdup(str);
                break;
                case 2:
                    current->artist = strdup(str);
                break;
                case 3:
                    current->artistRole = strdup(str);
                break;
                case 4:
                    current->artistId = atoi(str);
                break;
                case 5:
                    current->title = strdup(str);
                break;
                case 6:
                    current->dateText = strdup(str);
                break;
                case 7:
                    current->medium = strdup(str);
                break;
                case 8:
                    current->creditLine = strdup(str);
                break;
                case 9:
                    current->year = atoi(str);
                break;
                case 10:
                    current->acquisitionYear = atoi(str);
                break;
                case 11:
                    current->dimText = strdup(str);
                break;
                case 12:
                    current->width = atoi(str);
                break;
                case 13:
                    current->height = atoi(str);
                break;
                case 14:
                    current->depth = atoi(str);
                break;
                case 15:
                    current->unit = strdup(str);
                break;
                case 16:
                    current->inscription = strdup(str);
                break;
                case 17: 
                    current->thumbnailCopyright = strdup(str);
                break;
                case 18: 
                    current->thumbnailURL = strdup(str);
                break;
                case 19:
                    current->url = strdup(str);
                break;
            }
            j+=1;
            quotes = false;
            free(str);
            str = (char*)malloc(taille[j]*sizeof(char));
            strcpy(str,"");
        }
        else{
            char temp[2] = {c,'\0'};
            strcat(str,temp);
        }
    }

    return true;
}

void afficher_oeuvre(Oeuvre oeuvre){ 
    
    printf("ID : %d\n",oeuvre.id);
    printf("accession_number : %s\n",oeuvre.accession_number);
    printf("artist : %s\n",oeuvre.artist);
    printf("artisteRole : %s\n",oeuvre.artistRole);
    printf("artistId : %d\n",oeuvre.artistId);
    printf("title : %s\n",oeuvre.title);
    printf("dateText : %s\n",oeuvre.dateText);
    printf("medium : %s\n",oeuvre.medium);
    printf("creditLine : %s\n",oeuvre.creditLine);
    printf("year : %d\n",oeuvre.year);
    printf("acquisitionYear : %d\n",oeuvre.acquisitionYear);
    printf("dimensions : %s\n",oeuvre.dimText);
    printf("width : %d\n",oeuvre.width);
    printf("height : %d\n",oeuvre.height);
    printf("units : %s\n",oeuvre.unit);
    printf("inscription : %s\n",oeuvre.inscription);
    printf("thumbnailURL : %s\n",oeuvre.thumbnailURL);
    printf("url : %s\n",oeuvre.url);
}

int main(void){
    Collection* ptrCollection = (Collection *)malloc(sizeof(Collection));
    read_file(ptrCollection);
    afficher_oeuvre(ptrCollection->liste_oeuvre[2]);
    return 0;
}
