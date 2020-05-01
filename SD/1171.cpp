void stergePrimul(nod * & p)
{
    if(p=='\0')
        return;
    if(p->urm=='\0')
    {
        p=NULL;
        return;
    }
    nod *q=p;
    p=p->urm;
    delete(q);
    return;
}
