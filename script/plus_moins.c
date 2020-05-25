#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int plus_moins(int choix_joueur, int nb_atrouver)
{ 

	if (choix_joueur > nb_atrouver){

		printf("c'est Moins \n"); 
		return 0;
	}
	else if (choix_joueur < nb_atrouver) {

		printf("c'est Plus \n");
		return 0;
	}
	else {

		printf("Bingo\n");
		return 1;
	} 
		

}

int main()
{
	srand (time(NULL));
	int nb_atrouver = rand() % 100;
	int choix_joueur;
	printf("Allez commencer a devinez: ");
	do
	{
	    scanf("%d", &choix_joueur);
		plus_moins(choix_joueur, nb_atrouver);
	}while (choix_joueur != nb_atrouver);
}
