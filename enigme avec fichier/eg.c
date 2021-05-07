#include"eg.h"

void init_enigme(enigme * e)
{
	e->pos.x=0;
	e->pos.y=0;	
	e->srf=NULL;


}

int  enigmee(enigme *screen,int* e1,int* e2,int* e3,int* e4,int* e5,int *close,int rep)
{
enigme e;
int r=0,A=0;
    FILE* fichier=NULL;
    FILE* fichierr=NULL;
 do {
    srand(time(NULL));
   r=rand()%8+1;
   printf("%d\n",r );
 } while(r==(*e1)||r==(*e2)||r==(*e3)||r==(*e4)||r==(*e5));
  if (rep==1) (*e1)=r;
   if (rep==2) (*e2)=r;
    if (rep==3) (*e3)=r;
    if (rep==4) (*e4)=r;
      if (rep==5) (*e5)=r;


    char chaine[256]="";
    char chainer[256]="";
    fichier=fopen("fichier/question.txt", "r");
    fichierr=fopen("fichier/reponse.txt", "r");
int i =0;
while (fgets (chaine, 256, fichier ) != NULL && fgets (chainer, 256, fichierr ) !=NULL)
{
  i++;
  if (i==r) {
break;
  }
}
(e.fond)=NULL;
(e.texte)=NULL;
(e.rp)=NULL;
    SDL_Event event;
    TTF_Font *police = NULL, *police1 = NULL;
    SDL_Color couleurRouge = {255, 0, 0};
    SDL_Color couleurGris = {173, 167, 167};
  int continuer = 1;
  //  SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
e.fond = IMG_Load("graphic/back.png");
police = TTF_OpenFont("graphic/Bubblegum.ttf", 25);
police1 = TTF_OpenFont("graphic/font.ttf", 30);
e.texte = TTF_RenderText_Blended(police,chaine, couleurRouge);
e.rp = TTF_RenderText_Blended(police1,chainer, couleurGris);


  while (continuer)
    {
        (e.pos).x = 0;
        (e.pos).y = 0;
          SDL_BlitSurface(e.fond, NULL, screen->srf, &(e.pos));

        (e.pos).x = 170;
        (e.pos).y = 200;
        SDL_BlitSurface(e.texte, NULL, screen->srf, &(e.pos));

        (e.pos).x = 170;
        (e.pos).y = 370;
        SDL_BlitSurface(e.rp, NULL, screen->srf, &(e.pos));

        SDL_Flip(screen->srf);
      SDL_WaitEvent(&event);
     switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                (*close)=1;
                break;
                case SDL_KEYDOWN:
            			switch (event.key.keysym.sym)
        {

            				case SDLK_KP1:
                  if (r==1||r==4||r==7)  A=1 ; continuer=0;
break;

  case SDLK_KP2:
               if (r==2||r==5||r==8) A=1; continuer=0;
break;

	case SDLK_KP3:
               if (r==3||r==6) A=1; continuer=0;
break;
}
       }

   }

    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface((e.texte));
return A;
}
