#ifndef FORMULAIRE_H_-INCLUDED
#define FORMULAIRE_H_INCLUDED
HWND creation_etudiant(HWND hwnd)
{
    cin_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE|ES_NUMBER /*|WS_EX_TRANSPARENT*/,345,133,70,20,hwnd,0,hinst,0);
    nom_wind= CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,345,174,165,20,hwnd,0,hinst,0);
    prenom_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE ,345,215,165,20,hwnd,0,hinst,0);
    j_wind = CreateWindow("COMBOBOX","jj",  WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,345,257,50,150,hwnd,0,hinst,NULL);
    m_wind = CreateWindow("COMBOBOX","mm",  WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,425,257,50,150,hwnd,0,hinst,NULL);
    a_wind= CreateWindow("COMBOBOX","aaaa",  WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,505,257,60,150,hwnd,0,hinst,NULL);
    section_wind = CreateWindow("COMBOBOX", "LA INFO", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,297,175,150,hwnd,0,hinst,0);
    etape_wind = CreateWindow("COMBOBOX", "1", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,350,336,50,90,hwnd,0,hinst,0);
    button_save = CreateWindow("Button","SAVEGARDER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,420,390,120,35,hwnd,ID_B_SAVE,hinst,0);
    button_annuler = CreateWindow("Button","ANNULER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,550,390,120,35,hwnd,ID_B_ANNULER,hinst,0);
    for (i=0;i<30;i++)SendMessage(a_wind,CB_ADDSTRING,0,aacombo[i]);
    for (i=0;i<31;i++)SendMessage(j_wind,CB_ADDSTRING,0,jjcombo[i]);
    for (i=0;i<12;i++)SendMessage(m_wind,CB_ADDSTRING,0,mmcombo[i]);
    for (i=0;i<5;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);

}
HWND ajout_etudiant(HWND hwnd)
{
    cin_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE|ES_NUMBER  /*|WS_EX_TRANSPARENT*/,345,133,70,20,hwnd,0,hinst,0);
    nom_wind= CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,345,174,165,20,hwnd,0,hinst,0);
    prenom_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE ,345,215,165,20,hwnd,0,hinst,0);
    j_wind = CreateWindow("COMBOBOX","1",  WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,345,257,50,150,hwnd,0,hinst,NULL);
    m_wind = CreateWindow("COMBOBOX","1",  WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,425,257,50,150,hwnd,0,hinst,NULL);
    a_wind= CreateWindow("COMBOBOX","1990",  WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL,505,257,60,150,hwnd,0,hinst,NULL);
    section_wind = CreateWindow("COMBOBOX", "LA INFO", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,297,175,150,hwnd,0,hinst,0);
    etape_wind = CreateWindow("COMBOBOX", "1", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,350,336,50,90,hwnd,0,hinst,0);
    pos_wind =CreateWindow("COMBOBOX", "",WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL|WS_BORDER,540,419,60,150,hwnd,0,hinst,0);
    but_tet_ajout= CreateWindow("Button","Ajouter en t�te",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,345,370,120,35,hwnd,ID_AJOUT_TETE,hinst,0);
    but_que_ajout = CreateWindow("Button","Ajouter en queue",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE|WS_BORDER ,490,370,120,35,hwnd,ID_AJOUT_QUEUE,hinst,0);
    but_pos_ajout = CreateWindow("Button","Ajouter dans une position",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE|WS_BORDER/*|BS_ICON*/,345,415,180,35,hwnd,ID_AJOUT_POS,hinst,0);
    for (i=0;i<30;i++)SendMessage(a_wind,CB_ADDSTRING,0,aacombo[i]);
    for (i=0;i<31;i++)SendMessage(j_wind,CB_ADDSTRING,0,jjcombo[i]);
    for (i=0;i<12;i++)SendMessage(m_wind,CB_ADDSTRING,0,mmcombo[i]);
    for (i=0;i<5;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
    for (i=1;i<=taille_liste(LE);i++)
    {
        itoa(i,poscombo,8);
        SendMessage(pos_wind,CB_ADDSTRING,i,poscombo);
    }
}

