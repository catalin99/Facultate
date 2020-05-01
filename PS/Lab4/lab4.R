eroare_absoluta = function(given,expected){
  if(given>expected)return(given-expected)
  else return(expected-given)
}
eroare_relativa = function(given,expected){
  return(eroare_absoluta(given,expected)/expected)
}
N_minim = function(marja_eroare,probabilitate){
  alfa = 1-probabilitate
  z = qnorm(alfa/2)
  epsilon = marja_eroare
  n_min = (1/4)*(z/epsilon)^2
  return(as.integer(n_min))
}
# Estimarea volumelor si ariilor
# exemplu
disc_area = function(N)
{
  N_C = 0;
  for(i in 1:N)
  {
    x = runif(1, -1, 1);
    y = runif(1, -1, 1);
    if(x*x + y*y <= 1)
      N_C = N_C + 1;
  }
  return(4*N_C/N);
}
disc_area(10000)
disc_area(50000)
disc_area(100000)
# 1.
volum_sfera = function(N)
{
  N_C = 0
  for(i in 1:N)
  {
    x = runif(1, -1, 1)
    y = runif(1, -1, 1)
    z = runif(1, -1, 1)
    if(x*x + y*y + z*z <= 1)
      N_C = N_C + 1;
  }
  return(8*N_C/N);
}
given = volum_sfera(10000)
print(given)
eroare_absoluta(given,(pi*4)/3)
eroare_relativa(given,(pi*4)/3)
# 2.
arie_elipsa = function(N){
  N_C = 0
  for(i in 1:N)
  {
    x = runif(1, -2, 2)
    y = runif(1, -2, 2)
    if(x*x + 4*y*y <= 4)
      N_C = N_C + 1;
  }
  return((4^2)*N_C/N);
}
arie_elipsa(10000)
# 3.
arie_parabola = function(N){
  N_C = 0
  for(i in 1:N)
  {
    x = runif(1, -1, 3)
    y = runif(1, 0, 4)
    if((-1)*x*x + 2*x + 3 >= y)
      N_C = N_C + 1;
  }
  return((4^2)*N_C/N);
}
given = arie_parabola(100000)
print(given)
# Estimarea Integralelor
# 1.
# a.
unu_a = function(n){
  sum = 0
  for(i in 1:n){
    x = runif(1,0,pi)
    sum = sum + (cos(x))^2
  }
  return((pi*sum)/n)
}
unu_a(10000)
# b.
unu_b = function(n){
  sum = 0
  for(i in 1:n){
    x = runif(1,0,3)
    sum = sum + exp(x)
  }
  return((3*sum)/n)
}
unu_b(10000)
# 2.
# a.
doi_a = function(n){
  sum = 0
  for(i in 1:n){
    x = rexp(1,1)
    sum = sum + ((1/(x^2+1))/exp(-x))
  }
  return(sum/n)
}
doi_a(10000)
# 3.
trei = function(n){
  sum = 0
  for(i in 1:n){
    u = rexp(1,1)
    sum = sum + exp(((-1)*u*u)/2)/exp(-u)
  }
  return(sum/n)
}
trei(40000)
# Estimarea mediilor
# 1.
nr_days = function(){
  nrd = 1;
  last_errors = c(11,16,18)
  nr_err = 18
  while(nr_err > 0){
    lambda = min(last_errors)
    nr_err = rpois(1,lambda)
    last_errors = c(nr_err,last_errors[1:2])
    nrd = nrd + 1
  }
  return(nrd)
}
MC_nr_days = function(n){
  sum = 0
  for(i in 1:n){
    sum = sum + nr_days()
  }
  return(sum/n)
}
MC_nr_days(10000)
# 2.
calc_timp = function(n){
  t = 0
  for(i in 1:n){
    r = runif(1,0,1)
    if(r <= 0.8){
      t = t + rexp(1,20)
    }
    else{
      t = t + rexp(1,5)
    }
  }
  return(t/n)
}
calc_timp(10000)
# Estimarea probabilitatilor
# 1.
prob1 = function(n){
  counter = 0
  for(i in 1:n){
    x = rpois(1,3)
    y = rpois(1,5)
    if( x>y ){
      counter = counter+1
    }
  }
  return(counter/n)
}
prob1(10000)
prob1(1+N_minim(0.005,0.95))
# 2.
infectare = function(){
  max_infectate = 1
  nr_infectate = 1
  nr_zile = 1
  while(0<nr_infectate && nr_infectate<20){
    # dezinfectare
    if(nr_zile > 1){
      nr_infectate = nr_infectate - 2
    }
    #infectare
    nr_curate = 20-nr_infectate
    if(nr_curate > 0){
      for(i in 1:nr_curate){
        r = runif(1,0,1)
        if(r<=0.1){
          nr_infectate = nr_infectate + 1
        }
      }
    }
    #maxim calc infectate
    if(max_infectate < nr_infectate)max_infectate = nr_infectate
    #trecem la ziua urmatoare
    nr_zile = nr_zile + 1
  }
  return(max_infectate)
}
prob_infectare_20 = function(n){
  counter = 0
  for(i in 1:n){
    if(infectare() == 20){
      counter = counter + 1
    }
  }
  return(counter/n)
}
prob_infectare_8 = function(n){
  counter = 0
  for(i in 1:n){
    if(infectare() >= 8){
      counter = counter + 1
    }
  }
  return(counter/n)
}

prob_infectare_20(100)
prob_infectare_8(1+N_minim(0.01,0.95))