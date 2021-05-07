#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "eg.h"
#include "enigme.h"


int nb_enigme=1;

int enigme1(SDL_Surface *ecran)
{
enigme screen,e;
    int hauteur_fenetre = 700,
        largeur_fenetre = 1100;



    SDL_Init(SDL_INIT_VIDEO);

    //FENETRE PRINCIPALE
    screen.srf = NULL;
    screen.srf = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
init_enigme(&e);
    SDL_WM_SetCaption("Enigme", NULL); // titre de la fenetre
  int enigme_right=0,e1=0,e2=0,e3=0,e4=0,e5=0,rep=0 ;

int close=0;

for (int i=0;i<nb_enigme;i++)
{rep++;
enigme_right+=enigmee(&screen,&e1,&e2,&e3,&e4,&e5,&close,rep);
if (close) break;
}

if (enigme_right>=(nb_enigme/2)+1) printf("win\n");
else printf("lose\n");


    SDL_Quit();

    return 0;
}
