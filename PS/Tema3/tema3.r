#C1
#LV-Always give the correct answer
#time-variaza pentru acelasi input, mare
#MC-poate sa genereze rezultate gresite !!!
#time-fix, mai mic decat lv
Volum_Elipsoid=function(n) #trebuie sa rezolvam folosind monte carlo
{             #si sa comparam rezultatul generat de algoritm cu cel corect (eroarea)
  N_C=0;
  for(i in 1:n)
  {
    x=runif(1,-2,2);
    y=runif(1,-3,3);
    z=runif(1,-4,4);
    if((x*x/4)+(y*y/9)+(z*z*z/16)<=1)
      N_C=N_C+1;
  }
  return (8*6*4*N_C/n);
}

CalculErori = function(valMC, valActual)
{
  errAbs = abs(valMC - valActual)
  errRel = errAbs/valActual
  
  return(errRel)
}

PI=3.14159265358
VolumActual=PI*2*3*4*4/3
print("Volumul elipsoidului actual este:")
print(VolumActual)

v1 = Volum_Elipsoid(10000)
print(v1)
print(CalculErori(v1,VolumActual))

v2 = Volum_Elipsoid(20000)
print(v2)
print(CalculErori(v2,VolumActual))

v3 = Volum_Elipsoid(50000)
print(v3)
print(CalculErori(v3,VolumActual))

#C3.a)

Integrala1 = function(n) #monte carlo+comparatie cu rezultat corect
{
  suma = 0
  
  for(i in 1:n)
  {
    x = runif(1,0,1)
    suma = suma + (cos(50*x) + sin(20*x))^2
  }
  
  return (suma/n)
}

Integrala1Actual = 0.9652
print(Integrala1Actual)
print(Integrala1(10000))
#C3.b)

Integrala2 = function(n)
{
  suma = 0
  
  for(i in 1:n)
  {
    x = runif(1,0,3)
    suma = suma + (x^3)/(x^4+1)
  }
  
  return (3*suma/n)
}

Integrala2Actual = 1.10168
print(Integrala2Actual)
print(Integrala2(100000))

#C4

EstimareTimpMediu = function(n)
{
  suma = 0
  for(i in 1:n)
  {
    server1 = rgamma(1,shape=5,scale=3) #generare random pentru gama in functie de shape si scale
    server2 = rgamma(1,shape=7,scale=5) #shape, scale - distributia
    server3 = rgamma(1,shape=5,scale=2) 
    x = rexp(1,1) #distributia exponentiala
    y = runif(1,0,1)#distributia uniforma
    
    if(y >= 0.5) #directionam catre primul server
    {
      suma = suma + server1
    }
    else
    {
      if(y < 0.3) #directionam catre celelalte
      {
        suma = suma + server2
      }
      else
      {
        suma = suma + server3
      }
    }
    suma = suma + x #adunam si latenta dintre client si server
  }
  return (suma/n);
}

print(EstimareTimpMediu(1000))

#C7

ConturiInfectate = function()
{
  
  maxInfect = 1
  countInfect = 1
  countZile = 1
  while(countInfect > 0 & countInfect < 20)
  {
    
    if(countZile >= 2)
    {
      countInfect = countInfect - 5 #scadem conturile infectate
    }
    
    countCurat = 20 - countInfect  #actualizam valoarea conturilor "curate"
    if(countCurat > 0)
    {
      for(i in 1:countCurat)
      {
        x = runif(1,0,1)
        if(x <= 0.25)
        {
          countInfect = countInfect + 1 #raspandirea malware-ului cu probabilitatea de 0.25
        }
      }
    }
    
    if(maxInfect < countInfect) 
    {
      maxInfect = countInfect
    }
    
    countZile = countZile + 1
  }
  return(maxInfect)
}

print(ConturiInfectate())

#a)

InfectCelPutinOdata = function(n)
{
  
  suma = 0
  
  for(i in 1:n)
  {
    j=ConturiInfectate()
    if(j >= 1){
      suma = suma + j
    }
  }
  return(suma/n)
}

print(InfectCelPutinOdata(1000))

#b)

InfectToateConturile = function(n){
  suma = 0
  for(i in 1:n){
    if(ConturiInfectate() == 20){
      suma = suma + 200
    }
  }
  return(suma/n)
}

print(InfectToateConturile(10000))

#c)

N_minim = function(epsilon,n)
{ 
  alfa = 1-n
  z = qnorm(alfa/2)
  rez = (1/4)*(z/epsilon)*(z/epsilon)
  return(rez)
}

nrSimulari = 1 + N_minim(0.01, 0.99) 
print(nrSimulari)
print(InfectToateConturile(nrSimulari))

