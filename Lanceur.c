#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <historique.h>
int  processusfils(){
        int n;
        srand(time(NULL));
        n=rand()%3+1;
       // while(1){
                switch(n){
                        case 1:
                                printf("je suis l'ecran statique\n");
                                //execl("ecranStatique","",NULL);
                                break;
                        case 2:
                                printf("je suis l'ecran dynamique\n");
                                //execl("ecranDynamique","",NULL);
                                break;
                        case 3:
                                printf("je suis l'ecran interactif\n");
                                //execl("ecranInteractif","",NULL);
                                break;
                }
       // }
	return n;
}

void main(){
	//lance la veille
	system("clear");
	int n;
	int pid=fork();
	switch(pid){
	case -1:
		printf("Erreur lors de la création");
		break;
	case 0:

		n=processusfils();
		sauvegarde(n);
		break;
	}
	afficherhistorique();
}

