#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "personnage.h"




/*************************************************************  INTEGRATION  *************************************************************/


int main(int argc, char *argv[])
{

        


personnage p,p1;

int done=1,x,x1; // lorsqu'on clique sur le clavier



	/* Declaration des SDLs */

SDL_Surface *ecran=NULL;
SDL_Rect *position_ecran;
SDL_Event event;
SDL_Surface *image;
SDL_Rect positionecran;
image = SDL_LoadBMP("bg1366x768.bmp");

        

 
/*---- fenetre et ecran ----*/

 SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
 TTF_Init();
 SDL_EnableKeyRepeat(100,100); //Fonctions de la SDL permettant d'initialiser la fenêtre

    ecran = SDL_SetVideoMode(1366,768,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("aaaaa", NULL);


//le fonction


initialiser_personnage(&p);
initialiser_personnage(&p1);

positionecran.x=0;
positionecran.y=0;
// Use image->w to display the entire width of the image
    positionecran.w=image->w;
// Use image->h to display the entire height of the image
    positionecran.h=image->h;


	/****----- la boucle du jeu -----****/
 SDL_EnableKeyRepeat(100,100);
x=p.position_personnage.y;
x1=p1.position_personnage.y;
// hp ....
SDL_Rect php; 
SDL_Surface *hp[5];
int fhp;

php.x=670;
php.y=0;
php.w=10;
php.h=10;
hp[0]=SDL_LoadBMP("hp/0.bmp");
hp[1]=SDL_LoadBMP("hp/1.bmp");
hp[2]=SDL_LoadBMP("hp/2.bmp");
hp[3]=SDL_LoadBMP("hp/3.bmp");
hp[4]=SDL_LoadBMP("hp/4.bmp");
hp[5]=SDL_LoadBMP("hp/5.bmp");
fhp=6;

//score
SDL_Rect ps; 
SDL_Surface *score[130];
int fs;


ps.x=1170;
ps.y=0;
ps.w=100;
ps.h=50;

score[0]=IMG_Load("score/0.JPG");
score[1]=IMG_Load("score/1.JPG");
score[2]=IMG_Load("score/2.JPG");
score[3]=IMG_Load("score/3.JPG");
score[4]=IMG_Load("score/4.JPG");
score[5]=IMG_Load("score/5.JPG");
fs=0;

	while (done)
	{
SDL_BlitSurface(image, NULL, ecran, &positionecran);
afficher_personnage(p,ecran);
afficher_personnage(p1,ecran);
SDL_BlitSurface(hp[fhp],NULL,ecran,&php);
SDL_BlitSurface(score[fs],NULL,ecran,&ps);
int clic=0,clic1=0;
int clic2=0,clic12=0;
 // variable que lorsqu'on clique sur la touche elle nous indique le sens

        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
                case SDL_QUIT:
                done=1;
                break;

                //les touches de clavier
                case SDL_KEYDOWN: // touches enfoncées
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:  // echape
                    done = 1;
                    break;

                    case SDLK_LEFT: // Flèche droite
                     clic=1;
                    break;

                    case SDLK_RIGHT: // Flèche gauche
                        clic=2;
                    break;
                    case SDLK_UP: // Flèche haut
                        clic=3;
                    break;
                   case SDLK_DOWN: // Flèche bas
                        clic=4;
                    break;
                  case SDLK_d:
                    clic=5;
                    break;
                    case SDLK_q:
                    clic=6;
                    break;
                    case SDLK_c:
                    clic=7;
                    break;
                    case SDLK_o:
                    clic=8;
                    break;
                    case SDLK_p:
                    clic=9;
                    break;
                    case SDLK_x:
                    clic=12;
                    break;
                    case SDLK_n:
                      fhp++;
                    break;
                    case SDLK_b:
                      fhp--;
                    break;
                    case SDLK_y:
                      fs++;
                    break;
                    case SDLK_u:
                      fs--;
                    break;
                    case SDLK_f: // Flèche droite
                     clic2=1;
                    break;

                    case SDLK_h: // Flèche gauche
                        clic2=2;
                    break;
                    case SDLK_t: // Flèche haut
                        clic2=3;
                    break;
                   case SDLK_g: // Flèche bas
                        clic2=4;
                    break;


                   }
                break;
//les touches de clavier
                case SDL_KEYUP: // touches enfoncées
                    switch (event.key.keysym.sym)
                    {
                    
                    case SDLK_LEFT: // Flèche droite
                     clic=1;

                    break;

                    case SDLK_RIGHT: // Flèche gauche
                        clic=2;

                    break;
                      case SDLK_UP: // Flèche haut                
                        clic=2;
                        x=p.position_personnage.y;
                        clic1=1;      
                    break;
                   case SDLK_DOWN: // Flèche bas
                        clic=2;

                    break;
                  case SDLK_d:
                    clic=2;

                    break;
                    case SDLK_q:
                    clic=1;

                    break;
                    case SDLK_c:
                    clic=2;

                    break;
                    case SDLK_o:
                    clic=2;

                    break;
                    case SDLK_p:
                    clic=1;

                    break;
                    case SDLK_x:
                    clic=1;

                    break;
		    case SDLK_t: // Flèche haut                
                        clic2=2;
                        x1=p.position_personnage.y;
                        clic12=1;      
                    break;
                   }
                break;

}
if (fhp<=0)
{
fhp=0;
}
if (fhp>=5)
{
fhp=5;
}
if (fs<=0)
{
fs=0;
}
if (fs>=5)
{
fs=5;
}
}
if (clic!=0)
{
	/*-----deplacement du personnage -----*/
deplacement_clavier(&p,clic);
Evolue(&p,clic,clic1,x);
}
if (clic2!=0)
{
	/*-----deplacement du personnage -----*/
deplacement_clavier(&p1,clic2);
Evolue(&p1,clic2,clic12,x1);
}
/*while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
                //les touches de clavier
                case SDL_KEYDOWN: // touches enfoncées
                    switch (event.key.keysym.sym)
                    {               
                    /*
                  case SDLK_d:
                    clic=5;
                    break;
                    case SDLK_q:
                    clic=6;
                    break;
                    case SDLK_c:
                    clic=7;
                    break;
                    case SDLK_o:
                    clic=8;
                    break;
                    case SDLK_p:
                    clic=9;
                    break;
                    case SDLK_x:
                    clic=12;
                    break;
                    case SDLK_n:
                      fhp++;
                    break;
                    case SDLK_b:
                      fhp--;
                    break;
                    case SDLK_y:
                      fs++;
                    break;
                    case SDLK_t:
                      fs--;
                    break;



                   }
                break;

//les touches de clavier
                case SDL_KEYUP: // touches enfoncées
                    switch (event.key.keysym.sym)
                    {
                    
                    /*case SDLK_LEFT: // Flèche droite
                     clic=1;
                    break;

                    case SDLK_RIGHT: // Flèche gauche
                        clic=2;
                    break;*/
                      
					/*
                   case SDLK_DOWN: // Flèche bas
                        clic=2;
                    break;
                  case SDLK_d:
                    clic=2;
                    break;
                    case SDLK_q:
                    clic=1;
                    break;
                    case SDLK_c:
                    clic=2;
                    break;
                    case SDLK_o:
                    clic=2;
                    break;
                    case SDLK_p:
                    clic=1;
                    break;
                    case SDLK_x:
                    clic=1;
                    break;
                   }
                break;

}
}*/






/*--------FLIP------*/

SDL_Flip (ecran);

}
// liberation SDL
TTF_Quit();
SDL_Quit();


 return 1;
}
