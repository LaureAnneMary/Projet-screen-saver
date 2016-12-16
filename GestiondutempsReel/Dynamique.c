#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PBM.h"

int main()
{
    int sleepTime = 10;
    sleepTime = 3;
    // atoi(getenv("EXIASAVER2_SLEEP"));
    //char* test = "oui";
    //test = getenv("EXIASAVER2_PBM");
    //printf("%s",test);
    int tableauPourImage[80][24] = {0}; //
    Pbm image;
    Pbm heure;
    image.largeurImage = 5;
    image.longueurImage = 39;
    heure.largeurImage = 5;
    heure.longueurImage = 3;
    while(1)
    {
        system("clear");
        tableauHorloge(tableauPourImage);
        afficherTableau(tableauPourImage);
        printf("\nActualisation toutes les %d secondes ",sleepTime);
        fflush(stdout);
        for (int i = 0; i<sleepTime; i++)
        {
            sleep(1);
            printf(". ");
            fflush(stdout);
        }
    }
    return 0;
}
