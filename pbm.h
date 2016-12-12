#ifndef PBM_H_INCLUDED
#define PBM_H_INCLUDED

typedef struct

void afficherImageStatique(){
    int n;
    srand(time(NULL));
    n = rand() % 3+1;
    switch(n){
        case 1 :
            chargerImage(im1);
            affichageCentré(im1);
        case 2 :
            chargerImage(im2);
            affichageCentré(im2);
        case 3 :
            chargerImage(im3);
            affichageCentré(im3);
        case 4 :
            chargerImage(im4);
            affichageCentré(im4);
        case 5 :
            chargerImage(im5);
            affichageCentré(im5);
        defaut :
            break;
    }
    retrun 0;
}

#endif // PBM_H_INCLUDED
