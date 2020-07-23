
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<myconio.h>
HINSTANCE hinst;
HWND hwnd;
#include"ID.h"
#include"ressource.h"
#include"definition.h"
#include"fichier.h"
#include"etudiant.h"
#include"matiere.h"
#include"note.h"
#include"formulaire.h"

char szAppName[] = "bouton";
liste_etud LE;
liste_mat LM;
liste_note LN;

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

    hwnd = CreateWindow("MaWinClass", "MINI PROJET :BENOUN NESRINE ",
       WS_SYSMENU | WS_ACTIVECAPTION | WS_MINIMIZEBOX|WS_OVERLAPPEDWINDOW
       |WS_BORDER|WS_VISIBLE,200, 50,
                  960,575,
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

    AppendMenuW(hMenu1, MF_POPUP|MF_STRING,ID_ETUD, L"&Creation des etudiants");
    AppendMenuW(hMenu1, MF_POPUP|MF_STRING,hSubMenu1, L"&Mise a jour des etudiants");

    AppendMenuW(hSubMenu1, MF_STRING,ID_ETUD+1, L"&Ajouter un nouvel etudiant");
  /*  AppendMenuW(hSubMenu2, MF_STRING,ID_ETUD+1, L"&Ajout en tete");
    AppendMenuW(hSubMenu2, MF_STRING,ID_ETUD+2, L"&Ajout en queue");
    AppendMenuW(hSubMenu2, MF_STRING,ID_ETUD+3, L"&Ajout dans une position");
*/
    AppendMenuW(hSubMenu1,MF_STRING,ID_ETUD+2, L"&Supprimer un etudiant");
    /*AppendMenuW(hSubMenu3, MF_STRING,ID_ETUD+4, L"&supp. en tete");
    AppendMenuW(hSubMenu3, MF_STRING,ID_ETUD+5, L"&supp. en queue");
    AppendMenuW(hSubMenu3, MF_STRING,ID_ETUD+6, L"&supp. a partir d'une position");
    AppendMenuW(hSubMenu3, MF_STRING,ID_ETUD+7, L"&suppv.d'un etudiant donnee");
    AppendMenuW(hSubMenu3, MF_STRING,ID_ETUD+8, L"&supp des etudiant d'une sc. et ep. donnee");
    */
    AppendMenuW(hMenu1, MF_POPUP|MF_STRING,hSubMenu4, L"&Recherche, Affichage et Tri");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+9, L"&Contenu de la liste des etudiants");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+10, L"&Recherche par matricule");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+11, L"&Recherche par section");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+12, L"&Recherche par etape");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+13, L"&Recherche par etape et section");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+14, L"&Tri 1");
    AppendMenuW(hSubMenu4, MF_STRING,ID_ETUD+15, L"&Tri 2");
    /************************************* MENU MATIERE ******************************************/
     AppendMenuW(hMenu2, MF_POPUP|MF_STRING,ID_MAT, L"&Creation des matieres");
    AppendMenuW(hMenu2, MF_POPUP|MF_STRING,hSubMenu5, L"&Mise a jour des matieres");
    AppendMenuW(hSubMenu5, MF_POPUP|MF_STRING,hSubMenu6, L"&Ajouter un nouvelle matiere");
    AppendMenuW(hSubMenu6, MF_STRING,ID_MAT+1, L"&Ajout en tete");
    AppendMenuW(hSubMenu6, MF_STRING,ID_MAT+2, L"&Ajout en queue");
    AppendMenuW(hSubMenu6, MF_STRING,ID_MAT+3, L"&Ajout dans une position");
    AppendMenuW(hSubMenu5, MF_POPUP|MF_STRING,hSubMenu7, L"&Supprimer une matiere");
    AppendMenuW(hSubMenu7, MF_STRING,ID_MAT+4, L"&supp. en tete");
    AppendMenuW(hSubMenu7, MF_STRING,ID_MAT+5, L"&supp. en queue");
    AppendMenuW(hSubMenu7, MF_STRING,ID_MAT+6, L"&supp. a partir d'une position");
    AppendMenuW(hSubMenu7, MF_STRING,ID_MAT+7, L"&supp.d'une matiere donnee");

    AppendMenuW(hSubMenu5, MF_POPUP|MF_STRING,hSubMenu8, L"&modifier les donnees d'une matiere");
    AppendMenuW(hSubMenu8, MF_STRING,ID_MAT+8, L"&nom");
    AppendMenuW(hSubMenu8, MF_STRING,ID_MAT+9, L"&coefficient");
    AppendMenuW(hMenu2, MF_POPUP|MF_STRING,hSubMenu9, L"&Recherche,affichage et Tri");
    AppendMenuW(hSubMenu9, MF_STRING,ID_MAT+10, L"&Centenu de la liste des matieres");
    AppendMenuW(hSubMenu9, MF_STRING,ID_MAT+11, L"&Recherche par code_mat");
    AppendMenuW(hSubMenu9, MF_STRING,ID_MAT+12, L"&Recherche par section");
    AppendMenuW(hSubMenu9, MF_STRING,ID_MAT+13, L"&Recherche par etape et section");
    AppendMenuW(hSubMenu9, MF_STRING,ID_MAT+14, L"&Tri");

    AppendMenuW(hMenu3, MF_POPUP|MF_STRING,ID_NOTE, L"&Creation des notes");
    AppendMenuW(hMenu3, MF_POPUP|MF_STRING,hSubMenu10, L"&Mise a jour de la liste des notes");
    AppendMenuW(hSubMenu10, MF_POPUP|MF_STRING,hSubMenu11, L"&Ajouter une nouvelle note");
    AppendMenuW(hSubMenu11, MF_STRING,ID_NOTE+1, L"&Ajout en tete");
    AppendMenuW(hSubMenu11, MF_STRING,ID_NOTE+2, L"&Ajout en queue");
    AppendMenuW(hSubMenu11, MF_STRING,ID_NOTE+3, L"&Ajout dans une position");
    AppendMenuW(hSubMenu10, MF_POPUP|MF_STRING,hSubMenu12, L"&Supprimer une note");
    AppendMenuW(hSubMenu12, MF_STRING,ID_NOTE+4, L"&supp. en tete");
    AppendMenuW(hSubMenu12, MF_STRING,ID_NOTE+5, L"&supp. en queue");
    AppendMenuW(hSubMenu12, MF_STRING,ID_NOTE+6, L"&supp. a partir d'une position");
    AppendMenuW(hSubMenu12, MF_STRING,ID_NOTE+7, L"&supp.d'une note donnee");
    AppendMenuW(hSubMenu10, MF_POPUP|MF_STRING,hSubMenu13, L"&modifier les donnees d'une note");
    AppendMenuW(hSubMenu13, MF_STRING,ID_NOTE+8, L"&note");
    AppendMenuW(hMenu3, MF_POPUP|MF_STRING,hSubMenu14, L"&Recherche,affichage et Tri");
    AppendMenuW(hSubMenu14, MF_STRING,ID_NOTE+9, L"&Centenu de la liste des notes");
    AppendMenuW(hSubMenu14, MF_STRING,ID_NOTE+10, L"&Recherche par mat");
    AppendMenuW(hSubMenu14, MF_STRING,ID_NOTE+11, L"&Recherche par mat et DS");
    AppendMenuW(hSubMenu14, MF_STRING,ID_NOTE+12, L"&Recherche par mat et EX");
    AppendMenuW(hMenu4,MF_STRING,ID_CA, L"&Bulletin de note d'un etudiant");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+1, L"&Moyennes des etudiants de l'etablissement");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+2, L"&Moyennes des etudiants d'une section donnee");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+3, L"&Etudiant admis de l'etablissement");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+4, L"&Etudiant redouble de l'etablissement");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+5, L"&Etudiant admis d'une section donnee");
    AppendMenuW(hMenu4,MF_STRING,ID_CA+6, L"&Etudiant redouble d'une section donnee");
    AppendMenuW(hMenu5,MF_STRING,ID_ER, L"&Enregistrement fichier ETUDIANTS");
    AppendMenuW(hMenu5,MF_STRING,ID_ER+1, L"&Recuperation fichier ETUDIANTS");
    AppendMenuW(hMenu5,MF_STRING,ID_ER+2, L"&Enregistrement fichier MATIERES");
    AppendMenuW(hMenu5,MF_STRING,ID_ER+3, L"&Recuperation fichier MATIERES");
    AppendMenuW(hMenu5,MF_STRING,ID_ER+4, L"&Enregistrement fichier NOTES");
    AppendMenuW(hMenu5,MF_STRING,ID_ER+5, L"&Recuperation fichier NOTES");


    AppendMenuW(hMenubar, MF_POPUP,ID_ACCUEL, L"&ACCUEL");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu1, L"&Gestion des etudiants");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu2, L"&Gestion des matieres");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu3, L"&Gestion des notes");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu4, L"&Calcul et affichage");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu5, L"&Enreg. et Recup. Fichiers");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu6, L"&HELP");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu7, L"&Quitter");


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


