#ifndef FONCTION_RECH_H_INCLUDED
#define FONCTION_RECH_H_INCLUDED
#include"definition.h"
liste_etud  recherche_etud(liste_etud l,char mat[])
{
    liste_etud p=l;
    while(p)
    {
        if(strcmp(p->info1.cin,mat)==0)
            return p;
        p=p->suiv1;
    }
    return NULL;

}
liste_mat recherche_code_m(liste_mat l,char code_m[])
{
    liste_mat p=l;
    while(p)
    {
        if(strcmp(p->info2.code_mat,code_m)==0)
            return p;
        else
            p=p->suiv2;
    }
    return NULL;
}
liste_mat  recherche_mat(liste_mat l,char mat[])
{
    liste_mat p=l;
    while(p)
    {
        if(strcmp(p->info2.code_mat,mat)==0)
        {
            printf("Deja EXISTE");
            return p;
        }
        p=p->suiv2;
    }
    printf("N'EXISTE PAS");
    return NULL;

}
liste_note recherche_cin_mat(liste_note l,char mat[],char code_m[],char nat[])
{
    liste_note p=l;
    while(p)
    {
        if(strcmp(p->info3.code_mat,code_m)==0&&strcmp(p->info3.mat,mat)==0&&strcmp(p->info3.nature,nat)==0)
            return p;
    p=p->suiv3;
    }
    return NULL;
}
liste_note recherche_cin_note(liste_note l,char mat[])
{
    liste_note p=l;
    while(p)
    {
        if(strcmp(p->info3.mat,mat)==0)
            return p;
        p=p->suiv3;
    }
    return NULL;
}


#endif // FONCTION_RECH_H_INCLUDED
