#ifndef TOUCHES_H_INCLUDED
#define TOUCHES_H_INCLUDED

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#include "commandes.h"

int fonctionArret(){
	int touche;
	touche = commandeClavier();
	system("setterm-cursor off");
	while(1){
		if(touche == 32){ // 32 : touche espace
                	printf(" %d : arret \n", touche);
                	system("clear");
			system("setterm-cursor on");
                	exit(0);
        } else{
            touche = commandeClavier();
        }
    }
    return 0;
}

int commandesFleches(){
    int a, b, c;
    while(1){
    a = commandeClavier();
    printf("%d", a);
        if(a == 27){
            b = commandeClavier();
            printf(", %d", b);
            if(b == 91){
                c = commandeClavier();
                printf( "et %d \n", c);
            }
 	}
    }
    return 0;
}


#endif // TOUCHES_H_INCLUDED
