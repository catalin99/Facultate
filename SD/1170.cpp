void adaugareInainte(nod * & p , int x)
{
    nod *q=new nod;
    q->info=x;
    q->urm='\0';
    if(p=='\0')
        p=q;
    else
    {
        q->urm=p;
        p=q;
    }
}
