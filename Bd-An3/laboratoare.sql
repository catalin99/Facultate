select *
from STUDENTI s
         join NOTE n on s.NR_MATRICOL = n.NR_MATRICOL
where s.NUME like 'A%'

-- Lab2
-- 1)
select nume, prenume, an, DATA_NASTERE
from STUDENTI

-- 2)
select distinct bursa
from studenti

-- 4)
select nume || prenume || ',' || an as "Studenți pe ani de studiu"
from STUDENTI
order by AN

--5)
select nume, prenume, DATA_NASTERE
from studenti
where DATA_NASTERE between to_date('01/01/1995', 'dd/mm/yyyy') and to_date('10/06/1997', 'dd/mm/yyyy')
order by an desc

--6)
select nume, prenume, data_nastere
from STUDENTI
where extract(year from data_nastere)='1995'

--7)
select *
from STUDENTI
where bursa is null

--8)
select *
from STUDENTI
where bursa is not null and (an='2' or an='3')
order by nume asc, prenume desc

--9)
select s.bursa+s.bursa*0.15, s.*
from STUDENTI s
where bursa is not null

--10)
select *
from STUDENTI
where NUME like 'P%' and an='1'

--11)
select *
from STUDENTI
where prenume like '%a%a%'

--12)
select * from STUDENTI
where prenume='Alexandru' or PRENUME='Ioana' or PRENUME='Marius'

--13)
select * from STUDENTI
where BURSA is not null
      and GRUPA like 'A%'

--14)
select nume, prenume from PROFESORI
where trim(prenume) like '%n'

--lab3
--1)
select current_date as "Astazi" from dual;

--2)
select nume, DATA_NASTERE, floor(months_between(current_date,DATA_NASTERE)) from STUDENTI

--3)
select to_char(data_nastere, 'Day') d from studenti

--4)
select 'Elevul '||prenume||' este in grupa '||grupa from STUDENTI

--5)
select rpad(bursa,10,'$') from studenti

--6)
select  substr(lower(nume),1,1)||substr(upper(nume),2),length(nume) from profesori where nume like 'B%'


--7)
select nume,
       DATA_NASTERE,
       case when to_date(to_char(DATA_NASTERE, 'mmdd'), 'mmdd') < trunc(sysdate)
                    then add_months(to_date(to_char(DATA_NASTERE, 'mmdd'), 'mmdd'), 12)
                    else to_date(to_char(DATA_NASTERE, 'mmdd'), 'mmdd')
       end next_bday,
       NEXT_DAY(case when to_date(to_char(DATA_NASTERE, 'mmdd'), 'mmdd') < trunc(sysdate)
                    then add_months(to_date(to_char(DATA_NASTERE, 'mmdd'), 'mmdd'), 12)
                    else to_date(to_char(DATA_NASTERE, 'mmdd'), 'mmdd')
            end,'SUNDAY')
from STUDENTI

--8)
select nume, prenume, extract(month from data_nastere)
from studenti
where bursa is null
order by (extract(month from data_nastere))

--9)
select nume, bursa, DECODE(bursa, 450, 'premiul 1',
350, 'premiul 2', 250, 'premiul 3',null, 'mentiune' ) AS "Premiu"
from studenti;

select nume, bursa, case when bursa=450 then 'premiul 1'
                    when bursa=350 then 'premiul 2'
                    when bursa = 250 then 'premiul 3'
                    else 'mentiune' end as "Premiu"
from studenti

--10)
select nume, translate(nume, 'ai', 'ia') from studenti

--11)Afișați pentru fiecare student numele, vârsta acestuia la data curentă sub forma '<x> ani <y> luni și <z> zile'
-- (de ex '19 ani 3 luni și 2 zile') și numărul de zile până își va sărbători (din nou) ziua de naștere.

select nume, to_date(round(sysdate - DATA_NASTERE),2)
       from STUDENTI;

SELECT nume, FLOOR(MONTHS_BETWEEN(CURRENT_DATE, data_nastere)/12) AS ani,
       MOD(FLOOR(MONTHS_BETWEEN(CURRENT_DATE, data_nastere)/12),12) AS luni,
       FLOOR(CURRENT_DATE - ADD_MONTHS(data_nastere, FLOOR (MONTHS_BETWEEN (CURRENT_DATE, data_nastere)))) AS  zile
       from STUDENTi;

select NUME,CEIL(MONTHS_BETWEEN(CURRENT_DATE, data_nastere)/12),CURRENT_DATE
    from studenti;

	FLOOR(ADD_MONTHS(data_nastere, 12*CEIL(MONTHS_BETWEEN(CURRENT_DATE, data_nastere)/12)-CURRENT_DATE)) FROM studenti;

--13)
select nume,lpad(rpad('*'),(BURSA/50))


