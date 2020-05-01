/*1.Afiºaþi studenþii ºi notele luate de acestia precum si profesorii care le-au pus acele note.*/
--varianta mai putin corecta in care sunt cazuri cand, pentru acelasi student, exista 2 note la acelasi obiect, puse de profi diferiti
select s.nume,s.prenume,trim(p.nume) as nume_prof, c.titlu_curs,valoare
from studenti s join note n on n.nr_matricol=s.nr_matricol join didactic d on d.id_curs=n.id_curs join profesori p on p.id_prof=d.id_prof
  join cursuri c on c.id_curs=d.id_curs
order by 1;

--varianta mai buna, in care pentru un student apare o singura nota
--am ales un "artificiu" in sensul ca am afisat proful cu id mai mic
--mai corect ar fi sa mergem in tabela note si sa mai adaugam un camp si anume id_prof !!!
select s.nume,s.prenume,trim(p.nume) as nume_prof,c.titlu_curs,valoare
  from profesori p join 
	(select d.id_curs, min(d.id_prof) as id_prof from didactic d group by d.id_curs) d on p.id_prof = d.id_prof
	join cursuri c on d.id_curs = c.id_curs join note n on c.id_curs = n.id_curs
  join studenti s on n.nr_matricol = s.nr_matricol
order by 1;

	
/*2.Afisati studenþii care au luat nota 10 la materia 'BD'. 
Singurele valori pe care aveþi voie sã le hardcodaþi în interogare sunt valoarea notei (10) ºi numele cursului ('BD').*/
select s.nr_matricol,nume,prenume
from studenti s join note n on s.nr_matricol=n.nr_matricol join cursuri c on c.id_curs=n.id_curs
where titlu_curs='BD' and valoare=10
order by 1;


/*3.Afisaþi profesorii (numele ºi prenumele) impreuna cu cursurile pe care fiecare le þine.*/
select nume,prenume,titlu_curs
from didactic d join profesori p on p.id_prof=d.id_prof join cursuri c on d.id_curs=c.id_curs 
order by 1;


/*4.Modificaþi interogarea de la punctul 3 pentru a fi afiºaþi ºi acei profesori care nu au încã alocat un curs.*/
--afisam toti profii, adica si cei ce au curs si cei ce nu au curs
select nume,prenume,nvl(titlu_curs,'Nu are curs !') as titlu_curs
from profesori p left join didactic d on p.id_prof=d.id_prof left join cursuri c on d.id_curs=c.id_curs  
where c.id_curs is null or c.id_curs is not null
order by 1;

--sau(varianta cu functia in)
--afisam doar profii ce nu au curs !
select nume,prenume
from profesori p
where id_prof not in(
	select id_prof from didactic)
order by 1;	

--varianta cu operatorul exists (lab2)
select nume,prenume
from profesori p
where not exists(
	select * from didactic d where p.id_prof=d.id_prof)
order by 1;	

--daca ar fi sa afisam cu operatorul exists toti profii, adica si cei ce au curs, dar si cei ce nu au
select nume,prenume,nvl(titlu_curs,'Nu are curs !') as titlu_curs
from profesori p left join didactic d on d.id_prof=p.id_prof left join cursuri c on c.id_curs=d.id_curs
where not exists(
	select * from didactic d where p.id_prof=d.id_prof)
union
select nume,prenume,nvl(titlu_curs,'Nu are curs !') as titlu_curs
from profesori p left join didactic d on d.id_prof=p.id_prof left join cursuri c on c.id_curs=d.id_curs
where exists(
	select * from didactic d where p.id_prof=d.id_prof)
order by 1;

--daca ar fi sa afisam cu functia in toti profii, adica si cei ce au curs, dar si cei ce nu au
select nume,prenume,nvl(titlu_curs,'Nu are curs !') as titlu_curs
from profesori p left join didactic d on d.id_prof=p.id_prof left join cursuri c on c.id_curs=d.id_curs
where d.id_prof not in(
	select id_prof from didactic d where p.id_prof=d.id_prof)
union
select nume,prenume,nvl(titlu_curs,'Nu are curs !') as titlu_curs
from profesori p left join didactic d on d.id_prof=p.id_prof left join cursuri c on c.id_curs=d.id_curs
where d.id_prof in(
	select id_prof from didactic d where p.id_prof=d.id_prof)
order by 1;	

