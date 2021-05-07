#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "play.h"

#define SCREENFULL screen = SDL_SetVideoMode(1920,1080,32, SDL_FULLSCREEN | SDL_HWSURFACE | SDL_DOUBLEBUF);
#define SCREENWINDOWED screen = SDL_SetVideoMode(1366,768,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
#define IFULL image = SDL_LoadBMP("game_files/backgrounds/bg1920x1080.bmp");
#define IWINDOWED image = SDL_LoadBMP("game_files/backgrounds/bg1366x768.bmp");
#define MBGFULL menu_bg = SDL_LoadBMP("game_files/backgrounds/menu_bg1920x1080.bmp");
#define MBGWINDOWED menu_bg = SDL_LoadBMP("game_files/backgrounds/menu_bg1366x768.bmp");



void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int max=6;
int main (void) {




//################################# DECLARATOINS ###########################################
    SDL_Surface *screen; // reference to the backbuffer
    SDL_Surface *image; // reference to our image
    SDL_Surface *perso;
    SDL_Rect positionecran,pos_perso; // rect to describe the source destination region for our blit
    SDL_Event event;
	SDL_Surface *texte=NULL;
   	SDL_Surface *menu_bg;
    	SDL_Surface *play;
        SDL_Surface *play_selected;
   	SDL_Surface *settings;
	SDL_Surface *quit;
	SDL_Surface *settings_selected;
	SDL_Surface *quit_selected;
	SDL_Surface *fullscreen_checked;
	SDL_Surface *fullscreen_unchecked;
	SDL_Surface *soundplus;
	SDL_Surface *soundminus;
	SDL_Surface *fullscreen;
	SDL_Surface *volume;
	SDL_Surface *back;
	SDL_Surface *back_selected;
	SDL_Surface *vol_0;
	SDL_Surface *vol_1;
	SDL_Surface *vol_2;
	SDL_Surface *vol_3;
	SDL_Surface *vol_4;
	SDL_Surface *vol_5;
	SDL_Surface *object;
	SDL_Rect posIFS; // image full screen
	SDL_Rect posBFS;
	SDL_Rect posVI;
	SDL_Rect posIB;
	SDL_Rect posVS;
	SDL_Rect pos_text;
	SDL_Rect posVIU;
	SDL_Rect posVID;
	//SDL_Rect posOBJ;
	SDL_Color white={ 255, 255, 255};
	 // pos volume button
	SDL_Rect posP,posS,posQ,posBG; // pos play , pos options , pos quit
	int Mx=0,My=0;
        int play_s,settings_s,quit_s;
	int b_play_clicked=0,b_settings_clicked=0,b_quit_clicked=0,back_s=0,button_ticked=0;
	int volume_level=5;
	int keyboard_select=0;
	int menu=1;
     int continuer = 1;
	//int collision=0;
     TTF_Font *font=NULL;
//################################# DECLARATOINS ###########################################









// #########################################################################################################
	TTF_Init();
	font= TTF_OpenFont("game_files/fonts/Mighty Brush Demo.ttf",30);
    if ((SDL_Init(SDL_INIT_VIDEO != 0))) {
         printf("Unable to initialize SDL : %s\n",SDL_GetError() );
         return 1;
    }
screen = SDL_SetVideoMode(1366,768,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Demo :3", NULL);
  if (screen == NULL) {
    printf("unable to set video mode : %s\n",SDL_GetError() );
    return 1;
  }
// #########################################################################################################








// #########################################################################################################
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) == -1)
// API Mixer initialisation
{
  printf("%s\n",Mix_GetError() );
}
Mix_Music *music; // construct Mix_Music pointer
music = Mix_LoadMUS("game_files/sound/akatsuki.mp3"); // Load the music
Mix_PlayMusic(music,-1); //play music
 Mix_Chunk *son;
  son = Mix_LoadWAV("click.wav");
// #########################################################################################################








