#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "PBM.h"

void AfficherPBM(Pbm image)
{
int tableauPourImage[24][5] = {0};
FILE* fichier = NULL;

                 fichier = fopen(image.nomImage, "r"); 
		printf("%c\n", image.nomImage[1]);
		
                         if(fichier != NULL)
                         {
         
                                lireResolution(fichier, &image);
         
                                insererImageCentreeDansTableau(fichier, &image, tableauPourImage);
                                fclose(fichier); 
                        } else {
                                printf("Impossible\n");
                        } 
}

int main(void)
{
    time_t secondes;
    struct tm instant;

    time(&secondes);
    instant=*localtime(&secondes);

    printf("%d:%d:%d\n", instant.tm_hour, instant.tm_min, instant.tm_sec);
    int horloge[3];
    horloge[0] = instant.tm_hour;
    horloge[1] = instant.tm_min;
    horloge[2] = instant.tm_sec;
   /*printf("%d\n", horloge[0]);
    printf("%d\n", horloge[1]);
    printf("%d\n", horloge[2]);*/
	int i; 
	char* tabhoraire[11] = {"Chiffre0.pbm", "Chiffre1.pbm", "Chiffre2.pbm", "Chiffre3.pbm", "Chiffre4.pbm", "Chiffre5.pbm", "Chiffre6.pbm", "Chiffre7.pbm", "Chiffre8.pbm", "Chiffre9.pbm", "Deuxpoints.pbm"};
for (i = 0; i < 3; i++)
{
        int nombre1 = (horloge[i]/10) %10;
        int nombre2 = (horloge[i]-nombre1*10) %10;
	char converted[100];
//	printf("%s\n", tabhoraire[nombre1]);
	strncpy(converted, tabhoraire[nombre1], sizeof(converted-1));
	int f;
        for(f =0; f<11; f++)
{
// printf("%c", converted[f]);
}
        Pbm pbm1 ={3,5, tabhoraire[nombre1]};
	Pbm pbm2 ={3,5, tabhoraire[nombre2]};
	if(i <2)
	{
	AfficherPBM(pbm1);
	}
}

    return 0;

}
