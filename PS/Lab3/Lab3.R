z=matrix(c(1,2,3,4,5,6,0.15,0.3,0.15,0.1,0.25,0.05), nrow= 2, ncol= 6, byrow=T)

var_aleatoare=function(f)
{
  randvar=runif(1,0,1)
  print(randvar)
  aux=0;
  for(i in 1:6){
    if(randvar>=aux && randvar<(aux+f[2,i])){
      print(f[1,i])
    }
    aux=aux+f[2,i]
  }
}

var_aleatoare(z)