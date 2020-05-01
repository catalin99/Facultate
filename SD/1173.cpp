int numarare(nod * p)
{
    if(!p || !p->urm)
        return 0;
    int numar=0;
    nod *q=p;
    while(q->urm)
    {
        if(q->info==q->urm->info)
            numar++;
        q=q->urm;
    }
    return numar;
}
