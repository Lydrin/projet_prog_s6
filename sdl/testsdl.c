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
	
    	
	//INIT
	SDL_Surface * screen = NULL, *image = NULL, *bg=NULL;
	SDL_Init(SDL_INIT_VIDEO); 

	if (SDL_Init(SDL_INIT_VIDEO) == -1){
	        fprintf(stderr, "Erreur d'initialisation de la SDL");
	        return EXIT_FAILURE;
	}
	
	SDL_WM_SetCaption("Galerie Tate Britain", NULL);	
	screen = SDL_SetVideoMode(626, 626, 32, SDL_HWSURFACE); 


	//BACKGROUND
	SDL_Rect coor_bg;
	coor_bg.x = 0;
    	coor_bg.y = 0;
	bg = SDL_LoadBMP("pics/background.bmp");
	SDL_BlitSurface(bg, NULL, screen, &coor_bg);
	SDL_Flip(screen);

	//IMAGE
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

	SDL_Rect coor_img;
	coor_img.x = 150;
    	coor_img.y = 200;
	
	image = SDL_LoadBMP(path);
	if(image == NULL){
		image = SDL_LoadBMP("pics/indisponible.bmp");
	}
	
   	SDL_BlitSurface(image, NULL, screen, &coor_img);
	
	//PROCESS
	SDL_Flip(screen);
 	pause2();
	

	//FREE
	SDL_FreeSurface(image);
	SDL_FreeSurface(bg);
	SDL_Quit();
	return EXIT_SUCCESS;
}

 


