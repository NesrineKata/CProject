#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include"definition.h"
#include"fonction_rech.h"
#include"controle.h"
date saisie_date()
{
    date d;
    do
    {
        printf("Donner la date sous la forme jj/mm/aaaa: ");
        fflush(stdin);
        scanf("%d/%d/%d",&d.j,&d.m,&d.a);
    }while(!valide(d));
    return d;
}
etudiant saisie_etudiant(liste_etud l)
{
    etudiant e;
    do
    {
        printf("saisir cin: ");fflush(stdin);gets(e.cin);
    }while(!(verif_cin(e.cin)&&recherche_etud(l,e.cin)==NULL));
    do
    {
        printf("saisir nom: ");fflush(stdin);gets(e.nom);
    }while(verif_chaine(e.nom)==0);
    do
    {
        printf("saisir prenom: ");fflush(stdin);gets(e.prenom);
    }while(verif_chaine(e.prenom)==0);
    do
    {
        printf("la date de naissance \n");
        e.dn=saisie_date();
    }while(valide(e.dn)==0);
    do
    {
        printf("saisir la section: ");fflush(stdin);gets(e.section);
    }while(verif_section(e.section)==0);
    do
    {
        printf("saisir l'etape: ");fflush(stdin);scanf("%d",&e.etape);
    }while(e.etape!=1&&e.etape!=2&&e.etape!=3);
    return e;
}
int taille_liste(liste_etud l)
{
    int n=0;
    while(l)
    {
        n++;
        l=l->suiv1;
    }
    return n;
}
liste_etud insere_tete(liste_etud l ,etudiant e)
{
    liste_etud p;
    p=malloc(sizeof(struct cellule1));
    p->info1=e;
    p->suiv1=l;
    l=p;
    return l;
}
liste_etud insere_queue(liste_etud l,etudiant e)
{
    liste_etud p,q=l;
    if(l==NULL)
        l=insere_tete(l,e);
    else
    {
        while(q->suiv1)
            q=q->suiv1;
        p=malloc(sizeof(struct cellule1));
        p->info1=e;
        p->suiv1=NULL;
        q->suiv1=p;

    }
return l;
}
liste_etud insere_pos(liste_etud l,etudiant e,int pos)
{
    int cp=1;
    liste_etud p,q=l;
    while(cp<pos-1)
    {
        cp++;
        q=q->suiv1;
    }
    p=malloc(sizeof(struct cellule1));
    p->info1=e;
    p->suiv1=q->suiv1;
    q->suiv1=p;
    return l;
}
liste_etud supprimmer_tete_etudiant(liste_etud l)
{
    liste_etud p=l;
    if(l==NULL)
        printf("liste vide");
    else
    {
        l=l->suiv1;
        free(p);
    }
    return l;
}
liste_etud supprimmer_queue_etudiant(liste_etud l)
{
    liste_etud p=l,q;
    if(l==NULL)
        printf("liste vide");
    else
        if(l->suiv1==NULL)
        {
            l=l->suiv1;
            free(p);
        }
        else
        {
        while(p->suiv1->suiv1)
            p=p->suiv1;
        q=p->suiv1;
        free(q);
        p->suiv1=NULL;
    }
    return l;
}
liste_etud suppression_pos_etudiant(liste_etud l,int pos)
{
    int cp=1;
    liste_etud p=l,q;
    while(cp<pos-1)
        p=p->suiv1;
    q=p->suiv1;
    p=q->suiv1;
    free(q);
    return l;
}
liste_etud suppression_etudiant_donne(liste_etud l,char mat[])
{
    liste_etud p=l,prec=NULL,q;
    while(strcmp(p->info1.cin,mat)!=0&&p)
    {
        prec=p;
        p=p->suiv1;
    }
    if(prec==NULL)
        l=supprimmer_tete_etudiant(l);
    else
        if(p!=NULL)
        {
         prec->suiv1=p->suiv1;
         free(p);
        }
        else
            printf("etudiant n'existe pas!");
    return l;
}
void affiche_etudiant(liste_etud l, char mat[])
{
    liste_etud p=l;
    int j=1;
    while(strcmp(p->info1.cin,mat)!=0&&p)
        p=p->suiv1;

    if(p!=NULL)
    {/*
        gotoxy(1,7+j);printf("|%s",p->info1.cin); Sleep(1000);
        gotoxy(12,7+j);printf("|%s",p->info1.nom); Sleep(1000);
        gotoxy(43,7+j);printf("|%s",p->info1.prenom); Sleep(1000);
        gotoxy(74,7+j);printf("|%d/%d/%d",p->info1.dn.j,p->info1.dn.m,p->info1.dn.a); Sleep(1000);
        gotoxy(86,7+j);printf("|%.1f",p->info1.section); Sleep(1000);
        gotoxy(107,7+j);printf("|%d",p->info1.etape); Sleep(1000);
        gotoxy(110,7+j);printf("|"); Sleep(1000);
        j++;
        Sleep(1000);
       */printf("CIN:%s",p->info1.cin);
        printf("\nNOM:%s",p->info1.nom);
        printf("\nPRENOM:%s",p->info1.prenom);
        printf("\nDATE DE NAISSSANCE:%d/%d/%d",p->info1.dn.j,p->info1.dn.m,p->info1.dn.a);
        printf("\nSECTION:%s",p->info1.section);
        printf("\nETAPE:%d",p->info1.etape);
    }
    else
        printf("ETUDIANT N'EXISTE PAS");
}
void affiche_liste_etudiant(liste_etud l)
{
    int i=1;
    if(l==NULL)
        printf("LISTE VIDE\n");
    else
    {
    /*printf("----------------------------------------------------------------------------------------------------------");
    gotoxy(1,6);printf("|   CIN ");
    gotoxy(11,6);printf("|");
    gotoxy(12,6);printf("   Nom");
    gotoxy(42,6);printf("|");
    gotoxy(43,6);printf("   Prenom");
    gotoxy(73,6);printf("|");
    gotoxy(74,6);printf("  Date de naissance");
    gotoxy(85,6);printf("|");
    gotoxy(86,6);printf("SECTION");
    gotoxy(106,6);printf("|");
    gotoxy(107,6);printf("ETAPE");
    gotoxy(110,6);printf("|");
    printf("\n");
    printf("|------------------|--------------------|--------------------|--------------------|---------------|----------|");
      */  while(l)
        {
            affiche_etudiant(l,l->info1.cin);
            l=l->suiv1;
            i++;
        }
    //printf("\n");
    //printf("--------------------------------------------------------------------------------------------------------------");
    }
}
liste_etud CREATION(liste_etud l)
{
    int pos,t;
    char rep;
    etudiant e;
    do
    {
        t=taille_liste(l);
        do
        {
            printf("Saisir la postion entre 1 et %d :",t+1);fflush(stdin);
            scanf("%d",&pos);
        }while(pos<1||pos>t+1);
        e=saisie_etudiant(l);
        if(pos==1)
            l=insere_tete(l,e);
        else
            if(pos==t+1)
                l=insere_queue(l,e);
            else
                l=insere_pos(l,e,pos);
        do
        {
            printf("Voulez_vous ajouter un autre etudiant O/N:");fflush(stdin);
            scanf("%c",&rep);
        }while(rep!='O'&&rep!='N');
    }while(rep=='O');
    return l;
}
liste_etud supp_etud_sec_etape(liste_etud l,char sect,int nv)
{
    liste_etud p=l,pos=1;
    while(p)
    {
        if(strcmp(p->info1.section,sect)==0&&p->info1.etape==nv)
        {
            if(pos==1)
                l=supprimmer_tete_etudiant(l);
            else
            {
                l=suppression_pos_etudiant(l,pos);
                pos--;
            }
        }
        else
        pos++;
        p=p->suiv1;
    }
    return l;
}
void recherche_etud_mat(liste_etud l)
{
    char mat[9];
    int  cp=0;
    printf("\nSAISIR NUMERO DE CIN:");fflush(stdin);gets(mat);
    if(recherche_etud(l,mat))
        affiche_etudiant(l,mat);
    else
        printf("\nETUDIANT N'EXISTE PAS\n");
}
void  recherche_section(liste_etud l)
{
    liste_etud p=l;
    int cp=0;
    char sect[20];
    printf("\n SAISIR SECTION:");fflush(stdin);gets(sect);
    while(p)
    {
        if(strcmp(p->info1.section,sect)==0)
        {
            affiche_etudiant(l,p->info1.cin);
            cp=1;
        }
        p=p->suiv1;
    }
    if(cp==0)
        printf("Aucun etudiant dans le section: %s\n",sect);
}
void  recherche_etape(liste_etud l)
{
    liste_etud p=l;
    int cp=0,nv;
    printf("\n SAISIR ETAPE:");fflush(stdin);scanf("%d",&nv);
    while(p)
    {
        if(p->info1.etape==nv)
        {
            affiche_etudiant(l,p->info1.cin);
            cp=1;
        }
        p=p->suiv1;
    }
    if(cp==0)
        printf("Aucun etudiant dans l'etape : %d\n",nv);
}
void  recherche_etape_section(liste_etud l)
{
    liste_etud p=l;
    int cp=0,nv;
    char sect[20];
    printf("\n SAISIR SECTION:");fflush(stdin);gets(sect);
    printf("\n SAISIR ETAPE:");fflush(stdin);scanf("%d",&nv);
    while(p)
    {
        if(strcmp(p->info1.section,sect)==0&&p->info1.etape==nv)
        {
            affiche_etudiant(l,p->info1.cin);
            cp=1;
        }
        p=p->suiv1;
    }
    if(cp==0)
              printf("Aucun etudiant dans la section :%s de l'etape : %d\n",sect,nv);

}
liste_etud ajout_tete_etudiant(liste_etud l)
{
    etudiant e;
    printf("\t\tSAISIR UN ETUDIANT EN TETE DE LA LISTE\n");
    e=saisie_etudiant(l);
    l=insere_tete(l,e);
    return l;
}
liste_etud ajout_queue_etudiant(liste_etud l)
{
    etudiant e;
    printf("\t\tSAISIR UN ETUDIANT EN  QUEUE DE LA LISTE\n");
    e=saisie_etudiant(l);
    l=insere_queue(l,e);
    return l;
}
liste_etud ajout_pos_etudiant(liste_etud l)
{
    etudiant e;
    int pos;
    printf("\t\tSAISIR UN ETUDIANT DANS UNE POSTION DE LA LISTE\n");
    do{printf("\n SAISIR LA POSITION:");fflush(stdin);scanf("%d",&pos);}while(pos<=1||pos>taille_liste(l)+1);
    e=saisie_etudiant(l);
    l=insere_pos(l,e,pos);
    return l;
}
liste_etud sup_pos(liste_etud l)
{
    int pos;
    printf("\t\tSUPPRISSION UN ETUDIANT D'UNE POSTION DE LA LISTE\n");
    if(taille_liste(l)==1)
        printf("impossible de supprimer car la position doit etre ente 2 et taille de la liste +1");
    else
    {
        do{printf("\n SAISIR LA POSITION:");fflush(stdin);scanf("%d",&pos);}while(pos>taille_liste(l)+1||pos<=1);
        l=suppression_pos_etudiant(l,pos);
    }
    return l;
}
liste_etud sup_etud_donne(liste_etud l)
{
    char mat[9];
    printf("\t\tSUPPRISSION UN ETUDIANT DE LA LISTE\n");
    printf("\n SAISIR CIN:");fflush(stdin);scanf("%s",&mat);
    l=suppression_etudiant_donne(l,mat);
    return l;
}
liste_etud sup_etud_sect_etape_donne(liste_etud l)
{
    char sect[20];
    int nv;
    printf("\t\tSUPPRISSION DES ETUDIANT  D'UNE SECTION ET ETAPE DONNE DE LA LISTE\n");
    printf("\n SAISIR SECTION:");fflush(stdin);scanf("%s",&sect);
    printf("\n SAISIR ETAPE:");fflush(stdin);scanf("%d",&nv);
    l=supp_etud_sec_etape(l,sect,nv);
    return l;
}
void tri_liste_etud(liste_etud l)
{
    liste_etud p=l,q;
    etudiant aux;
    while(p->suiv1)
    {
        q=p->suiv1;
        while(q)
        {
            if(strcmp(p->info1.cin,q->info1.cin)>0)
            {
                aux=p->info1;
                p->info1=q->info1;
                q->info1=aux;
            }
        q=q->suiv1;
        }
        p=p->suiv1;
    }

}
void tri1(liste_etud l)
{
    tri_liste_etud(l);
    printf("\nCONTENU DE LA LISTE APRES  TRI1:\n");
    affiche_liste_etudiant(l);
}
#endif // FONCTION_H_INCLUDED
