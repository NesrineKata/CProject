#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include"definition.h"
#include"etudiant.h"
#include"matiere.h"
#include"note.h"
void enregistrement_etud (liste_etud l)
{
    liste_etud q=l;
    FILE *f;
    f=fopen("ETUDIANT.txt","w");
    while(q)
    {
        //fscanf(INFILE,"%[^;];%[^;];%[^;];%[^n]%*c", ch1,ch2,ch3,ch4)

        fprintf(f,"%s\n",q->info1.cin);
        fprintf(f,"%s\n",q->info1.nom);
        fprintf(f,"%s\n",q->info1.prenom);
        fprintf(f,"%d/%d/%d\n",q->info1.dn.j,q->info1.dn.m,q->info1.dn.a);
        fprintf(f,"%s\n",q->info1.section);
        fprintf(f,"%d\n\n",q->info1.etape);
        q=q->suiv1;
    }
    fclose(f);
}
liste_etud recuperation_etudiant ()
{
    liste_etud l=NULL;
    etudiant info1;
    FILE *f=NULL;
    printf("RECUPERATION DE FINCIER TEXTE :etud.txt\n");
    f=fopen("ETUDIANT.txt","r");
    if(f!=NULL)
    while(!(feof(f)))
    {
        size_t ln;
        fgets(info1.cin,sizeof(info1.cin),f);
        ln = strlen(info1.cin)-1;
        if (info1.cin[ln] == '\n')
        info1.cin[ln] = '\0';

        fgets(info1.nom,sizeof(info1.nom),f);
        ln = strlen(info1.nom)-1;
        if (info1.nom[ln] == '\n')
        info1.nom[ln] = '\0';

        fgets(info1.prenom,sizeof(info1.prenom),f);
        ln = strlen(info1.prenom)-1;
        if (info1.prenom[ln] == '\n')
        info1.prenom[ln] = '\0';

        fscanf(f,"%d/%d/%d\n",&info1.dn.j,&info1.dn.m,&info1.dn.a);
        fgets(info1.section,sizeof(info1.section),f);
        ln = strlen(info1.section)-1;
        if (info1.section[ln] == '\n')
        info1.section[ln] = '\0';
        fflush(stdin);
        fscanf(f,"%d\n\n",&info1.etape);
        l=insere_queue(l,info1);

    }
    fclose(f);
    return l;
}
void enregistrement_matiere(liste_mat l)
{
    liste_mat q=l;
    FILE *f;
    f=fopen("MATIERE.txt","w");
    while(q)
    {
        //fscanf(INFILE,"%[^;];%[^;];%[^;];%[^n]%*c", ch1,ch2,ch3,ch4)

        fprintf(f,"%s\n",q->info2.code_mat);
        fprintf(f,"%s\n",q->info2.nom_mat);
        fprintf(f,"%s\n",q->info2.section);
        fprintf(f,"%.2f\n",q->info2.coef);
        fprintf(f,"%d\n\n",q->info2.niveau);
        q=q->suiv2;
    }
    fclose(f);
}
liste_mat recuperation_mat ()
{
    liste_mat l=NULL;
    matiere info2;
    FILE *f=NULL;
    printf("RECUPERATION DE FICHIER TEXTE :MATIERE.txt\n");
    f=fopen("MATIERE.txt","r");
    while(!(feof(f)))
    {
        size_t ln;
        fgets(info2.code_mat,sizeof(info2.code_mat),f);
        ln = strlen(info2.code_mat)-1;
        if (info2.code_mat[ln] == '\n')
        info2.code_mat[ln] = '\0';

        fgets(info2.nom_mat,sizeof(info2.nom_mat),f);
        ln = strlen(info2.nom_mat)-1;
        if (info2.nom_mat[ln] == '\n')
        info2.nom_mat[ln] = '\0';

        fgets(info2.section,sizeof(info2.section),f);
        ln = strlen(info2.section)-1;
        if (info2.section[ln] == '\n')
        info2.section[ln] = '\0';

        fscanf(f,"%.2f\n",&info2.coef);
        fscanf(f,"%d\n\n",&info2.niveau);
        l=insere_queue_mat(l,info2);

    }
    fclose(f);
    return l;
}
void enregistrement_note(liste_note l)
{
    liste_note q=l;
    FILE *f;
    f=fopen("NOTE.txt","w");
    while(q)
    {
        //fscanf(INFILE,"%[^;];%[^;];%[^;];%[^n]%*c", ch1,ch2,ch3,ch4)

        fprintf(f,"%s\n",q->info3.mat);
        fprintf(f,"%s\n",q->info3.code_mat);
        fprintf(f,"%.2f\n",q->info3.note);
        fprintf(f,"%s\n\n",q->info3.nature);
        q=q->suiv3;
    }
    fclose(f);
}
liste_note recuperation_note ()
{
    liste_note l=NULL;
    note info3;
    FILE *f=NULL;
    printf("RECUPERATION DE FICHIER TEXTE :NOTE.txt\n");
    f=fopen("NOTE.txt","r");
    while(!(feof(f)))
    {
        size_t ln;
        fgets(info3.mat,sizeof(info3.mat),f);
        ln = strlen(info3.mat)-1;
        if (info3.mat[ln] == '\n')
        info3.mat[ln] = '\0';

        fgets(info3.code_mat,sizeof(info3.code_mat),f);
        ln = strlen(info3.code_mat)-1;
        if (info3.code_mat[ln] == '\n')
        info3.code_mat[ln] = '\0';

        fscanf(f,"%.2f\n",&info3.note);
        fscanf(f,"%s\n\n",&info3.nature);
        l=insere_queue_note(l,info3);

    }
    fclose(f);
    return l;
}




#endif // FICHIER_H_INCLUDED