HWND sup_etudiant(HWND hwnd)
{
section_wind = CreateWindow("COMBOBOX", "LA INFO", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,400,380,175,150,hwnd,0,hinst,0);
etape_wind = CreateWindow("COMBOBOX", "1", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,350,380,50,90,hwnd,0,hinst,0);
cin_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE|ES_NUMBER  /*|WS_EX_TRANSPARENT*/,560,280,70,20,hwnd,0,hinst,0);
pos_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,560,230,50,175,hwnd,0,hinst,0);
but_tet_sup= CreateWindow("Button","SUPPRESION EN TETE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,130,160,35,hwnd,ID_SUP_TETE,hinst,0);
but_que_sup= CreateWindow("Button","SUPPRESSION EN QUEUE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,180,180,35,hwnd,ID_SUP_QUEUE,hinst,0);
but_pos_sup= CreateWindow("Button","SUPPRESSION DANS UNE POS",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,230,210,35,hwnd,ID_SUP_POS,hinst,0);
but_etd_sup= CreateWindow("Button","SUPPRESSION ETU DONNEE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,280,210,35,hwnd,ID_SUP_ETD,hinst,0);
but_etsecet_sup= CreateWindow("Button","SUPP. ETU. PAR ETAPE ET SECTION",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,330,280,35,hwnd,ID_SUP_ETsecet,hinst,0);
for (i=1;i<=taille_liste(LE);i++)
    {
        itoa(i,poscombo,8);
        SendMessage(pos_wind,CB_ADDSTRING,i,poscombo);
    }
for (i=0;i<5;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
}

void ajout_espace(char ch[],int taille)
{
    int j;
    while(strlen(ch)<=taille)strcat(ch,"_");

}


void etudiant_info(etudiant l,char *ch)
{
    int i;int c;
    char ch1[30]=" ",ch2[30]=" ",ch3[30]=" ",ch4[30]=" ",ch5[30]=" ",ch6[30]=" ",ch7[40]=" ";
    strcpy(ch,"");
    sprintf(ch1,"%s",l.cin);ajout_espace(ch1,18);
    sprintf(ch2,"%s",l.nom);ajout_espace(ch2,21);
    sprintf(ch3,"%s",l.prenom);ajout_espace(ch3,21);
    sprintf(ch4,"%d/%d/%d",l.dn.j,l.dn.m,l.dn.a);ajout_espace(ch3,15);
    sprintf(ch5,"%s",l.section);ajout_espace(ch4,30);
    sprintf(ch6,"%d",l.etape);ajout_espace(ch5,15);
    sprintf(ch,"%s%s%s%s%s%s",ch1,ch2,ch3,ch4,ch5,ch6);

    }



HWND affichage_etudiants(HWND hwnd)
{
         liste_etud p=LE;

        int j=1;
        char ch[1000]=" ",cin[20]=" ",nom[30]=" ",prenom[30]=" ",section[30]=" ",etape[2]=" ",dn[11]=" ",espace1[30]=" ",espace2[30]=" ",espace3[30]=" ",espace4[30]=" ",espace5[30]=" ",espace6[30]=" ";
        hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         14,117,914,325,hwnd,NULL,NULL,NULL);

       while(p)
        {
           etudiant_info(p->info1,ch);
        /*  sprintf(ch,"%s",p->info1.cin);
            while(strlen(ch)<24)strcat(ch,"_");
            sprintf(nom,"%s",p->info1.nom);
            strcat(ch,nom);
            while(strlen(ch)<45)strcat(ch,"_");
            sprintf(prenom,"%s",p->info1.prenom);
            strcat(ch,prenom);
            while(strlen(ch)<65)strcat(ch,"_");
            sprintf(dn,"%d/%d/%d",p->info1.dn.j,p->info1.dn.m,p->info1.dn.a);
            strcat(ch,dn);
            while(strlen(ch)<83)strcat(ch,"_");
            sprintf(section,"%s",p->info1.section);
            strcat(ch,section);
            while(strlen(ch)<103)strcat(ch,"_");
            sprintf(etape,"%d",p->info1.etape);
            strcat(ch,etape);
           while(strlen(ch)<115)strcat(ch,"_");
           sprintf(ch,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",cin,espace1,nom,espace2,prenom,espace3,dn,espace4,section,espace5,etape,espace6);

          */  SendMessage(hListBox,LB_ADDSTRING,j,ch);
            p=p->suiv1;
            j++;
        }
}
HWND affichage_etudiants_section(HWND hwnd,char sec[])
{
        liste_etud p=LE;
        int j=1;
        char ch[1000]=" ",cin[9]=" ",nom[20]=" ",prenom[20]=" ",section[20]=" ",etape[2]=" ",dn[11]=" ";
           hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         14,117,914,325,hwnd,NULL,hinst,NULL);
       while(p)
        {
            if(strcmp(p->info1.section,sec)==0)
            {
             sprintf(ch,"%s",p->info1.cin);
            while(strlen(ch)<24)strcat(ch,"  ");
            sprintf(nom,"%s",p->info1.nom);
            strcat(ch,nom);
            while(strlen(ch)<45)strcat(ch,"  ");
            sprintf(prenom,"%s",p->info1.prenom);
            strcat(ch,prenom);
            while(strlen(ch)<65)strcat(ch,"  ");
            sprintf(dn,"%d/%d/%d",p->info1.dn.j,p->info1.dn.m,p->info1.dn.a);
            strcat(ch,dn);
            while(strlen(ch)<83)strcat(ch,"  ");
            sprintf(section,"%s",p->info1.section);
            strcat(ch,section);
            while(strlen(ch)<103)strcat(ch,"  ");
            sprintf(etape,"%d",p->info1.etape);
            strcat(ch,etape);
            while(strlen(ch)<115)strcat(ch,"  ");
            SendMessage(hListBox,LB_ADDSTRING,j,ch);
            }
            p=p->suiv1;
            j++;
        }
}

HWND rech_matricule(HWND hwnd)
{

        cin_wind= CreateWindow("Edit", "",  WS_CHILD | WS_VISIBLE|ES_NUMBER  ,280,155,70,20,hwnd,0,hinst,0);
        but_rech_mat= CreateWindow("Button","|> COMMENCER",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,500,150,120,35,hwnd,ID_B_RECH_cin,hinst,0);
}
HWND rech_et_mat (HWND hwnd,char cinc[])
{
    liste_etud p;
    int j=1;
    char ch[1000]=" ",cin[9],nom[20],prenom[20],section[20],cincc[9],etape[2]=" ",dn[11]=" ";
            hListBox=CreateWindow("LISTBOX","",WS_VISIBLE|WS_CHILD|WS_DISABLED ,
                         350,270,170,180,hwnd,hinst,NULL,NULL);
            p=recherche_etud(LE,cinc);
            if(p==NULL)
                MessageBoxW(NULL, L"ETUDIANT NON INSCRI", L"ERREUR", MB_OK);
            else
            {

               sprintf(etape,"%d",p->info1.etape);
               sprintf(dn,"%d/%d/%d",p->info1.dn.j,p->info1.dn.m,p->info1.dn.a);
               SendMessage(hListBox,LB_ADDSTRING,j,p->info1.cin);
               SendMessage(hListBox,LB_ADDSTRING,j,"");
               SendMessage(hListBox,LB_ADDSTRING,j,p->info1.nom);
               SendMessage(hListBox,LB_ADDSTRING,j,"");
               SendMessage(hListBox,LB_ADDSTRING,j,p->info1.prenom);
               SendMessage(hListBox,LB_ADDSTRING,j,"");
               SendMessage(hListBox,LB_ADDSTRING,j,dn);
               SendMessage(hListBox,LB_ADDSTRING,j,"");
               SendMessage(hListBox,LB_ADDSTRING,j,p->info1.section);
               SendMessage(hListBox,LB_ADDSTRING,j,"");
               SendMessage(hListBox,LB_ADDSTRING,j,etape);
            }
}
HWND recherche_section(HWND hwnd)
{
    section_wind = CreateWindow("COMBOBOX", "LA INFO", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,20,150,150,hwnd,0,hinst,0);
    button_rech_sec= CreateWindow("Button","RECHERCHER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,680,20,120,35,hwnd,ID_B_RECH_SEC,hinst,0);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
              hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         14,117,914,325,hwnd,NULL,hinst,NULL);
}

HWND rech_et_sec(HWND hwnd,char sectionc[])
{

         liste_etud p=LE;
        int j=1;
        char etape[2]=" ",dn[11]=" ",ch[1000]=" ",cin[9],nom[20],prenom[20],section[20];
         while(p)
                    {
                        if(strcmp(p->info1.section,sectionc)==0)
                        {
                            sprintf(ch,"%s",p->info1.cin);
                            while(strlen(ch)<24)strcat(ch,"_");
                            sprintf(nom,"%s",p->info1.nom);
                            strcat(ch,nom);
                            while(strlen(ch)<45)strcat(ch,"_");
                            sprintf(prenom,"%s",p->info1.prenom);
                            strcat(ch,prenom);
                            while(strlen(ch)<65)strcat(ch,"_");
                            sprintf(dn,"%d/%d/%d",p->info1.dn.j,p->info1.dn.m,p->info1.dn.a);
                            strcat(ch,dn);
                            while(strlen(ch)<83)strcat(ch,"_");
                            sprintf(section,"%s",p->info1.section);
                            strcat(ch,section);
                            while(strlen(ch)<103)strcat(ch,"_");
                            sprintf(etape,"%d",p->info1.etape);
                            strcat(ch,etape);
                            while(strlen(ch)<115)strcat(ch,"_");
                            SendMessage(hListBox,LB_ADDSTRING,j,ch);
                        j++;
                        }
                        p=p->suiv1;
                    }
}
HWND recherche_etape(HWND hwnd)
{
    etape_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,20,150,150,hwnd,0,hinst,0);
    button_rech_etape= CreateWindow("Button","RECHERCHER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,680,20,120,35,hwnd, ID_B_RECH_etp,hinst,0);
    for (i=0;i<5;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
        hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         14,117,914,325,hwnd,NULL,hinst,NULL);
}
HWND rech_et_etape(HWND hwnd,int  nv)
{

         liste_etud p=LE;
        int j=1;
        char etape[2]=" ",dn[11]=" ",ch[1000]=" ",cin[9],nom[20],prenom[20],section[20];
         while(p)
                    {
                        if(p->info1.etape==nv)
                        {
                             sprintf(ch,"%s",p->info1.cin);
            while(strlen(ch)<24)strcat(ch,"_");
            sprintf(nom,"%s",p->info1.nom);
            strcat(ch,nom);
            while(strlen(ch)<45)strcat(ch,"_");
            sprintf(prenom,"%s",p->info1.prenom);
            strcat(ch,prenom);
            while(strlen(ch)<65)strcat(ch,"_");
            sprintf(dn,"%d/%d/%d",p->info1.dn.j,p->info1.dn.m,p->info1.dn.a);
            strcat(ch,dn);
            while(strlen(ch)<83)strcat(ch,"_");
            sprintf(section,"%s",p->info1.section);
            strcat(ch,section);
            while(strlen(ch)<103)strcat(ch,"_");
            sprintf(etape,"%d",p->info1.etape);
            strcat(ch,etape);
            while(strlen(ch)<115)strcat(ch,"_");
                            SendMessage(hListBox,LB_ADDSTRING,j,ch);
                            j++;
                        }
                        p=p->suiv1;
                    }
}
HWND recherche_etape_section(HWND hwnd)
{
    section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,200,20,150,150,hwnd,0,hinst,0);
    etape_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,20,150,150,hwnd,0,hinst,0);
    button_rech_etape_section= CreateWindow("Button","RECHERCHER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,680,20,120,35,hwnd, ID_B_RECH_etp_sec,hinst,0);
    for (i=0;i<5;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
        hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         14,117,914,325,hwnd,NULL,hinst,NULL);
}
HWND rech_et_etape_section(HWND hwnd,char sectionc[], int  nv)
{

        liste_etud p=LE;
        int j=1;
        char etape[2]=" ",dn[11]=" ",ch[1000]=" ",cin[9],nom[20],prenom[20],section[20];
        while(p)
        {
                    if(p->info1.etape==nv)
                        if(strcmp(p->info1.section,sectionc)==0)
                            {
                            sprintf(ch,"%s",p->info1.cin);
            while(strlen(ch)<24)strcat(ch,"_");
            sprintf(nom,"%s",p->info1.nom);
            strcat(ch,nom);
            while(strlen(ch)<45)strcat(ch,"_");
            sprintf(prenom,"%s",p->info1.prenom);
            strcat(ch,prenom);
            while(strlen(ch)<65)strcat(ch,"_");
            sprintf(dn,"%d/%d/%d",p->info1.dn.j,p->info1.dn.m,p->info1.dn.a);
            strcat(ch,dn);
            while(strlen(ch)<83)strcat(ch,"_");
            sprintf(section,"%s",p->info1.section);
            strcat(ch,section);
            while(strlen(ch)<103)strcat(ch,"_");
            sprintf(etape,"%d",p->info1.etape);
            strcat(ch,etape);
            while(strlen(ch)<115)strcat(ch,"_");
            SendMessage(hListBox,LB_ADDSTRING,j,ch);
                            j++;
                            }

                        p=p->suiv1;
                    }
}

