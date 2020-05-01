# B1
quicksort=function(v)
{
  if(length(v)>1)
  {
    x=sample(1:length(v),1);
    pivot=v[x];
    left=1;
    right=length(v);
    while(left<=right)
    {
      while(v[left]<pivot)
        left=left+1;
      while(v[right]>pivot)
        right=right-1;
      if(left<=right)
      {
        aux=v[left];
        v[left]=v[right];
        v[left]=aux;
        left=left+1;
        right=right-1;
      }
    }
    return (c(quicksort(v[v<pivot]),pivot,quicksort(v[v>pivot])));
  }
  return (v);
}

x=c(17,9,15,31,32,-10,1,14,39,22)
quicksort(x)

# B2

Rand_Min_Cut=function(G)
{
  while(nrow(G)>2)
  {
    z=sample(1:nrow(G),2,replace=T);
    while(G[z[1],z[2]]==0)
    {
      z=sample(1:nrow(G),2,replace=T);
    }
    for(j in 1:ncol(G))
    {
      if(G[z[2],j]>0&j!=z[1])
      {
        G[z[1],j]=G[z[1],j]+G[z[2],j];
        G[j,z[1]]=G[z[1],j];
      }
    }
    G=G[-z[2],];
    G=G[,-z[2]];
  }
  return (G);
}

y=c(0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0)
M=matrix(y,6,6)
Rand_Min_Cut(M)