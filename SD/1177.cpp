void sterge(nod * & p, nod * q)
{
    if(p==q)
    {
        p=p->urm;
        return;
    }
    nod *s=p;
	while(s!='\0')
    {
        if(s->urm==q)
        {
            s->urm=s->urm->urm;
            delete(q);
            break;
        }
        s=s->urm;
    }
}
