prog:personne.o main.o
	gcc personne.o main.o -o prog -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g 
personne.o:personne.c
	gcc -c personne.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