--sau (legatura intre tabele se face in clauza where cu ajutorul operatorului "+"- varianta mai veche, mai putin folosita azi)
--afisam doar profii ce nu au curs !
select nume,prenume
from profesori p, didactic d 
where p.id_prof=d.id_prof(+) and id_curs is null
order by 1;
	

/*5.Modificaþi interogarea de la punctul 3 pentru a fi afiºate acele cursuri ce nu au alocate încã un profesor.*/
select titlu_curs
from cursuri c left join didactic d on c.id_curs=d.id_curs
where d.id_prof is null;

--varianta cu functia in
select titlu_curs
from cursuri
where id_curs not in
  (select id_curs from didactic);

--sau (varianta cu operatorul exists - lab 2)
select titlu_curs
from cursuri c
where not exists(
	select * from didactic d where c.id_curs=d.id_curs)
order by 1;	

--sau (legatura intre tabele se face in clauza where)
select titlu_curs
from cursuri c, didactic d
where c.id_curs=d.id_curs(+) and id_prof is null;

/*6.Modificaþi interogarea de la punctul 3 astfel încât sã fie afiºaþi atat profesorii care nu au nici 
un curs alocat cât ºi cursurile care nu sunt încã predate de nici un profesor*/
--varianta cu full join 
select nvl(nume,'nu exista prof !') as nume_prof,nvl(titlu_curs,'nu are curs') as titlu_curs
from profesori p full join didactic d on d.id_prof=p.id_prof full join cursuri c on c.id_curs=d.id_curs
where c.id_curs is null or p.id_prof is null;

--varianta cu exists
select nume ||' - profesor' as Rezultat
from profesori p 
where not exists
	(select * from didactic d where p.id_prof=d.id_prof)
union
select titlu_curs||' - curs' as rezultat
from cursuri c
where not exists
	(select * from didactic d where d.id_curs=c.id_curs);
	

/*7.In tabela studenti existã studenþi care s-au nascut în aceeasi zi a sãptãmânii. 
De exemplu, Cobzaru George ºi Pintescu Andrei s-au nãscut amândoi într-o zi de marti.
Construiti o listã cu studentii care s-au nãscut in aceeaºi zi grupându-i doi câte doi în ordine alfabeticã a numelor 
(de exemplu in rezultat va apare combinatia Cobzaru-Pintescu dar nu va apare ºi Pintescu-Cobzaru).
Lista va trebui sã conþinã doar numele de familie a celor doi împreunã cu ziua în care cei doi s-au nãscut. 
Evident, dacã existã ºi alþi studenti care s-au nãscut marti, vor apare si ei in combinatie cu cei doi amintiþi mai sus. 
Lista va fi ordonatã în funcþie de ziua sãptãmânii în care s-au nãscut si, în cazul în care sunt mai mult de trei studenþi nãscuþi în aceeaºi zi, 
rezultatele vor fi ordonate ºi dupã numele primei persoane din listã*/

--varianta 1 (joinul se face printr-o coloana non-cheie)
select s1.nume||' - '||s2.nume||' - '||to_char(s1.data_nastere,'day') as perechi
from studenti s1 join studenti s2 on to_char(s1.data_nastere,'d')=to_char(s2.data_nastere,'d')
where s1.nr_matricol<s2.nr_matricol
order by s1.data_nastere,s1.nume;

--varianta 2 (self-joinul se face in clauza from prin intermediul cheii)
select s1.nume||' - '||s2.nume||' - '||to_char(s1.data_nastere,'day') as perechi
from studenti s1 join studenti s2 on s1.nr_matricol < s2.nr_matricol 
where to_char(s1.data_nastere,'day')=to_char(s2.data_nastere,'day') 
order by s1.data_nastere,s1.nume;


/*8.Sa se afiseze, pentru fiecare student, numele colegilor care au luat nota mai mare ca ei la fiecare dintre cursuri. 
Formulati rezultatele ca propozitii (de forma "Popescu Gigel a luat nota mai mare ca Vasilescu Ionel la matera BD."). 
Dati un nume corespunzator coloanei [pont: interogarea trebuie sã returneze 118 rânduri].*/
select s1.nume||' '||s1.prenume||' a luat nota mai mare ca '||s2.nume||' '||s2.prenume||' la materia '||titlu_curs as note
from cursuri c join note n1 on n1.id_curs=c.id_curs join note n2 on n2.id_curs=c.id_curs
  join studenti s1 on s1.nr_matricol=n1.nr_matricol join studenti s2 on s2.nr_matricol=n2.nr_matricol
