#Problema E2
z_test=function(a,n,z_score,tip)
{#Testul Z pentru diferentta mediilor unor populattii
  #cu dispersii cunoscute
  if(tip==0)
  {
    #ipoteza simetrica
    z_critical=qnorm(1-a/2,0,1)
    if(abs(z_score)<abs(z_critical))
      print("Ipoteza nula se accepta!")
    else
      print("Ipoteza nula se respinge!")
  }
  else
  {
    if(tip==1)
    {
      #ipoteza asimetrica la stanga
      z_critical=qnorm(a,0,1)
      if(z_score>z_critical)
        print("Ipoteza nula se accepta!")
      else
        print("Ipoteza nula se respinge!")
    }
    else
    {
      #ipoteza asimetrica la dreapta
      z_critical=qnorm(1-a,0,1)
      if(z_score<z_critical)
        print("Ipoteza nula se accepta!")
      else
        print("Ipoteza nula se respinge!")
    }
  }

  return (c(z_score,z_critical))
}
print("Pentru nivelul de semnificatie 1%:")
z_test(0.01,36,-2.35,0)
print("Pentru nivelul de semnificatie 5%:")
z_test(0.05,36,-2.35,0)

#E4

z_test_means=function(a,n1,n2,x1,x2,s1,s2,tip)
{
  z_score=(x1-x2)/(sqrt(s1^2/n1)+sqrt(s2^2/n2))
  if(tip==0)
  {
    #ipoteza simetrica
    z_critical=qnorm(1-a/2,0,1)
    if(abs(z_score)<abs(z_critical))
      print("Ipoteza nula se accepta!")
    else
      print("Ipoteza nula se respinge!")
  }
  else
  {
    if(tip==1)
    {
      #ipoteza asimetrica la stanga
      z_critical=qnorm(a,0,1)
      if(z_score>z_critical)
        print("Ipoteza nula se accepta!")
      else
        print("Ipoteza nula se respinge!")
    }
    else
    {
      #ipoteza asimetrica la dreapta
      z_critical=qnorm(1-a,0,1)
      if(z_score<z_critical)
        print("Ipoteza nula se accepta!")
      else
        print("Ipoteza nula se respinge!")
    }
  }

  return (c(z_score,z_critical))
}
print("Pentru nivelul de semnificatie 1%:")
z_test_means(0.01,155,150,15,14.5,0.75,0.78,0)
print("Pentru nivelul de semnificatie 5%:")
z_test_means(0.05,155,150,15,14.5,0.75,0.78,0)

#E5

f_test=function(n1,s1,n2,s2,alfa,tip)
{
  f=s1^2/s2^2
  if(tip==0)  
  {
    #ipoteza simetrica
    Fs_critical=qf(alfa/2,n1-1,n2-1)
    Fd_critical=qf(1-alfa/2,n1-1,n2-1)
    if(f<=Fd_critical && f>=Fs_critical)
      print("Ipoteza nula NU a fost respinsa!")
    else
      print("Ipoteza nula a fost respinsa!")
    rezultat=vector()
    rezultat[1]=f
    rezultat[2]=Fs_critical
    rezultat[3]=Fd_critical
  }
  else
  {
    #ipoteza asimetrica la dreapta
    F_critical=qf(1-alfa,n1-1,n2-2)
    if(f<=F_critical)
      print("Ipoteza nula NU a fost respinsa!")
    else
      print("Ipoteza nula a fost respinsa!")
    rezultat=vector()
    rezultat[1]=f
    rezultat[2]=F_critical
  }
  return (rezultat)
}

T_test_means=function(a,n1,n2,s1,s2,x1,x2,m0,tip)
{
  el_curent=f_test(n1,s1,n2,s2,a,0)
  if(el_curent[1]>=el_curent[2] && el_curent[1]<=el_curent[3])
    ok=1  #dispersiile sunt egale
  else ok=0   #dispersiile nu sunt egale
  if(ok==0)
  {
    t_score=(x1-x2-m0)/sqrt(s1^2/n1 + s2^2/n2)
    df=min(n1-1,n2-1)
  }
  else
  {
    s=((n1-1)*s1^2+(n2-1)*s2^2)/(n1+n2-2)
    t_score=(x1-x2-m0)/sqrt(s/n1 + s/n2)
    df=n1+n2-2
  }
  if(tip==0)    #ipoteza simetrica
  {
    
    t_critical=-qt(a/2,df)
    if(abs(t_score)>abs(t_critical))
      print("Ipoteza nula a fost acceptata!")
    else
      print("Ipoteza nula a fost respinsa!")
  }
  else if(tip==1)    #ipoteza asimetrica la stanga
  {
    
    t_critical=qt(a,df)
    if(t_score>t_critical)
      print("Ipoteza nula a fost acceptata!")
    else
      print("Ipoteza nula a fost respinsa!")
  }
  else if(tip==2)    #ipoteza asimetrica la dreapta
  {
    
    t_critical=qt(1-a,df)
    if(t_score<t_critical)
      print("Ipoteza nula a fost acceptata!")
    else
      print("Ipoteza nula a fost respinsa!")
  }
  
  return(c(t_score,t_critical))
}

T_test_means(0.05,66,68,1.2,1.1,21,20,0,0)
