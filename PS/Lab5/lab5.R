# I ###################################################################################################
normal_density = function(med,sigma_squared,limit){
  t = seq(-limit,limit,length = 400)
  sig = sqrt(sigma_squared)
  f = (1/(sig*sqrt(2*pi)))*exp(-(((t-med)^2)/(2*sigma_squared)))
  plot(t,f,type = "l",lwd = 1)
}
normal_density(0,1,6)
# II ##################################################################################################
selection_mean = function(filename){
  x = scan(filename)
  return(mean(x))
}
selection_mean("history.txt")
# III #################################################################################################
# 1
zconfidence_interval = function(n,sample_mean,alfa,sigma_squared){
  alfa = 1 - alfa
  sigma = sqrt(sigma_squared)
  critical_z = qnorm(1-alfa/2,0,1)
  a = sample_mean - critical_z * sigma / sqrt(n)
  b = sample_mean + critical_z * sigma / sqrt(n)
  return(c(a,b))
}
# 2
zconfidence_interval(n = 25,sample_mean = 67.53,alfa = 0.9,sigma_squared = 100)
# 3
zconfidence_interval(n = 50,sample_mean = 5,alfa = 0.95,sigma_squared = 0.5^2)
# IV ###################################################################################################
# 1
t_conf_interval = function(n,sample_mean,alfa,s){
  alfa = 1 - alfa
  se = s/sqrt(n)
  critical_t = qt(1-alfa/2,n-1)
  a = sample_mean - critical_t * se
  b = sample_mean + critical_t * se
  return(c(a,b))
}
# 2
t_conf_interval(n = 196,sample_mean = 44.65,alfa = 0.99,s = sqrt(2.25))
# 5
date = scan("date45.txt")
m_date = mean(date)
s_date = sd(date)
n_date = length(date)
t_conf_interval(n = n_date,sample_mean = m_date,alfa = 0.9,s = s_date)
t_conf_interval(n = n_date,sample_mean = m_date,alfa = 0.95,s = s_date)
t_conf_interval(n = n_date,sample_mean = m_date,alfa = 0.99,s = s_date)
# V ####################################################################################################
# 1
test_proportion = function(n,succese,alfa,p0,tip){
  alfa = 1 - alfa
  p_prim = succese / n
  z_score = (p_prim-p0) / sqrt(p0*(1-p0)/n)
  if( tip == 1){
    # 1 pentru asimetrica la stanga
    critical_z = qnorm(alfa,0,1)
  }
  else{
    if( tip == 2){
      # 2 pentru asimetrica la dreapta
      critical_z = qnorm(1-alfa,0,1)
    }
    else{
      # altceva pentru simetrica
      critical_z = -qnorm(alfa/2,0,1)
    }
  }
  return(c(z_score,critical_z))
}

# 2
# H0 - ( p0 = 0.1 )
# Ha - ( 0.1 < p )
# p0 < p - asimetrica la dreapta
test_proportion(n = 150,succese = 20,alfa = 0.95,p0 = 0.1,tip = 2)
# rezultatul este z < z* ( in loc de z > z* )
# nu putem respinge ipoteza initiala
# rez: H0

# 3