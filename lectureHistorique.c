#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int x;
	printf("Bonjour, tu es dans le menu de l'historique.\n Si tu veux ton historique en fonction de l'heure tape 1. \n Si tu veux ton historique en fonction du type, tape 2\n");
	printf("Choisi soit 1, soit 2: ");
	scanf("%d",&x);
	if(x==1){
		FILE* fichier=NULL;
		int lecteur=0;
		fichier=fopen("historique.txt","r");
		if(fichier!=NULL){
			do{	
				lecteur=fgetc(fichier);
				printf("%c",lecteur);
			}while(lecteur!=EOF); // on lit un a un les caractères du fichier tant que l'on est pas arriver a EOF End Of File
		fclose(fichier);
		}
	}
	if(x==2){
		printf("je suis désolé, cet partie du programme est en cours de developpement. Reviens plus tard");
	}
}
