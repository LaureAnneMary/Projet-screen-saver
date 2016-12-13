#ifndef COMMANDES_H_INCLUDED
#define COMMANDES_H_INCLUDED

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int commandeClavier(void){
    struct termios ancienTerm, nouveauTerm;
    int touche;
    tcgetattr(STDIN_FILENO, &ancienTerm);// on récupère les infos du terminal
    nouveauTerm = ancienTerm;
    nouveauTerm.c_lflag &= ~ICANON;// on passe le terminal en mode canonique
    nouveauTerm.c_lflag &= ~ECHO; // on passe le terminal en mode non-echo
    tcsetattr(STDIN_FILENO, TCSANOW, &nouveauTerm); // on met en place les nouvelles infos du terminal
    touche = getchar(); // getchar() permet de lire une touche du clavier
    tcsetattr(STDIN_FILENO, TCSANOW, &ancienTerm); // on met en place les infos dans l'ancien terminal
    return touche; // la fonction renvoie la touche appuyée sur le clavier
}

#endif // COMMANDES_H_INCLUDED