HWND tri_etu (HWND hwnd)
{
        liste_etud p=LE;

        int j=1,tc,tn,tp,td,ts;
        char ch[1000]="",cin[30]="",nom[30]="",prenom[30]="",section[30]="",etape[30]="",dn[30]="";
         hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         14,117,914,325,hwnd,NULL,hinst,NULL);

                p=tri_liste_etud(p);
                while(p)
                {



                            sprintf(cin,"%s",p->info1.cin);
                            sprintf(nom,"%s",p->info1.nom);
                            sprintf(prenom,"%s",p->info1.prenom);
                            sprintf(dn,"%d/%d/%d",p->info1.dn.j,p->info1.dn.m,p->info1.dn.a);
                            sprintf(section,"%s",p->info1.section);
                            sprintf(etape,"%d",p->info1.etape);
                            tc=strlen(cin);
                            tn=strlen(nom);
                            tp=strlen(prenom);
                            ts=strlen(section);
                            td=strlen(dn);
                            for(i=1;i<=25-tc;i++)
                                strcat(cin," ");
                            for(i=1;i<=26-tn;i++)
                                strcat(nom," ");
                            for(i=1;i<=26-tp;i++)
                                strcat(prenom," ");
                            for(i=1;i<=15-tp;i++)
                                strcat(dn," ");
                            for(i=1;i<=26-tp;i++)
                                strcat(section," ");
                           // while(strlen(section)<25)strcat(section," ");
                            //while(strlen(etape)<7)strcat(etape," ");



                            sprintf(ch,"%s %s %s %s %s %s",cin,nom,prenom,dn,section,etape);
                            printf("%s\n",ch);
                            SendMessage(hListBox,LB_ADDSTRING,j,ch);
                        j++;
                        p=p->suiv1;
                }
}
HWND tri_etu_v2 (HWND hwnd)
{
        liste_etud p=LE;

        int j=1,tc,tn,tp,td,ts;
        char ch[1000]="",cin[30]="",nom[30]="",prenom[30]="",section[30]="",etape[30]="",dn[30]="";
         hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         14,117,914,325,hwnd,NULL,hinst,NULL);

                p=tri2(p);
                while(p)
                {



                            sprintf(cin,"%s",p->info1.cin);
                            sprintf(nom,"%s",p->info1.nom);
                            sprintf(prenom,"%s",p->info1.prenom);
                            sprintf(dn,"%d/%d/%d",p->info1.dn.j,p->info1.dn.m,p->info1.dn.a);
                            sprintf(section,"%s",p->info1.section);
                            sprintf(etape,"%d",p->info1.etape);
                            tc=strlen(cin);
                            tn=strlen(nom);
                            tp=strlen(prenom);
                            ts=strlen(section);
                            td=strlen(dn);
                            for(i=1;i<=25-tc;i++)
                                strcat(cin," ");
                            for(i=1;i<=26-tn;i++)
                                strcat(nom," ");
                            for(i=1;i<=26-tp;i++)
                                strcat(prenom," ");
                            for(i=1;i<=15-tp;i++)
                                strcat(dn," ");
                            for(i=1;i<=26-tp;i++)
                                strcat(section," ");
                           // while(strlen(section)<25)strcat(section," ");
                            //while(strlen(etape)<7)strcat(etape," ");



                            sprintf(ch,"%s %s %s %s %s %s",cin,nom,prenom,dn,section,etape);
                            printf("%s\n",ch);
                            SendMessage(hListBox,LB_ADDSTRING,j,ch);
                        j++;
                        p=p->suiv1;
                }
}
/****************************************************LISTE MATIERE*****************************************************************************/
/****************************************************LISTE MATIERE*****************************************************************************/
/****************************************************LISTE MATIERE*****************************************************************************/
/****************************************************LISTE MATIERE*****************************************************************************/
/****************************************************LISTE MATIERE*****************************************************************************/
/****************************************************LISTE MATIERE*****************************************************************************/
/****************************************************LISTE MATIERE*****************************************************************************/
/****************************************************LISTE MATIERE*****************************************************************************/
/****************************************************LISTE MATIERE*****************************************************************************/


HWND creation_matiere(HWND hwnd)
{
    mat_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE,345,145,30,20,hwnd,0,hinst,0);
    nom_mat_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE ,345,200,120,20,hwnd,0,hinst,0);
    section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,255,140,150,hwnd,0,hinst,0);
    coef_wind = CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE,345,300,60,20,hwnd,0,hinst,0);
    etape_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,323,175,90,hwnd,0,hinst,0);
    button_save_mat= CreateWindow("Button","SAVEGARDER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,420,390,120,35,hwnd,ID_B_SAVE_mat,hinst,0);
    button_annuler_mat = CreateWindow("Button","ANNULER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,570,390,120,35,hwnd,ID_B_ANNULER_mat,hinst,0);
    for (i=0;i<5;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
}
HWND ajout_matiere(HWND hwnd)
{
    mat_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE,345,133,30,20,hwnd,0,hinst,0);
    nom_mat_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE ,345,175,245,20,hwnd,0,hinst,0);
    section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,215,140,150,hwnd,0,hinst,0);
    coef_wind = CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE,345,260,60,20,hwnd,0,hinst,0);
    etape_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,300,175,90,hwnd,0,hinst,0);
    pos_wind =CreateWindow("COMBOBOX", "",WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL|WS_BORDER,540,419,60,150,hwnd,0,hinst,0);
    but_tet_ajout_mat= CreateWindow("Button","Ajouter en t�te",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,345,370,120,35,hwnd,ID_AJOUT_TETE_MAT,hinst,0);
    but_queue_ajout_mat= CreateWindow("Button","Ajouter en queue",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE|WS_BORDER ,490,370,120,35,hwnd,ID_AJOUT_QUEUE_MAT,hinst,0);
    but_pos_ajout_mat = CreateWindow("Button","Ajouter dans une position",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE|WS_BORDER/*|BS_ICON*/,345,415,180,35,hwnd,ID_AJOUT_POS_MAT,hinst,0);
    for (i=0;i<5;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
    for (i=1;i<=taille_liste_mat(LM);i++)
    {
        itoa(i,poscombo,8);
        SendMessage(pos_wind,CB_ADDSTRING,i,poscombo);
    }
}

