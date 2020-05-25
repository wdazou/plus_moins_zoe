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
int mode_deuxJoueurs(int val_a_trouver, int tours, int joueur, int score1, int score2) {
	int choix=0,counter = 0, coup;
	
	printf("Le joueur %d set un nombre de coup (>=10): ", joueur);
	scanf("%d", &coup);
	
	
	 
	if (coup >= 10){
		printf("Le joueur %d devine.\n",(joueur%2) + 1);
		int a_trouver = 0;
		while (counter < coup) {
				
				printf("Devinez le nombre : ");
				
				scanf("%d", &choix);
				
				if (plus_moins(choix, val_a_trouver)){
					a_trouver = 1;
					break;	
				}
					
				counter +=1;
				
					
			
		}
		if (!a_trouver){
			printf("Vous n'avez plus de coup\n");
			printf("Reponse : %d \n",val_a_trouver);
		}
		
		int points = coup - counter; 
		

		if (joueur == 1){
			joueur = 2;
			score2 += points; 
		}
		else{
			joueur = 1;
			tours -= 1;
		score1 += points;
		}
		printf("le joueur %d a obtenu %d points \n", joueur, points); 
		srand(time(NULL)); 
		int hasard = rand() % 100; 
		if (tours)
			mode_deuxJoueurs(hasard, tours,joueur,score1,score2); 
		else {
			printf("Game over\n");			
			printf("[+]score joueur(1) %d",score1 ); 
			printf("\n[+]score joueur(2) %d \n",score2 );
			if(score2>score1)
			{
			printf("[+]joueur(2) vainqueur avec %d",score2);
			}
			else
			printf("[+]joueur(1) vainqueur avec %d",score1);
		}
		
	}	
	else{
		printf("Minimum 10 . \n");
		mode_deuxJoueurs(val_a_trouver, tours,joueur,score1,score2);
	}
		
}


int main(int argc, char** argv)
{
	srand(time(NULL)); 

	int hasard = rand() % 100; 

	int choix;
	printf("Voulez-vous jouer en 1 joueur ou 2 joueurs (1 ou 2): ");
	scanf("%d",&choix);
	if (choix == 1)
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
        
        				    if(i == 10)
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
            else
    	    {
    			printf("Combien de tours voulez vous: ");
    			scanf("%d",&choix);
    			mode_deuxJoueurs(hasard,choix,1,0,0);
             }
		printf("###############GAME OVER#################");
    }


    	    



