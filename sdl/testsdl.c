#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <unistd.h>
 

void pause2(){
	int continuer = 1;
	SDL_Event event;
	while (continuer){

		SDL_WaitEvent(&event);
        	switch(event.type){
	       		case SDL_QUIT:
	        	        continuer = 0;
				break;
        	}
    	}
}
 

int main(int argc, char *argv[]){
	
    	
	char img[6];
	scanf("%[^\n]s", &img);
	char cmd[18];
	strcpy(cmd,"bash img_dl.sh ");
	strcat(cmd, img);
	system(cmd);
	
	strcat(img,"_8.bmp");
	char path[20];
	strcpy(path,"pics/");
	strcat(path,img);
	
	SDL_Surface * screen = NULL, *imageDeFond = NULL;;
	SDL_Init(SDL_INIT_VIDEO); 
	SDL_Rect positionFond;
	positionFond.x = 0;
    	positionFond.y = 0;

	if (SDL_Init(SDL_INIT_VIDEO) == -1){
	        fprintf(stderr, "Erreur d'initialisation de la SDL");
	        return EXIT_FAILURE;
	}
	
	SDL_WM_SetCaption("Galerie Tate Britain", NULL);
	
	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); 
	imageDeFond = SDL_LoadBMP(path);
	if(imageDeFond == NULL){
		imageDeFond = SDL_LoadBMP("pics/indisponible.bmp");
	}
	
   	SDL_BlitSurface(imageDeFond, NULL, screen, &positionFond);
	SDL_Flip(screen);

 	pause2();
	
	SDL_FreeSurface(imageDeFond);
	SDL_Quit();
	return EXIT_SUCCESS;
}

 