--1)considerand ca in statele unite au 21 ani limita, cati au 21 de ani ?
--afisati numele concatenat cu prenumele.
--2)
-- selectati titlu anul si nr de credite pt fiecare curs sub formatul:
--cursul <titlu curs> se face in anul <an> si are un numar de <credite> credite
--doar pentru cusurile care se fac in semestrul 1 si al carui titlu se scrie cu caractere majuscule
--3)
--Sa se afiseze suma dintre valoare si numar matricol din tabelul note intr o coloana denumita 'suma'
--in alta coloana numita 'nota' se va regasi x daca aceasta suma este para, altfel nota ramane neschimbata (decode+mod)
--4)
-- ==afisati doar pentru studentii bursieri numele, prenumele si data nasterii unde data nasterii are urmatorul format:
-- Vineri,17 Februarie 1995
-- ordonati studentii crescator in functie de anul si luna in care s au nascut

-- 1)
select nume||prenume, floor(months_between(sysdate, data_nastere)/12) AS "data"  from studenti where floor(months_between(sysdate,data_nastere)/12)>=21

-- 2)
select 'Cursul '||TITLU_CURS||' se face in anul '||an||' si are numar de '||credite||' credite' from cursuri where semestru=1 and TITLU_CURS=upper(titlu_curs)

-- 3)
select to_number(nr_matricol)+valoare AS "suma", decode(mod(to_number(nr_matricol)+valoare,2), 0, 'x', valoare) as "nota" from note

--4)

select nume, prenume, to_char(data_nastere, 'Day, DD Month YYYY', 'nls_date_language=romanian') as "Data_Nastere"
from studenti
where bursa is not null
ORDER BY to_char(data_nastere, 'YYYY'),
		to_char(data_nastere, 'MM');
--Laboratorul 4
--1)
select s.nume, p.nume,n.valoare
from studenti s
join note n on s.nr_matricol=n.nr_matricol
join didactic d on d.id_curs=n.id_curs
join profesori p on p.id_prof=d.id_prof

--3)
select p.nume, p.prenume, c.titlu_curs from profesori p join didactic d on p.id_prof=d.id_prof join cursuri c on c.id_curs=d.id_curs

--4)
select p.nume, p.prenume, c.titlu_curs from profesori p left join didactic d on p.id_prof=d.id_prof left join cursuri c on c.id_curs=d.id_curs


--5)
select p.nume, p.prenume, c.titlu_curs from profesori p right join didactic d on p.id_prof=d.id_prof right join cursuri c on c.id_curs=d.id_curs

--6)
select p.nume, p.prenume, c.titlu_curs from profesori p full join didactic d on p.id_prof=d.id_prof full join cursuri c on c.id_curs=d.id_curs

--7)
select s1.nume, s1.data_nastere, s2.nume, s2.data_nastere
from studenti s1
    join studenti s2 on s1.nr_matricol>s2.nr_matricol
where to_char(s1.data_nastere, 'D') = to_char(s2.data_nastere, 'D')
order by extract(Day from s1.data_nastere), s1.nume

--8)
select s1.nume, s2.nume
from studenti s1
    join studenti s2 on s1.nr_matricol<s2.nr_matricol
    join note n1 on s1.nr_matricol=n1.nr_matricol
    join note n2 on s2.nr_matricol=n2.nr_matricol
join cursuri c on n1.id_curs=c.id_curs and n2.id_curs=c.id_curs
where n2.valoare>n1.valoare
--
-- Afisati concatenat numele si prenumele studentilor, iar numele si prenumele sa fie scrise cu majuscule concatenate,
-- titlul cursului cu litere mici,
-- nota luata de acestia la cursul respectiv
-- o coloana numita promovabilitate in care sa fie afisat promovat/restantier in functie de nota luata
--
-- Pentru studentii nascuti in luna decembrie afisati numele, prenumele, ziua din saptamana in care s-au nascut cu aliasul zi nastere
-- cu prima litera majuscula, iar restul litere mici
-- si varsta in ani valoare intreaga cu aliasul varsta

-- afisati numele, prenumele si anul de studiu incrementat cu 1 pentru studentii care au bursa si care au in componenta numelui litera a sau A

-- afisati scris cu litere mari in coloana nume si textul are bursa sau nu are bursa in coloana statut doar pentru acei studenti care au litera e sau E in componenta numelui

-- selectati numele (trim), gradul didactic al profesorului si titlul cursului la care acesta preda
-- daca profesorul nu preda la niciun curs sau nu are grad didactic se va afisa *
-- daca cursul nu are niciun profesor asociat se va afisa no prof

select upper(s.nume)||upper(s.prenume), c.titlu_curs, n.valoare,
case n.valoare
    when 5 then 'Restantier'
    else 'Promovat'
end
from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL join cursuri c on c.id_curs=n.ID_CURS;

select nume, prenume, to_char(data_nastere, 'Day') as "ZI Nastere", round(months_between(current_date, DATA_NASTERE)/12) as "Varsta" from studenti;


select nume, prenume, an+1 from studenti
where bursa is not null and translate(nume, 'aA', 'zZ') <> nume;

select lower(nume), bursa from studenti
where bursa is not null or (bursa is null and translate(nume, 'eE', '')=nume)

select nvl(trim(p.nume),'*'), nvl(p.GRAD_DIDACTIC, 'no prof'), c.titlu_curs from profesori p full join didactic d on p.ID_PROF=d.ID_PROF
full join cursuri c on c.ID_CURS=d.ID_CURS



