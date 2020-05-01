int numarare(nod * p)
{
    int nr=0;
    while(p)
    {
        nr++;
        p=p->urm;
    }
    return nr;
}
