#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED
#include"definition.h"
#include"etudiant.h"
#include"matiere.h"
#include"fonction_rech.h"
#include"controle.h"
note saisie_note(liste_note l)
{
    liste_etud l1/*=recuperation_etudiant(l1)*/;
    liste_mat l2/*=recuperation_matiere(l2)*/;
    note n;
    /*
    do
    {
        printf("saisir CIN: ");fflush(stdin);gets(n.mat);
    }while(recherche_etud(l1,n.mat)==NULL);
    do
    {
        printf("saisir Code matiere: ");fflush(stdin);gets(n.code_mat);
    }while(recherche_mat(l2,n.code_mat)==NULL);
    */

        printf("saisir CIN: ");fflush(stdin);gets(n.mat);


        printf("saisir Code matiere: ");fflush(stdin);gets(n.code_mat);
    do
    {
        printf("Saisir le NOTE:");fflush(stdin);scanf("%f",&n.note);
    }while(verif_note(n.note)==0);
    do
    {
        printf("saisir la NATURE (DS/EX): ");fflush(stdin);gets(n.nature);
        if(recherche_cin_mat(l,n.mat,n.code_mat,n.nature))
            printf("NOTE DEJA SAISIE !!");
    }while(!((strcmp(n.nature,"DS")==0||strcmp(n.nature,"EX")==0)&&recherche_cin_mat(l,n.mat,n.code_mat,n.nature)==NULL));
    return n;
}
int taille_liste_note(liste_note l)
{
    int n=0;
    while(l)
    {
        n++;
        l=l->suiv3;
    }
    return n;
}
liste_note insere_tete_note(liste_note l ,note n)
{
    liste_note p;
    p=malloc(sizeof(struct cellule3));
    p->info3=n;
    p->suiv3=l;
    l=p;
    return l;
}
liste_note insere_queue_note(liste_note l,note n)
{
    liste_note p,q=l;
    if(l==NULL)
        l=insere_tete_note(l,n);
    else
    {
        while(q->suiv3)
            q=q->suiv3;
        p=malloc(sizeof(struct cellule3));
        p->info3=n;
        p->suiv3=NULL;
        q->suiv3=p;

    }
return l;
}
liste_note insere_pos_note(liste_note l,note n,int pos)
{
    int cp=1;
    liste_note p,q=l;
    while(cp<pos-1)
    {
        cp++;
        q=q->suiv3;
    }
    p=malloc(sizeof(struct cellule3));
    p->info3=n;
    p->suiv3=q->suiv3;
    q->suiv3=p;
    return l;
}
liste_note supprimmer_tete_note (liste_note l)
{
    liste_note p=l;
    if(l==NULL)
        printf("liste vide");
    else
    {
        l=l->suiv3;
        free(p);
    }
    return l;
}
liste_note supprimmer_queue_note(liste_note l)
{
    liste_note p=l,q;
    if(l==NULL)
        printf("liste vide");
    else
        if(l->suiv3==NULL)
        {
            l=l->suiv3;
            free(p);
        }
        else
        {
        while(p->suiv3->suiv3)
            p=p->suiv3;
        q=p->suiv3;
        free(q);
        p->suiv3=NULL;
    }
    return l;
}
liste_note suppression_pos_note(liste_note l,int pos)
{
    int cp=1;
    liste_note p=l,q;
    while(cp<pos-1)
        p=p->suiv3;
    q=p->suiv3;
    p=q->suiv3;
    free(q);
    return l;
}
liste_note suppression_note_donne(liste_note l,char mat[],char code_m[],char nat[])
{
    liste_note p=l,prec=NULL,q;

    while(strcmp(p->info3.code_mat,mat)!=0&&p&&strcmp(p->info3.mat,mat)!=0&&strcmp(p->info3.nature,nat)!=0)
    {
        prec=p;
        p=p->suiv3;
    }
    if(prec==NULL)
        l=supprimmer_tete_note(l);
    else
        if(p!=NULL)
        {
         prec->suiv3=p->suiv3;
         free(p);
        }
        else
            printf("NOTE non saisie");
    return l;
}
void affiche_note(liste_note l, char mat[])
{
    int test=0;
    liste_note p=l;
    while(p)
    {
        if(strcmp(p->info3.mat,mat)==0)
        {
            printf("\nCIN:%s",p->info3.mat);
            printf("\nCODE MATIERE:%s",p->info3.code_mat);
            printf("\nNOTE:%f",p->info3.note);
            printf("\nNATURE:%s",p->info3.nature);
            test=1;
        }
        p=p->suiv3;
    }
    if(test==0)
        printf("L'ETUDIANT n cin:%s n'a aucune note",mat);
}
void affiche_liste_note(liste_note l,char mat[],char code_m[])
{
    int test=0;
    liste_note p=l;
    while(p)
    {
        if(strcmp(p->info3.mat,mat)==0&&strcmp(p->info3.code_mat,code_m)==0)
        {
            printf("\nCIN :%s",p->info3.mat);
            printf("\nCODE MATIERE:%s",p->info3.code_mat);
            printf("\nNOTE:%f",p->info3.note);
            printf("\nNATURE:%s",p->info3.nature);
        }
        p=p->suiv3;
    }

}
liste_note CREATION_note(liste_note l)
{
    int pos,t;
    char rep;
    note n;
    do
    {
        t=taille_liste_note(l);
        do
        {
            printf("Saisir la postion entre 1 et %d :",t+1);fflush(stdin);
            scanf("%d",&pos);
        }while(pos<1||pos>t+1);
        n=saisie_note(l);
        if(pos==1)
            l=insere_tete_note(l,n);
        else
            if(pos==t+1)
                l=insere_queue_note(l,n);
            else
                l=insere_pos_note(l,n,pos);
        do
        {
            printf("Voulez_vous ajouter un autre note O/N:");fflush(stdin);
            scanf("%c",&rep);
        }while(rep!='O'&&rep!='N');
    }while(rep=='O');
    return l;
}
liste_note ajout_tete_note(liste_note l)
{
    note n;
    printf("\t\tSAISIR UNE NOTE EN TETE DE LA LISTE\n");
    n=saisie_note(l);
    l=insere_tete_note(l,n);
    return l;
}
liste_note ajout_queue_note(liste_note l)
{
    note n;
    printf("\t\tSAISIR UNE NOTE EN  QUEUE DE LA LISTE\n");
    n=saisie_note(l);
    l=insere_queue_note(l,n);
    return l;
}
liste_note ajout_pos_note(liste_note l)
{
    note n;
    int pos;
    printf("\t\tSAISIR UNE NOTE DANS UNE POSTION DE LA LISTE\n");
    do{printf("\n SAISIR LA POSITION:");fflush(stdin);scanf("%d",&pos);}while(pos<=1||pos>taille_liste_note(l)+1);
    n=saisie_note(l);
    l=insere_pos_note(l,n,pos);
    return l;
}
liste_note sup_pos_note(liste_note l)
{
    int pos;
    printf("\t\tSUPPRISSION UNE NOTE D'UNE POSTION DE LA LISTE\n");
    if(taille_liste_note(l)==1)
        printf("impossible de supprimer car la position doit etre ente 2 et taille de la liste +1");
    else
    {
        do{printf("\n SAISIR LA POSITION:");fflush(stdin);scanf("%d",&pos);}while(pos>taille_liste_note(l)+1||pos<=1);
        l=suppression_pos_note(l,pos);
    }
    return l;
}
liste_note sup_note_donne(liste_note l)
{
    char mat[9];
    char code_m[4];
    char nature[3];
    printf("\t\tSUPPRISSION UNE NOTE DE LA LISTE\n");
    do
    {
        printf("\n SAISIE CIN:");fflush(stdin);fflush(stdin);gets(mat);
        printf("SAISIE CODE MATIERE:");fflush(stdin);gets(code_m);
        printf("SAISIE LA NATURE:");fflush(stdin);gets(nature);
        if(recherche_cin_mat(l,mat,code_m,nature)==NULL)
            printf("NOTE NON SAISIE");
    }while(recherche_cin_mat(l,mat,code_m,nature)==NULL);
    l=suppression_note_donne(l,mat,code_m,nature);
    return l;
}
liste_note modifier_note(liste_note l)
{
    char mat[9];
    char code_m[4];
    char nature[3];
    float  note;
    printf("\t\tMODIFICATION D'UNE NOTE DE LA LISTE\n");
    do
    {
        printf("\n SAISIE CIN:");fflush(stdin);fflush(stdin);gets(mat);
        printf("SAISIE CODE MATIERE:");fflush(stdin);gets(code_m);
        printf("SAISIE LA NATURE:");fflush(stdin);gets(nature);
        if(recherche_cin_mat(l,mat,code_m,nature)==NULL)
            printf("NOTE NON SAISIE");
    }while(recherche_cin_mat(l,mat,code_m,nature)==NULL);
    do
    {
        printf("SAISIR LE NOUVEAU NOTE:");fflush(stdin);scanf("%f",note);
    }while(verif_note(recherche_cin_mat(l,mat,code_m,nature)->info3.note)==0);
    recherche_cin_mat(l,mat,code_m,nature)->info3.note=note;
    return l;
}
void affiche_liste_note_etudiant(liste_note l)
{
    liste_note p=l;
    if(l=NULL)
        printf("\nLISTE NOTE VIDE!!\n");
    else
        while(p)
        {
            printf("\nCIN :%s",p->info3.mat);
            printf("\nCODE MATIERE:%s",p->info3.code_mat);
            printf("\nNOTE:%f",p->info3.note);
            printf("\nNATURE:%s\n",p->info3.nature);
            p=p->suiv3;
        }
}
void affiche_notes_etud(liste_note l)
{
    char mat[9];
    do
    {
        printf("SAISIR CIN ETUDIANT:");fflush(stdin);gets(mat);
        if(recherche_cin_note(l,mat)==NULL)
            printf("L'ETUDIANT N'AUCUNE NOTE,SAISIR UN AUTRE CIN!!");
    }while(recherche_cin_note(l,mat)==NULL);
    affiche_note(l,mat);
}