-- test
-- lab1
-- 1
select nume, prenume, an, data_nastere from studenti;

-- 2
select distinct bursa from studenti

-- 4
select nume||prenume||','||an as "Studenti pe an de studiu"
from STUDENTI
order by an;

-- 5
select nume, prenume, DATA_NASTERE
from STUDENTI
where data_nastere between to_date('01/jan/1995','dd/month/yyyy') and to_date('10/jun/1997','dd/month/yyyy')
order by an desc;

-- 6
select nume, prenume
from STUDENTI
where extract(year from data_nastere)=1995;

-- 7
select * from STUDENTI
where bursa is null;

-- 8
select nume, prenume from STUDENTI
where bursa is not null and (an=2 or an=3)
order by nume asc, prenume desc;

-- 9
select s.*, s.bursa+s.bursa*0.15 from studenti s
where bursa is not null;

-- 10
select * from STUDENTI
where nume like 'P%' and an=1;

-- 11
select * from STUDENTI
where prenume like '%a%a%';

-- 12
select * from STUDENTI
where prenume = 'Alexandru' or prenume = 'Marius' or prenume = 'Ioana';

-- 13
select * from STUDENTI
where bursa is not null and grupa like 'A%';

-- 14
select nume, prenume from profesori where trim(prenume) like '%n';

-- Lab 3
-- 1
select sysdate from dual;

-- 2
select nume, data_nastere, round(months_between(sysdate, data_nastere)) from STUDENTI;

-- 3
select to_char(data_nastere, 'day', 'nls_date_language=Romanian') from STUDENTI;

-- 4
select concat(concat(concat('Elevul ', prenume) , ' este in grupa  '), grupa) from studenti;

-- 5
select rpad(bursa,10,'$') from studenti;

-- 6
select substr(lower(nume), 1, 1)||substr(upper(nume), 2), length(nume)
from PROFESORI
where nume like 'B%'

-- 7
select nume, data_nastere,
        case when to_date(to_char(data_nastere, 'dd/mm'), 'dd/mm')>sysdate
            then to_date(to_char(data_nastere, 'dd/mm'), 'dd/mm')
        else add_months (to_date(to_char(data_nastere, 'dd/mm'), 'dd/mm'),12)
        end,
        case when to_date(to_char(data_nastere, 'dd/mm'), 'dd/mm')>sysdate
            then next_day(to_date(to_char(data_nastere, 'dd/mm'), 'dd/mm'),'SUNDAY')
        else
            next_day(add_months (to_date(to_char(data_nastere, 'dd/mm'), 'dd/mm'),12),'SUNDAY')
        end
from studenti;

-- 8
select nume, prenume, extract(Month from data_nastere)
from STUDENTI
where bursa is null
      order by extract(month from data_nastere);

-- 9
select nume, bursa,
       decode(bursa, 450, 'Premiul 1', 350, 'Premiul 2', 250, 'Premiul 3', 'Mentiune') as "Premiu"
from STUDENTI;

-- 10
select translate(nume, 'ia', 'ai') from studenti;

-- 11
-- nu ms

-- 12
select nume,
       '1/'||extract(month from add_months(DATA_NASTERE,1))||'/'||extract(year from add_months(DATA_NASTERE,1)),
       decode(bursa, 450, 450+450*0.1, 350, 350+350*0.15, 250, 250+250*0.2, 0)
from studenti;

-- 13
select nr_matricol,nume,prenume,bursa,nvl(rpad(' ',bursa/50,'*'),'nu are bursa') as bursa_stelute
from studenti
order by 5 desc;

column nr_matricol format a3
column nume format a15
column prenume format a9
column bursa format 9999999
column bursa_stelute format a15
select nr_matricol,nume,prenume,bursa,to_char(rpad(' ',bursa/50,'*')) as bursa_stelute
from studenti
where bursa is not null and bursa<>0
order by 5 desc;

select nume from studenti order by nume

select s1.nume from studenti s1 join studenti s2 on s1.NR_MATRICOL>s2.NR_MATRICOL
where s1.nume=s2.nume

select s.nume, nvl(n.valoare, 0) , c.titlu_curs from studenti s
left join note n on s.NR_MATRICOL=n.NR_MATRICOL join cursuri c on c.ID_CURS=n.ID_CURS

select p.nume, c.TITLU_CURS from profesori p
join didactic d on p.ID_PROF=d.ID_PROF
join cursuri c on c.ID_CURS=d.ID_CURS
where p.GRAD_DIDACTIC is not null
      order by p.nume desc, c.TITLU_CURS asc

select decode(trim(to_char(data_nastere, 'day')), 'sunday', upper(nume), 'tuesday', lower(nume), nume) from studenti;

select nume, 'student' from studenti where nume like '%b%' union
select nume, 'profesor' from profesori where nume like '%b%';

select distinct(c.titlu_curs) from cursuri c
join note n on c.ID_CURS=n.ID_CURS
where n.valoare>5
minus
select distinct(c.titlu_curs) from cursuri c
join note n on c.ID_CURS=n.ID_CURS
where n.valoare<=5

