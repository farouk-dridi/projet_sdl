#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "personnage.h"


//---------------------Initialisation des variables ---------------------//


void initialiser_personnage(personnage *p)
{
p->position_personnage.x=0;
p->position_personnage.y=200;
p->position_personnage.w=100;
p->position_personnage.h=100;

// init perso image
    p->tab[0]=IMG_Load("per/0.png");
    p->tab[1]=IMG_Load("per/1.png");
    p->tab[2]=IMG_Load("per/2.png");
    p->tab[3]=IMG_Load("per/3.png");
    p->tab[4]=IMG_Load("per/4.png");
    p->tab[5]=IMG_Load("per/5.png");
    p->tab[6]=IMG_Load("per/6.png");
    p->tab[7]=IMG_Load("per/7.png");
    p->tab[8]=IMG_Load("per/8.png");
    p->tab[9]=IMG_Load("per/9.png");
    p->tab[10]=IMG_Load("per/10.png");
    p->tab[11]=IMG_Load("per/11.png");
    p->tab[12]=IMG_Load("per/12.png");
    p->tab[13]=IMG_Load("per/13.png");
    p->tab[14]=IMG_Load("per/14.png");
    p->tab[15]=IMG_Load("per/15.png");
    p->tab[16]=IMG_Load("per/16.png");
    p->tab[17]=IMG_Load("per/17.png");
    p->tab[18]=IMG_Load("per/18.png");
    p->tab[19]=IMG_Load("per/19.png");
     p->tab[20]=IMG_Load("per/20.png");
    p->tab[21]=IMG_Load("per/21.png");
    p->tab[22]=IMG_Load("per/22.png");
    p->tab[23]=IMG_Load("per/23.png");
    p->tab[24]=IMG_Load("per/24.png");
    p->tab[25]=IMG_Load("per/25.png");
    p->tab[26]=IMG_Load("per/26.png");
    p->tab[27]=IMG_Load("per/27.png");
    p->tab[28]=IMG_Load("per/28.png");
    p->tab[29]=IMG_Load("per/29.png");
    p->tab[30]=IMG_Load("per/30.png");
    p->tab[31]=IMG_Load("per/31.png");
    p->tab[32]=IMG_Load("per/32.png");
    p->tab[33]=IMG_Load("per/33.png");
    p->tab[34]=IMG_Load("per/34.png");
    p->tab[35]=IMG_Load("per/35.png");
    p->tab[36]=IMG_Load("per/36.png");
    p->tab[37]=IMG_Load("per/37.png");
    p->tab[38]=IMG_Load("per/38.png");
    p->tab[39]=IMG_Load("per/39.png");
 p->tab[40]=IMG_Load("per/40.png");
    p->tab[41]=IMG_Load("per/41.png");
    p->tab[42]=IMG_Load("per/42.png");
    p->tab[43]=IMG_Load("per/43.png");
    p->tab[44]=IMG_Load("per/44.png");
    p->tab[45]=IMG_Load("per/45.png");
    p->tab[46]=IMG_Load("per/46.png");
    p->tab[47]=IMG_Load("per/47.png");
    p->tab[48]=IMG_Load("per/48.png");
    p->tab[49]=IMG_Load("per/49.png");
    p->tab[50]=IMG_Load("per/50.png");
    p->tab[51]=IMG_Load("per/51.png");
    p->tab[52]=IMG_Load("per/52.png");
    p->tab[53]=IMG_Load("per/53.png");
    p->tab[54]=IMG_Load("per/54.png");
    p->tab[55]=IMG_Load("per/55.png");
    p->tab[56]=IMG_Load("per/56.png");
    p->tab[57]=IMG_Load("per/57.png");
    p->tab[58]=IMG_Load("per/58.png");
    p->tab[59]=IMG_Load("per/59.png");
 p->tab[60]=IMG_Load("per/60.png");
    p->tab[61]=IMG_Load("per/61.png");
    p->tab[62]=IMG_Load("per/62.png");
    p->tab[63]=IMG_Load("per/63.png");
    p->tab[64]=IMG_Load("per/64.png");
    p->tab[65]=IMG_Load("per/65.png");
    p->tab[66]=IMG_Load("per/66.png");
    p->tab[67]=IMG_Load("per/67.png");
    p->tab[68]=IMG_Load("per/68.png");
    p->tab[69]=IMG_Load("per/69.png");
    p->tab[70]=IMG_Load("per/70.png");
    p->tab[71]=IMG_Load("per/71.png");
    p->tab[72]=IMG_Load("per/72.png");
    p->tab[73]=IMG_Load("per/73.png");
    p->tab[74]=IMG_Load("per/74.png");
    p->tab[75]=IMG_Load("per/75.png");
    p->tab[76]=IMG_Load("per/76.png");
    p->tab[77]=IMG_Load("per/77.png");
    p->tab[78]=IMG_Load("per/78.png");
    p->tab[79]=IMG_Load("per/79.png");
     p->tab[80]=IMG_Load("per/80.png");
    p->tab[81]=IMG_Load("per/81.png");
    p->tab[82]=IMG_Load("per/82.png");
    p->tab[83]=IMG_Load("per/83.png");
    p->tab[84]=IMG_Load("per/84.png");
    p->tab[85]=IMG_Load("per/85.png");
    p->tab[86]=IMG_Load("per/86.png");
    p->tab[87]=IMG_Load("per/87.png");
    p->tab[88]=IMG_Load("per/88.png");
    p->tab[89]=IMG_Load("per/89.png");
    p->tab[90]=IMG_Load("per/90.png");
    p->tab[91]=IMG_Load("per/91.png");
    p->tab[92]=IMG_Load("per/92.png");
    p->tab[93]=IMG_Load("per/93.png");
    p->tab[94]=IMG_Load("per/94.png");
    p->tab[95]=IMG_Load("per/95.png");
    p->tab[96]=IMG_Load("per/96.png");
    p->tab[97]=IMG_Load("per/97.png");
    p->tab[98]=IMG_Load("per/98.png");
    p->tab[99]=IMG_Load("per/99.png");
     p->tab[100]=IMG_Load("per/100.png");
    p->tab[101]=IMG_Load("per/101.png");
    p->tab[102]=IMG_Load("per/102.png");
    p->tab[103]=IMG_Load("per/103.png");
    p->tab[104]=IMG_Load("per/104.png");
    p->tab[105]=IMG_Load("per/105.png");
    p->tab[106]=IMG_Load("per/106.png");
    p->tab[107]=IMG_Load("per/107.png");
    p->tab[108]=IMG_Load("per/108.png");
    p->tab[109]=IMG_Load("per/109.png");
    p->tab[110]=IMG_Load("per/110.png");
    p->tab[111]=IMG_Load("per/111.png");
    p->tab[112]=IMG_Load("per/112.png");
    p->tab[113]=IMG_Load("per/113.png");
    p->tab[114]=IMG_Load("per/114.png");
    p->tab[115]=IMG_Load("per/115.png");
    p->tab[116]=IMG_Load("per/116.png");
    p->tab[117]=IMG_Load("per/117.png");
    p->tab[118]=IMG_Load("per/118.png");
    p->tab[119]=IMG_Load("per/119.png");
    p->tab[120]=IMG_Load("per/120.png");
    p->tab[121]=IMG_Load("per/121.png");
    p->tab[122]=IMG_Load("per/122.png");
    p->tab[123]=IMG_Load("per/123.png");
    p->tab[124]=IMG_Load("per/124.png");

//                                  *********************************************
p->Frame=0;
p->vitesse=5;
p->speed=0;

}

