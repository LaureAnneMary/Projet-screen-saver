#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED

void sauvegarde(int n){
        FILE* fichier = NULL;
        time_t secondes;
        struct tm instant;
        fichier=fopen("historique.txt","w");
        if(fichier!=NULL){
        fprintf(fichier,"%d/%d/%d  %d:%d:%d, %d",instant.tm_mday, instant.tm_mon+1,instant.tm_year,i$
        }
        fclose(fichier);
}

void afficherhistorique(){
        FILE* fichier=NULL;
        char texte[7]="";
        fichier=fopen("historique.txt","r");
        if(fichier!=NULL){
                fscanf(fichier,"%d %d %d %d %d %d %d", %texte[0], %texte[1], %texte[2], %texte[3], %$
                printf("%d/%d/%d  %d:%d:%d, %d",texte[0],texte[1],texte[2],texte[3],texte[4],texte[5$
        }
        fclose(fichier);
}




#endif // HISTORIQUE_H_INCLUDED