-- lab4

select s.*, n.valoare, p.NUME from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
join didactic d on d.ID_CURS=n.ID_CURS
join profesori p on p.ID_PROF=d.ID_PROF

select s.nume from studenti s
join note n on s.NR_MATRICOL=n.NR_MATRICOL
join cursuri c on c .ID_CURS=n.ID_CURS
where n.valoare=10
and TITLU_CURS='BD';

select s2.nume||' '||s2.prenume||' a luat nota mai mare ca '||s1.nume||' '||s2.PRENUME||' la materia '||c.TITLU_CURS
from cursuri c
join note n1 on c.id_curs=n1.id_curs
join note n2 on c.ID_CURS=n2.ID_CURS
join studenti s1 on s1.NR_MATRICOL=n1.NR_MATRICOL
join studenti s2 on s2.NR_MATRICOL=n2.NR_MATRICOL
where n2.valoare>n1.valoare

select s.nume, s.prenume,c.TITLU_CURS, n.valoare, decode(n.valoare, 4, 'restantier', 'promovat')
from studenti s
     join note n on s.nr_matricol=n.NR_MATRICOL
join CURSURI c on n.ID_CURS=c.ID_CURS;

select nume, prenume, initcap(to_char(data_nastere, 'day')) as "zi nastere",
       trunc(months_between(sysdate, data_nastere)/12) as "varsta"
from studenti
where extract(month from data_nastere)=12;

select trim(to_char(DATA_NASTERE,'month')) from STUDENTI;

select upper(nume), decode(nvl(bursa,0), 0, 'nu are bursa', 'are bursa') from STUDENTI
where nume like '%e%' or nume like '%S%'

select decode(trim(to_char(data_nastere,'day')), 'sunday', upper(nume), 'tuesday', lower(nume), nume) from studenti;

select distinct s1.nume from studenti s1 join studenti s2 on s1.nr_matricol<s2.nr_matricol
where s1.nume=s2.nume;

select s1.nume from note n
join studenti s1 on s1.NR_MATRICOL=n.NR_MATRICOL
join STUDENTI s2 on s2.NR_MATRICOL>s1.NR_MATRICOL
join note n2 on n2.NR_MATRICOL=s2.NR_MATRICOL
join cursuri c on n.ID_CURS=c.ID_CURS
where s2.nume='Popescu' and s1.AN=s2.AN and c.TITLU_CURS='OOP' and n.VALOARE=n2.valoare;

-- lab 8
-- 1
 select count(nume), an from studenti group by an;
-- 2
select count(nume), an, grupa from studenti group by an, grupa order by an,  grupa;
--3
select count(nume), an, grupa, count(bursa) from studenti group by an, grupa;
--4
-- select count(bursa) from studenti;
select sum(nvl(bursa,0))/count(NR_MATRICOL) from studenti;
-- 5
select avg(bursa) from studenti where bursa is not null;
-- 6
select count(valoare), valoare from note group by valoare order by valoare desc
-- 7
select count(valoare), to_char(data_notare, 'day') from note group by to_char(data_notare, 'day') order by count(valoare) desc;
-- 8
select count(valoare), to_char(data_notare, 'day') from note group by to_char(data_notare, 'day'), to_char(data_notare, 'd') order by to_char(data_notare, 'd');
-- am pus si group by data_notare, 'd' ca sa ordoneze in functie de ziua saptamanii, nu alfabetic dupa day
-- 9
select nume, avg(valoare) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL group by nume, n.NR_MATRICOL;
-- having count(valoare)>0 -- nu se pune pt ca joinul face automat asta
-- 10
select nume, avg(valoare) from studenti s left join note n on s.NR_MATRICOL=n.NR_MATRICOL group by nume, n.NR_MATRICOL;
-- 11
select nume, nvl(avg(valoare),0) from studenti s left join note n on s.NR_MATRICOL=n.NR_MATRICOL group by nume, n.NR_MATRICOL;
-- 12
select nume, nvl(avg(valoare),0) from studenti s left join note n on s.NR_MATRICOL=n.NR_MATRICOL group by nume, n.NR_MATRICOL having avg(valoare)>8;
-- 13
select nume, max(valoare), min(valoare), avg(valoare) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
group by s.NR_MATRICOL, s.nume
having min(valoare)>=7;
-- 14
select nume, prenume from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.NR_MATRICOL,s.nume, s.PRENUME having count(valoare)>=4;
-- 15
select nume, avg(valoare) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL where s.an=3 and s.grupa='A2' group by s.NR_MATRICOL, s.nume;
-- 16
select max(avg(valoare)) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.NR_MATRICOL;
--
select avg(valoare) as medie from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.NR_MATRICOL
having avg(valoare)=(select(max(avg(valoare))) from note group by s.NR_MATRICOL);
-- 17
select c.titlu_curs, min(n.valoare), max(n.valoare) from cursuri c join note n on c.ID_CURS=n.ID_CURS group by c.titlu_curs

