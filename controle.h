#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED
int valide(date d)
{
   int jmax;
   switch(d.m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:jmax=31;
        case 4:
        case 6:
        case 9:
        case 11:jmax=30;
        case 2:if(d.m%4)
            jmax=28;
            else
                jmax=29;
    }
    return (jmax>=d.j&&d.m>=1&&d.m<=12&&d.a>=1970&&d.j>=1);
}
int verif_chaine( char ch[])
{
    int i;
    for(i=0;ch[i];i++)
        if(ch[i]>"Z"||ch[i]<"A"||ch[i]<"a"||ch[i]>"z")
            return 0;
    return 1;
}
int verif_cin(char cin[])
{
    int i;
   if(strlen(cin)!=8)
        return 0;
   else
   {
       for(i=0;cin[i];i++)
       if(cin[i]>'9'&&cin[i]<'0')
            return 0;
   }
   return 1;
}
int verif_section(char sec[])
{
    if(strcmp(sec,"LA INFO")&&strcmp(sec,"LF INFO")&&strcmp(sec,"LA STIC")&&strcmp(sec,"LF STIC")&&strcmp(sec,"LF MATH"))
        return 0;
    return 1;
}
int verif_code(char code[])
{
   int i;
   if(strlen(code)!=3)
        return 0;
   else
   {
       for(i=0;code[i];i++)
        if(code[i]>'9'||code[i]<'0'||code[i]>'Z'||code[i]<'A')
            return 0;
   }
   return 1;
}
int verif_nom_mat( char ch[])
{
    int i=0;
    while(!ch[i])
    {
        if(ch[i]>'Z'||ch[i]<'A'||ch[i]<'a'||ch[i]>'z')
            return 0;
        i++;
    }
    return 1;
}
int verif_note(float c)
{
    if(c>20||c<0)
        return 0;
    return 1;
}
int verif_coef(float c)
{
    if(c<=0)
        return 0;
    return 1;
}

#endif // CONTROLE_H_INCLUDED
