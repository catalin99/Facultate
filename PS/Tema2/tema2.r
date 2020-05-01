#B1 QuickSort

QuickSort=function(vect)
{
  if(length(vect)<=1)
    return(vect);
  
  random = sample(1:length(vect),1)
  pivot = vect[random] #alegem random pivotul din vector
  right = length(vect)
  left = 1
  
  while(left<right) 
  {
      while(vect[left] < pivot) #daca pivot>stanga, stanga creste
          left = left + 1
      while(vect[right] > pivot)#daca pivot>dreapta, dreapta creste
          right = right - 1
    if(left <= right)
    {
      aux = vect[left]
      vect[left] = vect[right]
      vect[right] = aux #interschimbare intre stanga si dreapta
      left = left + 1
      right = right - 1
    }
  }
  
  return(c(QuickSort(vect[vect<pivot]),vect[vect==pivot],QuickSort(vect[vect>pivot])))
}

sir=c(25,-1,-2,-1,15,0,19,5)
QuickSort(sir)

#B2
KargerAlg = function(G) #dam ca parametru o matrice G
{
  while(nrow(G)>2)  #eliminam muchii pana graful mai are doar 2
  {
    muchieRand = sample(1:nrow(G), 2, replace=T);
    while(G[muchieRand[1], muchieRand[2]] == 0) #Selectam 2 noduri care au muchii intre ele
    {
      muchieRand = sample(1:nrow(G), 2, replace=T);
    }
    for(i in 1:ncol(G)) #combinam cele 2 noduri ramase intr-un multi-graf #contractare
    {
      if(G[muchieRand[2], i] > 0 & i != muchieRand[1])
      {
        G[muchieRand[1], i] = G[muchieRand[1],i] + G[muchieRand[2],i];
        G[i, muchieRand[1]] = G[muchieRand[1],i];
      }
    }
    G = G[-muchieRand[2], ]; #eliminam al doilea nod(selectat aleatoriu) din graf
    G = G[, -muchieRand[2]];
  }
  return (G[1,2]); #numarul minim de taieturi pentru a avea 2 componente conexe disjuncte
}

matrice = matrix(c(0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0), 6, 6)#matricea de adiacenta din problema
KargerAlg(matrice)


