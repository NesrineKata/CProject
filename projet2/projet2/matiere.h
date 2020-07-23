#ifndef MATIERE_H_INCLUDED
#define MATIERE_H_INCLUDED
#include"etudiant.h"
#include"definition.h"
#include"fonction_rech.h"
#include"controle.h"
matiere saisie_matiere(liste_mat l)
{
    matiere m;
    do
    {
        printf("saisir code matiere: ");fflush(stdin);gets(m.code_mat);
    }while(verif_code(m.code_mat)==0||recherche_code_m(l,m.code_mat));
    do
    {
        printf("saisir nom matiere: ");fflush(stdin);gets(m.nom_mat);
    }while(verif_nom_mat(m.nom_mat)==0);
    do
    {
        printf("saisir la section: ");fflush(stdin);gets(m.section);
    }while(verif_section(m.section)==0);
    do
    {
        printf("saisir le niveau: ");fflush(stdin);scanf("%d",&m.niveau);
    }while(m.niveau!=1&&m.niveau!=2&&m.niveau!=3);
    do
    {
        printf("Saisir le coefficient:");fflush(stdin);scanf("%f",&m.coef);
    }while(m.coef<=0);
    return m;
}
int taille_liste_mat(liste_mat l)
{
    int n=0;
    while(l)
    {
        n++;
        l=l->suiv2;
    }
    return n;
}
liste_mat insere_tete_mat(liste_mat l ,matiere e)
{
    liste_mat p;
    p=malloc(sizeof(struct cellule2));
    p->info2=e;
    p->suiv2=l;
    l=p;
    return l;
}
liste_mat insere_queue_mat(liste_mat l,matiere e)
{
    liste_mat p,q=l;
    if(l==NULL)
        l=insere_tete_mat(l,e);
    else
    {
        while(q->suiv2)
            q=q->suiv2;
        p=malloc(sizeof(struct cellule2));
        p->info2=e;
        p->suiv2=NULL;
        q->suiv2=p;

    }
return l;
}
liste_mat insere_pos_mat(liste_mat l,matiere e,int pos)
{
    int cp=1;
    liste_mat p,q=l;
    while(cp<pos-1)
    {
        cp++;
        q=q->suiv2;
    }
    p=malloc(sizeof(struct cellule2));
    p->info2=e;
    p->suiv2=q->suiv2;
    q->suiv2=p;
    return l;
}
liste_mat supprimmer_tete_mat (liste_mat l)
{
    liste_mat p=l;
    if(l==NULL)
        printf("liste vide");
    else
    {
        l=l->suiv2;
        free(p);
    }
    return l;
}
liste_mat supprimmer_queue_mat(liste_mat l)
{
    liste_mat p=l,q;
    if(l==NULL)
        printf("liste vide");
    else
        if(l->suiv2==NULL)
        {
            l=l->suiv2;
            free(p);
        }
        else
        {
        while(p->suiv2->suiv2)
            p=p->suiv2;
        q=p->suiv2;
        free(q);
        p->suiv2=NULL;
    }
    return l;
}
liste_mat suppression_pos_mat(liste_mat l,int pos)
{
    int cp=1;
    liste_mat p=l,q;
    while(cp<pos-1)
        p=p->suiv2;
    q=p->suiv2;
    p=q->suiv2;
    free(q);
    return l;
}
liste_mat suppression_mat_donne(liste_mat l,char mat[])
{
    liste_mat p=l,prec=NULL;
    while(strcmp(p->info2.code_mat,mat)!=0&&p)
    {
        prec=p;
        p=p->suiv2;
    }
    if(prec==NULL)
        l=supprimmer_tete_mat(l);
    else
        if(p!=NULL)
        {
         prec->suiv2=p->suiv2;
         free(p);
        }
        else
            printf("Matiere n'existe pas!");
    return l;
}
void affiche_matiere(liste_mat l, char mat[])
{
    liste_mat p=l;
    while(strcmp(p->info2.code_mat,mat)!=0&&p)
        p=p->suiv2;
    if(p!=NULL)
    {
        printf("CODE MATIERE:%s",p->info2.code_mat);
        printf("\nNOM MATIERE:%s",p->info2.nom_mat);
        printf("\nSECTION:%s",p->info2.section);
        printf("\nNIVEAU:%d",p->info2.niveau);
        printf("\nCOEFICIENT:%f",p->info2.coef);
    }
    else
        printf("ETUDIANT N'EXISTE PAS");
}
void affiche_liste_matiere(liste_mat l)
{
    int i=1;
    if(l==NULL)
        printf("LISTE VIDE\n");
    else
    {
        while(l)
        {
            printf("\nLES INFORMATIONS  DE MATIERE N:%d\n",i);
            affiche_matiere(l,l->info2.code_mat);
            l=l->suiv2;
            i++;
        }
    }
}
liste_mat CREATION_mat(liste_mat l)
{
    int pos,t;
    char rep;
    matiere m;
    do
    {
        t=taille_liste_mat(l);
        do
        {
            printf("Saisir la postion entre 1 et %d :",t+1);fflush(stdin);
            scanf("%d",&pos);
        }while(pos<1||pos>t+1);
        m=saisie_matiere(l);
        if(pos==1)
            l=insere_tete_mat(l,m);
        else
            if(pos==t+1)
                l=insere_queue_mat(l,m);
            else
                l=insere_pos_mat(l,m,pos);
        do
        {
            printf("Voulez_vous ajouter un autre matiere O/N:");fflush(stdin);
            scanf("%c",&rep);
        }while(rep!='O'&&rep!='N');
    }while(rep=='O');
    return l;
}
liste_mat ajout_tete_mat(liste_mat l)
{
    matiere m;
    printf("\t\tSAISIR UN MATIERE EN TETE DE LA LISTE\n");
    m=saisie_matiere(l);
    l=insere_tete_mat(l,m);
    return l;
}
liste_mat ajout_queue_mat(liste_mat l)
{
    matiere m;
    printf("\t\tSAISIR UN MATIERE EN  QUEUE DE LA LISTE\n");
    m=saisie_matiere(l);
    l=insere_queue_mat(l,m);
    return l;
}
liste_mat ajout_pos_mat(liste_mat l)
{
    matiere m;
    int pos;
    printf("\t\tSAISIR UN MATIERE DANS UNE POSTION DE LA LISTE\n");
    do{printf("\n SAISIR LA POSITION:");fflush(stdin);scanf("%d",&pos);}while(pos<=1||pos>taille_liste_mat(l)+1);
    m=saisie_matiere(l);
    l=insere_pos_mat(l,m,pos);
    return l;
}
liste_mat sup_pos_mat(liste_mat l)
{
    int pos;
    printf("\t\tSUPPRISSION UN MATIERE D'UNE POSTION DE LA LISTE\n");
    if(taille_liste_mat(l)==1)
        printf("impossible de supprimer car la position doit etre ente 2 et taille de la liste +1");
    else
    {
        do{printf("\n SAISIR LA POSITION:");fflush(stdin);scanf("%d",&pos);}while(pos>taille_liste_mat(l)+1||pos<=1);
        l=suppression_pos_mat(l,pos);
    }
    return l;
}
liste_mat sup_mat_donne(liste_mat l)
{
    char mat[4];
    printf("\t\tSUPPRISSION UN MATIERE DE LA LISTE\n");
    printf("\n SAISIR CODE MATIERE:");fflush(stdin);fflush(stdin);gets(mat);
    l=suppression_mat_donne(l,mat);
    return l;
}

