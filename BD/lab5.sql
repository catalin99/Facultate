/*1.Afisati studentii doi cate doi impreuna cu diferenta de varsta dintre ei. Sortati in ordine crescatoare in functie de aceste diferente.
Aveti grija sa nu comparati un student cu el insusi.*/
column matr1 format A4
column nume1 format A10
column prenume1 format A10
column matr2 format A4
column nume2 format A10
column prenume2 format A10
column dif_varsta format A20
select s1.nr_matricol as matr1,s1.nume as nume1,s1.prenume as pren1,s2.nr_matricol as matr2,s2.nume as nume2,s2.prenume as pren2,
  abs(trunc(months_between(s1.data_nastere,s2.data_nastere)/12))||' ani '||
  abs(trunc(to_number(months_between(s1.data_nastere,s2.data_nastere)-(trunc(months_between(s1.data_nastere,s2.data_nastere)/12))*12)))||' luni '||
  abs(trunc(to_number(s1.data_nastere-add_months(s2.data_nastere,trunc(months_between(s1.data_nastere,s2.data_nastere))))))||' zile. ' as dif_varsta
from studenti s1 join studenti s2 on s1.nr_matricol>s2.nr_matricol
order by abs(s1.data_nastere-s2.data_nastere);


/*2.Afisati posibilele prietenii dintre studenti si profesori. Un profesor si un student se pot imprieteni daca numele lor de familie are acelasi numar de litere.*/



/*3.Afisati denumirile cursurilor la care s-au pus note cel mult egale cu 8 (<=8).*/
--varianta cu minus
	

/*4.Afisati numele studentilor care au toate notele mai mari ca 7 sau egale cu 7.*/


/*5.Sa se afiseze studentii care au luat nota 7 sau nota 10 la OOP intr-o zi de marti.*/


/*6.O sesiune este identificata prin luna si anul in care au fost tinute. 
Scrieti numele si prenumele studentilor ce au promovat examenele in fiecare sesiune impreuna cu notele luate de acestia si sesiunea in care a fost promovata materia.
Formatul ce identifica sesiunea este "LUNA, AN", fara alte spatii suplimentare (De ex. "JUNE, 2015" sau "FEBRUARY, 2014"). 
In cazul in care luna in care s-a tinut sesiunea a avut mai putin de 30 de zile afisati simbolul "+" pe o coloana suplimentara,
indicand faptul ca acea sesiune a fost mai grea (avand mai putine zile), in caz contrar (cand luna are mai mult de 29 de zile) valoarea coloanei va fi null.*/



--Interogari suplimentare
--EXEMPLE CU LEFT-JOIN (e posibil unele interogari sa se mai repete prin alte locuri)
--1.Afisati DOAR studentii (nr_matricol,nume,prenume,an,grupa) ce nu au nici o nota.
--foarte important de pus id_curs is null, altfel se afiseaza atatea tuple cate linii sunt in tabela de note


--2.Afisati toti studentii impreuna cu notele lor, chiar si pe aceia ce nu au note.
--La cei ce nu au note, scrieti un mesaj corespunzator.


--3.Afisati DOAR profesorii ce nu sunt titulari de curs.


--4.Afisati toti profesorii impreuna cu disciplinele pe care le tin, chiar si pe aceia ce nu tin nici o disciplina.
--In cazul acelora ce nu tin nici un curs, afisati un mesaj corespunzator.


--5.Afisati DOAR cursurile ce nu au nici un titular de curs.


--6.Afisati toate cursurile impreuna cu profesorii care le tin, chiar si acelea ce nu au nici un titular.



--7.Afisati studentii ce nu au nici o nota la BD.


/*8.Identificati toate cursurile predate in facultate si toate cadrele didactice ale facultatii.
Veti afisa: titlul cursului, numarul de credite alocate, numele si prenumele cadrului didactic care preda cursul.
Vor aparea si cursurile care inca nu au asociati profesori, precum si profesorii care inca nu au asignat vreun curs.*/	
--cel mai usor se face cu full join