HWND sup_matiere(HWND hwnd)
{
mat_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE,590,350,30,20,hwnd,0,hinst,0);
pos_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,560,280,50,175,hwnd,0,hinst,0);
but_tet_sup_mat= CreateWindow("Button","SUPPRESION EN TETE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,130,160,35,hwnd,ID_SUP_TETE_MAT,hinst,0);
but_que_sup_mat= CreateWindow("Button","SUPPRESSION EN QUEUE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,200,180,35,hwnd,ID_SUP_QUEUE_MAT,hinst,0);
but_pos_sup_mat= CreateWindow("Button","SUPPRESSION DANS UNE POS",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,270,210,35,hwnd,ID_SUP_POS_MAT,hinst,0);
but_sup_mat= CreateWindow("Button","SUPPRESSION MATIERE DONNEE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,350,230,35,hwnd,ID_SUP_MAT,hinst,0);
for (i=1;i<=taille_liste_mat(LM);i++)
    {
        itoa(i,poscombo,8);
        SendMessage(pos_wind,CB_ADDSTRING,i,poscombo);
    }
}
HWND modiefie_nom_matiere(HWND hwnd)
{

        mat_wind= CreateWindow("Edit","",  WS_CHILD | WS_VISIBLE,310,185,30,20,hwnd,0,hinst,0);
        nom_mat_wind= CreateWindow("Edit","",  WS_CHILD | WS_VISIBLE,310,133,245,20,hwnd,0,hinst,0);
        but_modifier_nom_mat= CreateWindow("Button","|> MODIFFIER",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,370,235,120,35,hwnd,ID_modifier_nom_mat,hinst,0);
}
HWND modiefie_coef_matiere(HWND hwnd)
{

        mat_wind= CreateWindow("Edit", "",  WS_CHILD | WS_VISIBLE,310,185,30,20,hwnd,0,hinst,0);
        coef_wind= CreateWindow("Edit", "",  WS_CHILD | WS_VISIBLE,310,133,40,20,hwnd,0,hinst,0);
        but_modifier_coef_mat= CreateWindow("Button","|> MODIFFIER",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,370,235,120,35,hwnd,ID_modifier_coef_mat,hinst,0);
}
HWND affichage_matieres(HWND hwnd)
{
         liste_mat p=LM;

        int j=1;
        char ch[1000]=" ";
        hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);

       while(p)
        {
            sprintf(etapec,"%d",p->info2.niveau);
            sprintf(matc,"%s",p->info2.code_mat);
            sprintf(nomc,"%s",p->info2.nom_mat);
            sprintf(coefc,"%.2f",p->info2.coef);
            sprintf(sectionc,"%s",p->info2.section);
            while(strlen(nom)<21)strcat(nom,"   ");
            while(strlen(section)<21)strcat(section,"   ");


            sprintf(ch,"%s        %s         %s         %s        %s",matc,nomc,sectionc,coefc,etapec);
            SendMessage(hListBox,LB_ADDSTRING,j,ch);
            p=p->suiv2;
            j++;
        }
}

HWND rech_matiere(HWND hwnd)
{

        mat_wind= CreateWindow("Edit", "",  WS_CHILD | WS_VISIBLE,360,175,30,20,hwnd,0,hinst,0);
        but_rech_matiere= CreateWindow("Button","|> COMMENCER",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,460,170,120,35,hwnd,ID_B_RECH_matiere,hinst,0);
}
HWND rech_matiere_code (HWND hwnd,char matc[])
{
    liste_mat p;
    int j=1;
    char ch[1000]=" ";

            p=recherche_mat(LM,matc);
            if(p==NULL)
                MessageBoxW(NULL, L"MATIERE NON SAISIE", L"ERREUR", MB_OK);
            else
            {
                hListBox=CreateWindow("LISTBOX","",WS_VISIBLE|WS_CHILD|WS_DISABLED ,
                         425,220,170,150,hwnd,hinst,NULL,NULL);

               sprintf(etapec,"%d",p->info2.niveau);
               sprintf(coefc,"%.2f",p->info2.coef);
               SendMessage(hListBox,LB_ADDSTRING,j,p->info2.code_mat);
               SendMessage(hListBox,LB_ADDSTRING,j,"");
               SendMessage(hListBox,LB_ADDSTRING,j,p->info2.nom_mat);
               SendMessage(hListBox,LB_ADDSTRING,j,"");
               SendMessage(hListBox,LB_ADDSTRING,j,p->info2.section);
               SendMessage(hListBox,LB_ADDSTRING,j,"");
               SendMessage(hListBox,LB_ADDSTRING,j,coefc);
               SendMessage(hListBox,LB_ADDSTRING,j,"");
               SendMessage(hListBox,LB_ADDSTRING,j,etapec);

            }
}
HWND recherche_section_matiere(HWND hwnd)
{
    section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,20,150,150,hwnd,0,hinst,0);
    button_rech_sec_mat= CreateWindow("Button","RECHERCHER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,680,20,120,35,hwnd,ID_B_RECH_SEC_mat,hinst,0);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
               hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);
}

HWND rech_sec_matiere(HWND hwnd,char sectionc[])
{

         liste_mat p=LM;
        int j=1;
        char ch[1000]=" ";
         while(p)
                    {
                        if(strcmp(p->info2.section,sectionc)==0)
                        {

            sprintf(etapec,"%d",p->info2.niveau);
            sprintf(matc,"%s",p->info2.code_mat);
            sprintf(nomc,"%s",p->info2.nom_mat);
            sprintf(coefc,"%.2f",p->info2.coef);
            sprintf(sectionc,"%s",p->info2.section);
            while(strlen(nom)<21)strcat(nom,"   ");
            while(strlen(section)<21)strcat(section,"   ");


            sprintf(ch,"%s      %s      %s     %s     %s",matc,nomc,sectionc,coefc,etapec);
            SendMessage(hListBox,LB_ADDSTRING,j,ch);
            j++;
                        }
                        p=p->suiv2;
                    }
}
HWND tri_matiere(HWND hwnd)
{
         liste_mat p=LM;

        int j=1;
        char ch[1000]=" ";
        hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);
        tri_liste_mat(LM);
       while(p)
        {
            sprintf(etapec,"%d",p->info2.niveau);
            sprintf(matc,"%s",p->info2.code_mat);
            sprintf(nomc,"%s",p->info2.nom_mat);
            sprintf(coefc,"%.2f",p->info2.coef);
            sprintf(sectionc,"%s",p->info2.section);
            while(strlen(nom)<21)strcat(nom,"   ");
            while(strlen(section)<21)strcat(section,"   ");


            sprintf(ch,"%s        %s         %s         %s        %s",matc,nomc,sectionc,coefc,etapec);
            SendMessage(hListBox,LB_ADDSTRING,j,ch);
            p=p->suiv2;
            j++;
        }
}

HWND recherche_etape_matiere(HWND hwnd)
{
   section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,200,20,150,150,hwnd,0,hinst,0);
    etape_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,20,150,150,hwnd,0,hinst,0);
    button_rech_etape_mat= CreateWindow("Button","RECHERCHER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,680,20,120,35,hwnd,ID_B_RECH_etp_mat,hinst,0);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
    for (i=0;i<5;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);
               hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);

}

HWND rech_etape_matiere(HWND hwnd,char sectionc[],int nv)
{

         liste_mat p=LM;
        int j=1;
        char ch[1000]=" ";
         while(p)
                    {
                        if(p->info2.niveau==nv)
                            if(strcmp(p->info2.section,sectionc)==0)
                            {
                                sprintf(etapec,"%d",p->info2.niveau);
                                sprintf(matc,"%s",p->info2.code_mat);
                                sprintf(nomc,"%s",p->info2.nom_mat);
                                sprintf(coefc,"%.2f",p->info2.coef);
                                sprintf(sectionc,"%s",p->info2.section);
                                while(strlen(nom)<21)strcat(nom,"   ");
                                while(strlen(section)<21)strcat(section,"   ");
                                sprintf(ch,"%s      %s       %s       %s      %s",matc,nomc,sectionc,coefc,etapec);
                                SendMessage(hListBox,LB_ADDSTRING,j,ch);
                                j++;
                            }

                        p=p->suiv2;
                    }
}
/****************************************************LISTE NOTE****************************************************************************/
/****************************************************LISTE NOTE*****************************************************************************/
/****************************************************LISTE NOTE*****************************************************************************/
/****************************************************LISTE NOTE****************************************************************************/
/****************************************************LISTE NOTE*****************************************************************************/
/****************************************************LISTE NOTE*****************************************************************************/
/****************************************************LISTE NOTE****************************************************************************/
/****************************************************LISTE NOTE*****************************************************************************/
/****************************************************LISTE NOTE*****************************************************************************/

