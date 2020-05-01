void inserare(nod * p, nod * q, int x)
{
    if(!p)
        return;
    if(q)
    {
        nod*r=new nod;
        r->info=x;
        r->urm=q->urm;
        q->urm=r;
    }
}
