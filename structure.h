#define MAX_OEUVRES 10 
typedef struct{
    short width;
    short height;
    short depth;
    char unit[2];
}Dimensions;

typedef struct{
    char* nom;
    char* prenom;
    int artistId;
}Artist;

typedef struct{
    int id;
    char accession_number[6];
    Artist artiste;
    char* artisteRole;
    char* title;
    char* dateText;
    char* medium;
    char* creditLine;
    int year;
    int acquisitionYear;
    Dimensions dimensions;
    char* inscription;
    char* thumbnailCopyright;
    char* thumbnailURL;
    char* url;
}Oeuvre;

typedef struct{
    Oeuvre liste_oeuvre[MAX_OEUVRES];
    int dernier;
}Collection;