HWND ajout_notes(HWND hwnd)
{
    cin_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE|ES_NUMBER  /*|WS_EX_TRANSPARENT*/,345,140,70,20,hwnd,0,hinst,0);
    mat_wind= CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,345,195,30,20,hwnd,0,hinst,0);
    note_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE ,345,255,60,20,hwnd,0,hinst,0);
    nature_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,310,100,150,hwnd,0,hinst,0);
    pos_wind =CreateWindow("COMBOBOX", "",WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL|WS_BORDER,540,410,60,150,hwnd,0,hinst,0);
    but_tet_ajout_note= CreateWindow("Button","Ajouter en t�te",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,345,350,120,35,hwnd,ID_AJOUT_TETE_note,hinst,0);
    but_queue_ajout_note = CreateWindow("Button","Ajouter en queue",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE|WS_BORDER ,490,350,120,35,hwnd,ID_AJOUT_QUEUE_note,hinst,0);
    but_pos_ajout_note= CreateWindow("Button","Ajouter dans une position",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE|WS_BORDER/*|BS_ICON*/,345,410,180,35,hwnd,ID_AJOUT_POS_note,hinst,0);
    for (i=0;i<2;i++)SendMessage(nature_wind,CB_ADDSTRING,0,naturecombo[i]);
    for (i=1;i<=taille_liste(LE);i++)
    {
        itoa(i,poscombo,8);
        SendMessage(pos_wind,CB_ADDSTRING,i,poscombo);
    }
}
HWND sup_note(HWND hwnd)
{
cin_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE,345,400,70,20,hwnd,0,hinst,0);
mat_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE,430,400,30,20,hwnd,0,hinst,0);
nature_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,490,398,50,175,hwnd,0,hinst,0);
pos_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,560,280,50,175,hwnd,0,hinst,0);
but_tet_sup_note= CreateWindow("Button","SUPPRESION EN TETE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,130,160,35,hwnd,ID_SUP_TETE_note,hinst,0);
but_queue_sup_note= CreateWindow("Button","SUPPRESSION EN QUEUE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,200,180,35,hwnd,ID_SUP_QUEUE_note,hinst,0);
but_pos_sup_note= CreateWindow("Button","SUPPRESSION DANS UNE POS",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,270,210,35,hwnd,ID_SUP_POS_note,hinst,0);
but_sup_note= CreateWindow("Button","SUPPRESSION NOTE DONNEE",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,345,350,230,35,hwnd,ID_SUP_note,hinst,0);
for (i=0;i<2;i++)SendMessage(nature_wind,CB_ADDSTRING,0,naturecombo[i]);
for (i=1;i<=taille_liste_note(LN);i++)
    {
        itoa(i,poscombo,8);
        SendMessage(pos_wind,CB_ADDSTRING,i,poscombo);
    }
}
HWND mdf_note(HWND hwnd)
{
        cin_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE|ES_NUMBER  /*|WS_EX_TRANSPARENT*/,345,133,70,20,hwnd,0,hinst,0);
        mat_wind= CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE |WS_BORDER,345,174,30,20,hwnd,0,hinst,0);
        note_wind= CreateWindow("Edit", "",WS_BORDER | WS_CHILD | WS_VISIBLE ,345,215,60,20,hwnd,0,hinst,0);
        nature_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,257,100,150,hwnd,0,hinst,0);
        for (i=0;i<2;i++)SendMessage(nature_wind,CB_ADDSTRING,0,naturecombo[i]);
        but_modifier_nom_note= CreateWindow("Button","|> MODIFFIER",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,370,285,120,35,hwnd,ID_modifier_note,hinst,0);
}
HWND affichage_notes(HWND hwnd)
{
         liste_note p=LN;

        int j=1;
        char ch[1000]=" ";
        hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);

       while(p)
        {
            sprintf(cinc,"%s",p->info3.mat);
            sprintf(matc,"%s",p->info3.code_mat);
            sprintf(notec,"%.2f",p->info3.note);
            sprintf(naturec,"%s",p->info3.nature);
            sprintf(ch,"%s                                    %s                                         %s                                  %s",cinc,matc,notec,naturec);
            SendMessage(hListBox,LB_ADDSTRING,j,ch);
            p=p->suiv3;
            j++;
        }
}
HWND rech_notes_etudiant(HWND hwnd)
{

        cin_wind= CreateWindow("Edit", "",  WS_CHILD | WS_VISIBLE|ES_NUMBER,360,175,70,20,hwnd,0,hinst,0);
        but_rech_note_etudiant= CreateWindow("Button","|> COMMENCER",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,460,170,120,35,hwnd,ID_B_RECH_etudiant_note,hinst,0);
}
HWND affichage_notes_etud(HWND hwnd,char cinc[])
{
         liste_note p=LN;

        int j=1;
        char ch[1000]=" ";
        hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);

       while(p)
        {
            if(strcmp(p->info3.mat,cinc)==0)
            {
            sprintf(cinc,"%s",p->info3.mat);
            sprintf(matc,"%s",p->info3.code_mat);
            sprintf(notec,"%.2f",p->info3.note);
            sprintf(naturec,"%s",p->info3.nature);
            sprintf(ch,"%s                                    %s                                         %s                                  %s",cinc,matc,notec,naturec);
            SendMessage(hListBox,LB_ADDSTRING,j,ch);
            j++;
            }
            p=p->suiv3;

        }
}
HWND rech_notes_etudiant_Ds(HWND hwnd)
{

        cin_wind= CreateWindow("Edit", "",  WS_CHILD | WS_VISIBLE|ES_NUMBER,360,175,70,20,hwnd,0,hinst,0);
        but_rech_note_etudiant_ds= CreateWindow("Button","|> COMMENCER",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,460,170,120,35,hwnd,ID_B_RECH_etudiant_note_ds,hinst,0);
}
HWND affichage_notes_etud_DS(HWND hwnd,char cinc[])
{
         liste_note p=LN;

        int j=1;
        char ch[1000]=" ";
        hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);

       while(p)
        {
            if(strcmp(p->info3.mat,cinc)==0&&strcmp(p->info3.nature,"DS")==0)
            {
            sprintf(cinc,"%s",p->info3.mat);
            sprintf(matc,"%s",p->info3.code_mat);
            sprintf(notec,"%.2f",p->info3.note);
            sprintf(naturec,"%s",p->info3.nature);
            sprintf(ch,"%s                                    %s                                         %s                                  %s",cinc,matc,notec,naturec);
            SendMessage(hListBox,LB_ADDSTRING,j,ch);
            j++;
            }
            p=p->suiv3;

        }
}
HWND rech_notes_etudiant_EX(HWND hwnd)
{

        cin_wind= CreateWindow("Edit", "",  WS_CHILD | WS_VISIBLE|ES_NUMBER,360,175,70,20,hwnd,0,hinst,0);
        but_rech_note_etudiant_ex= CreateWindow("Button","|> COMMENCER",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,460,170,120,35,hwnd,ID_B_RECH_etudiant_note_ex,hinst,0);
}
HWND affichage_notes_etud_EX(HWND hwnd,char cinc[])
{
         liste_note p=LN;

        int j=1;
        char ch[1000]=" ";
        hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);

       while(p)
        {
            if(strcmp(p->info3.mat,cinc)==0&&strcmp(p->info3.nature,"EX")==0)
            {
            sprintf(cinc,"%s",p->info3.mat);
            sprintf(matc,"%s",p->info3.code_mat);
            sprintf(notec,"%.2f",p->info3.note);
            sprintf(naturec,"%s",p->info3.nature);
            sprintf(ch,"%s                                    %s                                         %s                                  %s",cinc,matc,notec,naturec);
            SendMessage(hListBox,LB_ADDSTRING,j,ch);
            j++;
            }
            p=p->suiv3;

        }
}
HWND bulletin_etud(HWND hwnd)
{

        cin_wind= CreateWindow("Edit", "",  WS_CHILD | WS_VISIBLE|ES_NUMBER,360,175,70,20,hwnd,0,hinst,0);
        but_bulletin_etud= CreateWindow("Button","|> BULLETIN",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,460,170,120,35,hwnd,ID_B_etud,hinst,0);
}
HWND bulletin(HWND hwnd,char cinc[])
{
         liste_note p=LN,pds,pex;
         liste_etud p1;
         liste_mat p2=LM;
         etudiant info;


        int j=1,i=1;
        char ch[1000]=" ",ch3[20]=" ";
        wchar_t  ch_mm[1000]=L"";

        p1=recherche_etud(LE,cinc);
        info=p1->info1;
        strcpy(sectionc,info.section);
        nv=info.etape;
        int test=0;

        if(nb_etud_mat(cinc)!=nb_mat_section_nv(sectionc,nv)||nb_mat_section_nv(sectionc,nv)==0)
        {
                matiere_manque(cinc,ch_mm,sectionc,nv);
               // printf("\n%s",ch_m);

                MessageBox(NULL,(LPCWSTR)ch_mm,L"ECHEC",MB_OK);
        }
        else
        {
            hListBox1=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         250,40,420,80,hwnd,NULL,hinst,NULL);
            hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                        100,150,700,480,hwnd,NULL,hinst,NULL);

                            sprintf(cinc,"%s",info.cin);
                            SendMessage(hListBox1,LB_ADDSTRING,i++,cinc);
                            sprintf(nomc,"%s",info.nom);
                             SendMessage(hListBox1,LB_ADDSTRING,i++,nomc);
                            sprintf(prenomc,"%s",info.prenom);
                             SendMessage(hListBox1,LB_ADDSTRING,i++,prenomc);
                            sprintf(sectionc,"%s",info.section);
                             SendMessage(hListBox1,LB_ADDSTRING,i++,sectionc);
                            sprintf(etapec,"%d",info.etape);
                             SendMessage(hListBox1,LB_ADDSTRING,i++,etapec);
                           // sprintf(ch,"%s    %s    %s    %s   %s",cinc,nomc,prenomc,sectionc,etapec);




            while(p2)
                {
                    if(strcmp(p2->info2.section,info.section)==0&&p2->info2.niveau==nv)
                        if(recherche_cin_mat(LN,cinc,p2->info2.code_mat,"DS")&&recherche_cin_mat(LN,cinc,p2->info2.code_mat,"EX"))
                        {
                            pds=recherche_cin_mat(LN,cinc,p2->info2.code_mat,"DS");
                            pex=recherche_cin_mat(LN,cinc,p2->info2.code_mat,"EX");
                            moy=pds->info3.note*0.3+pex->info3.note*0.7;
                            sprintf(matc,"%s",p2->info2.code_mat);
                            sprintf(nomc,"%s",p2->info2.nom_mat);
                            sprintf(coefc,"%.2f",p2->info2.coef);
                            sprintf(moyc,"%.2f",moy);
                            sprintf(ch,"%s                        %s                            %s                         %s",matc,nomc,coefc,moyc);
                            SendMessage(hListBox,LB_ADDSTRING,j,ch);
                            j++;
                        }
                        p2=p2->suiv2;
                }
                    sprintf(ch2,"%.2f",moyenne_etudiant(LM,cinc));
                    sprintf(ch1,"%d",rang_etud(cinc));
                    // strcpy(ch1,"MOYENNE GENERALE:");
                    //strcat(ch1,ch2);
                    moyenne_etab=CreateWindow("LISTBOX","",
                            WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                            800,630,160,20,hwnd,NULL,hinst,NULL);
                    SendMessage(moyenne_etab,LB_ADDSTRING,j,ch2);
                    SendMessage(moyenne_etab,LB_ADDSTRING,j+1,ch1);
                    if(moyenne_etudiant(LM,cinc)>=10)
                        SendMessage(moyenne_etab,LB_ADDSTRING,j+1,"ADMIS");
                    else
                        SendMessage(moyenne_etab,LB_ADDSTRING,j+1,"REDOUBLE");
                    //moyenne_etab= CreateWindow("Edit",ch2,  WS_CHILD | WS_VISIBLE,800,630,90,20,hwnd,0,hinst,0);
                }
}
HWND moy_etablissement(HWND hwnd)
{
         liste_etud p1=LE;
         etudiant info;
        int test=0;

        int j=1;
        char ch[1000]=" ";

        while(p1)
                {
                    info=p1->info1;
                    strcpy(sectionc,info.section);
                    nv=info.etape;
                    strcpy(cinc,p1->info1.cin);
                    if(nb_etud_mat(cinc)!=nb_mat_section_nv(sectionc,nv)||nb_mat_section_nv(sectionc,nv)==0)
                        p1=p1->suiv1;

                    else
                    {
                        moy=moyenne_etudiant(LM,p1->info1.cin);
                        printf("%f",moy);
                        sprintf(cinc,"%s",p1->info1.cin);
                        sprintf(nomc,"%s",p1->info1.nom);
                        sprintf(prenom,"%s",p1->info1.prenom);
                        sprintf(sectionc,"%s",p1->info1.section);
                        sprintf(etapec,"%d",p1->info1.etape);
                        sprintf(moyc,"%.2f",moy);
                        sprintf(ch,"%s         %s        %s          %s        %s       %s",cinc,nomc,prenom,sectionc,etapec,moyc);
                        printf("%s\n",ch);
                        SendMessage(hListBox,LB_ADDSTRING,j,ch);
                        j++;
                        p1=p1->suiv1;
                    }
                }


}
HWND recherche_moyenne_etud_section(HWND hwnd)
{
    section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,20,150,150,hwnd,0,hinst,0);
    button_rech_sec_moy_etud= CreateWindow("Button","RECHERCHER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,680,20,120,35,hwnd,ID_B_RECH_SEC_moy_etud,hinst,0);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
}

