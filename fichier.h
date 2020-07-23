#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include"definition.h"
#include"etudiant.h"
#include"matiere.h"
#include"note.h"



  /************************** CONSTRUCTION CHAINE ****************************/
int construction(char *ligne,int pos,char s,char *ch)
{
    int i,j;
    for(i=pos,j=0;ligne[i]!=s;i++)
            ch[j++]=ligne[i];
        ch[j]='\0';
    //puts(ch);
    return i+1;
}

        /****************** Stockage de la liste etudiant dans un fichier ************/
void enregistrement_etudiant(liste_etud l)
{
    int i;
    FILE *fp;
    fp=fopen("liste_etudiant.txt","w");
    while(l)
    {

        fprintf(fp,"|%s|%s|%s|%d/%d/%d|%s|%d|\n",l->info1.cin,l->info1.nom,l->info1.prenom,l->info1.dn.j,l->info1.dn.m,l->info1.dn.a,l->info1.section,l->info1.etape);
        l=l->suiv1;
    }
    fclose(fp);
    printf ("\nEnregistrement du tableau dans le fichier %s \n","fihcier_etud.txt");
}
    /****************** Enregistrement de la liste mati?re dans un fichier ************/
void enregistrement_mat(liste_mat l)
{
    int i;
    FILE *fp;
    fp=fopen("fichier_mat.txt","w");

    while(l)
    {

        fprintf(fp,"|%s|%s|%s|%.2f|%d|\n",l->info2.code_mat,l->info2.nom_mat,l->info2.section,l->info2.coef,l->info2.niveau);
        l=l->suiv2;
    }
    fclose(fp);
    printf ("\nEnregistrement de la liste matiere dans le fichier %s \n","fichier_mat.txt");
}
            /************ Recuperation du fichier dans une liste etudiant ****************/

liste_etud recuperation_etudiant()
{

    FILE *fp;
    liste_etud p=NULL;
    etudiant e;
    int pos;
    char ligne[100];
    char ch[5];
    char etape[3];
    fp=fopen("liste_etudiant.txt","r");

    if(fp==NULL)
         MessageBoxW(NULL, L"LISTE ETUDIANT  VIDE", L"ERREUR", MB_OK);
    else
       while(fgets(ligne,100,fp)!=NULL)
       {
            pos=construction(ligne,1,'|',e.cin);
            pos=construction(ligne,pos,'|',e.nom);
            pos=construction(ligne,pos,'|',e.prenom);
            pos=construction(ligne,pos,'/',ch);
            e.dn.j=atoi(ch);
            pos=construction(ligne,pos,'/',ch);
            e.dn.m=atoi(ch);
            pos=construction(ligne,pos,'|',ch);
            e.dn.a=atoi(ch);
            pos=construction(ligne,pos,'|',e.section);
            pos=construction(ligne,pos,'|',etape);
            e.etape=atoi(etape);
            p=insere_queue(p,e);

       }
    fclose(fp);
    return p;
}




         /************ Recuperation du fichier dans la liste matiere ****************/


liste_mat recuperation_mat()
{

    FILE *fp;
    liste_mat p=NULL;
    matiere e;
    int pos;
    char ligne[100];
    fp=fopen("fichier_mat.txt","r");

    if(fp==NULL)
         MessageBoxW(NULL, L"LISTE MATIERE  VIDE", L"ERREUR", MB_OK);
    else
       while(fgets(ligne,100,fp)!=NULL)
       {
            pos=construction(ligne,1,'|',e.code_mat);
            pos=construction(ligne,pos,'|',e.nom_mat);
            pos=construction(ligne,pos,'|',e.section);
            pos=construction(ligne,pos,'|',coefc);
            pos=construction(ligne,pos,'|',etapec);
            e.coef=atof(coefc);
            e.niveau=atoi(etapec);
            p=insere_queue_mat(p,e);
       }
    fclose(fp);
    return p;
}

void enregistrement_note(liste_note l)
{
    int i;
    FILE *fp;
    fp=fopen("fichier_note.txt","w");

    while(l)
    {

        fprintf(fp,"|%s|%s|%.2f|%s|\n",l->info3.mat,l->info3.code_mat,l->info3.note,l->info3.nature);
        l=l->suiv3;
    }
    fclose(fp);
    printf ("\nEnregistrement de la liste matiere dans le fichier %s \n","fichier_note.txt");
}
liste_note recuperation_note()
{

    FILE *fp;
    liste_note p=NULL;
    note e;
    int pos;
    char ligne[100];
    fp=fopen("fichier_note.txt","r");

    if(fp==NULL)
         MessageBoxW(NULL, L"LISTE NOTE  VIDE", L"ERREUR", MB_OK);
    else
       while(fgets(ligne,100,fp)!=NULL)
       {
            pos=construction(ligne,1,'|',e.mat);
            pos=construction(ligne,pos,'|',e.code_mat);
            pos=construction(ligne,pos,'|',notec);
            pos=construction(ligne,pos,'|',e.nature);
            e.note=atof(notec);
            p=insere_queue_note(p,e);
       }
    fclose(fp);
    return p;
}
#endif // FICHIER_H_INCLUDED
