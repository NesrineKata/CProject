#ifndef FORMULAIRE_H_INCLUDED
#define FORMULAIRE_H_INCLUDED
HWND creation_etudiant(HWND hwnd)
{
    cin_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE|ES_NUMBER  ,265,117,70,20,hwnd,0,hinst,0);
    nom_wind= CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,265,175,165,20,hwnd,0,hinst,0);
    prenom_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE ,265,233,165,20,hwnd,0,hinst,0);
    j_wind = CreateWindow("COMBOBOX","1",  WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,265,290,50,150,hwnd,0,hinst,NULL);
    m_wind = CreateWindow("COMBOBOX","1",  WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,330,290,50,150,hwnd,0,hinst,NULL);
    a_wind= CreateWindow("COMBOBOX","1990",  WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,390,290,60,150,hwnd,0,hinst,NULL);
    section_wind = CreateWindow("COMBOBOX", "LA INFO", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,265,350,175,150,hwnd,0,hinst,0);
    etape_wind = CreateWindow("COMBOBOX", "1", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,265,405,50,90,hwnd,0,hinst,0);
    button_save = CreateWindow("Button","SAVE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,265,450,60,35,hwnd,ID_B_SAVE,hinst,0);
    button_annuler = CreateWindow("Button","RESET",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,390,450,60,35,hwnd,ID_B_ANNULER,hinst,0);
    for (i=0;i<20;i++)SendMessage(a_wind,CB_ADDSTRING,0,aacombo[i]);
    for (i=0;i<31;i++)SendMessage(j_wind,CB_ADDSTRING,0,jjcombo[i]);
    for (i=0;i<12;i++)SendMessage(m_wind,CB_ADDSTRING,0,mmcombo[i]);
    for (i=0;i<3;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
    for (i=0;i<5;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);

}
HWND ajout_etudiant(HWND hwnd)
{

    cin_wind=CreateWindow("Edit","",WS_BORDER | WS_CHILD | WS_VISIBLE|ES_NUMBER,180,55,70,20,hwnd,0,hinst,0);
    nom_wind=CreateWindow("Edit","",WS_CHILD | WS_VISIBLE |WS_BORDER,180,90,165,20,hwnd,0,hinst,0);
    prenom_wind=CreateWindow("Edit","",WS_BORDER | WS_CHILD | WS_VISIBLE ,180,125,165,20,hwnd,0,hinst,0);
    j_wind =CreateWindow("COMBOBOX","",WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,180,160,50,150,hwnd,0,hinst,NULL);
    m_wind =CreateWindow("COMBOBOX","",WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,260,160,50,150,hwnd,0,hinst,NULL);
    a_wind=CreateWindow("COMBOBOX","",WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,340,160,60,150,hwnd,0,hinst,NULL);
    section_wind =CreateWindow("COMBOBOX", "",WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,180,195,175,150,hwnd,0,hinst,0);
    etape_wind =CreateWindow("COMBOBOX", "",WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,180,230,50,90,hwnd,0,hinst,0);
    pos_wind =CreateWindow("COMBOBOX", "",WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,180,265,175,150,hwnd,0,hinst,0);
    but_tet_ajout= CreateWindow("Button","Ajouter en téte",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,80,300,120,35,hwnd,ID_AJOUT_TETE,hinst,0);
    but_que_ajout = CreateWindow("Button","Ajouter en queue",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,220,300,120,35,hwnd,ID_AJOUT_QUEUE,hinst,0);
    but_pos_ajout = CreateWindow("Button","Ajouter dans une position",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,360,300,180,35,hwnd,ID_AJOUT_POS,hinst,0);
    for (i=0;i<20;i++)SendMessage(a_wind,CB_ADDSTRING,0,aacombo[i]);
    for (i=0;i<31;i++)SendMessage(j_wind,CB_ADDSTRING,0,jjcombo[i]);
    for (i=0;i<12;i++)SendMessage(m_wind,CB_ADDSTRING,0,mmcombo[i]);
    for (i=0;i<3;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
    for (i=0;i<5;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
    for (i=1;i<=10;i++)SendMessage(pos_wind,CB_ADDSTRING,0,poscombo[i]);
}

HWND sup_etudiant(HWND hwnd)
{
cin_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE|ES_NUMBER  ,180,55,70,20,hwnd,0,hinst,0);
pos_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,180,265,175,150,hwnd,0,hinst,0);
but_tet_sup= CreateWindow("Button","SUPPRESION EN TETE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,40,300,160,35,hwnd,ID_SUP_TETE,hinst,0);    but_que_sup= CreateWindow("Button","SUPPRESSION EN QUEUE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,230,300,180,35,hwnd,ID_SUP_QUEUE,hinst,0);
but_que_sup=CreateWindow("Button","SUPPRESSION EN QUEUE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,220,300,120,35,hwnd,ID_SUP_QUEUE,hinst,0);
but_pos_sup= CreateWindow("Button","SUPPRESSION DANS UNE POSITION",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,440,300,250,35,hwnd,ID_SUP_POS,hinst,0);
for (i=1;i<=10;i++)SendMessage(pos_wind,CB_ADDSTRING,0,poscombo[i]);
}

HWND creation_matiere(HWND hwnd)
{
    mat_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE,180,55,60,20,hwnd,0,hinst,0);
    nom_mat_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE ,180,90,95,20,hwnd,0,hinst,0);
    section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,180,125,140,150,hwnd,0,hinst,0);
    coef_wind = CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE|ES_RIGHT|ES_AUTOHSCROLL,180,55,60,20,hwnd,0,hinst,0);
    etape_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,180,230,175,90,hwnd,0,hinst,0);
    button_save_mat= CreateWindow("Button","SAVE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,180,300,60,35,hwnd,ID_B_SAVE_mat,hinst,0);
    button_annuler_mat = CreateWindow("Button","RESET",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,350,300,60,35,hwnd,ID_B_ANNULER_mat,hinst,0);
    for (i=0;i<3;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
    for (i=0;i<5;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
}

void destroyallwindow ()
{

    DestroyWindow(image);
    DestroyWindow(button_save);
    DestroyWindow(button_annuler);
    DestroyWindow(etape_wind);
    DestroyWindow(section_wind);
    DestroyWindow(nom_wind);
    DestroyWindow(prenom_wind);
    DestroyWindow(cin_wind);
    //DestroyWindow(dnw);
    DestroyWindow(hComboBox1);
    DestroyWindow(j_wind);
    DestroyWindow(m_wind);
    DestroyWindow(a_wind);
    DestroyWindow(but_tet_ajout);
    DestroyWindow(but_que_ajout);
    DestroyWindow(but_pos_ajout);
    DestroyWindow(but_tet_sup);
    DestroyWindow(but_que_sup);
    DestroyWindow(but_pos_sup);
    DestroyWindow(pos_wind);
    DestroyWindow(coef_wind);
    DestroyWindow(nom_mat_wind);
    DestroyWindow( mat_wind);
    DestroyWindow(bout_enrg);
    DestroyWindow(bout_rec);


}


#endif // FORMULAIRE_H_INCLUDED