HWND rech_sec_moyenne(HWND hwnd,char sect[])
{

        liste_etud p1=LE;
        etudiant info;
        int test=0;

        int j=1;
        char ch[1000]=" ";
    printf("SECTION %s\n",sect);
     hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);
        while(p1)
        {
            if(strcmp(sect,p1->info1.section)==0)
            {
                    info=p1->info1;
                    strcpy(sectionc,info.section);
                    printf("%s",sectionc);
                    nv=info.etape;
                    strcpy(cinc,p1->info1.cin);
                        if(nb_etud_mat(cinc)==nb_mat_section_nv(sect,nv)&&nb_mat_section_nv(sect,nv)!=0)
                        {
                            moy=moyenne_etudiant(LM,p1->info1.cin);
                            sprintf(cinc,"%s",p1->info1.cin);
                            sprintf(nomc,"%s",p1->info1.nom);
                            sprintf(prenom,"%s",p1->info1.prenom);
                            sprintf(sectionc,"%s",p1->info1.section);
                            sprintf(etapec,"%d",p1->info1.etape);
                            sprintf(moyc,"%.2f",moy);
                            sprintf(ch,"%s         %s        %s          %s        %s       %s",cinc,nomc,prenom,sectionc,etapec,moyc);
                         //   printf("%s\n",ch);
                            SendMessage(hListBox,LB_ADDSTRING,j,ch);
                            j++;
                        }
            }
                        p1=p1->suiv1;
                }
}

