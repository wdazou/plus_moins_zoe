#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int plus_moins(int choix_joueur, int nb_atrouver)
{

	if (choix_joueur > nb_atrouver){

		printf("Moins \n"); 
		return 0;
	}
	else if (choix_joueur < nb_atrouver) {

		printf("Plus \n");
		return 0;
	}
	else {

		printf("Bingo\n");
		return 1;
	} 
		

}


int main(int argc, char** argv)
{
	int mode;
	printf("\t*****************MENU PRINCIPALE*****************\n");
        printf("Choisissez le mode de difficulte : \n1)facile\n2)moyen\n3)difficile\nVotre choix : ");
 	scanf("%d", &mode);
        printf("************************************************\n");
    
    	srand (time(NULL));
        int valeur_a_trouver = rand() % 100 + 1;
    
        int choix_joueur;
    
        printf("Devinez le chiffre : ");
        int i = 0;
    
        switch(mode)
        {
    	case 1:
    		do
    		{
    			scanf("%d", &choix_joueur);
    			plus_moins(choix_joueur, valeur_a_trouver);
    	    	}while (choix_joueur != valeur_a_trouver);
    		break;
    
       case 2:
    		do
    		    {
    			i++;
    			scanf("%d", &choix_joueur);
    	                 plus_moins(choix_joueur, valeur_a_trouver);
    
    		 if(i == 25)
    		{
    			printf("Vous avez perdu! Le chiffre est %d\n", valeur_a_trouver);
    			break;
    		}
    		}while (choix_joueur != valeur_a_trouver);
    		break;
    
      case 3:
    		    	do
    		    	{
    			    	i++;
    			    	scanf("%d", &choix_joueur);
    	                            plus_moins(choix_joueur, valeur_a_trouver);
    
    				    if(i == 3)
    				    {
    					    printf("Plus de cartouche! Le chiffre est %d\n", valeur_a_trouver);
    					    break;
    				}
    			    }while (choix_joueur != valeur_a_trouver);
    	                break;
    
    		    default:
    			    printf("Erreur! Vous deviez choisir entre 1, 2 et 3.\n");
    			    break;
    	    }
}

    	    