// #########################################################################################################
image = SDL_LoadBMP("game_files/backgrounds/bg1366x768.bmp"); // you can use IMG_Load
perso = SDL_LoadBMP("game_files/characters/deii.bmp");
menu_bg = SDL_LoadBMP("game_files/backgrounds/menu_bg1366x768.bmp");
play = SDL_LoadBMP("game_files/menu_images/play.bmp"); // you can use IMG_Load
settings = SDL_LoadBMP("game_files/menu_images/settings.bmp");
quit = SDL_LoadBMP("game_files/menu_images/quit.bmp");
play_selected = SDL_LoadBMP("game_files/menu_images/play-selected.bmp");
settings_selected = SDL_LoadBMP("game_files/menu_images/settings-selected.bmp");
quit_selected = SDL_LoadBMP("game_files/menu_images/quit-selected.bmp");
fullscreen_checked = SDL_LoadBMP("game_files/menu_images/fs_checked.bmp");
fullscreen_unchecked = SDL_LoadBMP("game_files/menu_images/fs_unchecked.bmp");
fullscreen =  SDL_LoadBMP("game_files/menu_images/fullscreen_image.bmp");
volume =  SDL_LoadBMP("game_files/menu_images/volume_image.bmp");
soundminus =  SDL_LoadBMP("game_files/menu_images/soundminus.bmp");
soundplus =  SDL_LoadBMP("game_files/menu_images/soundplus.bmp");
back = SDL_LoadBMP("game_files/menu_images/back.bmp");
back_selected = SDL_LoadBMP("game_files/menu_images/back_selected.bmp");
vol_0= SDL_LoadBMP("game_files/menu_images/vol_0.bmp");
vol_1= SDL_LoadBMP("game_files/menu_images/vol_1.bmp");
vol_2= SDL_LoadBMP("game_files/menu_images/vol_2.bmp");
vol_3= SDL_LoadBMP("game_files/menu_images/vol_3.bmp");
vol_4= SDL_LoadBMP("game_files/menu_images/vol_4.bmp");
vol_5= SDL_LoadBMP("game_files/menu_images/vol_5.bmp");
//object= SDL_LoadBMP("game_files/objects/object.bmp");
// #########################################################################################################

SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format,255, 255, 255));
SDL_SetColorKey(play, SDL_SRCCOLORKEY, SDL_MapRGB(play->format, 255, 186, 31));
SDL_SetColorKey(settings, SDL_SRCCOLORKEY, SDL_MapRGB(settings->format, 255, 186, 31));
SDL_SetColorKey(quit, SDL_SRCCOLORKEY, SDL_MapRGB(quit->format, 255, 186, 31));
SDL_SetColorKey(play_selected, SDL_SRCCOLORKEY, SDL_MapRGB(play_selected->format, 255, 186, 31));
SDL_SetColorKey(settings_selected, SDL_SRCCOLORKEY, SDL_MapRGB(settings_selected->format, 255, 186, 31));
SDL_SetColorKey(quit_selected, SDL_SRCCOLORKEY, SDL_MapRGB(quit_selected->format, 255, 186, 31));
SDL_SetColorKey(vol_0, SDL_SRCCOLORKEY, SDL_MapRGB(vol_0->format, 255, 186, 31));
SDL_SetColorKey(vol_1, SDL_SRCCOLORKEY, SDL_MapRGB(vol_1->format, 255, 186, 31));
SDL_SetColorKey(vol_2, SDL_SRCCOLORKEY, SDL_MapRGB(vol_2->format, 255, 186, 31));
SDL_SetColorKey(vol_3, SDL_SRCCOLORKEY, SDL_MapRGB(vol_3->format, 255, 186, 31));
SDL_SetColorKey(vol_4, SDL_SRCCOLORKEY, SDL_MapRGB(vol_4->format, 255, 186, 31));
SDL_SetColorKey(vol_5, SDL_SRCCOLORKEY, SDL_MapRGB(vol_5->format, 255, 186, 31));
SDL_SetColorKey(fullscreen_checked, SDL_SRCCOLORKEY, SDL_MapRGB(fullscreen_checked->format, 255, 186, 31));
SDL_SetColorKey(fullscreen_unchecked, SDL_SRCCOLORKEY, SDL_MapRGB(fullscreen_unchecked->format, 255, 186, 31));
SDL_SetColorKey(fullscreen, SDL_SRCCOLORKEY, SDL_MapRGB(fullscreen->format, 255, 186, 31));
SDL_SetColorKey(volume, SDL_SRCCOLORKEY, SDL_MapRGB(volume->format, 255, 186, 31));
SDL_SetColorKey(soundplus, SDL_SRCCOLORKEY, SDL_MapRGB(soundplus->format, 255, 186, 31));
SDL_SetColorKey(soundminus, SDL_SRCCOLORKEY, SDL_MapRGB(soundminus->format, 255, 186, 31));
SDL_SetColorKey(back, SDL_SRCCOLORKEY, SDL_MapRGB(back->format, 255, 186, 31));




