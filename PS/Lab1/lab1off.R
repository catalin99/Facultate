#ex1
v = c(46,33,39,37,46,30,48,32,49,35,30,48)
x=max(v)
y=min(v)
s=sum(v)
l=length(v)
factura=0
counter=0
for(i in 1:l)
{
  if(v[i]>40) factura=factura+1
  if(v[i]<35) counter=counter+1
}
proc=counter*100/l
print(x)
print(y)
print(s)
print(factura)
print(proc)
#ex2a
v=c(15,23,49,23,55)
ex2=function()
{
  print(log(v,2.71))
}

#ex2b
v=c(15,23,59,61,14)
ex2b=function(i)
{
  y=(v[i]-max(v))/min(v)
  return (y)
}
ex2b(3)
#ex3
citeste_vector=function(file)
{
  x=scan(file)
  return (x)
}
citeste_vector("vector.txt")

#ex4
pmax=function(n,p)
{
  x=(dbinom(0:n,n,p))
  barplot(x, space = 0, main="Trec la PS?", ylab = "Mi-e foame")
}
pmax(25,0.5)

#ex5
bmax=function(n,p)
{
  x=(dbinom(0:n,n,p))
  y=max(x);
  print (y)
}
bmax(30,0.7)

#ex6
vector_p=function(p,n)
{
  print(dpois(0:n,p))
}
vector_p(3,20)

#ex7
ex7=function(file)
{
y = read.table(file, header = T)
x1 = y[['AA']]
x2 = y[['BB']]
plot(x1,x2)
}
ex7('data.txt')