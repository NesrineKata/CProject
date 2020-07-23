const char *aacombo[] = { "1970","1971","1972","1973","1974","1974","1975","1976","1976","1977","1978","1979","1980", "1981", "1982","1983","1984","1985","1986","1987","1988","1989","1990","1991","1992","1993",
                        "1994","1995","1996","1997","1998","1999","2000" };
const char *jjcombo[] = { "1", "2","3","4","5","6","7","8","9","10","11","12","13",
                        "14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31" };
const char *mmcombo[] = { "1", "2","3","4","5","6","7","8","9","10","11","12"};
const char *etapecombo[] = { "1", "2","3","4","5"};
const char *naturecombo[] = { "DS", "EX"};
const char *sectioncombo[] = { "LA INFO","LA STIC","LF INFO","LF STIC","LF MATH","ING ELECTRONIQUE","MAST.PRO GL","MAST.RECH ELECTRONIQUE"};
char *poscombo[8];
char message[100];
#define texte(t,message,x,y,l,h) t = CreateWindow("STATIC",message,WS_VISIBLE | WS_CHILD,x,y,l,h,hwnd,NULL,NULL,NULL);
char txt[50];
int ok=0,i;
HWND static_label;
HWND chaine,t,console,cin_wind,nom_wind,prenom_wind,section_wind,hListBox,hListBox1,etape_wind,coef_wind,note_wind,nature_wind
, but_etd_sup,but_etsecet_sup,mat_wind,nom_mat_wind,button_save,button_annuler,button_save_mat,
button_rech_etape,button_rech_etape_section
,button_annuler_mat,button_save_note,button_annuler_note,hComboBox1,j_wind,m_wind,a_wind,
but_tet_ajout,but_rech_mat, but_que_ajout, but_pos_ajout,but_tet_sup, but_que_sup, but_pos_sup,ajpos,pos_wind,hListBoxcin,hListBoxnom,hListBoxprenom,hListBoxdn
,hListBoxsection,hListBoxetape,button_rech_sec,but_tet_ajout_mat,but_queue_ajout_mat,but_pos_ajout_mat,but_que_sup_mat,but_tet_sup_mat,
but_pos_sup_mat,but_sup_mat,but_modifier_coef_mat,but_modifier_nom_mat;
char cinc[50]=" ",nomc[50]=" ",prenomc[50]=" ",dnc[50]=" ",sectionc[50]=" ",etapec[4]=" ",notec[6]=" ",naturec[3]=" " ,jc[3]=" ",mc[3]=" ",ac[5]=" ",posc[10]=" ",coefc[6]=" ",matc[4]=" ";
HWND bout_rec,but_rech_note_etudiant_ds,but_rech_note_etudiant_ex,but_bulletin_etud,moyenne_etab, button_rech_sec_moy_etud;
HWND bout_enrg,button_rech_sec_mat,button_rech_etape_mat, but_rech_matiere,but_tet_ajout_note,but_queue_ajout_note,
but_pos_ajout_note,but_tet_sup_note,but_queue_sup_note,but_pos_sup_note,but_sup_note, but_modifier_nom_note,
but_rech_note_etudiant,button_rech_sec_redouble, button_rech_sec_admis,button_rech_sec_mention,  button_rech_etape_sec_mention,but_notes_etud;
HWND image;
CHAR lpText[256];
int pos,nv,en_m=2,en_e=2,en_n=2;
;
float coef,nt,moy;
char ch[1000]=" ",sect[21],cin[9]=" ",nom[20]=" ",prenom[20]=" ",section[20]=" ",etape[2]=" ",dn[11]=" ",moyc[10]="",ch1[10]="",ch2[10]="";
int la1info=0,la2info=0,la3info=0,lf1info=0,lf2info=0,lf3info=0,la1stic=0,la2stic=0,la3stic=0,lf1stic=0,lf2stic=0,
lf3stic=0,lf1math=0,lf2math=0,lf3math=0;
char *ch_m;
