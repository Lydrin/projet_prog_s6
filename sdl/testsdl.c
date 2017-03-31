#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <unistd.h>

#define W_HEIGHT 626
#define W_WIDTH 626


void load_image(SDL_Surface ** dest, SDL_Rect * coor_img, char * img){
	char cmd[18];
	strcpy(cmd,"bash img_dl.sh ");
	strcat(cmd, img);
	system(cmd);


	char path[20];
	strcpy(path,"pics/");
	strcat(path,img);
	strcat(path,"_8.bmp");

	*dest = SDL_LoadBMP(path);
	if(*dest == NULL){
		*dest = SDL_LoadBMP("pics/indisponible.bmp");
	}
	coor_img->x = (W_WIDTH - (*dest)->w)/2;
	coor_img->y = (W_HEIGHT*0.6) - (*dest)->h/2;	
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
	screen = SDL_SetVideoMode(W_HEIGHT, W_WIDTH, 32, SDL_HWSURFACE); 



	//BACKGROUND
	SDL_Rect coor_bg;
	coor_bg.x = 0;
    	coor_bg.y = 0;
	bg = SDL_LoadBMP("pics/background.bmp");
	SDL_BlitSurface(bg, NULL, screen, &coor_bg);
	SDL_Flip(screen);



	//IMAGE
	char img[6];
	scanf("%s",&img);
	SDL_Rect coor_img;
	load_image(&image,&coor_img,img);
	if(image!=NULL){
   		SDL_BlitSurface(image, NULL, screen, &coor_img);
	}



	//PROCESS
	SDL_Flip(screen);
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


	//FREE
	SDL_FreeSurface(image);
	SDL_FreeSurface(bg);
	SDL_Quit();
	return EXIT_SUCCESS;
}

 


