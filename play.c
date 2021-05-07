#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "play.h"



/*************************************************************  INTEGRATION  *************************************************************/

int nb_enigme=3;
int play1(SDL_Surface *ecran1)
{

temps t;    
obstacle o1,o2,o3;
background bg;
personnage p;
enigme e,screen;
int done=1,x; // lorsqu'on clique sur le clavier
int hauteur_fenetre = 700,
        largeur_fenetre = 1600;
 int enigme_right=0,e1=0,e2=0,e3=0,e4=0,e5=0,rep=0 ;

int close=0;
screen.srf = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	/* Declaration des SDLs */

SDL_Surface *ecran=NULL;
SDL_Rect *position_ecran;
SDL_Event event;
SDL_Rect positionecran;


        

 
/*---- fenetre et ecran ----*/

 SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
 TTF_Init();
 SDL_EnableKeyRepeat(100,100); //Fonctions de la SDL permettant d'initialiser la fenêtre

    ecran = SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("aaaaa", NULL);



// Ennemis 
ennemi en1,en2;

int ennemi1=1;
int ennemi2=2;

int touche=1; 
int sens=0;
//le fonction

initialiser_background(&bg);
initialiser_personnage(&p);
init_enigme(&e);
initialiser_ennemi1(&en1);
initialiser_ennemi2(&en2);

positionecran.x=0;
positionecran.y=0;
// Use image->w to display the entire width of the image
 
// Use image->h to display the entire height of the image



	/****----- la boucle du jeu -----****/
 //SDL_EnableKeyRepeat(100,100);
x=p.position_personnage.y;
// hp ....
SDL_Rect php; 
SDL_Surface *hp[6];
int fhp;

php.x=0;
php.y=0;
php.w=10;
php.h=10;
hp[0]=SDL_LoadBMP("hp/0.bmp");
hp[1]=SDL_LoadBMP("hp/1.bmp");
hp[2]=SDL_LoadBMP("hp/2.bmp");
hp[3]=SDL_LoadBMP("hp/3.bmp");
hp[4]=SDL_LoadBMP("hp/4.bmp");
hp[5]=SDL_LoadBMP("hp/5.bmp");
SDL_SetColorKey(hp[5], SDL_SRCCOLORKEY, SDL_MapRGB(hp[5]->format,238, 229, 179));
//score
SDL_Rect ps; 
SDL_Surface *score[6];
int fs;
ps.x=257;
ps.y=0;
ps.w=100;
ps.h=50;

score[0]=IMG_Load("score/0.jpg");
score[1]=IMG_Load("score/1.jpg");
score[2]=IMG_Load("score/2.jpg");
score[3]=IMG_Load("score/3.jpg");
score[4]=IMG_Load("score/4.jpg");
score[5]=IMG_Load("score/5.jpg");
fhp=5;
fs=0;
int valeur_score=0; int nb_potion=0;
SDL_SetColorKey(score[0], SDL_SRCCOLORKEY, SDL_MapRGB(score[0]->format,255, 255, 255));
SDL_SetColorKey(score[1], SDL_SRCCOLORKEY, SDL_MapRGB(score[1]->format,255, 255, 255));
SDL_SetColorKey(score[2], SDL_SRCCOLORKEY, SDL_MapRGB(score[2]->format,255, 255, 255));
SDL_SetColorKey(score[3], SDL_SRCCOLORKEY, SDL_MapRGB(score[3]->format,255, 255, 255));
SDL_SetColorKey(score[4], SDL_SRCCOLORKEY, SDL_MapRGB(score[4]->format,255, 255, 255));
SDL_SetColorKey(score[5], SDL_SRCCOLORKEY, SDL_MapRGB(score[5]->format,255, 255, 255));
/*POTIONS*/
int potion0=1;
int potion1=2;
int potion2=3;int potion3=4
;int potion4=5;int potion5=6;
int potion6=7;int potion7=8;int potion8=9;
int potion9=10;


initialiser_temps(&t);
initialiser_obstacle1(&o1);
initialiser_obstacle2(&o2);
initialiser_obstacle3(&o3);
initialiser_potion();

	while (done)
	{
/*-----affichage -----*/
afficher_background(bg,ecran);
afficher_personnage(p,ecran);


SDL_BlitSurface(score[fs],NULL,ecran,&ps);
SDL_BlitSurface(hp[fhp],NULL,ecran,&php);



//if(ennemi1)
afficher_ennemi1(en1,ecran);
//if(ennemi2)
afficher_ennemi2(en2,ecran);


afficher_obstacle1(o1,ecran);
afficher_obstacle2(o2,ecran);
afficher_obstacle3(o3,ecran);




if (potion1)
afficher_potion1(ecran);

afficher_temps(&t,ecran);

int clic=0,clic1=0;
 // variable que lorsqu'on clique sur la touche elle nous indique le sens

        while(SDL_PollEvent(&event))
        {
//SDL_SetColorKey(hp[fhp], SDL_SRCCOLORKEY, SDL_MapRGB(hp[fhp]->format, 0, 255, 255));
            switch(event.type)
            {
                case SDL_QUIT:
                done=1;
                break;

                //les touches de clavier
                case SDL_KEYDOWN: // touches enfoncées
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_m:  //echape
                    done = 1;
                    printf("fin");
		load (&p,t);
		save (p,t);
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
                    case SDLK_t:
                      fs--;
                    break;



                   }
                break;
//les touches de clavier
                case SDL_KEYUP: // touches enfoncées
                    switch (event.key.keysym.sym)
                    {
                    
                    case SDLK_LEFT: // Flèche droite
                     clic=1;
                    // x=p.position_personnage.y;
                    break;

                    case SDLK_RIGHT: // Flèche gauche
                        clic=2;
                        //x=p.position_personnage.y;
                    break;
                      case SDLK_UP: // Flèche haut                
                        clic=2;
                        x=p.position_personnage.y;
                        clic1=1;      
                    break;
                   case SDLK_DOWN: // Flèche bas
                        clic=2;
                       // x=p.position_personnage.y;
                    break;
                  case SDLK_d:
                    clic=2;
                    //x=p.position_personnage.y;
                    break;
                    case SDLK_q:
                    clic=1;
                   // x=p.position_personnage.y;
                    break;
                    case SDLK_c:
                    clic=2;
                   // x=p.position_personnage.y;
                    break;
                    case SDLK_o:
                    clic=2;
                    //x=p.position_personnage.y;
                    break;
                    case SDLK_p:
                    clic=1;
                    //x=p.position_personnage.y;
                    break;
                    case SDLK_x:
                    clic=1;
                    //x=p.position_personnage.y;
                    break;
                   }
                break;

}
if (fhp<=0)
fhp=0;

if (fhp>=5)
fhp=5;

if (fs<=0)
fs=0;

if (fs>=5)
fs=5;
}
if (clic!=0)
{
	/*-----deplacement du personnage -----*/
deplacement_clavier(&p,clic);
Evolue(&p,clic,clic1,x);
scrolling_bg(clic,&bg);
	/*--- animations Ennemis---*/
animation_droite (&en1);
SDL_Delay(80);
animation_droite2 (&en2);
SDL_Delay(80);

/* pour faire rouler les entites au meme temps avec le scrolling du perso */
scroll_ennemi(clic,&en1);
scroll_ennemi2(clic,&en2);

scroll_obstacle(clic,&o1);
scroll_obstacle2(clic,&o2);
scroll_obstacle3(clic,&o3);
scroll_potion1(clic,&pt1);


}









/**------- collision avec ennemi -------**/

/*-collision ennemi 1-*/
if(collision_enn(&p,en1)==1)
{ if (ennemi1==1)
{
for (int i=0;i<nb_enigme;i++)
{rep++;
enigme_right+=enigmee(&screen,&e1,&e2,&e3,&e4,&e5,&close,rep);
if (close) break;
}
if (enigme_right>=(nb_enigme/2)+1) 
{
printf("win\n");
fs++;
}
else fhp--;
ennemi1=0;}
}
/*-collision ennemi 2-*/
if( collision_enn2(&p,en2)==1)
{if (ennemi2==2)
{
for (int i=0;i<nb_enigme;i++)
{rep++;
enigme_right+=enigmee(&screen,&e1,&e2,&e3,&e4,&e5,&close,rep);
if (close) break;
}
if (enigme_right>=(nb_enigme/2)+1)
 {
printf("win\n");
fs++;
}
else fhp--;

ennemi2=0;}
}
		/**--------Collision avec les Potions-------**/

/*collision 1 */
if( collision_potion(&p,pt1)==1)
{if (potion1==2)
{nb_potion++;
fhp++;
fs++;
potion1=0;
SDL_FreeSurface(pt1.img_pt);
}}






/*--------FLIP------*/

SDL_Flip (ecran);
SDL_Flip (score[fs]);
SDL_Flip (hp[fhp]);
}

// liberation SDL
SDL_FreeSurface(ecran);
TTF_Quit();
SDL_Quit();


 return 1;
}