// #########################################################################################################
if (image == NULL) {
    printf("Unable to load bitmap : %s\n",SDL_GetError() );
    return 1;
}
if (perso == NULL) {
    printf("Unable to load avatar : %s\n",SDL_GetError() );
    return 1;
}
if (menu_bg == NULL) {
    printf("Unable to load menu background : %s\n",SDL_GetError() );
    return 1;
}
if (play == NULL) {
    printf("Unable to load play button : %s\n",SDL_GetError() );
    return 1;
}
if (settings == NULL) {
    printf("Unable to load settings button : %s\n",SDL_GetError() );
    return 1;
}
if (quit == NULL) {
    printf("Unable to load quit button : %s\n",SDL_GetError() );
    return 1;
}
if (play_selected == NULL) {
    printf("Unable to load play_selected button : %s\n",SDL_GetError() );
    return 1;
}
if (settings_selected == NULL) {
    printf("Unable to load settings_selected button : %s\n",SDL_GetError() );
    return 1;
}
if (quit_selected == NULL) {
    printf("Unable to load quit_selected button : %s\n",SDL_GetError() );
    return 1;
}
if (fullscreen_checked == NULL) {
    printf("Unable to load fullscreeen_checked img : %s\n",SDL_GetError() );
    return 1;
}
if (soundplus == NULL) {
    printf("Unable to load sound plus img : %s\n",SDL_GetError() );
    return 1;
}
if (soundminus == NULL) {
    printf("Unable to load sound minus img : %s\n",SDL_GetError() );
    return 1;
}
if (fullscreen_unchecked == NULL) {
    printf("Unable to load fullscreen_unchecked img : %s\n",SDL_GetError() );
    return 1;
}
if (fullscreen == NULL) {
    printf("Unable to load fullscreen img : %s\n",SDL_GetError() );
    return 1;
}
if (volume == NULL) {
    printf("Unable to load volume img : %s\n",SDL_GetError() );
    return 1;
}
if (back == NULL) {
    printf("Unable to load back img : %s\n",SDL_GetError() );
    return 1;
}
if (back_selected == NULL) {
    printf("Unable to load back_selcted img : %s\n",SDL_GetError() );
    return 1;
}
//if (object == NULL) {
  //  printf("Unable to load object img : %s\n",SDL_GetError() );
  //  return 1;
//}
// #########################################################################################################







// #########################################################################################################
    positionecran.x=0;
    positionecran.y=0;
    pos_perso.x= screen->w / 2 - perso->w / 2;
    pos_perso.y= screen->w / 2 - perso->w / 2;
// Use image->w to display the entire width of the image
    positionecran.w=image->w;
// Use image->h to display the entire height of the image
    positionecran.h=image->h;
// menu positions here:
    	posBG.x=0;
    	posBG.y=0;
    posP.x= 1050;//screen->w / 2 - perso->w / 2;
    posP.y= 122; //screen->w / 2 - perso->w / 2;
    posS.x= 1050;
    posS.y= 200;
    posQ.x= 1050;
    posQ.y= 278;
    posIFS.x=800; //pos image fullscreen
    posIFS.y=150; //pos image fullscreen
    posBFS.x=1040; // pos button tick full screen
    posBFS.y=160;// pos button tick full screen
    posVI.x=800; // pos image volume ( text )
    posVI.y=225; // pos image volume ( text )
    posIB.x=930;  // pos image back to menu
    posIB.y=420;   // pos image back to menu
    posVS.x=1100;  // sound level indicator
    posVS.y=225;    // sound level indicator
    posVID.x=1040;  // sound minus
    posVID.y=240;    // sound minus
    posVIU.x=1280;  // sound plus
    posVIU.y=240;   // sound plus
	            pos_text.x=100;
                    pos_text.y=700;

	//posOBJ.x=930;
	//posOBJ.y=240;
// #########################################################################################################







// #########################################################################################################

// #########################################################################################################







// #########################################################################################################
// SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */
// #########################################################################################################
SDL_Rect postr;
int slow=0,i=0;
postr.x=100;
postr.y=365;

