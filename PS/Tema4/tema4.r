#D1

zconfidence_interval=function(n,media,alfa,varianta)
{
  deviatieStandard = sqrt(varianta)
  critical_z = qnorm(1-alfa/2,0,1)
  a = media - critical_z * deviatieStandard/sqrt(n)
  b = media + critical_z * deviatieStandard/sqrt(n)
  
  return(c(a,b))
}

zconfidence_interval(8, 2.75, 0.01, 0.25) #afla=0.01=>incredere 99%
#masurat de 8 ori
#media masuratorilor este 2.75
#deviatia standard=sqrt din varianta (0.5)

#D3

test_proportion = function(n,succese,alfa,p0,tip) #testul z asupra proportiilor
{#se numara succesele din n incercari
  pPrim = succese / n
  z_score = ( pPrim - p0 ) / sqrt( p0*(1-p0) / n)
  
  if(tip == 1) #Ipoteza asimetrica la dreapta
    {
    critical_z = qnorm(1-alfa,0,1) #x, mean, dev standard
    if(z_score < critical_z)
      print("Se accepta ipoteza nula")
    else 
      print("Se respinge ipoteza nula")
    }
  if(tip == 2) #Ipoteza asimetrica la stanga
    {
    critical_z = qnorm(alfa,0,1)
    if(z_score > critical_z)
      print("Se accepta ipoteza nula")
    else 
      print("Se respinge ipoteza nula")
    }
  if(tip == 3) #Ipoteza simetrica
    {
    critical_z = -qnorm(alfa/2,0,1)
    if(abs(critical_z) > abs(z_score))
      print("Se accepta ipoteza nula")
    else 
      print("Se respinge ipoteza nula")
    }

  return(c(critical_z, z_score))
}
print("Pentru alfa=0.01")
test_proportion(112, 14, 0.01, 0.1, 1)
#112 clienti, 14 nemultumiti, 0.01/0.05 nivel de semnificatie, 
#0.1=10% clienti numultumiti initial
print("Pentru alfa=0.05")
test_proportion(112, 14, 0.05, 0.1, 1)