void inserare(nod * & p, nod * q, int x)
{
    nod *nou=new nod;
    nou->info=x;
    nou->urm='\0';
    if(p==q)
    {
        nou->urm=p;
        p=nou;
        return;
    }
    nod *idkname=p;
    while(idkname->urm!=q)
        idkname=idkname->urm;
    nou->urm=idkname->urm;//nou->urm=q
    idkname->urm=nou;
    return;
}