-- +
-- 1)
-- afisati numarul total de studenti, nr de stud bursieri, si nr de tipuri de burse
-- 2)
-- interogand tabela note, afisati pt fiecare nota posibila valoarea acesteia cu aliasul nota si nr de studenti care au fost notati cu acea nota
-- 3)
-- pentru disciplinele la care s au pus doar note de trecere afisati titlul, cea mai mica si cea mai mare nota
-- 4)
-- interogand tabela profesori afisati doar pentru profesorii ce au grad didactic nr total de prof si nr de grade didactice
-- 5)
-- identificati stud care au medie intre 5 si 6, afisati nr_mat si nume
-- 6)
-- interogand tabela  note aflati cum sunt distribuite notele astfel:
-- afisati fiecare valoare a notei cu aliasul nota
-- nr de stud care au luat  acea nota cu aliasul studenti
-- si nr de cursuri distincte la care s a  obtinut nota cu aliasul cursul
-- 7)
-- afisati suma  notelor pare sub coloana suma note pare si media notelor impare sub coloana medie note impare pt fiecare stud care are note
-- 8)
-- afisati perechile de cursuri din anul 2 in functie de media acestora
-- primul va fi afisat cursul cu media mai mare

-- 1)
select count(nr_matricol), count(bursa), count(distinct (bursa)) from studenti;
-- 2
--distinct pentru ca un student poate lua mai multe note de acelasi fel
select valoare, count(distinct(nr_matricol)) from note group by valoare;
-- 3

select t.id_curs, n.ID_CURS, n.valoare from cursuri t left join note n on t.ID_CURS=n.ID_CURS
where t.ID_CURS not in
(select distinct n.id_curs from cursuri t join note n on t.ID_CURS=n.ID_CURS) or n.valoare=10;

select t.id_curs, n.ID_CURS, n.valoare from cursuri t left join note n on t.ID_CURS=n.ID_CURS
group by t.id_curs, n.ID_CURS, n.valoare having n.ID_CURS is null or n.valoare=10;


-- lab 9

-- 1
select nr_matricol, nume_prenume from STUDENTI where bursa = (select MAX(bursa) from studenti)

-- 2
select NR_MATRICOL, nume, PRENUME
from STUDENTI
where (grupa, an) in
      (select grupa, an from studenti where nume = 'Arhire') and nume <> 'Arhire'

-- 3
select s.nr_matricol, s.nume, s.an, s.grupa, n.valoare from STUDENTI s join note n
on s.NR_MATRICOL=n.NR_MATRICOL where (s.an, s.grupa, n.valoare) IN
(select s.an, s.grupa, MIN(n.valoare) from studenti s join  note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.an, s.grupa);

-- 4
select s.nr_matricol, s.nume, s.prenume, round(avg(n.valoare)),
       (select round(avg(valoare),2)  from note ) AS "Medie facultate"
from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
group by s.nr_matricol, s.nume, s.prenume
having avg(n.VALOARE) > (select avg(valoare) from note);

-- 5
select * from
(select s.NR_MATRICOL,s.nume, avg(n.valoare) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
    group by s.NR_MATRICOL, s.nume order by avg(n.valoare) desc)
where ROWNUM<4

-- sau  // cu pozitia
select * from
(select s.NR_MATRICOL, s.nume, round(avg(n.valoare),2) as media, rank() over (order by avg(n.valoare) desc) as poz
from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.NR_MATRICOL, s.nume)
where poz<4;
-- 6
-- campuri libere in select nu avem voie sa avem dubla agregare
-- dubla agregare => group by neaparat
select s.NR_MATRICOL, s.nume, s.PRENUME, round(avg(n.VALOARE))
from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
group by s.NR_MATRICOL, s.nume, s.PRENUME
having round(avg(n.VALOARE)) in (select max(round(avg(n.VALOARE)) )from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.NR_MATRICOL);


-- 7
select s.nr_matricol, s.nume, s.PRENUME, n.valoare, c.titlu_curs
from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL join CURSURI c on n.ID_CURS=c.ID_CURS
where (n.valoare, c.titlu_curs) in (select n.valoare, c.TITLU_CURS
from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL join CURSURI c on n.ID_CURS=c.ID_CURS where nume='Ciobotariu' and c.TITLU_CURS='Logica')
and s.nume<>'Ciobotariu';

-- 8
select * from (select * from (select * from studenti order by prenume desc) where rownum<6 order by prenume desc) where rownum <2;

-- 9
select * from
              (select * from
                             (select s.nr_matricol, sum(n.valoare*c.credite) as punctaj
                             from studenti s join note n on s.nr_matricol=n.NR_MATRICOL join cursuri c on c.ID_CURS=n.ID_CURS
                             group by s.nr_matricol
                             order by sum(n.valoare*c.credite) desc)
              where rownum<4 order by punctaj desc)
where rownum <2;
-- 1)
-- sa se afiseze cursul/cursurile la care s-au pus cele mai multe note
-- iar pentru acest curs sa se afiseze cea mai mica nota, cea mai mare nota si media tuturor notelor
-- sa se rotunjeasca media la 2 zec sup, sortarea cresc dupa titlul cursurilor
--
-- 2)
-- care este studentul nerestantier care are cea mai mica medie

