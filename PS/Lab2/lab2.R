#seminar8


x=c(11,14,21,32,17,24,21,35,52,44,21,28,36,49,41,19,20,34,37,29)
stem(x)
I.1
    sample=scan("sample1.txt")
    stem(sample)

  2.
    tablou=read.csv("unemploy2012.csv",header=T,sep = ';')
    rate=tablou[['rate']]
    interval=c(0,4,6,8,10,12,14,30)
    hist(rate,breaks=interval,right=T,freq=F)
    
  #3.
    tablou=read.csv("life_expect.csv",header=T,sep=',')
    barbat=tablou[['male']]
    femeie=tablou[['female']]
    intervale_b=7
    intervale_f=7
    hist(barbat,breaks=intervale_b,right=F,freq=7,col="green")
    hist(femeie,breaks=intervale_f,right=F,freq=7,col="pink")
    
    II.1.
    doc=scan("sample1.txt")
    mean(doc)
    median(doc)
    
    2.
    tablou=read.csv("life_expect.csv",header=T,sep=",")
    life_man=tablou[['male']]
    life_female=tablou[['female']]
    
    mean(life_man)
    median(life_man)
    
    mean(life_female)
    median(life_female)
    
    
    3.
    module = function(esantion)
    {
      a=rle(sort(esantion))
      maxim=max(a$lengths) 
      aux=vector()  
      k=0
      for(i in 1:length(a$values))
      {
        if(a$lengths[i]==maxim)
        {
          k=k+1
          aux[k]=a$values[i]
        }
      }
      return (aux)
    }
    
    exemplu3 = c(6,6,6,5,3,8,5,3,3,7)
    module(exemplu3)
    
    #III. 1
    outliers_mean=function(esantion)
    {
      m=mean(esantion)
      s=sd(esantion)
      new=vector()
      j=0
      for (i in 1:length(esantion))
      {
        if ((esantion[i]<m-2*s) || (esantion[i]>m+2*s))
        {
          j=j+1
          new[j]=esantion[i]    
        }
      }
      return (new)
    }
    x=c(1,91,38,72,13,27,11,85,5,22,20,19,8,17,11,15,13,23,14,17)
    outliers_mean(x)
    
    # III. 2
    outliers_iqr=function(esantion)
    {
      new_vector=vector()
      j=0
      IQR=as.vector(quantile(esantion))[4]-as.vector(quantile(esantion))[2]
      Q1=as.vector(quantile(esantion))[2]
      Q3=as.vector(quantile(esantion))[4]
      for (i in 1:length(esantion))
      {
        if (  (esantion[i]<Q1-1.5*IQR  ) || (esantion[i]>Q3+1.5*IQR))
        {
          j=j+1
          new_vector[j]=esantion[i]    
        }
      }
      return (new_vector)
    }
    x=c(1,91,38,72,13,27,11,85,5,22,20,19,8,17,11,15,13,23,14,17)
    outliers_iqr(x)
    
    # III. 3
    
    ex3= function(esantion)
    {
      summary(esantion)
    }
    
    sample = scan("sample2.txt")
    ex3(sample)
    