static HBITMAP hBmp;

    switch (uMsg)
    {


        case WM_CREATE:

             image=CreateWindow("STATIC", "MyPicture0",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                       0, 0, 960,500 , hwnd, NULL, hinst, NULL);
        return 0;
        case WM_COMMAND:

           switch(LOWORD(wParam))
           {

                case ID_ACCUEL:
                    destroyallwindow();
                    image=CreateWindow("STATIC", "MyPicture",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575, hwnd, NULL, hinst, NULL);
                    bout_rec=CreateWindowW(L"Button", L"RECUPERE TOUS LES LISTES ",WS_VISIBLE | WS_CHILD ,
                                400, 100, 250, 25,hwnd, (HMENU) ID_RECP_T, NULL, NULL);
                    bout_enrg=CreateWindowW(L"Button", L"ENREGISTRE TOUS LES LISTES",WS_VISIBLE | WS_CHILD ,
                                400, 200, 250, 25,hwnd, (HMENU) ID_ENR_T, NULL, NULL);

                break;
                case ID_ETUD:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();
                    image=CreateWindow("STATIC", "creation_etudiant",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                    creation_etudiant(hwnd);
                    ShowWindow(hwnd,SW_NORMAL);
                break;
                case ID_ETUD+1:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();
                    image=CreateWindow("STATIC", "ajout_etudiant",WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                0, 0, 960,575 , hwnd, NULL, hinst, NULL);
                    ajout_etudiant(hwnd);
                    ShowWindow(hwnd,SW_NORMAL);
                break;
                case ID_ETUD+2:
                    ShowWindow(hwnd,SW_HIDE);
                    destroyallwindow();
                    sup_etudiant(hwnd);
                    ShowWindow(hwnd,SW_NORMAL);
                break;
       /*     case ID_ETUD+3:
                ShowWindow(hwnd,SW_HIDE);
                system("cls");
                LE=recuperation_etudiant();
                LE=ajout_pos_etudiant(LE);
                enregistrement_etud(LE);
                affiche_liste_etudiant(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+4:
                ShowWindow(hwnd,SW_HIDE);
                LE=recuperation_etudiant();
                 system("cls");
                LE=supprimmer_tete_etudiant(LE);
                 affiche_liste_etudiant(LE);
                enregistrement_etud(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+5:
                ShowWindow(hwnd,SW_HIDE);
                system("cls");
                LE=recuperation_etudiant();
                LE=supprimmer_queue_etudiant(LE);
                affiche_liste_etudiant(LE);
                enregistrement_etud(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+6:
                ShowWindow(hwnd,SW_HIDE);
                LE=recuperation_etudiant();
                system("cls");
                LE=sup_pos(LE);
                affiche_liste_etudiant(LE);
                enregistrement_etud(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;

            case ID_ETUD+7:
                ShowWindow(hwnd,SW_HIDE);
              LE=recuperation_etudiant();
                 system("cls");
                LE=sup_etud_donne(LE);
                enregistrement_etud(LE);
                affiche_liste_etudiant(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+8:
                LE=recuperation_etudiant();
                 system("cls");
                LE=sup_etud_sect_etape_donne(LE);
                affiche_liste_etudiant(LE);
               enregistrement_etud(LE);
               system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+9:
                ShowWindow(hwnd,SW_HIDE);
                system("cls");
               LE=recuperation_etudiant();
                affiche_liste_etudiant(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+10:
                ShowWindow(hwnd,SW_HIDE);
                LE=recuperation_etudiant();
                 system("cls");
                recherche_etud_mat(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+11:
                ShowWindow(hwnd,SW_HIDE);
                LE=recuperation_etudiant();
                 system("cls");
                recherche_section(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+12:
                ShowWindow(hwnd,SW_HIDE);
                LE=recuperation_etudiant();
                 system("cls");
                recherche_etape(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+13:
                ShowWindow(hwnd,SW_HIDE);
                LE=recuperation_etudiant();
                 system("cls");
                recherche_etape_section(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ETUD+14:
                ShowWindow(hwnd,SW_HIDE);
                LE=recuperation_etudiant();
                system("cls");
                tri1(LE);
                enregistrement_etud(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            */case ID_MAT:
                ShowWindow(hwnd,SW_HIDE);
                destroyallwindow();
                image=CreateWindow("STATIC", "creation_matiere",
                                    WS_CHILD | WS_VISIBLE| SS_BITMAP,
                                       0, 0, 960,575 , hwnd, NULL, hinst, NULL);

               CREATION_mat(hwnd);
                ShowWindow(hwnd,SW_NORMAL);

            break;
      /*      case ID_MAT+1:
                ShowWindow(hwnd,SW_HIDE);
                //LM=recuperation_matiere();
                system("cls");
                LM=ajout_tete_mat(LM);
                affiche_liste_matiere(LM);
                //enregistrement_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+2:
                ShowWindow(hwnd,SW_HIDE);
               // LM=recuperation_etudiant();
                system("cls");
                LM=ajout_queue_etudiant(LM);
                //enregistrement_matiere(LM);
                affiche_liste_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+3:
                ShowWindow(hwnd,SW_HIDE);
                 system("cls");
                //LM=recuperation_matiere();
                LM=ajout_pos_mat(LM);
                //enregistrement_matiere(LM);
                affiche_liste_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+4:
                ShowWindow(hwnd,SW_HIDE);
                //LM=recuperation_matiere();
                 system("cls");
                LM=supprimmer_tete_mat(LM);
                 affiche_liste_matiere(LM);
                //enregistrement_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+5:
                ShowWindow(hwnd,SW_HIDE);
                 system("cls");
                //LM=recuperation_matiere();
                LM=supprimmer_queue_mat(LM);
                affiche_liste_matiere(LM);
                //enregistrement_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+6:
                ShowWindow(hwnd,SW_HIDE);
                //LM=recuperation_matiere();
                 system("cls");
                LM=sup_pos(LM);
                affiche_liste_matiere(LM);
                //enregistrement_etud(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;

            case ID_MAT+7:
                ShowWindow(hwnd,SW_HIDE);
              //  LM=recuperation_matiere();
                 system("cls");
                LM=sup_mat_donne(LM);
                //enregistrement_matiere(LM);
                affiche_liste_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+8:
                ShowWindow(hwnd,SW_HIDE);
              //  LM=recuperation_matiere();
                 system("cls");
                modifier_nom(LM);
                //enregistrement_matiere(LM);
                affiche_liste_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+9:
                ShowWindow(hwnd,SW_HIDE);
              //  LM=recuperation_matiere();
                 system("cls");
                modifier_coef(LM);
                //enregistrement_matiere(LM);
                affiche_liste_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+10:
                ShowWindow(hwnd,SW_HIDE);
              //  LM=recuperation_matiere();
                 system("cls");
                affiche_liste_matiere(LM);
                //enregistrement_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+11:
                ShowWindow(hwnd,SW_HIDE);
              //  LM=recuperation_matiere();
                 system("cls");
               recherche_code_mat(LM);
                //enregistrement_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+12:
                ShowWindow(hwnd,SW_HIDE);
              //  LM=recuperation_matiere();
                system("cls");
                recherche_section_mat(LM);
                //enregistrement_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+13:
                ShowWindow(hwnd,SW_HIDE);
              //  LM=recuperation_matiere();
                system("cls");
                recherche_etape_section_mat(LM);
                //enregistrement_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_MAT+14:
                ShowWindow(hwnd,SW_HIDE);
              //  LM=recuperation_matiere();
                system("cls");
                tri_liste_mat(LM);
                //enregistrement_matiere(LM);
                affiche_liste_matiere(LM);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
             case ID_NOTE:
                ShowWindow(hwnd,SW_HIDE);
                LN=NULL;
                system("cls");
                LN=CREATION_note(LN);
                affiche_liste_note_etudiant(LN);
//                enregistrement_note(LN);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);

            break;
            case ID_NOTE+1:
                ShowWindow(hwnd,SW_HIDE);
               // LN=recuperation_note();
               system("cls");
                LN=ajout_tete_note(LN);
                affiche_liste_note_etudiant(LN);
                //enregistrement_note(LN);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+2:
                ShowWindow(hwnd,SW_HIDE);
               // LN=recuperation_note();
                system("cls");
                LN=ajout_queue_note(LN);
                //enregistrement_note(LN);
                affiche_liste_note_etudiant(LN);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+3:
                ShowWindow(hwnd,SW_HIDE);
                 system("cls");
                //LN=recuperation_note();
                LN=ajout_pos_note(LN);
                //enregistrement_note(LN);
                affiche_liste_note_etudiant(LN);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+4:
                ShowWindow(hwnd,SW_HIDE);
                //LN=recuperation_note();
                 system("cls");
                LN=supprimmer_tete_note(LN);
                 affiche_liste_note_etudiant(LN);
                //enregistrement_note(LN);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+5:
                ShowWindow(hwnd,SW_HIDE);
                 system("cls");
                //LN=recuperation_note();
                LN=supprimmer_queue_note(LN);
                affiche_liste_note_etudiant(LN);
                //enregistrement_note(LN);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+6:
                ShowWindow(hwnd,SW_HIDE);
                //LN=recuperation_note();
                system("cls");
                LN=sup_pos_note(LN);
                affiche_liste_note_etudiant(LN);
                //enregistrement_note(LN);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+7:
                ShowWindow(hwnd,SW_HIDE);
              // LN=recuperation_note();
                system("cls");
                LN=CREATION_note(LN);
                LN=sup_note_donne(LN);
                //enregistrement_etud(LE);
                affiche_liste_note_etudiant(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+8:
                ShowWindow(hwnd,SW_HIDE);
              // LN=recuperation_note();
                 system("cls");
                //modifier_note(LN);
                //enregistrement_etud(LE);
                affiche_liste_note_etudiant(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+9:
                ShowWindow(hwnd,SW_HIDE);
              // LN=recuperation_note();
                 system("cls");
                affiche_liste_note_etudiant(LN);
                //enregistrement_etud(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+10:
                ShowWindow(hwnd,SW_HIDE);
              // LN=recuperation_note();
                 system("cls");
                affiche_liste_note_etudiant(LN);
                //enregistrement_etud(LE);
                affiche_liste_etudiant(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+11:
                ShowWindow(hwnd,SW_HIDE);
              // LN=recuperation_note();
                 system("cls");
                affiche_ds_etud(LN);
                //enregistrement_etud(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_NOTE+12:
                ShowWindow(hwnd,SW_HIDE);
              // LN=recuperation_note();
                 system("cls");
                affiche_ex_etud(LN);
                //enregistrement_etud(LE);
                system("PAUSE");
                ShowWindow(hwnd,SW_NORMAL);
            break;
            case ID_ER:
                enregistrement_etud(LE);
            break;
            case ID_ER+1:
                LE=recuperation_etudiant();
            break;
            case ID_ER+2:
                enregistrement_matiere(LM);
            break;
            case ID_ER+3:
                LM=recuperation_mat();
            break;
            case ID_ER+4:
                enregistrement_note(LN);
            break;
            case ID_ER+5:
                LN=recuperation_note();
            break;
*/           }


        return 0 ;
        case WM_DESTROY:

                                MessageBoxW(NULL, L"n'est pas oublie d'enregistre votre liste", L"SUCCEE", MB_OK);
                                PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

}