-- 3)
-- pentru fiecare student aflati disciplinele la care a luat o nota peste media acelor
-- discipline sau cel putin egale (mat, n, p, titlu curs, media la nivel de disciplina)

-- 4)
-- pentru toti studentii nerestantieri din anii 2 si 3 afisati notele de 10 ale acestora si disciplinele aferente
--
-- 5
-- sa se afiseze matricola, n, p si media pentru toti studentii care au exact o restanta

-- 6
-- selectati numele si prenumele studentului care are media mai mica decat media notelor luate la toate materiile care au idul cursului nr par

-- 5)
select s.NR_MATRICOL, s.nume, s.prenume, trunc(avg(n.valoare)) as media
from studenti s join note n on s.NR_MATRICOL = n.NR_MATRICOL
group by s.NR_MATRICOL, s.nume, s.prenume
having (s.NR_MATRICOL, 1) in
       (select NR_MATRICOL, count(*)
           from NOTE
           where valoare < 5
           group by NR_MATRICOL)
order by 4 desc

-- 1)
select c.titlu_curs, max(n.valoare), min(n.valoare), count(n.valoare)
from cursuri c join note n on n.ID_CURS=c.ID_CURS
group by c.ID_CURS, c.titlu_curs
having count(n.valoare) =
       (select max(count(n.valoare))
           from cursuri c join note n on n.ID_CURS=c.ID_CURS
group by c.ID_CURS)

-- lab 11
-- update
update studenti set bursa=500 where exists (select * from note n join studenti s on n.NR_MATRICOL=s.NR_MATRICOL
    where n.valoare=10)

select * from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL where valoare=10

update studenti s set bursa=(select 100*avg(n.valoare) from note n where s.NR_MATRICOL=n.nr_matricol)

select * from studenti

-- delete
delete from studenti s where s.nr_matricol not in (select n.nr_matricol from note n);

create table T1 AS
	select nume, prenume,
	nvl(to_char(bursa), 'nu are bursa') as bursa,
	nvl(to_char(round(avg(valoare), 2)), ' nu are note ') AS media
	from studenti s
	left join note n on s.nr_matricol = n.nr_matricol
	group by s.nr_matricol, s.nume, s.prenume, s.bursa;

select * from T1;

-- constraints
alter table studenti add constraint pk_stud primary key (NR_MATRICOL);
alter table cursuri add constraint pk_curs primary key (ID_CURS);
alter table profesori add constraint pk_prof primary key (ID_PROF);

-- 2
alter table note add constraint fk_idcurs foreign key (id_curs)
references cursuri(id_curs);
alter table note add constraint fk_idnrmat foreign key (NR_MATRICOL)
references studenti(nr_matricol);
--3
alter table note add constraint  pk_note primary key (ID_CURS,NR_MATRICOL); -- niciuna din cele doua nu poate fi null

-- 4
alter table note add constraint ck_note check (vloare between  1 and 10);

--
delete from DIDACTIC;
delete from profesori;
insert into profesori values ('p1', 'nume1', 'prenume1', 'prof');
savepoint s1;
update profesori set nume='nume2'
                     where nume='num1';
select * from profesori;
rollback to s1;
select * from PROFESORI;

rollback;
select * from profesori;


-- lab  8
-- 1
select count(NR_MATRICOL), an from STUDENTI group by an;
-- 2
select count(NR_MATRICOL), an, grupa from STUDENTI group by an, grupa order by an, grupa;
-- 3
select count(NR_MATRICOL), count(bursa), an, grupa from STUDENTI group by an, grupa order by an, grupa;
-- 4
select sum(bursa) from studenti where bursa is not null;
-- 5
select avg(bursa) from studenti where bursa is not null;
-- 6
select count(nr_matricol), valoare from note group by valoare;
-- 7
select count(nr_matricol), TO_CHAR(DATA_NOTARE, 'Day') from note group by  TO_CHAR(DATA_NOTARE, 'Day') order by count(nr_matricol) desc;
-- 8
select count(nr_matricol), TO_CHAR(DATA_NOTARE, 'Day') from note group by  TO_CHAR(DATA_NOTARE, 'Day') order by TO_CHAR(DATA_NOTARE, 'Day') desc;
-- 9
select s.nume, avg(n.valoare) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.NR_MATRICOL, s.nume
order by avg(n.valoare) desc;
-- 10
select s.nume, avg(n.valoare)from studenti s left join note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.NR_MATRICOL, s.nume
order by avg(n.valoare) desc;
-- 11
select s.nume, nvl(avg(n.valoare),0) from studenti s left join note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.NR_MATRICOL, s.nume
order by avg(n.valoare) desc;
-- 12
select s.nume, nvl(avg(n.valoare),0) from studenti s left join note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.NR_MATRICOL, s.nume
having avg(valoare)>8
order by avg(n.valoare) desc;

-- 13
select s.nume, max(n.valoare), min(n.valoare) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
having min(n.valoare)>=7 group by s.NR_MATRICOL, s.nume;

-- 14
select s.nume, avg(n.valoare) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
having count(n.valoare)>=4 group by s.NR_MATRICOL, s.nume;

