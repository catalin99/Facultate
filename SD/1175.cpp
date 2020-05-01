int suma(nod * p)
{
    if(!p || !p->urm || !p->urm->urm)
        return 0;
    int suma=0;
    nod *prec=p;
    nod *actual=p->urm;
    while(actual->urm)
    {
        if(actual->info%2)
            if(!(prec->info%2) && !(actual->urm->info%2))
            {
                suma+=actual->info;
                prec=prec->urm;
                actual=actual->urm;
            }
        prec=prec->urm;
        if(actual->urm)
            actual=actual->urm;
    }
    return suma;
}