HWND etudiant_admis(HWND hwnd)
{
               hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,800,760,hwnd,NULL,hinst,NULL);
    int j=1;
    liste_etud p=LE;
    int test=0;
    etudiant info;
        while(p)
        { if(nb_etud_mat(p->info1.cin)==nb_mat_section_nv(p->info1.section,p->info1.etape)&&nb_mat_section_nv(p->info1.section,p->info1.etape)!=0)
           {
                    info=p->info1;
                    strcpy(sectionc,info.section);
                   // printf("%s",sectionc);
                    nv=info.etape;
                    strcpy(cinc,p->info1.cin);

                        if(moyenne_etudiant(LM,cinc)>=10)
                        {
                           // printf("%s",sectionc);
                            moy=moyenne_etudiant(LM,p->info1.cin);
                            printf("%f",moy);
                            sprintf(cinc,"%s",p->info1.cin);
                            sprintf(nomc,"%s",p->info1.nom);
                            sprintf(prenom,"%s",p->info1.prenom);
                            sprintf(sectionc,"%s",p->info1.section);
                            sprintf(etapec,"%d",p->info1.etape);
                            sprintf(moyc,"%.2f",moy);
                            sprintf(ch,"%s         %s        %s          %s        %s       %s",cinc,nomc,prenom,sectionc,etapec,moyc);
                         //   printf("%s\n",ch);
                            SendMessage(hListBox,LB_ADDSTRING,j,ch);
                            j++;
                        }
           }
                        p=p->suiv1;

        }
}
HWND etudiant_redouble(HWND hwnd)
{
    int j=1,test=0;
        liste_etud p=LE;
               hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,800,760,hwnd,NULL,hinst,NULL);


        while(p)
        {
            if(nb_etud_mat(p->info1.cin)==nb_mat_section_nv(p->info1.section,p->info1.etape)&&nb_mat_section_nv(p->info1.section,p->info1.etape)!=0)
           {
                strcpy(sectionc,p->info1.section);
                nv=p->info1.etape;
                strcpy(cinc,p->info1.cin);
                if(moyenne_etudiant(LM,p->info1.cin)<10)
                {
                    sprintf(etapec,"%d",p->info1.etape);
                    sprintf(matc,"%s",p->info1.cin);
                    sprintf(nomc,"%s",p->info1.nom);
                    sprintf(prenomc,"%s",p->info1.prenom);
                    sprintf(sectionc,"%s",p->info1.section);
                    sprintf(moyc,"%.2f",moyenne_etudiant(LM,matc));
                    while(strlen(nom)<21)strcat(nom," ");
                    while(strlen(section)<21)strcat(section," ");
                    sprintf(ch,"%s        %s           %s            %s         %s      %s",matc,nomc,prenomc,sectionc,etapec,moyc);
                    SendMessage(hListBox,LB_ADDSTRING,j,ch);
                    j++;
                }
           }
            p=p->suiv1;
        }
}
HWND recherche_admis_section_(HWND hwnd)
{
    section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,20,150,150,hwnd,0,hinst,0);
    button_rech_sec_admis= CreateWindow("Button","RECHERCHER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,680,20,120,35,hwnd,ID_admis_sec,hinst,0);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);

}
HWND recherche_redouble_section_(HWND hwnd)
{
    section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,20,150,150,hwnd,0,hinst,0);
    button_rech_sec_redouble= CreateWindow("Button","RECHERCHER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,680,20,120,35,hwnd,ID_redouble_sec,hinst,0);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);

}
HWND etudiant_admis_section(HWND hwnd,char sect[])
{

int j=1,test=0;
liste_etud p=LE;
hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);
        while(p)
        {
            if(strcmp(sect,p->info1.section)==0)
            {
            strcpy(sectionc,p->info1.section);
            nv=p->info1.etape;
            strcpy(cinc,p->info1.cin);

            if(moyenne_etudiant(LM,p->info1.cin)>=10&&strcmp(sect,sectionc)==0)
                {
                    sprintf(etapec,"%d",p->info1.etape);
                    sprintf(matc,"%s",p->info1.cin);
                    sprintf(nomc,"%s",p->info1.nom);
                    sprintf(prenomc,"%s",p->info1.prenom);
                    sprintf(sectionc,"%s",p->info1.section);
                    sprintf(moyc,"%.2f",moyenne_etudiant(LM,matc));
                    while(strlen(nom)<21)strcat(nom," ");
                    while(strlen(section)<21)strcat(section," ");
                    sprintf(ch,"%s        %s           %s            %s         %s      %s",matc,nomc,prenomc,sectionc,etapec,moyc);
                    SendMessage(hListBox,LB_ADDSTRING,j,ch);
                    j++;
                }
            }
            p=p->suiv1;
        }
}
HWND etudiant_redouble_section(HWND hwnd,char sect[])
{
        int j=1,test=0;
        liste_etud p=LE;

        hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);
        while(p)
        {
            if(strcmp(sect,p->info1.section)==0)
            {
            strcpy(sectionc,p->info1.section);
            nv=p->info1.etape;
            strcpy(cinc,p->info1.cin);

            if(moyenne_etudiant(LM,p->info1.cin)<10&&moyenne_etudiant(LM,p->info1.cin)>0)
            {
                    sprintf(etapec,"%d",p->info1.etape);
                    sprintf(matc,"%s",p->info1.cin);
                    sprintf(nomc,"%s",p->info1.nom);
                    sprintf(prenomc,"%s",p->info1.prenom);
                    sprintf(sectionc,"%s",p->info1.section);
                    sprintf(moyc,"%.2f",moyenne_etudiant(LM,matc));
                    while(strlen(nom)<21)strcat(nom," ");
                    while(strlen(section)<21)strcat(section," ");
                    sprintf(ch,"%s        %s           %s            %s            %s          %s",matc,nomc,prenomc,sectionc,etapec,moyc);
                    SendMessage(hListBox,LB_ADDSTRING,j,ch);
                    j++;
            }
            }
            p=p->suiv1;
        }
}
HWND recherche_mention_section_(HWND hwnd)
{
    section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,20,150,150,hwnd,0,hinst,0);
    button_rech_sec_mention= CreateWindow("Button","RECHERCHER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,680,20,120,35,hwnd,ID_mention_sec,hinst,0);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);

}
HWND etudiant_mention_section(HWND hwnd,char sect[])
{

int j=1,test=0;
liste_etud p=LE;
hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);
        while(p)
        {
             if(strcmp(sect,sectionc)==0)
             {
            strcpy(sectionc,p->info1.section);
            nv=p->info1.etape;
            strcpy(cinc,p->info1.cin);

            if(moyenne_etudiant(LM,p->info1.cin)>=14)

                {
                    sprintf(etapec,"%d",p->info1.etape);
                    sprintf(matc,"%s",p->info1.cin);
                    sprintf(nomc,"%s",p->info1.nom);
                    sprintf(prenomc,"%s",p->info1.prenom);
                    sprintf(sectionc,"%s",p->info1.section);
                    sprintf(moyc,"%.2f",moyenne_etudiant(LM,matc));
                    while(strlen(nom)<21)strcat(nom," ");
                    while(strlen(section)<21)strcat(section," ");
                    sprintf(ch,"%s        %s           %s            %s         %s      %s",matc,nomc,prenomc,sectionc,etapec,moyc);
                    SendMessage(hListBox,LB_ADDSTRING,j,ch);
                    j++;
                }
             }
            p=p->suiv1;
        }
}
HWND recherche_mention_etape_section(HWND hwnd)
{
    section_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,200,20,150,150,hwnd,0,hinst,0);
    etape_wind = CreateWindow("COMBOBOX", "", WS_CHILD|WS_VISIBLE|CBS_DISABLENOSCROLL|CBS_DROPDOWNLIST| WS_VSCROLL ,345,20,150,150,hwnd,0,hinst,0);
     button_rech_etape_sec_mention= CreateWindow("Button","RECHERCHER",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,680,20,120,35,hwnd,ID_mention_sec_etape,hinst,0);
    for (i=0;i<8;i++)SendMessage(section_wind,CB_ADDSTRING,0,sectioncombo[i]);
    for (i=0;i<5;i++)SendMessage(etape_wind,CB_ADDSTRING,0,etapecombo[i]);

}
HWND etudiant_mention_section_etape(HWND hwnd,char sect[],int ep)
{

int j=1,test=0;
liste_etud p=LE;
hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,620,320,hwnd,NULL,hinst,NULL);
        while(p)
        {
            if(strcmp(sect,sectionc)==0&&p->info1.etape==ep)
            {

            strcpy(sectionc,p->info1.section);
            nv=p->info1.etape;
            strcpy(cinc,p->info1.cin);

            if(moyenne_etudiant(LM,p->info1.cin)>=14)
                {
                    sprintf(etapec,"%d",p->info1.etape);
                    sprintf(matc,"%s",p->info1.cin);
                    sprintf(nomc,"%s",p->info1.nom);
                    sprintf(prenomc,"%s",p->info1.prenom);
                    sprintf(sectionc,"%s",p->info1.section);
                    sprintf(moyc,"%.2f",moyenne_etudiant(LM,matc));
                    while(strlen(nom)<21)strcat(nom," ");
                    while(strlen(section)<21)strcat(section," ");
                    sprintf(ch,"%s        %s           %s            %s         %s      %s",matc,nomc,prenomc,sectionc,etapec,moyc);
                    SendMessage(hListBox,LB_ADDSTRING,j,ch);
                    j++;
                }
            }
            p=p->suiv1;
        }
}
HWND etudiant_mention_etablissement(HWND hwnd)
{

int j=1,test=0;
liste_etud p=LE;

        while(p)
        {
            strcpy(cinc,p->info1.cin);
            if(moyenne_etudiant(LM,p->info1.cin)>=14)
                {
                    sprintf(etapec,"%d",p->info1.etape);
                    sprintf(matc,"%s",p->info1.cin);
                    sprintf(nomc,"%s",p->info1.nom);
                    sprintf(prenomc,"%s",p->info1.prenom);
                    sprintf(sectionc,"%s",p->info1.section);
                    sprintf(moyc,"%.2f",moyenne_etudiant(LM,matc));
                    while(strlen(nom)<21)strcat(nom," ");
                    while(strlen(section)<21)strcat(section," ");
                    sprintf(ch,"%s        %s           %s            %s         %s      %s",matc,nomc,prenomc,sectionc,etapec,moyc);
                    SendMessage(hListBox,LB_ADDSTRING,j,ch);
                    j++;
                }
            p=p->suiv1;
        }
}

