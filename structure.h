#define MAX_OEUVRES 80000
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
}Oeuvre; 

typedef struct{
    Oeuvre liste_oeuvre[MAX_OEUVRES];
    int dernier;
}Collection;
