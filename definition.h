#ifndef DEFINITION_H_INCLUDED
#define DEFINITION_H_INCLUDED
typedef struct
    {
        int j;
        int m;
        int a;
    }date;
typedef struct
    {
        char cin[9];
        char nom[21];
        char prenom[21];
        date dn;
        char section[21];
        int etape;
    }etudiant;
struct cellule1
    {
        etudiant info1;
        struct cellule1 * suiv1;
    };
typedef struct cellule1 * liste_etud;
typedef struct
    {
        char code_mat[4];
        char nom_mat[50];
        char section[21];
        float coef;
        int niveau;
    }matiere;
struct cellule2
    {
        matiere info2;
        struct cellule2 *suiv2;
    };
typedef struct cellule2 * liste_mat;
typedef struct
    {
        char mat[9];
        char code_mat[4];
        float note;
        char nature[3];
    }note;
struct cellule3
    {
        note info3;
        struct cellule3 * suiv3;
    };
typedef struct cellule3 * liste_note;

#endif // DEFINITION_H_INCLUDED