where n1.valoare>n2.valoare
order by s1.nume;  

--varianta cu joinul in clauza where
select s1.nume||' '||s1.prenume||' a luat nota mai mare ca '||s2.nume||' '||s2.prenume||' la materia '||titlu_curs as note
from cursuri c, note n1, note n2, studenti s1, studenti s2
where n1.id_curs=c.id_curs and n2.id_curs=c.id_curs and s1.nr_matricol=n1.nr_matricol and s2.nr_matricol=n2.nr_matricol and n1.valoare>n2.valoare
order by s1.nume; 

--Intrebari suplimentare
--1.Afisati concatenat numele si prenumele studentilor (atat numele cat si prenumele sa fie scrise cu majuscule), titlul cursului cu litere mici, nota 
--luata de acestia si o ultima coloana, numita Promovabilitate in care sa fie afisat promovat/restantier, pentru fiecare nota a studentului.
--Trebuie sa aveti in total 42 de linii
select upper(nume)||' '||upper(prenume) as "Studenti",lower(titlu_curs) as "Curs",valoare as "Nota",
  case valoare
  when 4 then 'restantier'
  else 'promovat' end as "Promovabilitate" 
from studenti s join note n on n.nr_matricol=s.nr_matricol join cursuri c on c.id_curs=n.id_curs
order by 1;

/*2.Pentru studentii nascuti in luna decembrie afisati numele, prenumele, ziua din saptamana in care s-a nascut cu Aliasul "Zi nastere"
cu prima litera majuscula iar restul litere mici, si varsta sa in ani (valoare intreaga) cu aliasul "Varsta".*/ 
select nume,prenume,initcap(to_char(data_nastere,'day')) as "Zi nastere",trunc(months_between(sysdate,data_nastere)/12) as Varsta
from studenti
where extract(month from data_nastere)=12;

/*3.Afisati numele, prenumele si anul de studiu incrementat cu 1 (in coloana "an nou") pentru studentii care au bursa si au in componenta numelui litera "a" (sau "A").*/
select nume,prenume,an+1 as "an nou"
from studenti
where bursa is not null and (nume like '%a%' or nume like '%A%');

/*4.Afisati numele scris cu litere mari (in coloana 'NUME') si textul "are bursa" sau "nu are bursa", 
dupa caz (in coloana 'statut') doar pentru acei studenti care au litera "e" (sau "E") in componenta numelui.*/
select upper(nume) as "NUME", decode(nvl(bursa,0),0,'nu are bursa','are bursa') as statut
from studenti
where upper(nume) like '%E%';

/*5.Selectati numele (cu trim), gradul didactic ale profesorului si titlul cursului la care acesta preda.
Daca profesorul nu preda la nici un curs sau nu are grad didactic, se va afisa '*'. Daca cursul nu are nici un profesor asociat, se va afisa 'No prof'. 
Ordonati dupa nume. (Ex: Pentru cursul de Limbaje Formale: No prof   *   Limbaje Formale).
Coloanele se vor numi nume_prof, grad_didactic si titlu_curs. Hint: 18 linii*/
select nvl(trim(p.nume),'No prof') as nume_prof,nvl(p.grad_didactic, '*') as grad_didactic,nvl(c.titlu_curs, '*') as titlu_curs
from profesori p full join didactic d on d.id_prof=p.id_prof full join cursuri c on c.id_curs=d.id_curs
order by trim(p.nume);

/*6.Selectati numele si prenumele concatenate printr-un spatiu ale profesorilor in coloana "Nume prof", 
si notele puse de acestia in coloana "Note". Numele profesorului trebuie sa contina literele 'a' si 's' (sau 'A' si 'S')(doar perechile date, nu altfel, gen 'a' si 'S').
Daca profesorul nu a pus nici o nota, atunci se afiseaza '*'. Ordonati dupa "Note". Hint: 12 linii.*/
select distinct trim(p.nume)||' '||trim(p.prenume) as "Nume prof", nvl(to_char(n.valoare), '*') as "Note" 
from profesori p left join didactic d on p.id_prof=d.id_prof left join note n on n.id_curs=d.id_curs
where trim(p.nume) like '%a%s%' or trim(p.nume) like '%A%S%'
order by "Note";