// #########################################################################################################
    while (continuer)
{

	play_s=0;
	settings_s=0;
	quit_s=0;
	back_s=0;
	//collision=0;
    SDL_WaitEvent(&event);


    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;

        case SDL_MOUSEMOTION:
        Mx=event.motion.x;
        My=event.motion.y;
// ###############################################################




// ###############################################################
 if (menu==1) {
if (Mx >= posP.x && Mx <= posP.x + posP.w && My >= posP.y && My <= posP.y + posP.h)
            {
         play_s=1;
}
else if (Mx >= posS.x && Mx <= posS.x + posS.w && My >= posS.y && My <= posS.y + posS.h)
            {
         settings_s=1;
}
else if (Mx >= posQ.x && Mx <= posQ.x + posQ.w && My >= posQ.y && My <= posQ.y + posQ.h)
            {
         quit_s=1;
}
} // IF MENU == 1 ENDS HERE
// ###############################################################





// ###############################################################
else if (menu==2) { // we're in settings page now
if (Mx >= posIB.x && Mx <= posIB.x + posIB.w && My >= posIB.y && My <= posIB.y + posIB.h)
            {
         back_s=1;
}

}
            break;
// ###############################################################







// ###############################################################
        case SDL_MOUSEBUTTONUP:
if (menu==1) {  // FI WOST EL MENU
	 if ((Mx >= posP.x && Mx <= posP.x + posP.w && My >= posP.y && My <= posP.y + posP.h) && (event.button.button == SDL_BUTTON_LEFT)) { Mix_PlayChannel(-1,son,0);
				texte= TTF_RenderText_Blended(font,"Let's GO !",white);

                    SDL_BlitSurface(texte, NULL, screen, &pos_text);
              menu=0;
  // GO TO GAME | MENU = 0;
	}

	 if ((Mx >= posS.x && Mx <= posS.x + posS.w && My >= posS.y && My <= posS.y + posS.h) && (event.button.button == SDL_BUTTON_LEFT)) { Mix_PlayChannel(-1,son,0);
              menu=2;
  // GO TO SETTINGS | MENU = 0;
	}

 	 if ((Mx >= posQ.x && Mx <= posQ.x + posQ.w && My >= posQ.y && My <= posQ.y + posQ.h) && (event.button.button == SDL_BUTTON_LEFT)) {
                       continuer = 0;
                       SDL_Quit();  // Quit program
	}
}
// ###############################################################








// ###############################################################
else if (menu==2) { // fel options
 if ((Mx >= posIB.x && Mx <= posIB.x + posIB.w && My >= posIB.y && My <= posIB.y + posIB.h) && (event.button.button == SDL_BUTTON_LEFT)) { Mix_PlayChannel(-1,son,0);
              menu=1;   // GO TO BACK TO MENU | MENU = 1;
	 	back_s=1;
	}
 if ((Mx >= posBFS.x && Mx <= posBFS.x + posBFS.w && My >= posBFS.y && My <= posBFS.y + posBFS.h) && (event.button.button == SDL_BUTTON_LEFT)) {
        if (button_ticked==0) {
        button_ticked=1;
	 // TICK full screen and make the window full screen
	SCREENFULL
	IFULL
	MBGFULL

    posP.x= 1550;//screen->w / 2 - perso->w / 2;
    posP.y= 122; //screen->w / 2 - perso->w / 2;
    posS.x= 1550;
    posS.y= 200;
    posQ.x= 1550;
    posQ.y= 278;
    posIFS.x=1300; //pos image fullscreen
    posIFS.y=150; //pos image fullscreen
    posBFS.x=1540; // pos button tick full screen
    posBFS.y=160;// pos button tick full screen
    posVI.x=1300; // pos image volume ( text )
    posVI.y=225; // pos image volume ( text )
    posIB.x=1430;  // pos image back to menu
    posIB.y=420;   // pos image back to menu

    posVS.x=1600;  // sound level indicator
    posVS.y=225;    // sound level indicator
    posVID.x=1540;  // sound minus
    posVID.y=240;    // sound minus
    posVIU.x=1780;  // sound plus
    posVIU.y=240;   // sound plus

                    pos_text.x=130;
                    pos_text.y=970;
	font= TTF_OpenFont("game_files/fonts/Mighty Brush Demo.ttf",43);
		}
// ###############################################################








// ###############################################################
        else if (button_ticked==1) {
	button_ticked=0;
	SCREENWINDOWED
	IWINDOWED
	MBGWINDOWED
    posP.x= 1050;//screen->w / 2 - perso->w / 2;
    posP.y= 122; //screen->w / 2 - perso->w / 2;
    posS.x= 1050;
    posS.y= 200;
    posQ.x= 1050;
    posQ.y= 278;
    posIFS.x=800; //pos image fullscreen
    posIFS.y=150; //pos image fullscreen
    posBFS.x=1040; // pos button tick full screen
    posBFS.y=160;// pos button tick full screen
    posVI.x=800; // pos image volume ( text )
    posVI.y=225; // pos image volume ( text )
    posIB.x=930;  // pos image back to menu
    posIB.y=420;   // pos image back to menu

    posVS.x=1100;  // sound level indicator
    posVS.y=225;    // sound level indicator
    posVID.x=1040;  // sound minus
    posVID.y=240;    // sound minus
    posVIU.x=1280;  // sound plus
    posVIU.y=240;   // sound plus

	            pos_text.x=100;
                    pos_text.y=700;
	font= TTF_OpenFont("game_files/fonts/Mighty Brush Demo.ttf",30);
	}
	}
// ###############################################################






int v=128;
// ###############################################################
 if ((Mx >= posVIU.x && Mx <= posVIU.x + posVIU.w && My >= posVIU.y && My <= posVIU.y + posVIU.h) && (event.button.button == SDL_BUTTON_LEFT)) {
          if (volume_level>=0 && volume_level<5) {
	volume_level++;	 // just the pic
}
	}
 if ((Mx >= posVID.x && Mx <= posVID.x + posVID.w && My >= posVID.y && My <= posVID.y + posVID.h) && (event.button.button == SDL_BUTTON_LEFT)) {
          if (volume_level>0 && volume_level<=5) {
	volume_level--;  // just the pic
}
	}


if(volume_level== 0)
Mix_VolumeMusic(0);
if(volume_level== 1)
Mix_VolumeMusic(25);
if(volume_level== 2)
Mix_VolumeMusic(50);
if(volume_level== 3)
Mix_VolumeMusic(75);
if(volume_level== 4)
Mix_VolumeMusic(100);
if(volume_level== 5)
Mix_VolumeMusic(125);



}
	break;
// ###############################################################








// ###############################################################
        /*case SDL_KEYDOWN:
if (menu==0) {     // FI WOST L GAME
// ############################################


 //###############################################################
            switch(event.key.keysym.sym)
            {
              case SDLK_UP: // Flèche haut
		perso = SDL_LoadBMP("game_files/characters/deiUP.bmp");
		SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format,255, 255, 255));
		pos_perso.y=pos_perso.y-3;
                    break;

                case SDLK_DOWN: // Flèche bas
			perso = SDL_LoadBMP("game_files/characters/deiDOWN.bmp");
			SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format,255, 255, 255));
			pos_perso.y=pos_perso.y+3;
		 break;

                case SDLK_RIGHT: // Flèche droite
			perso = SDL_LoadBMP("game_files/characters/deiRIGHT.bmp");
			SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format,255, 255, 255));
			pos_perso.x=pos_perso.x+3;
		 break;

                case SDLK_LEFT: // Flèche gauche
			perso = SDL_LoadBMP("game_files/characters/deiLEFT.bmp");
			SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format,255, 255, 255));
			pos_perso.x=pos_perso.x-3;
                    break;

                case SDLK_ESCAPE:
                       menu=1;
                break;
            }
}*/
// ###############################################################








// ###############################################################
if (menu==1) {
   switch(event.key.keysym.sym)
            {
case SDLK_ESCAPE :
continuer=0;
return continuer;
break;
              case SDLK_UP: // Flèche haut

                    if (keyboard_select>=1 && keyboard_select<=3) {  keyboard_select--;  }
                if (keyboard_select<1) {  keyboard_select=3;  }
                    break;
                case SDLK_DOWN: // Flèche bas

                     if (  keyboard_select>=0 && keyboard_select<=3) {  keyboard_select++;  }
if (keyboard_select>3) {  keyboard_select=1;  }

                    break;

		case SDLK_RETURN:
		if (play_s==1) {
			menu=0;
		}
		if (settings_s==1) {
			menu=2;
		}

		if (quit_s==1) {
			continuer = 0;
                       SDL_Quit();
		}

		break;
	   }
}
            break;
    }