//---------------------Affichage du personnage sur l'ecran ---------------------//

void afficher_personnage(personnage p,SDL_Surface *ecran)
{
    SDL_BlitSurface(p.tab[p.Frame],NULL,ecran,&(p.position_personnage));
}


//---------------------Animation marche a droite ---------------------//

void animation_walk_right (personnage *p)
{
  if(p->Frame<=0 || p->Frame>=9)
		p->Frame=1;
	p->Frame++;
}

//---------------------Animation marche a gauche---------------------//

void animation_walk_left (personnage *p)
{
	if(p->Frame<=10 || p->Frame>=19)
		p->Frame=11;

	p->Frame++;
}

//---------------------Animation du saut a droite---------------------//
void animation_jump_right (personnage *p)
{
	if(p->Frame<=24 || p->Frame>=31)
		p->Frame=25;

	p->Frame++;

}

//---------------------Animation du saut a gauche--------------------//
void animation_jump_left (personnage *p)
{
  if(p->Frame<=39 || p->Frame>=46)
		p->Frame=40;

	p->Frame++;
}


//---------------------Animation course a droite---------------------//

void animation_run_right (personnage *p)
{
	if(p->Frame<=51 || p->Frame>=60)
		p->Frame=52;

	p->Frame++;

}

//---------------------Animation course a gauche---------------------//

void animation_run_left (personnage *p)
{
	if(p->Frame<=61 || p->Frame>=70)
		p->Frame=62;

	p->Frame++;

}

//---------------------Animation de glissage droite---------------------//

void animation_slide_right (personnage *p)
{
int nb_frames_p=0;

	if(p->Frame<=79 || p->Frame>=88)
		p->Frame=80;

	p->Frame++;

}
void animation_slide_left (personnage *p)
{
int nb_frames_p=0;

	if(p->Frame<=89 || p->Frame>=98)
		p->Frame=90;

	p->Frame++;

}
//---------------------Animation de l'attack droite---------------------//

void animation_attack_right (personnage *p)
{
int nb_frames_p=0;

	if(p->Frame<=99 || p->Frame>=108)
		p->Frame=100;

	p->Frame++;

}