-- 15
select s.nume, avg(n.valoare) from STUDENTI s join note n on s.NR_MATRICOL=n.NR_MATRICOL
where GRUPA='A2' and an=3 group by s.NR_MATRICOL, s.nume;

-- 16
select max(avg(n.valoare)) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
group by s.NR_MATRICOL;

-- 17
select c.titlu_curs, min(n.valoare), max(n.valoare) from cursuri c join note n on c.ID_CURS=n.ID_CURS group by c.titlu_curs, c.ID_CURS;

-- lab9
-- 1)
select nume, prenume from studenti where bursa in (select max(bursa) from studenti)

-- 2)
select nume from studenti where (an, grupa) in (select an, grupa from studenti where nume='Arhire');

-- 3
select s.nume from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
where (n.valoare, s.grupa, s.an) in
      (select min(n.valoare), s.GRUPA,s.an from studenti s join note n on n.NR_MATRICOL=s.nr_matricol group by s.an, s.grupa);

select s.nr_matricol, s.nume, s.prenume, s.grupa, s.an, n.valoare
from studenti s
join note n on s.nr_matricol = n.nr_matricol
where (an, grupa, valoare) IN
	(select an, grupa, min(valoare)
		from studenti s
		join note n on s.nr_matricol = n.nr_matricol
		group by an, grupa);

-- 4
select s.nume, s.prenume from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
having avg(n.valoare)>(select avg(valoare) from note)
group by s.NR_MATRICOL, s.nume, s.prenume;

-- 5
select * from (select s.nume, avg(n.valoare), rank() over (order by avg(n.valoare) desc) as poz from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
 group by s.nume, s.NR_MATRICOL ) where poz=4;

-- 6
select s.nume, avg(n.valoare) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL group by s.nume, s.NR_MATRICOL
having avg(n.valoare) IN (select max(avg(n.valoare)) from note n group by NR_MATRICOL);

select s.nr_matricol, nume, prenume, round(avg(n.valoare),2) as medie
from studenti s
join note n on n.nr_matricol = s.nr_matricol
group by s.nr_matricol, nume, prenume
having avg(valoare) = (
	select max(avg(valoare))
	from note
	group by nr_matricol);


-- 7
select s.nume, s.prenume, n.valoare from STUDENTI s join note n on s.NR_MATRICOL=n.NR_MATRICOL join cursuri c on c.ID_CURS=n.ID_CURS
where (n.valoare, c.titlu_curs) in
      (select n.valoare, c.TITLU_CURS from note n join cursuri c on n.ID_CURS=c.ID_CURS join studenti s on s.NR_MATRICOL=n.NR_MATRICOL
          where s.nume='Ciobotariu' and s.PRENUMe='Ciprian' and c.TITLU_CURS='Logica')
and s.nume!='Ciobotariu' and s.PRENUME!='Ciprian';

select s.nr_matricol, nume, prenume, n.valoare
from studenti s
join note n on n.nr_matricol = s.nr_matricol
join cursuri c on c.id_curs = n.id_curs
where (titlu_curs, valoare) IN (
	select titlu_curs, valoare
	from studenti s
	join note n on n.nr_matricol = s.nr_matricol
	join cursuri c on c.id_curs = n.id_curs
	where titlu_curs = 'Logica' and nume = 'Ciobotariu' and prenume='Ciprian')
	AND nume != 'Ciobotariu' and prenume != 'Ciprian';

-- 8
select * from(
select prenume, rank() over (order by prenume asc) as poz from studenti)
where poz=5;

-- 9
select * from(
select * from
(select sum(n.valoare*c.credite), s.nume, s.PRENUME from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL join cursuri c on n.id_curs=c.id_curs
group by s.nume, s.PRENUME order by  sum(n.valoare*c.credite) desc)
where ROWNUM<4)
where ROWNUM<2;

-- 10
select s.nume, n.valoare, c.titlu_curs from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL join cursuri c on c.ID_CURS=n.ID_CURS
where (n.valoare, c.titlu_curs) IN (select max(n.valoare), c.TITLU_CURS from note n join cursuri c on c.ID_CURS=n.ID_CURS group by c.ID_CURS, c.TITLU_CURS)

-- lab 10
-- 1
select NR_MATRICOL from studenti s1
where Exists (select * from studenti s2 where s2.DATA_NASTERE<s1.DATA_NASTERE and s1.an=s2.an );

-- 2

select s1.nume, s1.prenume, avg(n1.valoare)
from studenti s1 join note n1 on s1.nr_matricol = n1.nr_matricol
group by s1.nr_matricol, s1.nume,s1.prenume, s1.an
having avg(n1.valoare) >(
	select avg(n2.valoare) from studenti s2
    	join note n2 on s2.nr_matricol = n2.nr_matricol
    	where s1.an=s2.an
	);

-- 3
select s.nume, s.prenume, s.grupa, s.an from STUDENTI s join note n on s.NR_MATRICOl=n.NR_MATRICOL
having avg(n.valoare) IN (select max(avg(n.valoare)) from STUDENTI s join note n on s.NR_MATRICOl=n.NR_MATRICOL group by s.GRUPA, s.AN)
group by s.nume, s.prenume, s.grupa, s.an;