void modifier_nom(liste_mat l)
{
    char nom[30];
    char code_m[4];
    do
    {
            printf("SAISIR CODE MATIERE POUR MODIFIER NOM MATIERE:");fflush(stdin);gets(code_m);
            if(recherche_mat(l,code_m)==NULL)
                printf("CODE MATIERE INCORRECT!!!");
    }while(recherche_mat(l,code_m)==NULL);
    do
    {
        printf("SAISIR LE NOUVEAU NOM DE LA MATIERE:");fflush(stdin);gets(nom);
    }while(verif_nom_mat(nom)==0);
    strcpy(nom,recherche_mat(l,code_m)->info2.nom_mat);
}
void modifier_coef(liste_mat l)
{
    float coef;
    char code_m[4];
    do
    {
            printf("SAISIR CODE MATIERE POUR MODIFIER COEFFICIENT MATIERE:");fflush(stdin);gets(code_m);
            if(recherche_mat(l,code_m)==NULL)
                printf("CODE MATIERE INCORRECT!!!");
    }while(recherche_mat(l,code_m)==NULL);
    do
    {
        printf("SAISIR LE NOUVEAU COEFFICIENT DE LA MATIERE:");fflush(stdin);scanf("%f",&coef);
    }while(coef<=0);
    recherche_mat(l,code_m)->info2.coef=coef;
}
void recherche_code_mat(liste_mat l)
{
    char mat[4];
    int  cp=0;
    printf("\nSAISIR CODE MATIERE:");fflush(stdin);gets(mat);
    if(recherche_mat(l,mat))
        affiche_matiere(l,mat);
    else
        printf("\nMATIERE N'EXISTE PAS\n");
}
void  recherche_section_mat(liste_mat l)
{
    liste_mat p=l;
    int cp=0;
    char sect[20];
    printf("\n SAISIR SECTION:");fflush(stdin);gets(sect);
    while(p)
    {
        if(strcmp(p->info2.section,sect)==0)
        {
            affiche_matiere(l,p->info2.code_mat);
            cp=1;
        }
        p=p->suiv2;
    }
    if(cp==0)
        printf("Aucun MATIERE dans le section: %s\n",sect);
}
void  recherche_etape_section_mat(liste_mat l)
{
    liste_mat p=l;
    int cp=0,nv;
    char sect[20];
    printf("\n SAISIR SECTION:");fflush(stdin);gets(sect);
    printf("\n SAISIR ETAPE:");fflush(stdin);scanf("%d",&nv);
    while(p)
    {
        if(strcmp(p->info2.section,sect)==0&&p->info2.niveau==nv)
        {
            affiche_matiere(l,p->info2.code_mat);
            cp=1;
        }
        p=p->suiv2;
    }
    if(cp==0)
              printf("Aucun Matiere dans la section :%s de l'etape : %d\n",sect,nv);

}
void tri_liste_mat(liste_mat l)
{
    liste_mat p=l,q;
    matiere aux;
    while(p->suiv2)
    {
        q=p->suiv2;
        while(q)
        {
            if(strcmp(p->info2.nom_mat,q->info2.nom_mat)>0)
            {
                aux=p->info2;
                p->info2=q->info2;
                q->info2=aux;
            }
        q=q->suiv2;
        }
        p=p->suiv2;
    }
}
void tri_mat(liste_mat l)
{
    tri_liste_mat(l);
    printf("\nCONTENU DE LA LISTE APRES  TRI1:\n");
    affiche_liste_matiere(l);
}
#endif // MATIERE_H_INCLUDED

