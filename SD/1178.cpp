void sterge(nod * & p)
{
    if(!p)
        return;
    if(p->info%2==0)
        while(p->info%2==0)
            {
                nod *q=p;
                p=p->urm;
                delete q;
            }
    nod*prec=p;
    nod*q=p->urm;
    while(q)
    {
        if(q->info%2==0)
        {
            prec->urm=q->urm;
            delete(q);
            q=prec->urm;
        }
        else
        {
            prec=q;
            q=q->urm;
        }
    }
}
