#ifndef FLECHESDIRECTIONNELLES_H_INCLUDED
#define FLECHESDIRECTIONNELLES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "commandes.h"

int main() //fonction pour diriger l'avion avec les flèches directionnelles
{
    int a, b, c; // le code ascii des flèches est composé de trois chiffres qui sont a, b et c
    int x, y; // x et y sont les coordonnées du tableau à deux dimensions du ciel
    while(1){
    a = commandeClavier();// a correspond au premier nombre lorsque l'on appuie sur l'une des flèches
    printf("%d", a);
        if(a == 27){ // on sait que les flèches ont toutes pour premier nombre 27
            b = commandeClavier();
            printf(", %d", b);
            if(b == 91){ //le deuxième nombre communs à toutes les flèches est 91
                c = commandeClavier();
                printf( "et %d\n", c);
            } if (c == 65) { // pour la flèche du haut le troisième chiffre est 65
                printf("haut\n");
                y++; // l'avion va bouger d'une case vers le haut
            } if (c== 66) { // pour la flèche du haut le troisième chiffre est 65
                printf("bas\n");
                y--; // l'avion va bouger d'une case vers le bas
            } if (c == 67) { //pour la flèche du haut le troisième chiffre est 67
                printf("droite\n");
                x++; // l'avion va bouger d'une case vers la droite
            } if(c == 68) { // pour la flèche du haut le troisième chiffre est 68
                printf("gauche\n");
                x--; // l'avion va bouger d'une case vers la gauche
            }
        }
    }
    return 0;
}

#endif // FLECHESDIRECTIONNELLES_H_INCLUDED
