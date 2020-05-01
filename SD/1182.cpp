void inserare(nod * & p)
{
    if(!p)
        return;
    nod *prec=NULL;
    nod *parc=NULL;
    int ok=0;
    if(!(p->info%2))
    {
        nod *q=new nod;
        q->info=2*p->info;
        q->urm=p;
        p=q;
        ok=1;
    }
    if(!ok)
    {
        prec=p;
    	parc=p->urm;
    }
    else
    {
        prec=p->urm;
        parc=p->urm->urm;
    }
    while(parc)
    {
        if(!(parc->info%2))
        {
            nod *q=new nod;
            q->info=2*parc->info;
            q->urm=parc;
            prec->urm=q;
            prec=prec->urm;
        }
        parc=parc->urm;
        prec=prec->urm;
    }
}