void affiche_note_nature(liste_note l,char mat[],char nat[])
{
    liste_note p=l;
    while(p)
    {
        if(strcmp(p->info3.mat,mat)==0&&strcmp(p->info3.nature,nat)==0)
        {
            printf("\nCIN:%s",p->info3.mat);
            printf("\nMATIERE:%s",p->info3.code_mat);
            printf("\nNOTE DS:%f",p->info3.note);
        }
        p=p->suiv3;
    }
}
void affiche_ds_etud(liste_note l)
{
    char mat[9];
    do
    {
        printf("SAISIR CIN ETUDIANT:");fflush(stdin);gets(mat);
        if(recherche_cin_note(l,mat)==NULL)
            printf("L'ETUDIANT N'AUCUNE NOTE,SAISIR UN AUTRE CIN!!");
    }while(recherche_cin_note(l,mat)==NULL);
    affiche_note_nature(l,mat,"DS");
}
void affiche_ex_etud(liste_note l)
{
    char mat[9];
    do
    {
        printf("SAISIR CIN ETUDIANT:");fflush(stdin);gets(mat);
        if(recherche_cin_note(l,mat)==NULL)
            printf("L'ETUDIANT N'AUCUNE NOTE,SAISIR UN AUTRE CIN!!");
    }while(recherche_cin_note(l,mat)==NULL);
    affiche_note_nature(l,mat,"EX");
}
#endif // NOTE_H_INCLUDED
