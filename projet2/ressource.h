const char *aacombo[] = { "1980", "1981", "1982","1983","1984","1985","1986","1987","1988","1989","1990","1991","1992","1993",
                        "1994","1995","1996","1997","1998","1999","2000" };
const char *jjcombo[] = { "1", "2","3","4","5","6","7","8","9","10","11","12","13",
                        "14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31" };
const char *mmcombo[] = { "1", "2","3","4","5","6","7","8","9","10","11","12"};
const char *etapecombo[] = { "1", "2","3"};
const char *sectioncombo[] = { "LA INFO","LA STIC","LF INFO","LF STIC","LF MATH"};
const char *poscombo[]={"2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60","61"};

char tex[50];
int ok=0,i;
HWND static_label;
HWND console,cin_wind,nom_wind,prenom_wind,section_wind,etape_wind,coef_wind, mat_wind,nom_mat_wind,button_save,button_annuler,button_save_mat,button_annuler_mat,hComboBox1,j_wind,m_wind,a_wind, but_tet_ajout, but_que_ajout, but_pos_ajout,but_tet_sup, but_que_sup, but_pos_sup,ajpos,pos_wind;
char matriculec[50],nomc[50],prenomc[50],dnc[50],sectionc[50],etapec[50];
HWND bout_rec;
HWND bout_enrg;
HWND image;