HWND meilleur_etud_etablissement(HWND hwnd)
{

    char ch[1000]=" ",cin[9],nom[20],prenom[20],section[20],cincc[9],etape[2]=" ",dn[11]=" ";
            hListBox=CreateWindow("LISTBOX","",WS_VISIBLE|WS_CHILD|WS_DISABLED ,
                         350,270,170,180,hwnd,hinst,NULL,NULL);
           int j=1,test=0;
           etudiant info;
            liste_etud p=LE,max=premier_max(LE);
            //printf("%s",max->info1.cin);
        while(p)
        {
                   strcpy(sectionc,info.section);
                    nv=info.etape;
                   strcpy(cinc,p->info1.cin);
                    if(nb_etud_mat(cinc)==nb_mat_section_nv(sectionc,nv)&&nb_mat_section_nv(sectionc,nv)!=0)
                        if(moyenne_etudiant(LM,p->info1.cin)>=moyenne_etudiant(LM,max->info1.cin))
                            max=p;
                    p=p->suiv1;
        }

                    sprintf(etapec,"%d",max->info1.etape);
                    sprintf(matc,"%s",max->info1.cin);
                    sprintf(nomc,"%s",max->info1.nom);
                    sprintf(prenomc,"%s",max->info1.prenom);
                    sprintf(sectionc,"%s",max->info1.section);
                    sprintf(moyc,"%.2f",moyenne_etudiant(LM,matc));
                    while(strlen(nom)<21)strcat(nom," ");
                    while(strlen(section)<21)strcat(section," ");
                    sprintf(ch,"%s        %s           %s            %s         %s      %s",matc,nomc,prenomc,sectionc,etapec,moyc);
                    SendMessage(hListBox,LB_ADDSTRING,j,ch);

}

HWND notes_etud(HWND hwnd)
{

        cin_wind= CreateWindow("Edit", "",  WS_CHILD | WS_VISIBLE|ES_NUMBER,360,175,70,20,hwnd,0,hinst,0);
        but_notes_etud= CreateWindow("Button","|> BULLETIN",BS_PUSHBUTTON | WS_CHILD |WS_EX_TRANSPARENT| WS_VISIBLE|WS_BORDER,460,170,120,35,hwnd,ID_notes_etud,hinst,0);
}
HWND NOTES(HWND hwnd,char cinc[])
{
         liste_note p=LN,pds,pex;
         liste_etud p1;
         liste_mat p2=LM;
         etudiant info;


        int j=1;
        char ch[1000]=" ",ch3[20]=" ",exc[5]="",dsc[5]="";
        wchar_t  ch_mm[1000]=L"";

        p1=recherche_etud(LE,cinc);
        info=p1->info1;
        strcpy(sectionc,info.section);
        nv=info.etape;
        int test=0;

        if(nb_etud_mat(cinc)!=nb_mat_section_nv(sectionc,nv)||nb_mat_section_nv(sectionc,nv)==0)
                MessageBox(NULL,"L'etudiant n'a pas tous les notes dans tous les matieres" ,L"ECHEC",MB_OK);
        else
        {
            hListBox=CreateWindow(
                        "LISTBOX","",
                         WS_VISIBLE|WS_CHILD|LBS_NOTIFY|WS_VSCROLL|CBS_DISABLENOSCROLL,
                         106,125,700,480,hwnd,NULL,hinst,NULL);

            while(p2)
                {
                    if(strcmp(p2->info2.section,info.section)==0&&p2->info2.niveau==nv)
                        if(recherche_cin_mat(LN,cinc,p2->info2.code_mat,"DS")&&recherche_cin_mat(LN,cinc,p2->info2.code_mat,"EX"))
                        {
                            pds=recherche_cin_mat(LN,cinc,p2->info2.code_mat,"DS");
                            printf("%.f\t",pds->info3.note);
                            pex=recherche_cin_mat(LN,cinc,p2->info2.code_mat,"EX");
                             printf("%.f\t",pex->info3.note);
                            sprintf(matc,"%s",p2->info2.code_mat);
                            sprintf(nomc,"%s",p2->info2.nom_mat);
                            sprintf(dsc,"%.2f",pds->info3.note);
                            sprintf(exc,"%.2f",pex->info3.note);
                            sprintf(ch,"%s              %s                %s             %s",matc,nomc,dsc,exc);
                            SendMessage(hListBox,LB_ADDSTRING,j,ch);
                            j++;
                        }
                        p2=p2->suiv2;
                }

        }
}


void destroyallwindow ()
{

    DestroyWindow( but_notes_etud);
    DestroyWindow( button_rech_etape_sec_mention);
    DestroyWindow(button_rech_sec_mention);
    DestroyWindow(but_bulletin_etud);
    DestroyWindow( button_rech_sec_admis);
    DestroyWindow(button_rech_sec_redouble);
    DestroyWindow( button_rech_sec_moy_etud);
    DestroyWindow(but_tet_sup_note);
    DestroyWindow(but_rech_note_etudiant);
    DestroyWindow(but_rech_note_etudiant_ds);
    DestroyWindow(but_rech_note_etudiant_ex);
    DestroyWindow( but_modifier_nom_note);
    DestroyWindow(but_sup_note);
    DestroyWindow(but_queue_sup_note);
    DestroyWindow(but_pos_sup_note);
    DestroyWindow(button_save);
    DestroyWindow(but_queue_ajout_note);
    DestroyWindow(but_tet_ajout_note);
    DestroyWindow(but_pos_ajout_note);
    DestroyWindow(nature_wind);
    DestroyWindow(button_annuler);
    DestroyWindow(button_save_mat);
    DestroyWindow(button_annuler_mat);
    DestroyWindow(button_save_note);
    DestroyWindow(button_annuler_note);
    DestroyWindow(etape_wind);
    DestroyWindow(section_wind);
    DestroyWindow(nom_wind);
    DestroyWindow(prenom_wind);
    DestroyWindow(cin_wind);
    DestroyWindow(note_wind);
    DestroyWindow(but_modifier_nom_mat);
    DestroyWindow(but_modifier_coef_mat);
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
    DestroyWindow(hListBox);
    DestroyWindow(hListBoxcin);
    DestroyWindow(hListBoxnom);
    DestroyWindow(hListBoxprenom);
    DestroyWindow(hListBoxdn);
    DestroyWindow(hListBoxsection);
    DestroyWindow(hListBoxetape);
    DestroyWindow(but_etd_sup);
    DestroyWindow(but_etsecet_sup);
    DestroyWindow(button_rech_sec);
    DestroyWindow(button_rech_etape);
    DestroyWindow(button_rech_etape_section);
    DestroyWindow(but_pos_sup_mat);
    DestroyWindow(but_que_sup_mat);
    DestroyWindow(but_tet_sup_mat);
    DestroyWindow(but_sup_mat);
    DestroyWindow(but_tet_ajout_mat);
    DestroyWindow(but_queue_ajout_mat);
    DestroyWindow(but_pos_ajout_mat);
    DestroyWindow(but_pos_ajout_mat);
    DestroyWindow(but_rech_mat);
    DestroyWindow(button_rech_etape_mat);
    DestroyWindow( but_rech_matiere);
    DestroyWindow(image);
    DestroyWindow(moyenne_etab);
    DestroyWindow(hListBox1);

}


#endif // FORMULAIRE_H_INCLUDED
