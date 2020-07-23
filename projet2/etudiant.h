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
    }while(recherche_etud(l,e.cin));
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
liste_etud supp_etud_sec_etape(liste_etud l,char sect[],int nv)
{
    liste_etud p=l,q;
    int pos=1;
    while(p)
    {
        if(strcmp(p->info1.section,sect)==0&&p->info1.etape==nv)
        {
                if(p==l)
                {
                    l=l->suiv1;
                    free(p);
                    p=l;
                }
                else
                {
                    q=p;
                    p=p->suiv1;
                    free(q);
                }
        }
        else
        p=p->suiv1;
    }
    return l;
}



liste_etud tri_liste_etud(liste_etud l)
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
    return l;

}
liste_etud tri2(liste_etud l)
{
    int ok=1;
    liste_etud p,q,prec;
    while(ok)
    {
        ok=0;
        p=l;
        prec=NULL;
        q=p->suiv1;
        while(q)
        {
            if(strcmp(p->info1.cin,q->info1.cin)>0)
            {
                if(prec==NULL)
                {
                    p->suiv1=q->suiv1;
                    q->suiv1=p;
                    l=q;
                    prec=q;
                    q=p->suiv1;
                }
                else
                {
                    p->suiv1=q->suiv1;
                    prec->suiv1=q;
                    q->suiv1=p;
                    prec=q;
                    q=p->suiv1;
                }
                ok=1;

            }
            else
            {
                prec=p;
                p=p->suiv1;
                q=q->suiv1;
            }
        }
    }while(ok);
    return l;

}
void affiche(liste_etud l)
{
    if(l==NULL)
        printf("LISTE VIDE");
    else
        while(l)
        {
printf("%s\t%s\t%s\t%d/%d/%d\t%s\t%d\n",l->info1.cin,l->info1.nom,l->info1.prenom,l->info1.dn.j,l->info1.dn.m,l->info1.dn.a,l->info1.section,l->info1.etape);
 l=l->suiv1;
        }
}
/*
void tri1(liste_etud l)
{
    tri_liste_etud(l);
    printf("\nCONTENU DE LA LISTE APRES  TRI1:\n");
    affiche_liste_etudiant(l);
    printf("\n");
}*/
int nb_mat_section_nv(char sec[],int nv)
{
    liste_mat p=LM;
    int nb=0;
    while(p)
    {
        if(strcmp(p->info2.section,sec)==0&&p->info2.niveau==nv)
            nb++;
        p=p->suiv2;

    }
    //printf("Cette section a %d note ",nb);
    return nb;
}

int nb_etud_mat(char mat[])
{
    liste_note p=LN;
    int nb=0;
    while(p)
    {
        if(strcmp(p->info3.mat,mat)==0)
            nb++;
        p=p->suiv3;
    }
     //printf("L etudiant a %d note",nb/2);
    return nb/2;

}
float moyenne_etudiant(liste_mat l,char cinc[])
{
    liste_note p,pds,pex;
    float s=0,scoef=0;
    liste_mat p2=l;
    liste_etud p1;
    etudiant info;

        p1=recherche_etud(LE,cinc);
        info=p1->info1;
        nv=info.etape;

       while(p2)
        {
            if(strcmp(p2->info2.section,info.section)==0&&p2->info2.niveau==nv)
                if(recherche_cin_mat(LN,cinc,p2->info2.code_mat,"DS")&&recherche_cin_mat(LN,cinc,p2->info2.code_mat,"EX"))
                {
                    pds=recherche_cin_mat(LN,cinc,p2->info2.code_mat,"DS");
                    pex=recherche_cin_mat(LN,cinc,p2->info2.code_mat,"EX");
                    moy=pds->info3.note*0.3+pex->info3.note*0.7;


                    scoef+=p2->info2.coef;
                    s+=moy*p2->info2.coef;
             //       printf("moy=%f s=%f scoef= %f\n",moy,s,scoef);
                }
                p2=p2->suiv2;
        }
               //            printf("Moyenne  generale =%f\n",s/scoef);

    return ((float)s/scoef);

}
float moy_etab( liste_etud l)
{
    liste_etud p=l;
    int nb=0;
    float smoy=0;
    int test=0;
    while(p)
    {

        smoy+=moyenne_etudiant(LM,p->info1.cin);
        nb++;

        p=p->suiv1;
       // printf(" somme moyenne etudiant =%f nb=%d",smoy,nb);
    }
    return smoy/nb;
}
int nb_etud_sec_etape(char sec[],int nv)
{
    liste_etud p=LE;
    int nb=0;
    while(p)
    {
        if(strcmp(p->info1.section,sec)==0&&nv==p->info1.etape)
            if(nb_etud_mat(p->info1.cin)==nb_mat_section_nv(sec,nv)&&nb_mat_section_nv(sec,nv)==0)
                nb++;
        p=p->suiv1;
    }
    return nb;
}
int rang_etud(char cinc[])
{
    liste_etud p=LE,q;
    q=recherche_etud(LE,cinc);
    int rg=/*nb_etud_sec_etape(q->info1.section,q->info1.etape)*/1;
    printf("%d",rg);
    strcpy(sectionc,q->info1.section);
    nv=q->info1.etape;
    while(p)
    {if(strcmp(p->info1.section,sectionc)==0&&p->info1.etape==nv)
        if(moyenne_etudiant(LM,p->info1.cin)>=moyenne_etudiant(LM,cinc))
            rg++;
        p=p->suiv1;
    }
    return rg;
}
void matiere_manque(char cinc[],wchar_t *ch,char sec[],int nv)
{
    liste_mat p=LM;
    char es[2]="  ";
   // wchar_t ch[1024] = L"";
    strcat(ch,"Les matieres manquantes: ");
    while(p)
    {
        if(strcmp(p->info2.section,sec)==0&&p->info2.niveau==nv)
        if(recherche_cin_mat(LN,cinc,p->info2.code_mat,"DS")==NULL||recherche_cin_mat(LN,cinc,p->info2.code_mat,"EX")==NULL)
        {
            strcat(ch,p->info2.nom_mat);
            strcat(ch,L" |||| ");
             printf("%s",ch);
        }
         p=p->suiv2;
    }
    return ch;
}
liste_etud  premier_max(liste_etud LE)
{
    liste_etud  p=LE;
    etudiant info;
    while(p)
    {
       strcpy(sectionc,info.section);
       nv=info.etape;
       strcpy(cinc,p->info1.cin);
       if(nb_etud_mat(cinc)==nb_mat_section_nv(sectionc,nv)&&nb_mat_section_nv(sectionc,nv)!=0)
            return p;
        p=p->suiv1;
     }
    return p;
}
#endif // FONCTION_H_INCLUDED