--EXEMPLE CU SELF-JOIN
/*1.Pentru studenta Antonie Ioana afisati care sunt colegii ei. Nu o afisati si pe ea !
Coleg = acelasi an, aceeasi grupa. Afisati 3 coloane, exact asa cum sunt in baza de date: nr_matricol, nume, prenume.*/
--studenti s1 reprezinta Popescu Bogdan, iar studenti s2 sunt colegii lui (am partitionat tabela studenti in doua)
--evident s1.nr_matricol<>s2.nr_matricol, deoarece s1.nr_matricol este matricola lui Popescu Bogdan, iar s2.nr_matricol reprezinta matricolele colegilor
--s1.grupa=s2.grupa and s1.an=s2.an deoarece coleg inseamna sa fie din acelasi an si aceeasi grupa cu cel caruia ii afisam colegii


--2.Afisati suma notelor pare sub coloana "Suma note pare" si media notelor impare sub coloana "Medie note impare" pentru fiecare student care are note.
--este clar ca vom partitiona tabela de note in doua: n1 reprezinta notele ce vor intra in calculul sumei, iar n2 reprezinta notele ce vor in calculul mediei
--foloseste si functii de grupare, sum si avg
/*Cand aveti functii de grupare (in general sunt 5 foarte folosite si anume sum, avg, min, max si count...si ar mai fi stddev, deviatia standard,
dar e rar utilizata) sunteti obligati sa folositi clauza group by (obligatoriu se pune dupa where !!!), iar in group by punem acele campuri libere, adica 
acelea care nu au functie de grupare in fata. Aici nu avem astfel de campuri, asa cum se observa din select, caz in care suntem obligati oricum sa facem o
grupare, iar gruparea o facem dupa matricolele studentilor (evident, dupa matricole, si nu dupa note, deoarece trebuie luate in seama toate tuplele
ce indeplinesc conditia) !*/


--3.Pentru fiecare prof afisati colegii acestuia, impreuna cu cursurile tinute.
--Coleg inseamna sa tina acelasi curs cu el. Afisarea o vom face sub forma unei propozitii.

  
/*4.Sa se afiseze cupluri de numere matricole impreuna cu un ID al unui curs astfel 
incat studentul avand primul numar matricol a luat nota strict mai mare decat studentul 
avand cel de-al doilea numar matricol la cursul cu ID-ul dat de cea de-a treia coloana.
Afisarea se va face doar pentru cursurile cu ID-urile 21 si 24. Coloanele se vor numi "M1", "M2", "curs".*/
 
  
/*5.Pentru cursul de BD, afisati toate perechile de studenti ce au luat note, dar fara a afisa duplicate.
Primul va fi afisat studentul ce a luat nota mai mare (iar daca sunt doi cu aceeasi cota, se vor afisa de doua ori,
adica si a cu b, dar si b cu a). Afisati si notele !*/  


/*6.Afisati perechile de cursuri din anul 2, in functie de media acestora. Primul va fi afisat cursul cu media mai mare.*/


/*7.Selectati perechile de cursuri (adica titlurile lor) la care s-a pus acelasi numar de note in sesiunile din anul 2014.
Prima coloana se va numi "Pereche", iar cursul 1 va fi concantenat cu cursul 2 printr-un spatiu.
A doua coloana se va numi "Sesiune", iar o sesiune este identificata prin luna si an (vezi lab 5, de exemplu FEBRUARY, 2014).
Atentie la spatiul dintre luna si an ! Eliminati duplicatele.*/


/*8.Afisati toate perechile de profesori ce nu au grad didactic. Eliminati duplicatele.
Prima coloana se va numi "prof1", iar a doua se va numi "prof2".*/


/*9.Afisati perechile de cursuri la care s-a pus cel putin o nota de 10. Eliminati duplicatele.
Vor fi deci doua coloane, numite "Curs1" si "Curs2".*/


/*10.Afisati perechile de cursuri la care nu s-a pus nici o nota. Eliminati duplicatele.
Vor fi deci doua coloane, numite "Curs1" si "Curs2".*/


/*11.Afisati perechile de studenti (matricol, nume, prenume) care nu au nici o nota. Eliminati duplicatele*/


/*12.Afisati perechile de profesorii ce nu tin nici un curs. Eliminati duplicatele.*/

/*13.Afisati perechile de studenti ce au aceeasi nota la materiile din anul 1. Eliminati duplicatele.
Afisati si cursurile si notele ! Sunt deci doar 2 coloane. Coloanele se vor numi "student1" si "student2"*/

  
  
