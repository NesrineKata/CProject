
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
HINSTANCE hinst;
HWND hwnd;
#include"definition.h"
liste_etud LE=NULL,p=NULL;
liste_mat LM;
liste_note LN;
#include"ID.h"
#include"ressource.h"

#include"fichier.h"

#include"etudiant.h"
#include"matiere.h"
#include"note.h"
#include"formulaire.h"

char szAppName[] = "bouton";

etudiant e;
matiere m;
note n;


LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);
int nCmdShow;
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
                                                  LPSTR lpCmdLine, int nCmdShow)
{

HWND hwnd;

    MSG msg;
    WNDCLASS wc;
    RECT winRect;
    hinst = hinstance;


    wc.style = 0;
    wc.lpfnWndProc = MainWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hinstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_HAND);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName =  NULL;
    wc.lpszClassName = "MaWinClass";
    wc.hbrBackground=(HBRUSH)COLOR_MENUTEXT +4 ;


   if(!RegisterClass(&wc)) return FALSE;

    hwnd = CreateWindow("MaWinClass", "MINI PROJET :TBINI AMEN ALLAH * BENOUN NESRINE ",
       WS_SYSMENU | WS_ACTIVECAPTION | WS_MINIMIZEBOX|WS_OVERLAPPEDWINDOW
       |WS_BORDER|WS_VISIBLE,200, 50,
                  1000,720,
                                                  NULL,NULL , hinstance, NULL);
if (!hwnd) return FALSE;
        ShowWindow(hwnd, nCmdShow);
UpdateWindow(hwnd);




   HMENU hMenubar = CreateMenu();
    HMENU hMenu1 = CreateMenu();
    HMENU hMenu2 = CreateMenu();
    HMENU hMenu3 = CreateMenu();
    HMENU hMenu4 = CreateMenu();
    HMENU hMenu5 = CreateMenu();
    HMENU hMenu6 = CreateMenu();
    HMENU hMenu7 = CreateMenu();
    HMENU hMenu8 = CreateMenu();
    HMENU hMenu9 = CreateMenu();
    HMENU hMenu10 = CreateMenu();
    HMENU hSubMenu1 = CreatePopupMenu();
    HMENU hSubMenu2 = CreatePopupMenu();
    HMENU hSubMenu3 = CreatePopupMenu();
    HMENU hSubMenu4 = CreatePopupMenu();
    HMENU hSubMenu5 = CreatePopupMenu();
    HMENU hSubMenu6 = CreatePopupMenu();
    HMENU hSubMenu7 = CreatePopupMenu();
    HMENU hSubMenu8 = CreatePopupMenu();
    HMENU hSubMenu9 = CreatePopupMenu();
    HMENU hSubMenu10 = CreatePopupMenu();
    HMENU hSubMenu11 = CreatePopupMenu();
    HMENU hSubMenu12 = CreatePopupMenu();
    HMENU hSubMenu13 = CreatePopupMenu();
    HMENU hSubMenu14 = CreatePopupMenu();
    HMENU hSubMenu15 = CreatePopupMenu();
    HMENU hSubMenu16 = CreatePopupMenu();

    /************************************  MENU ETUDIANT  **********************************************/

    //AppendMenuW(hMenu1, MF_POPUP|MF_STRING,ID_ETUD, L"&Creation des etudiants");
    AppendMenuW(hMenu1, MF_POPUP|MF_STRING,hSubMenu1, L"&Mise a jour des etudiants");

    AppendMenuW(hSubMenu1, MF_STRING,ID_ETUD+1, L"&Ajouter un nouvel etudiant");
    AppendMenuW(hSubMenu1,MF_STRING,ID_ETUD+2, L"&Supprimer un etudiant");
    AppendMenuW(hMenu1, MF_POPUP|MF_STRING,hSubMenu4, L"&Recherche, Affichage et Tri");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+9, L"&Contenu de la liste des etudiants");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+10, L"&Recherche par matricule");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+11, L"&Recherche par section");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+12, L"&Recherche par etape");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+13, L"&Recherche par etape et section");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+14, L"&Tri 1");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+15, L"&Tri 2");
    /************************************* MENU MATIERE ******************************************/
     //AppendMenuW(hMenu2, MF_POPUP|MF_STRING,ID_MAT, L"&Creation des matieres");
    AppendMenuW(hMenu2, MF_POPUP|MF_STRING,hSubMenu5, L"&Mise a jour des matieres");
    AppendMenuW(hSubMenu5, MF_POPUP|MF_STRING,ID_MAT+1, L"&Ajouter un nouvelle matiere");
    AppendMenuW(hSubMenu5, MF_POPUP|MF_STRING,ID_MAT+2, L"&Supprimer une matiere");
    AppendMenuW(hSubMenu5, MF_POPUP|MF_STRING,hSubMenu8, L"&modifier les donnees d'une matiere");
    AppendMenuW(hSubMenu8, MF_STRING,ID_MAT+3, L"&nom");
    AppendMenuW(hSubMenu8, MF_STRING,ID_MAT+4, L"&coefficient");
    AppendMenuW(hMenu2, MF_POPUP|MF_STRING,hSubMenu9, L"&Recherche,affichage et Tri");
    AppendMenuW(hSubMenu9, MF_STRING,ID_MAT+5, L"&Centenu de la liste des matieres");
    AppendMenuW(hSubMenu9, MF_STRING,ID_MAT+6, L"&Recherche par code_mat");
    AppendMenuW(hSubMenu9, MF_STRING,ID_MAT+7, L"&Recherche par section");
    AppendMenuW(hSubMenu9, MF_STRING,ID_MAT+8, L"&Recherche par etape et section");
    AppendMenuW(hSubMenu9, MF_STRING,ID_MAT+9, L"&Tri");

    //AppendMenuW(hMenu3, MF_POPUP|MF_STRING,ID_NOTE, L"&Creation des notes");
    AppendMenuW(hMenu3, MF_POPUP|MF_STRING,hSubMenu10, L"&Mise a jour de la liste des notes");
    AppendMenuW(hSubMenu10, MF_POPUP|MF_STRING,ID_NOTE+1, L"&Ajouter une nouvelle note");
    AppendMenuW(hSubMenu10, MF_POPUP|MF_STRING,ID_NOTE+2, L"&Supprimer une note");
    AppendMenuW(hSubMenu10, MF_POPUP|MF_STRING,hSubMenu13, L"&modifier les donnees d'une note");
    AppendMenuW(hSubMenu13, MF_STRING,ID_NOTE+3, L"&note");
    AppendMenuW(hMenu3, MF_POPUP|MF_STRING,hSubMenu14, L"&Recherche,affichage et Tri");
    AppendMenuW(hSubMenu14, MF_STRING,ID_NOTE+4, L"&Centenu de la liste des notes");
    AppendMenuW(hSubMenu14, MF_STRING,ID_NOTE+5, L"&Recherche par mat");
    AppendMenuW(hSubMenu14, MF_STRING,ID_NOTE+6, L"&Recherche par mat et DS");
    AppendMenuW(hSubMenu14, MF_STRING,ID_NOTE+7, L"&Recherche par mat et EX");


    AppendMenuW(hMenu4,MF_STRING,ID_CA, L"&Bulletin de note d'un etudiant");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+1, L"&Moyennes des etudiants de l'etablissement");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+2, L"&Moyennes des etudiants d'une section donnee");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+3, L"&Etudiant admis de l'etablissement");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+4, L"&Etudiant redouble de l'etablissement");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+5, L"&Etudiant admis d'une section donnee");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+6, L"&Etudiant redouble d'une section donnee");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+7, L"&Etudiant mentionne d'une section donnee");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+8, L"&Etudiant mentionne d'une section et etape donnee");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+9, L"&Etudiant mentionne par etablissement");
   /* AppendMenuW(hMenu4,MF_STRING,ID_CA+10, L"&La meilleur etudiant d'une section donnee");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+11, L"&La meilleur etudiant d'une section et etape donnee");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+12, L"&La meilleur etudiant dde l'etablissement donnee");
    */
    AppendMenuW(hMenu4,MF_STRING,ID_CA+13, L"&NOTES d'un Etudiant Donnee");


    AppendMenuW(hMenu5,MF_POPUP|MF_STRING,hSubMenu2, L"&  LISTE ETUDIANT  ");
    AppendMenuW(hSubMenu2,MF_STRING,ID_ER, L"&Enregistre");
    AppendMenuW(hSubMenu2,MF_STRING,ID_ER+1, L"&Recupere");
    AppendMenuW(hSubMenu2,MF_STRING,ID_ER+6, L"&Ouvrir");
    AppendMenuW(hMenu5,MF_POPUP|MF_STRING,hSubMenu3, L"&  LISTE MATIERE  ");
    AppendMenuW(hSubMenu3,MF_STRING,ID_ER+2, L"&Enregistre");
    AppendMenuW(hSubMenu3,MF_STRING,ID_ER+3, L"&Recupere");
    AppendMenuW(hSubMenu3,MF_STRING,ID_ER+7, L"&Ouvrir");
    AppendMenuW(hMenu5,MF_POPUP|MF_STRING,hSubMenu15, L"&  LISTE NOTES  ");
    AppendMenuW(hSubMenu15,MF_STRING,ID_ER+4, L"&Enregistre");
    AppendMenuW(hSubMenu15,MF_STRING,ID_ER+5, L"&Recupere");
    AppendMenuW(hSubMenu15,MF_STRING,ID_ER+8, L"&Ouvrir");

    AppendMenuW(hMenubar, MF_POPUP,ID_ACCUEL, L"&ACCUEL");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu1, L"&Gestion des etudiants");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu2, L"&Gestion des matieres");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu3, L"&Gestion des notes");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu4, L"&Calcul et affichage");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu5, L"&Enreg. et Recup. Fichiers");
  //  AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu6, L"&HELP");
    //AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu7, L"&Quitter");


    SetMenu(hwnd,hMenubar);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    FILE *file;
    HDC hdc;
	PAINTSTRUCT ps;
    static HWND hEdit;
    AllocConsole();
    console = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(console,SW_SHOWMINIMIZED);

