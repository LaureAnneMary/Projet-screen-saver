#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void main(){
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