// ###############################################################







// ###############################################################
 if (menu==0)  // menu==0 : Affichage jeu
{

play1(screen);

//SDL_BlitSurface(object, NULL, screen, &posIB);
// Flip the backbuffer to the primary Hardware Video Memory
    SDL_Flip(screen);
}
// ###############################################################








// ###############################################################
else if (menu==1) {
SDL_BlitSurface(menu_bg, NULL, screen, &posBG);

switch (keyboard_select) {
	case 1:
	play_s=1;
	break;
	case 2:
	settings_s=1;
	break;
	case 3:
	quit_s=1;
	break;
}

if (play_s==1) {
SDL_BlitSurface(play_selected, NULL, screen, &posP);
	texte= TTF_RenderText_Blended(font,"Start a new game",white);
                    SDL_BlitSurface(texte, NULL, screen, &pos_text);
}
else {
SDL_BlitSurface(play, NULL, screen, &posP);
}

if (settings_s==1) {
SDL_BlitSurface(settings_selected, NULL, screen, &posS);
	texte= TTF_RenderText_Blended(font,"Modify game settings",white);
                    SDL_BlitSurface(texte, NULL, screen, &pos_text);
}
else{
SDL_BlitSurface(settings, NULL, screen, &posS);
}

if (quit_s==1) {
SDL_BlitSurface(quit_selected, NULL, screen, &posQ);
	texte= TTF_RenderText_Blended(font,"Exit the game",white);
                    SDL_BlitSurface(texte, NULL, screen, &pos_text);
}
else{
SDL_BlitSurface(quit, NULL, screen, &posQ);
}
SDL_Flip(screen);
}
// ###############################################################






