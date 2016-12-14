#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void horloge(){
	time_t maintenant=time(NULL);
	struct tm tm_maintenant=*localtime(&maintenant);
	char s_maintenant[sizeof"HH:MM:SS"];
	strftime(s_maintenant,sizeof s_maintenant,"%H:%M:%S",&tm_maintenant);
	printf("%s\n",s_maintenant);
}

void phraseDynamique(){
	int i,j;
	char actualisation[2];//va servir a stocker la valeur de la variable d'environnement
	char* valeur=getenv("EXIASAVER2_SLEEP");//getenv retroune la valeur de la variable d'environnement sous la forme d'une chaîne de caractère
	if(valeur==NULL){
		strcpy(actualisation,"10");//dans le cas ou on n'arrive a obtenir la valeur de la variable d'environnement 10 est la valeur par defaut 
	}else{
		strcpy(actualisation,valeur);// on met la valeur de valeur dans actualisation
	}
	j=atoi(actualisation);//la chaine de caractère d'actualisation va être transformer en valeur numerique
	printf("Cette ecran va s'actualisée dans quelques secondes");
	for(i=0;i<j;i++){
		printf(".");
		fflush(stdout);
		sleep(1);
	}
}

void main(){
	while(1){
		system("clear");
		horloge();
		fflush(stdout);
		phraseDynamique();
	}
}