-- Găsiţi toţi studenţii care au măcar un coleg în acelaşi an care să fi luat aceeaşi nota ca şi el la măcar o materie.
select distinct s.NR_MATRICOL, s.nume from  STUDENTI s join note n on s.NR_MATRICOl=n.NR_MATRICOL
where exists (select * from studenti s2 join note n2 on s2.NR_MATRICOL=n2.NR_MATRICOL
where s.an=s2.an and n.valoare=n2.valoare and n.ID_CURS=n2.id_curs)

-- Afișați toți studenții care sunt singuri în grupă (nu au alți colegi în aceeași grupă).
select distinct s.NR_MATRICOL, s.nume from  STUDENTI s
where not exists (select * from studenti s2 where s.an=s2.AN and s2.GRUPA=s.GRUPA and s.NR_MATRICOL<>s2.NR_MATRICOL)

-- Afișați profesorii care au măcar un coleg (profesor) ce are media notelor puse la fel ca și el.
select distinct p.nume from profesori p join didactic d on d.ID_PROF=p.ID_PROF join cursuri c on c.ID_CURS=d.ID_CURS join note n on n.ID_CURS=c.ID_CURS
where exists
    (select p.nume
    from profesori p2 join didactic d2 on d2.ID_PROF=p2.ID_PROF join cursuri c2 on c2.ID_CURS=d2.ID_CURS join note n2 on n2.ID_CURS=c2.ID_CURS
    having round(avg(n.valoare))=round(avg(n2.valoare)) )

select p1.nume, p1.prenume from profesori p1
join didactic d1 on d1.id_prof = p1.id_prof
join note n1 on d1.id_curs = n1.id_curs
where exists(
	select 'x' from didactic d2 join note n2 on n2.id_curs = d2.id_curs
	having round(avg(n1.valoare)) = round(avg(n2.valoare))
);

select s.nume,  (select avg(valoare) from note n where n.NR_MATRICOL=s.NR_MATRICOL) from studenti s

-- lab 11
-- actualizati valoarea bursei pentru studentii care au măcar o notă de 10. Acestia vor primi ca bursa 500RON.
-- Toti studentii primesc o bursa egala cu 100*media notelor lor. Efectuati modificarile necesare.
-- 1
update studenti  set bursa=500 where exists (select * from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL where n.valoare=10)
update studenti set bursa = (select 100*avg (n.valoare) from note n join studenti s on n.NR_MATRICOL=s.NR_MATRICOL);

select * from STUDENTI;


delete from studenti s
where s.nr_matricol not in (select n.nr_matricol from note n);

create table studentscopy (bursa number, nume varchar2(20));

create table studentscopy2 (bursa , nume) as select bursa, nume from studenti;

select s.nume, s.prenume from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
group by s.nume, s.prenume, s.NR_MATRICOL
having round(avg(n.valoare)) IN (select max(round(avg(n1.valoare))) from note n1 group by n1.NR_MATRICOL)

select count(distinct(grupa)) from studenti;

select s.nume, s.prenume, avg(n1.valoare) from studenti s join note n1 on n1.NR_MATRICOL=s.NR_MATRICOL
where not exists (select * from studenti s1 join note n on s1.NR_MATRICOL=n.NR_MATRICOL where n.valoare<5 and s.NR_MATRICOL=s1.NR_MATRICOL)
group by s.NR_MATRICOL, s.nume, s.prenume;

select * from
(select bursa from studenti where bursa is not null order by bursa desc)
where rownum<=2

alter table instructori rename to profesori

select * from note n;

update studenti set bursa = (select 100*avg (n.valoare) from note n join studenti s on n.NR_MATRICOL=s.NR_MATRICOL);
update note set valoare=(select n1.valoare*c.credite from note n1 join cursuri c on n1.ID_CURS=c.ID_CURS where valoare is not null)

delete from studenti s1 where exists (select * from studenti s join note n on s.NR_MATRICOl=n.NR_MATRICOL where n.valoare<5 and s1.NR_MATRICOL=s.NR_MATRICOL)

update studenti set bursa = (select 50*avg(n.valoare) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL where
    not exists (select * from studenti s1 join note n1 on s1.NR_MATRICOL=n1.NR_MATRICOL where n.valoare<5 and s.NR_MATRICOL=s1.nr_matricol))

select nume, count(nume) from studenti
having count(nume)>1
group by nume;

select count(NR_MATRICOL), count(distinct(grupa)), count(distinct(an)) from studenti;

select * from (
select nume, prenume, valoare from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL join CURSURI c on c.ID_CURS=n.ID_CURS
where TITLU_CURS='BD' order by valoare desc)
where ROWNUM<4;

alter table studenti drop constraint pk_stud;
alter table studenti add constraint  pk_stud primary key( nr_matricol)

select s.nume, avg(n.valoare) from studenti s join note n on s.NR_MATRICOL=n.NR_MATRICOL
having avg(n.valoare)> (select avg(valoare) from note)
group by s.nume, s.NR_MATRICOL  ;