// ###############################################################
else if (menu==2) { // menu options
  SDL_BlitSurface(menu_bg, NULL, screen, &posBG);
    SDL_BlitSurface(fullscreen, NULL, screen, &posIFS);
SDL_BlitSurface(soundminus, NULL, screen, &posVID);
SDL_BlitSurface(soundplus, NULL, screen, &posVIU);
switch (volume_level) {
	case 0:
	SDL_BlitSurface(vol_0, NULL, screen, &posVS);
	break;
	case 1:
	SDL_BlitSurface(vol_1, NULL, screen, &posVS);
	break;
	case 2:
	SDL_BlitSurface(vol_2, NULL, screen, &posVS);
	break;
	case 3:
	SDL_BlitSurface(vol_3, NULL, screen, &posVS);
	break;
	case 4:
	SDL_BlitSurface(vol_4, NULL, screen, &posVS);
	break;
	case 5:
	SDL_BlitSurface(vol_5, NULL, screen, &posVS);
	break;
}

if (button_ticked==1) {
SDL_BlitSurface(fullscreen_checked, NULL, screen, &posBFS);
}
else {
SDL_BlitSurface(fullscreen_unchecked, NULL, screen, &posBFS);
}
SDL_BlitSurface(volume, NULL, screen, &posVI);
if (back_s==1) {
SDL_BlitSurface(back_selected, NULL, screen, &posIB);
}
else {
SDL_BlitSurface(back, NULL, screen, &posIB);
}
}
// ###############################################################





// ###############################################################
SDL_Flip(screen);
// ###############################################################
}
// #########################################################################################################




// #########################################################################################################
    SDL_FreeSurface(image);
    SDL_FreeSurface(perso);
    SDL_FreeSurface(menu_bg);
    SDL_FreeSurface(play);
    SDL_FreeSurface(play_selected);
    SDL_FreeSurface(settings);
    SDL_FreeSurface(settings_selected);
    SDL_FreeSurface(quit);
    SDL_FreeSurface(quit_selected);
SDL_FreeSurface(fullscreen_checked);
SDL_FreeSurface(fullscreen_unchecked);
SDL_FreeSurface(volume);
SDL_FreeSurface(soundplus);
SDL_FreeSurface(soundminus);
SDL_FreeSurface(vol_0);
SDL_FreeSurface(vol_1);
SDL_FreeSurface(vol_2);
SDL_FreeSurface(vol_3);
SDL_FreeSurface(vol_4);
SDL_FreeSurface(vol_5);
SDL_FreeSurface(fullscreen);
SDL_FreeSurface(back);
SDL_FreeSurface(back_selected);
    Mix_FreeMusic(music);
Mix_FreeChunk(son);
    pause();
TTF_CloseFont(font);
TTF_Quit;
SDL_Quit();
// #########################################################################################################

return EXIT_SUCCESS;
}
