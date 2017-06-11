#ifndef STRUCTURE_H
#define STRUCTURE_H
#define MAX_OEUVRES 80000
#define STRUCTURE_H 
#define TABLE_SIZE 334
typedef struct{
    int id;
    char* accession_number;
    char* artist;
    char* artistRole;
    int artistId;
    char* title;
    char* dateText;
    char* medium;
    char* creditLine;
    int year;
    int acquisitionYear;
    char* dimText;
    int width;
    int height;
    int depth;
    char* unit;
    char* inscription;
    char* thumbnailCopyright;
    char* thumbnailURL;
    char* url;
}Oeuvrefull; 

typedef struct Oeuvre{
    int id;
    char* title;
    int year;
    struct Oeuvre* next;
}Oeuvre, *ListeOeuvre;

typedef struct Artiste{
    int artisteId;
    char* nom;
    Oeuvre* PtOeuvre;
    struct Artiste* next;
    int nombreOeuvre;
}Artiste, *ListeArtiste;

typedef struct{
	Oeuvre* PtOeuvre;
	Artiste* PtArtiste;
}Vieille;

typedef ListeArtiste HashListeArtiste[TABLE_SIZE];
#endif
