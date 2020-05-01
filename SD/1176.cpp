void sterge(nod * p, nod * q)
{
    nod *copie;
    if(q->urm)
    {
        copie=q->urm;
        q->urm=q->urm->urm;
        delete(copie);
    }
}
