void inserare(nod * p)
{
    if(!p)
        return;
    nod*q=p;
    while(q)
    {
        if(q->info%2==0)
        {
            nod *elt=new nod;
            elt->info=q->info*2;
            elt->urm=q->urm;
            q->urm=elt;
            q=q->urm;
        }
        q=q->urm;
    }
    return;
}