//---------------------Animation de l'attack gauche---------------------//

void animation_attack_left (personnage *p)
{
int nb_frames_p=0;

	if(p->Frame<=109 || p->Frame>=118)
		p->Frame=110;

	p->Frame++;

}

//---------------------Animation en cas d'echouer a droite------------------------//

void animation_fail_right (personnage *p)
{
int nb_frames_p=0;

	if(p->Frame<=71 || p->Frame>=78)
		p->Frame=72;

	p->Frame++;

}

//---------------------Animation en cas d'echouer a gauche------------------------//

void animation_fail_left (personnage *p)
{
int nb_frames_p=0;

	if(p->Frame<=79 || p->Frame>=77)
		p->Frame=80;

	p->Frame++;

}


//---------------------Animation de accroupissement droite---------------------//

void animation_crouch_right (personnage *p)
{
int nb_frames_p=0;

	if(p->Frame<=119 || p->Frame>=124)
		p->Frame=120;

	p->Frame++;

}





//------------------------Deplacement clavier ------------------------//


void deplacement_clavier(personnage *p,int clic)
{


          if (clic==1)
               {
		 p->position_personnage.x -=p-> vitesse;
		 animation_walk_left (p);
               }




         else if(clic==2)
               {
		 p->position_personnage.x += p->vitesse;
                 animation_walk_right (p);
               }




         else if (clic==3)
 	       {
            	 p->position_personnage.x += p->vitesse;
           	 p->position_personnage.y -= p->vitesse;
            	 animation_jump_right(p);

               }

         else if(clic==4)
               {
                 p->position_personnage.x += p->vitesse;
                // p->position_personnage.y += p->vitesse;
                 animation_crouch_right (p);

               }



	else if(clic==5)
               {
            p->xStep = 0.5 * p->vitesse * 2.2 * 2.2 + p->speed * 2.2;//dt²= dt * dt,
            p->position_personnage.x += p->vitesse+2;// xstep: combien le perso va avancer , combien de x
            if (p->velocity < 40)
            {
                p->velocity += 0.5;
            }
                 animation_run_right (p);
               }



	else if(clic==6)
               {
            p->xStep = 0.5 * p->vitesse * 2.2 * 2.2 + p->speed * 2.2;
            p->position_personnage.x -= p->vitesse+2;
            if (p->velocity < 40)
            {
                p->velocity += 0.5;
            }
             
                 animation_run_left (p);
               }




	else if(clic==7)
               {
                 p->position_personnage.x += p->vitesse;
                 animation_slide_right (p);
               }


               


	else if(clic==8)
               {
                 p->position_personnage.x += p->vitesse;
                 animation_attack_right (p);
               }



	else if(clic==9)
               {
                 p->position_personnage.x -= p->vitesse;
                 animation_attack_left (p);
               }
        else if(clic==12)
               {
                 p->position_personnage.x -= p->vitesse;
                 animation_slide_left (p);
               }
       /*else if (clic==10)
 	       {
            	 p->position_personnage.x += p->vitesse;
           	 p->position_personnage.y -= p->vitesse;
            	 animation_jump_left(p);

               }*/


}
//-------------------------------- CONTROLE DU SAUT ---------------------------------//

void Saute(personnage *p, float impulsion)
{
    p->vx = -impulsion;

    p->vy = -impulsion;

    p->status = STAT_AIR;
}
//--------------------------------RETOUR AU SOL---------------------------------//
void ControleSol(personnage *p, int x)
{
    if (p->position_personnage.y>x)
    {
       p->position_personnage.y =x;
        if (p->vy>0)
            p->vy =0.0;
        p->status = STAT_SOL;
    }
}
//--------------------------------GRAVITÉ DU PERSONNAGE---------------------------------//
void Gravite(personnage *p,int clic,float factgravite,float factsautmaintenu)
{
    if (p->status == STAT_AIR && (clic==3))
        factgravite/=factsautmaintenu;
    	p->vy += factgravite;
    	p->vy += factsautmaintenu;
}
//----------------------------- controle des fonctions----------------------------//

void Evolue(personnage *p, int clic,int clic1, int x)
{

// declarations de quelques variables

    float impulsion=0.5;
    float factgravite = 2;
    float factsautmaintenu = 0.5;


/***********************************************/
// saut

    if ((clic==3) && p->status == STAT_SOL)
        {
        Saute(p,impulsion);
        animation_jump_right (p);   	
        } 
 if ((clic!=3) && p->status == STAT_AIR && clic1==1)
        {
         p->status = STAT_SOL; 	
        } 
Gravite(p,clic,factgravite,factsautmaintenu);
ControleSol(p,x);
// application du vecteur à la position.
    if((clic == 3) && p->status == STAT_AIR)
{
    p->position_personnage.x +=p->vx;
    p->position_personnage.y +=p->vy-30;
} 
}









