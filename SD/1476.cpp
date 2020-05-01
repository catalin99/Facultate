void sortareCrescator(nod *&prim)
{
    nod*q=prim;
    while(q->urm)
    {
        nod*s=q->urm;
        while(s)
        {
            if(q->info>s->info)
            {
                int a=q->info;
                q->info=s->info;
                s->info=a;
            }
            s=s->urm;
        }
        q=q->urm;
    }
}
