struct node
{
    char key;
    node *next;
};

//Actualizare prim si ultim
bool palindrom(node *l)
{
    if(!l)
        return false;
    if(!l->next)
        return true;
    node *q=l;
    node *ultim;
    while(q->next)
        q=q->next;
    ultim=q;
    q=l;
    if(q->key!=ultim->key)
        return false;
    node *prim=q;
    while(prim!=ultim)
    {
        prim=prim->next;
        q=prim;
        if(q!=ultim)
            while(q->next!=ultim)
                q=q->next;
        ultim=q;
        if(prim->key!=ultim->key)
            return false;
    }
    return true;
}

//vector de caractere
bool palindrom(node *l)
{
    node *q=l;
    int nr=0;
    char s[10000];
    while(q)
    {
        s[nr]=q->key;
        nr++;
        q=q->next;
    }
    //s[nr]='\0';
    int i=0, j=nr-1;
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

//lista noua creata ca o stiva.
bool palindrom(node *l)
{
    node *q=l;
    node *lrev=NULL;
    while(q)
    {
        node *s=new node;
        s->key=q->key;
        if(!lrev)
        {
            s->next=NULL;
            lrev=s;
        }
        else
        {
            s->next=lrev;
            lrev=s;
        }
        q=q->next;
    }
    q=l;
    while(q)
    {
        if(q->key!=lrev->key)
            return false;
        q=q->next;
        lrev=lrev->next;
    }
    return true;
}
