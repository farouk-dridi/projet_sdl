prog:personne.o main.o play.o background.o ennemi.o enigme.o obstacle.o temps.o potion.o
	gcc personne.o main.o play.o background.o ennemi.o enigme.o obstacle.o temps.o potion.o -o prog -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g 
personne.o:personne.c
	gcc -c personne.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
play.o:play.c
	gcc -c play.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
background.o:background.c
	gcc -c background.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
enigme.o:enigme.c
	gcc -c enigme.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
obstacle.o:obstacle.c
	gcc -c obstacle.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
temps.o:temps.c
	gcc -c temps.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
potion.o:potion.c
	gcc -c potion.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g





