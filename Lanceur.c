#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
	lance la veille
	// idée -> sion touche la touche espace la fonction nous renvois 1 
	// int n;
	//n=toucheespace();
	// while (n!=1);
	int pid=creationprocessus();
	switch(pid){
	case -1: 
		printf("Erreur lors de la création");
		break;
	case 0:
		processusfils();
		break;
	default:
		processuspère();
		break;
	}
}

void processusfils(){
	int n;
	srand(time(NULL));
	n=rand()%3+1;
	while(1){
		switch(n){
			case 1:
				execl("ecranStatique","",NULL);
				break;
			case 2:
				execl("ecranDynamique","",NULL);
				break;
			case 3:
				execl("ecranInteractif","",NULL);
				break;
		}
	}
}

void processuspère(){

}