static HBITMAP hBmp;

    switch (uMsg)
    {


        case WM_CREATE:

            image=CreateWindow("STATIC", "MyPicture0",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                       0, 0, 1100,900 , hwnd, NULL, hinst, NULL);
            bout_rec=CreateWindowW(L"Button", L"RECUPERER",WS_VISIBLE | WS_CHILD ,
                               320, 230, 120, 25,hwnd, (HMENU) ID_RECP_T, NULL, NULL);
            bout_enrg=CreateWindowW(L"Button", L"ENREGISTRER",WS_VISIBLE | WS_CHILD ,
                                470, 230, 120, 25,hwnd, (HMENU) ID_ENR_T, NULL, NULL);
        return 0;
        case WM_COMMAND:

           switch(LOWORD(wParam))
           {

                case ID_ACCUEL:
                    destroyallwindow();
                    image=CreateWindow("STATIC", "MyPicture",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575, hwnd, NULL, hinst, NULL);
                    bout_rec=CreateWindowW(L"Button", L"RECUPERE",WS_VISIBLE | WS_CHILD ,
                               300,400, 120, 25,hwnd, (HMENU) ID_RECP_T, NULL, NULL);
                    bout_enrg=CreateWindowW(L"Button", L"ENREGISTRE",WS_VISIBLE | WS_CHILD ,
                                450,400, 120, 25,hwnd, (HMENU) ID_ENR_T, NULL, NULL);

                break;

                case ID_ETUD+1:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();
                    image=CreateWindow("STATIC", "ajout_etudiant",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                    ajout_etudiant(hwnd);
                    ShowWindow(hwnd,SW_NORMAL);
                break;

                 case ID_AJOUT_TETE:
                        GetWindowText(cin_wind,cinc,9);
                        GetWindowText(nom_wind,nomc,21);
                        GetWindowText(prenom_wind,prenomc,21);
                        GetWindowText(j_wind,jc,3);
                        GetWindowText(m_wind,mc,3);
                        GetWindowText(a_wind,ac,5);
                        GetWindowText(section_wind,sectionc,21);
                        GetWindowText(etape_wind,etapec,2);
                        GetWindowText(pos_wind,posc,10);
                        pos=atoi(posc);
                        e.dn.j=atoi(jc);
                        e.dn.m=atoi(mc);
                        e.dn.a=atoi(ac);
                        e.etape=atoi(etapec);
                        strcpy(e.cin,cinc);
                        strcpy(e.nom,nomc);
                        strcpy(e.prenom,prenomc);
                        strcpy(e.section,sectionc);
                        if(recherche_etud(LE,e.cin))
                            MessageBoxW(NULL, L"ETUDIANT DEJA SAISIE !!!", L"ERREUR", MB_OK);
                        else
                            if(verif_nom_mat(e.nom)==0)
                                MessageBoxW(NULL, L"NOM INCORRECT!!!", L"ERREUR", MB_OK);
                            else
                                if(verif_nom_mat(e.prenom)==0)
                                    MessageBoxW(NULL, L"PRENOM INCORRECT!!!", L"ERREUR", MB_OK);
                                else
                                    if(valide(e.dn)==0)
                                        MessageBoxW(NULL, L"DATE NON VALIDE!!!", L"ERREUR", MB_OK);
                                    else
                                    {
                                        if(strcmp(sectionc,"LA INFO")==0&&etape==1)
                                            la1info++;
                                        else
                                            if(strcmp(sectionc,"LA INFO")==0&&etape==2)
                                            la2info++;
                                            else
                                                if(strcmp(sectionc,"LA INFO")==0&&etape==3)
                                                    la3info++;
                                                else
                                                    if(strcmp(sectionc,"LF INFO")==0&&etape==1)
                                                        lf1info++;
                                                    else
                                                        if(strcmp(sectionc,"LF INFO")==0&&etape==2)
                                                            lf2info++;
                                                        else
                                                            if(strcmp(sectionc,"LF INFO")==0&&etape==3)
                                                                lf3info++;
                                                            else
                                                                if(strcmp(sectionc,"LA STIC")==0&&etape==1)
                                                                    la1stic++;
                                                                else
                                                                    if(strcmp(sectionc,"LA STIC")==0&&etape==2)
                                                                        la2stic++;
                                                                    else
                                                                        if(strcmp(sectionc,"LA STIC")==0&&etape==3)
                                                                            la3stic++;
                                                                        else
                                                                            if(strcmp(sectionc,"LF MATH")==0&&etape==1)
                                                                                lf1math++;
                                                                            else
                                                                                if(strcmp(sectionc,"LF MATH")==0&&etape==2)
                                                                                    lf2math++;
                                                                                else
                                                                                    if(strcmp(sectionc,"LF MATH")==0&&etape==3)
                                                                                        lf3math++;
                                                                                    else
                                                                                        if(strcmp(sectionc,"LF STIC")==0&&etape==1)
                                                                                            lf1stic++;
                                                                                        else
                                                                                            if(strcmp(sectionc,"LF STIC")==0&&etape==2)
                                                                                                lf2stic++;
                                                                                            else
                                                                                                if(strcmp(sectionc,"LF STIC")==0&&etape==3)
                                                                                                    lf3stic++;


                                        LE=insere_tete(LE,e);
                                        MessageBoxW(NULL, L"AJOUT EN TETE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                                    }
                break;
                case ID_AJOUT_QUEUE:
                        GetWindowText(cin_wind,cinc,9);
                        GetWindowText(nom_wind,nomc,21);
                        GetWindowText(prenom_wind,prenomc,21);
                        GetWindowText(j_wind,jc,3);
                        GetWindowText(m_wind,mc,3);
                        GetWindowText(a_wind,ac,5);
                        GetWindowText(section_wind,sectionc,21);
                        GetWindowText(etape_wind,etapec,2);
                        GetWindowText(pos_wind,posc,10);
                        pos=atoi(posc);
                        e.dn.j=atoi(jc);
                        e.dn.m=atoi(mc);
                        e.dn.a=atoi(ac);
                        e.etape=atoi(etapec);
                        strcpy(e.cin,cinc);
                        strcpy(e.nom,nomc);
                        strcpy(e.prenom,prenomc);
                        strcpy(e.section,sectionc);
                        if(recherche_etud(LE,e.cin))
                            MessageBoxW(NULL, L"ETUDIANT DEJA SAISIE !!!", L"ERREUR", MB_OK);
                        else
                            if(verif_nom_mat(e.nom)==0)
                                MessageBoxW(NULL, L"NOM INCORRECT!!!", L"ERREUR", MB_OK);
                            else
                                if(verif_nom_mat(e.prenom)==0)
                                    MessageBoxW(NULL, L"PRENOM INCORRECT!!!", L"ERREUR", MB_OK);
                                else
                                    if(valide(e.dn)==0)
                                        MessageBoxW(NULL, L"DATE NON VALIDE!!!", L"ERREUR", MB_OK);
                                    else
                                    {
                                        LE=insere_tete(LE,e);
                                        MessageBoxW(NULL, L"AJOUT EN TETE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                                    }
                break;
                case ID_AJOUT_POS:
                        GetWindowText(cin_wind,cinc,9);
                        GetWindowText(nom_wind,nomc,21);
                        GetWindowText(prenom_wind,prenomc,21);
                        GetWindowText(j_wind,jc,3);
                        GetWindowText(m_wind,mc,3);
                        GetWindowText(a_wind,ac,5);
                        GetWindowText(section_wind,sectionc,21);
                        GetWindowText(etape_wind,etapec,2);
                        GetWindowText(pos_wind,posc,10);
                        pos=atoi(posc);
                        e.dn.j=atoi(jc);
                        e.dn.m=atoi(mc);
                        e.dn.a=atoi(ac);
                        e.etape=atoi(etapec);
                        strcpy(e.cin,cinc);
                        strcpy(e.nom,nomc);
                        strcpy(e.prenom,prenomc);
                        strcpy(e.section,sectionc);
                        if(pos!=taille_liste(LE)&&pos!=1&&strcmp(posc,"")!=0&&recherche_etud(LE,e.cin)==NULL&&verif_nom_mat(e.nom)&&verif_nom_mat(e.prenom)&&valide(e.dn))
                        {

                                            LE=insere_pos(LE,e,pos);
                                            MessageBoxW(NULL, L"AJOUT DANS UNE POSITON EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);


                        }
                         else
                            if(pos==taille_liste(LE)||pos==1||strcmp(posc,"")==0)
                                MessageBoxW(NULL, L" POSTION INCORRECT!!!", L"ERREUR", MB_OK);
                            else
                                if(recherche_etud(LE,e.cin))
                                    MessageBoxW(NULL, L"ETUDIANT DEJA SAISIE !!!", L"ERREUR", MB_OK);
                                else
                                    if(verif_nom_mat(e.nom)==0)
                                        MessageBoxW(NULL, L"NOM INCORRECT!!!", L"ERREUR", MB_OK);
                                    else
                                        if(verif_nom_mat(e.prenom)==0)
                                            MessageBoxW(NULL, L"PRENOM INCORRECT!!!", L"ERREUR", MB_OK);
                                        else
                                            if(valide(e.dn)==0)
                                                MessageBoxW(NULL, L"DATE NON VALIDE!!!", L"ERREUR", MB_OK);
                break;
                case ID_ETUD+2:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();
                    image=CreateWindow("STATIC", "supprimer_etudiant",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                    sup_etudiant(hwnd);
                    ShowWindow(hwnd,SW_NORMAL);
                break;
                case ID_SUP_TETE:
                    LE=supprimmer_tete_etudiant(LE);
                    MessageBoxW(NULL, L"SUPPRESSION EN TETE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);

                break;
                case ID_SUP_QUEUE:
                    LE=supprimmer_queue_etudiant(LE);
                    MessageBoxW(NULL, L"SUPPRESSION EN QUEUE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                break;
                case ID_SUP_POS:
                    GetWindowText(pos_wind,posc,8);
                    pos=atoi(posc);
                    if(pos<=1||pos>=taille_liste(LE)||strcmp(posc," ")==0)
                            MessageBoxW(NULL, L"POSTION DOIT ETRE >1 ET < TAILLE LISTE ETUDIANT", L"ERREUR", MB_OK);
                    else
                    {
                        LE=suppression_pos_etudiant(LE,pos);
                        MessageBoxW(NULL, L"SUPPRESSION DANS UNE POSTION DONNE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                    }
                break;
                case ID_SUP_ETD:

                    GetWindowText(cin_wind,cinc,9);
                    if(recherche_etud(LE,cinc)==NULL)
                            MessageBoxW(NULL, L"ETUDIANT NON INSCRIT", L"ERREUR", MB_OK);
                    else
                    {
                        LE=suppression_etudiant_donne(LE,cinc);
                        MessageBoxW(NULL, L"ETUDIANT SUPPRIMER AVEC SUCCEE", L"SUCCEE", MB_OK);
                    }
                break;
                case ID_SUP_ETsecet:

                    GetWindowText(section_wind,sectionc,21);
                    GetWindowText(etape_wind,etapec,2);
                    nv=atoi(etapec);
                    LE=supp_etud_sec_etape(LE,sectionc,nv);
                    MessageBoxW(NULL, L"SUPPRESSION EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                break;
                case ID_ETUD+9:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();
                    image=CreateWindow("STATIC", "affichage_etudiants",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 1080,720 , hwnd, NULL, hinst, NULL);
                    affichage_etudiants(hwnd);
                    ShowWindow(hwnd,SW_NORMAL);
                break;
                case ID_ETUD+10:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();
                    image=CreateWindow("STATIC", "affichage_etudiants_mat",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 1080,720 , hwnd, NULL, hinst, NULL);
                    rech_matricule(hwnd);
                    ShowWindow(hwnd,SW_NORMAL);
            break;
             case ID_B_RECH_cin:

                GetWindowText(cin_wind,cinc,9);
                rech_et_mat(hwnd,cinc);
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+11:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();
                    image=CreateWindow("STATIC", "affichage_etudiants",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 1080,720 , hwnd, NULL, hinst, NULL);
                    recherche_section(hwnd);
                   ShowWindow(hwnd,SW_NORMAL);
            break;

            case ID_B_RECH_SEC:
                    ShowWindow(hwnd,SW_HIDE);
                    GetWindowText(section_wind,sectionc,21);
                    rech_et_sec(hwnd,sectionc);
                    ShowWindow(hwnd,SW_NORMAL);

            break;





            case ID_ETUD+12:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();
                    image=CreateWindow("STATIC", "affichage_etudiants",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 1080,720 , hwnd, NULL, hinst, NULL);
                    recherche_etape(hwnd);
                    ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_B_RECH_etp:
                    ShowWindow(hwnd,SW_HIDE);
                    GetWindowText(etape_wind,etapec,2);
                    nv=atoi(etapec);
                    rech_et_etape(hwnd,nv);
                    ShowWindow(hwnd,SW_NORMAL);
            break;
           case ID_ETUD+13:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                image=CreateWindow("STATIC", "affichage_etudiants",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 1080,720 , hwnd, NULL, hinst, NULL);
                recherche_etape_section(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_B_RECH_etp_sec:
                    ShowWindow(hwnd,SW_HIDE);
                    GetWindowText(etape_wind,etapec,2);
                    GetWindowText(section_wind,sectionc,21);
                    nv=atoi(etapec);
                    rech_et_etape_section(hwnd,sectionc,nv);
                    ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+14:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                image=CreateWindow("STATIC", "affichage_etudiants",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 1080,720 , hwnd, NULL, hinst, NULL);
                tri_etu(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+15:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                image=CreateWindow("STATIC", "affichage_etudiants",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 1080,720 , hwnd, NULL, hinst, NULL);
                tri_etu_v2(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;

            /*****************************************************************/
            /*****************************************************************/
            /************    GESTION DE LA LISTE MATIERE    ******************/
            /*****************************************************************/
            /*****************************************************************/


            case ID_MAT+1:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                image=CreateWindow("STATIC", "creation_matiere",
                                    WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                       0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                ajout_matiere(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_AJOUT_TETE_MAT:
                        GetWindowText(mat_wind,matc,4);
                        GetWindowText(nom_mat_wind,nomc,50);
                        GetWindowText(section_wind,sectionc,21);
                        GetWindowText(coef_wind,coefc,3);
                        GetWindowText(etape_wind,etapec,2);
                        m.coef=atof(coefc);
                        m.niveau=atoi(etapec);
                        pos=atoi(posc);
                        strcpy(m.code_mat,matc);
                        strcpy(m.nom_mat,nomc);
                        strcpy(m.section,sectionc);
                        if(recherche_mat(LM,m.code_mat)==NULL&&verif_nom_mat(m.nom_mat)==1&&verif_coef(m.coef)==1)
                            {
                                LM=insere_tete_mat(LM,m);
                                MessageBoxW(NULL, L"SAISIE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                            }
                            else
                                if(recherche_mat(LM,m.code_mat))
                                    MessageBoxW(NULL, L"MATIERE DEJA SAISIE !!!", L"ERREUR", MB_OK);
                                else
                                    if(verif_nom_mat(m.nom_mat)==0)
                                        MessageBoxW(NULL, L"NOM INCORRECT!!!", L"ERREUR", MB_OK);
                                    else
                                        if(verif_coef(m.coef)==0)
                                            MessageBoxW(NULL, L"COEFFICIENT NON VALIDE (DOIT ETRE >0)!!!", L"ERREUR", MB_OK);

            break;
            case ID_AJOUT_QUEUE_MAT:
                        GetWindowText(mat_wind,matc,4);
                        GetWindowText(nom_mat_wind,nomc,50);
                        GetWindowText(section_wind,sectionc,21);
                        GetWindowText(coef_wind,coefc,3);
                        GetWindowText(etape_wind,etapec,2);
                        m.coef=atof(coefc);
                        m.niveau=atoi(etapec);
                        strcpy(m.code_mat,matc);
                        strcpy(m.nom_mat,nomc);
                        strcpy(m.section,sectionc);
                        if(recherche_mat(LM,m.code_mat)==NULL&&verif_nom_mat(m.nom_mat)==1&&verif_coef(m.coef)==1)
                            {
                                LM=insere_queue_mat(LM,m);
                                MessageBoxW(NULL, L"SAISIE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                            }
                            else
                                if(recherche_mat(LM,m.code_mat))
                                    MessageBoxW(NULL, L"MATIERE DEJA SAISIE !!!", L"ERREUR", MB_OK);
                                else
                                    if(verif_nom_mat(m.nom_mat)==0)
                                        MessageBoxW(NULL, L"NOM INCORRECT!!!", L"ERREUR", MB_OK);
                                    else
                                        if(verif_coef(m.coef)==0)
                                            MessageBoxW(NULL, L"COEFFICIENT NON VALIDE (DOIT ETRE >0)!!!", L"ERREUR", MB_OK);

            break;
            case ID_AJOUT_POS_MAT:
                        GetWindowText(mat_wind,matc,4);
                        GetWindowText(nom_mat_wind,nomc,50);
                        GetWindowText(section_wind,sectionc,21);
                        GetWindowText(coef_wind,coefc,3);
                        GetWindowText(etape_wind,etapec,2);
                        GetWindowText(pos_wind,posc,5);
                        m.coef=atof(coefc);
                        m.niveau=atoi(etapec);
                        pos=atoi(posc);
                        strcpy(m.code_mat,matc);
                        strcpy(m.nom_mat,nomc);
                        strcpy(m.section,sectionc);
                        if(pos==1||pos==taille_liste_mat(LM)||strcmp(posc,"")==0)
                            MessageBoxW(NULL, L"POSTION DOIT ETRE >1 ET < TAILLE DE LA LISTE MATIERE", L"ERREUR", MB_OK);
                        if(recherche_mat(LM,m.code_mat)==NULL&&verif_nom_mat(m.nom_mat)==1&&verif_coef(m.coef)==1)
                            {
                                LM=insere_pos_mat(LM,m,pos);
                                MessageBoxW(NULL, L"SAISIE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                            }
                            else
                                if(recherche_mat(LM,m.code_mat))
                                    MessageBoxW(NULL, L"MATIERE DEJA SAISIE !!!", L"ERREUR", MB_OK);
                                else
                                    if(verif_nom_mat(m.nom_mat)==0)
                                        MessageBoxW(NULL, L"NOM INCORRECT!!!", L"ERREUR", MB_OK);
                                    else
                                        if(verif_coef(m.coef)==0)
                                            MessageBoxW(NULL, L"COEFFICIENT NON VALIDE (DOIT ETRE >0)!!!", L"ERREUR", MB_OK);

            break;

            case ID_MAT+2:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                image=CreateWindow("STATIC", "supprimer_matiere",
                                    WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                       0, 0, 960,575 , hwnd, NULL, hinst, NULL);

                sup_matiere(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;

            case ID_SUP_TETE_MAT:
                    LM=supprimmer_tete_mat(LM);
                    MessageBoxW(NULL, L"SUPPRESSION EN TETE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
            break;
            case ID_SUP_QUEUE_MAT:
                    LM=supprimmer_queue_mat(LM);
                    MessageBoxW(NULL, L"SUPPRESSION EN TETE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
            break;
            case ID_SUP_POS_MAT:
                    GetWindowText(pos_wind,posc,8);
                    pos=atoi(posc);
                    if(pos<=1||pos>=taille_liste_mat(LM))
                            MessageBoxW(NULL, L"POSTION DOIT ETRE >1 ET < TAILLE LISTE MATIERE", L"ERREUR", MB_OK);
                    else
                    {
                        LM=suppression_pos_mat(LM,pos);
                        MessageBoxW(NULL, L"SUPPRESSION DANS UNE POSTION DONNE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                    }
            break;
            case ID_SUP_MAT:
                GetWindowText(mat_wind,matc,4);
                if(recherche_code_m(LM,matc)==NULL)
                      MessageBoxW(NULL, L"SAISIR DE NOUVEAU LE MATIERE", L"ERREUR", MB_OK);
                else
                {
                    LM=suppression_mat_donne(LM,matc);
                    MessageBoxW(NULL, L"SUPPRESSION D'UNE MATIERE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                }


            break;
            case ID_MAT+3:
                destroyallwindow();
                image=CreateWindow("STATIC", "nv_nom",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                modiefie_nom_matiere(hwnd);
            break;
            case ID_modifier_nom_mat:
                    GetWindowText(mat_wind,matc,4);
                    GetWindowText(nom_mat_wind,nomc,50);
                    if(recherche_mat(LM,matc))
                    {
                        strcmp(nomc,recherche_mat(LM,matc)->info2.nom_mat);
                        MessageBoxW(NULL, L"NOM MATIERE MODIFIER", L"SUCCEE", MB_OK);
                    }
                    else
                         MessageBoxW(NULL, L"VERIFIER CODE MATIERE", L"ERREUR", MB_OK);

            break;
            case ID_MAT+4:
                destroyallwindow();
                image=CreateWindow("STATIC", "nv_coef",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                modiefie_coef_matiere(hwnd);
            break;
            case ID_modifier_coef_mat:
                    GetWindowText(mat_wind,matc,4);
                    GetWindowText(nom_mat_wind,coefc,5);
                    coef=atof(coefc);
                   if(recherche_mat(LM,matc))
                   {
                        recherche_mat(LM,matc)->info2.coef=coef;
                         MessageBoxW(NULL, L"COEFIICIENT MATIERE MODIFIER", L"SUCCEE", MB_OK);
                   }
                    else
                        MessageBoxW(NULL, L"VERIFIER CODE MATIERE", L"ERREUR", MB_OK);

            break;

            case ID_MAT+5:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                image=CreateWindow("STATIC", "affiche_liste_matiere",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                affichage_matieres(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+6:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                 image=CreateWindow("STATIC", "rech_mat_code",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                rech_matiere(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_B_RECH_matiere:

                GetWindowText(mat_wind,matc,4);
                rech_matiere_code(hwnd,matc);
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+7:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                image=CreateWindow("STATIC", "affiche_liste_matiere",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                recherche_section_matiere(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_B_RECH_SEC_mat:
                GetWindowText(section_wind,sectionc,21);
                    rech_sec_matiere(hwnd,sectionc);
            break;
             case ID_MAT+8:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                image=CreateWindow("STATIC", "affiche_liste_matiere",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                recherche_etape_matiere(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_B_RECH_etp_mat:
                GetWindowText(etape_wind,etapec,2);
                GetWindowText(section_wind,sectionc,21);
                nv=atoi(etapec);
                    rech_etape_matiere(hwnd,sectionc,nv);
            break;

            break;
            case ID_MAT+9:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                tri_matiere(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;

            /*
             case ID_NOTE:
                ShowWindow(hwnd,SW_HIDE);

                ShowWindow(hwnd,SW_NORMAL);

            break;
            */
            case ID_NOTE+1:
                 ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                image=CreateWindow("STATIC", "ajout_note",
                                    WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                       0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                ajout_notes(hwnd);
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_AJOUT_TETE_note:
                        GetWindowText(cin_wind,cinc,9);
                        GetWindowText(mat_wind,matc,4);
                        GetWindowText(note_wind,notec,6);
                        GetWindowText(nature_wind,naturec,3);
                        n.note=atof(notec);
                        strcpy(n.code_mat,matc);
                        strcpy(n.mat,cinc);
                        strcpy(n.nature,naturec);
                        if(recherche_mat(LM,n.code_mat)!=NULL&&verif_note(n.note)==1&&recherche_etud(LE,n.mat)!=NULL&&recherche_cin_mat(LN,n.mat,n.code_mat,n.nature)==NULL)
                            {
                                LN=insere_tete_note(LN,n);
                                MessageBoxW(NULL, L"SAISIE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                            }
                            else
                                if(recherche_mat(LM,n.code_mat)==NULL||recherche_etud(LE,n.mat)==NULL)
                                    MessageBoxW(NULL, L"MATIERE OU ETUDIANT INCONNUE!!!", L"ERREUR", MB_OK);
                                else
                                    if(verif_note(n.note)==0)
                                        MessageBoxW(NULL, L"NOTE INCORRECT!!!", L"ERREUR", MB_OK);
                                    else
                                        if(recherche_cin_mat(LN,n.mat,n.code_mat,n.nature))
                                            if(strcmp("DS",n.nature)==0)
                                                MessageBoxW(NULL, L"DS DEJA SAISIE!!!", L"ERREUR", MB_OK);
                                            else
                                                MessageBoxW(NULL, L"EX DEJA SAISIE!!!", L"ERREUR", MB_OK);

            break;
            case ID_AJOUT_QUEUE_note:
                       GetWindowText(cin_wind,cinc,9);
                        GetWindowText(mat_wind,matc,4);
                        GetWindowText(note_wind,notec,6);
                        GetWindowText(nature_wind,naturec,3);
                        n.note=atof(notec);
                        strcpy(n.code_mat,matc);
                        strcpy(n.mat,cinc);
                        strcpy(n.nature,naturec);
                        if(recherche_mat(LM,n.code_mat)!=NULL&&verif_note(n.note)==1&&recherche_etud(LE,n.mat)!=NULL&&recherche_cin_mat(LN,n.mat,n.code_mat,n.nature)==NULL)
                            {
                                LN=insere_queue_note(LN,n);
                                MessageBoxW(NULL, L"SAISIE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                            }
                            else
                                if(recherche_mat(LM,n.code_mat)==NULL||recherche_etud(LE,n.mat)==NULL)
                                    MessageBoxW(NULL, L"MATIERE OU ETUDIANT INCONNUE!!!", L"ERREUR", MB_OK);
                                else
                                    if(verif_note(n.note)==0)
                                        MessageBoxW(NULL, L"NOTE INCORRECT!!!", L"ERREUR", MB_OK);
                                    else
                                        if(recherche_cin_mat(LN,n.mat,n.code_mat,n.nature))
                                            MessageBoxW(NULL, L"NOTE DEJA SAISIE!!!", L"ERREUR", MB_OK);
            break;
            case ID_AJOUT_POS_note:
                        GetWindowText(cin_wind,cinc,9);
                        GetWindowText(mat_wind,matc,4);
                        GetWindowText(note_wind,notec,6);
                        GetWindowText(nature_wind,naturec,3);
                        n.note=atof(notec);
                        strcpy(n.code_mat,matc);
                        strcpy(n.mat,cinc);
                        strcpy(n.nature,naturec);
                        GetWindowText(pos_wind,posc,10);
                        pos=atoi(posc);
                        printf("%d",pos);
                        if(pos==taille_liste_note(LN)||pos==1||strcmp(posc,"")==0)
                            MessageBoxW(NULL, L" POSTION INCORRECT!!!", L"ERREUR", MB_OK);
                         else
                            if(recherche_mat(LM,n.code_mat)==NULL||recherche_etud(LE,n.mat)==NULL)
                                    MessageBoxW(NULL, L"MATIERE OU ETUDIANT INCONNUE!!!", L"ERREUR", MB_OK);
                                else
                                    if(verif_note(n.note)==0)
                                        MessageBoxW(NULL, L"NOTE INCORRECT!!!", L"ERREUR", MB_OK);
                                    else
                                        if(recherche_cin_mat(LN,n.mat,n.code_mat,n.nature))
                                            MessageBoxW(NULL, L"NOTE DEJA SAISIE!!!", L"ERREUR", MB_OK);
                                        else
                                            if(recherche_mat(LM,n.code_mat)!=NULL&&verif_note(n.note)==1&&recherche_etud(LE,n.mat)!=NULL&&recherche_cin_mat(LN,n.mat,n.code_mat,n.nature)==NULL)
                                            {
                                                LN=insere_pos_note(LN,n,pos);
                                                MessageBoxW(NULL, L"SAISIE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                                            }

                break;

            case ID_NOTE+2:
            ShowWindow(hwnd,SW_HIDE);
            destroyallwindow();
            image=CreateWindow("STATIC", "supprimer_note",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
            sup_note(hwnd);
            ShowWindow(hwnd,SW_NORMAL);
            break;

           case ID_SUP_TETE_note:
                    LN=supprimmer_tete_note(LN);
                    MessageBoxW(NULL, L"SUPPRESSION EN TETE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
            break;
            case ID_SUP_QUEUE_note:
                    LN=supprimmer_queue_note(LN);
                    MessageBoxW(NULL, L"SUPPRESSION EN TETE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
            break;
            case ID_SUP_POS_note:
                    GetWindowText(pos_wind,posc,8);
                    pos=atoi(posc);
                    if(pos<=1||pos>=taille_liste_note(LN)||strcmp(posc,"")==0)
                            MessageBoxW(NULL, L"POSTION DOIT ETRE >1 ET < TAILLE LISTE MATIERE", L"ERREUR", MB_OK);
                    else
                    {
                        LN=suppression_pos_note(LN,pos);
                        MessageBoxW(NULL, L"SUPPRESSION DANS UNE POSTION DONNE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                    }
            break;
            case ID_SUP_note:

                GetWindowText(cin_wind,cinc,9);
                GetWindowText(mat_wind,matc,4);
                GetWindowText(nature_wind,naturec,3);
                if(recherche_cin_mat(LN,cinc,matc,naturec)==NULL)
                      MessageBoxW(NULL, L"SAISIR DE NOUVEAU LE NOTE", L"ERREUR", MB_OK);
                else
                {
                    LM=suppression_note_donne(LN,cinc,matc,naturec);
                    MessageBoxW(NULL, L"SUPPRESSION D'UNE NOTE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                }
            break;
            case ID_NOTE+3:
            ShowWindow(hwnd,SW_HIDE);
            destroyallwindow();
            mdf_note(hwnd);
            ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_modifier_note:
                 GetWindowText(cin_wind,cinc,9);
                GetWindowText(mat_wind,matc,4);
                GetWindowText(note_wind,notec,4);
                GetWindowText(nature_wind,naturec,3);
                nt=atof(notec);
                if(recherche_cin_mat(LN,cinc,matc,naturec)==NULL)
                    MessageBoxW(NULL, L"SAISIR DE NOUVEAU LE NOTE", L"ERREUR", MB_OK);
                else
                {
                    recherche_cin_mat(LN,cinc,matc,naturec)->info3.note=nt;
                    MessageBoxW(NULL, L"MODIFICATION DE NOTE EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                }
            break;
            case ID_NOTE+4:
                destroyallwindow();
                image=CreateWindow("STATIC", "affiche_liste_note",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                affichage_notes(hwnd);
            break;
            case ID_NOTE+5:
                destroyallwindow();
                rech_notes_etudiant(hwnd);
            break;
            case ID_B_RECH_etudiant_note:
                GetWindowText(cin_wind,cinc,9);
                 affichage_notes_etud(hwnd,cinc);
            break;
             case ID_NOTE+6:
                destroyallwindow();
                rech_notes_etudiant_Ds(hwnd);
            break;
            case ID_B_RECH_etudiant_note_ds:
                GetWindowText(cin_wind,cinc,9);
                 affichage_notes_etud_DS(hwnd,cinc);
            break;
             case ID_NOTE+7:
                destroyallwindow();
                rech_notes_etudiant_EX(hwnd);
            break;
            case ID_B_RECH_etudiant_note_ex:
                GetWindowText(cin_wind,cinc,9);
                 affichage_notes_etud_EX(hwnd,cinc);
            break;
            case ID_CA:
                destroyallwindow();
                image=CreateWindow("STATIC", "bulletin",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                bulletin_etud(hwnd);
            break;
            case ID_B_etud:
                GetWindowText(cin_wind,cinc,9);
                DestroyWindow(but_bulletin_etud);
                image=CreateWindow("STATIC", "bulletin",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                    if(recherche_etud(LE,cinc)==NULL)
                            MessageBox(NULL,"Etudiant non inscri a l'etablissement","ECHEC",MB_OK);

                    else
                        bulletin(hwnd,cinc);
            break;
            case ID_CA+1:
                    destroyallwindow();
                     hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,700,480,hwnd,NULL,hinst,NULL);
                   moy_etablissement(hwnd);

            break;
            case ID_CA+2:
            destroyallwindow();
            recherche_moyenne_etud_section(hwnd);
            break;
            case ID_B_RECH_SEC_moy_etud:
                DestroyWindow(hListBox);
                    GetWindowText(section_wind,sectionc,21);
                    rech_sec_moyenne(hwnd,sectionc);
            break;

            case ID_CA+3:
                    destroyallwindow();
                     image=CreateWindow("STATIC", "etudiants_admis",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                    etudiant_admis(hwnd);
            break;
            case ID_CA+4:
                destroyallwindow(hwnd);
                 image=CreateWindow("STATIC", "etudiants_redoubles",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                etudiant_redouble(hwnd);
            break;
            case ID_CA+5:
                destroyallwindow();
                 image=CreateWindow("STATIC", "etudiants_admis",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                recherche_admis_section_(hwnd);

            break;
            case ID_admis_sec:
                GetWindowText(section_wind,sectionc,21);
                etudiant_admis_section(hwnd,sectionc);
            break;
             case ID_CA+6:
                destroyallwindow();
                 image=CreateWindow("STATIC", "etudiants_redoubles",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                recherche_redouble_section_(hwnd);

            break;
            case ID_redouble_sec:
                DestroyWindow(hListBox);
                GetWindowText(section_wind,sectionc,21);
                etudiant_redouble_section(hwnd,sectionc);
            break;
             case ID_CA+7:
                destroyallwindow();
                 image=CreateWindow("STATIC", "etudiants_redoubles",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                recherche_mention_section_(hwnd);
            break;
            case ID_mention_sec:
                DestroyWindow(hListBox);
                GetWindowText(section_wind,sectionc,21);
                etudiant_mention_section(hwnd,sectionc);
            break;
            case ID_CA+8:
                destroyallwindow();
                 image=CreateWindow("STATIC", "etudiants_redoubles",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                recherche_mention_etape_section(hwnd);
            break;
            case ID_mention_sec_etape:
                DestroyWindow(hListBox);
                GetWindowText(section_wind,sectionc,21);
                GetWindowText(etape_wind,etapec,2);
                nv=atoi(etapec);
                etudiant_mention_section_etape(hwnd,sectionc,nv);
            break;
             case ID_CA+9:
                destroyallwindow();
                 image=CreateWindow("STATIC", "etudiants_redoubles",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                etudiant_mention_etablissement(hwnd);
            break;



            case ID_CA+12:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();

                    meilleur_etud_etablissement(hwnd);
                    ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_CA+13:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();

                    notes_etud(hwnd);
                    ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_notes_etud:
                GetWindowText(cin_wind,cinc,9);
                destroyallwindow();
                if(recherche_etud(LE,cinc)==NULL)
                    MessageBox(NULL,"ETUDIANT NON INSCRI","ECHEC",NULL);
                else
                    NOTES(hwnd,cinc);


            break;





            case ID_ER:
                enregistrement_etudiant(LE);
                en_e=1;
            break;
            case ID_ER+1:
                LE=recuperation_etudiant();
                en_e=0;
            break;
            case ID_ER+2:
                enregistrement_mat(LM);
                en_m=1;
            break;
            case ID_ER+3:
                LM=recuperation_mat();
               /* la1info=nb_mat_section_nv("LA INFO",1);
                la2info=nb_mat_section_nv("LA INFO",2);
                la3info=nb_mat_section_nv("LA INFO",3);
                lf1info=nb_mat_section_nv("LF INFO",1);
                lf2info=nb_mat_section_nv("LF INFO",2);
                lf3info=nb_mat_section_nv("LF INFO",3);
                la1stic=nb_mat_section_nv("LA STIC",1);
                la2stic=nb_mat_section_nv("LA STIC",2);
                la3stic=nb_mat_section_nv("LA STIC",3);
                lf1math=nb_mat_section_nv("LF MATH",1);
                lf2math=nb_mat_section_nv("LF MATH",2);
                lf3math=nb_mat_section_nv("LF MATH",3);
                */
                en_m=0;
            break;
            case ID_ER+4:
                enregistrement_note(LN);
                en_n=1;
            break;
            case ID_ER+5:
                LN=recuperation_note();
                en_n=0;
            break;
            case ID_ENR_T:
                enregistrement_etudiant(LE);
                enregistrement_mat(LM);
                enregistrement_note(LN);
                 MessageBoxW(NULL, L"ENREGISTREMENT DE TOUS LES LISTES  EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                 en_e=1;
                 en_m=1;
                 en_n=1;
            break;
            case ID_RECP_T:
                LE=recuperation_etudiant();
                LM=recuperation_mat();
                LN=recuperation_note();
                MessageBoxW(NULL, L"RECUPERATION DE TOUS LES LISTES  EFFECTUE AVEC SUCCEE", L"SUCCEE", MB_OK);
                 en_e=0;
                 en_m=0;
                 en_n=0;
             /*   la1info=nb_mat_section_nv("LA INFO",1);
                la2info=nb_mat_section_nv("LA INFO",2);
                la3info=nb_mat_section_nv("LA INFO",3);
                lf1info=nb_mat_section_nv("LF INFO",1);
                lf2info=nb_mat_section_nv("LF INFO",2);
                lf3info=nb_mat_section_nv("LF INFO",3);
                la1stic=nb_mat_section_nv("LA STIC",1);
                la2stic=nb_mat_section_nv("LA STIC",2);
                la3stic=nb_mat_section_nv("LA STIC",3);
                lf1math=nb_mat_section_nv("LF MATH",1);
                lf2math=nb_mat_section_nv("LF MATH",2);
                lf3math=nb_mat_section_nv("LF MATH",3);*/
            break;



            case ID_ER+6:
                ShellExecute( NULL, "open", "liste_etudiant.txt", NULL, NULL, SW_SHOWNORMAL );
            break;
            case ID_ER+7:
                ShellExecute( NULL, "open", "fichier_mat.txt", NULL, NULL, SW_SHOWNORMAL );
            break;
            case ID_ER+8:
                ShellExecute( NULL, "open", "fichier_note.txt", NULL, NULL, SW_SHOWNORMAL );
            break;

           }
        return 0 ;

        case WM_CLOSE:

                    if(en_e==1 && en_m==1 && en_n==1 || en_e==2 && en_m==2 && en_n==2 )
                     {

                        PostQuitMessage(0);
                        DestroyWindow(console);
                     }
                    else if (en_e==0 && en_m && en_n)
                        MessageBoxW(NULL, L"vous avez oubliez d'enregistrer le fichier etudiant veuillez l'enregistrer", L"SUCCEE", MB_OK);
                    else if (en_e && en_m && en_n==0)
                        MessageBoxW(NULL, L"vous avez oubliez d'enregistrer le fichier note veuillez l'enregistrer", L"SUCCEE", MB_OK);
                    else if (en_e && en_m==0 && en_n)
                        MessageBoxW(NULL, L"vous avez oubliez d'enregistrer le fichier matiere veuillez l'enregistrer", L"SUCCEE", MB_OK);
                    else if (en_e==0 && en_m==0 && en_n==0)
                        MessageBoxW(NULL, L"vous avez oubliez d'enregistrer les trois fichier veuillez l'enregistrer", L"SUCCEE", MB_OK);

            return 0;
        case ID_QUITTER:
            MessageBoxW(NULL, L"n'est pas oublie d'enregistre votre liste", L"SUCCEE", MB_OK);

                                PostQuitMessage(0);
        break;



        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

}


