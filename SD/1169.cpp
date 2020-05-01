struct nod{
    int info;
    nod * urm;
};

void afisare(nod * p)
{
    nod *q=p;
    while(q)
    {
        cout<<q->info<<' ';
        q=q->urm;
    }
    return;
}
