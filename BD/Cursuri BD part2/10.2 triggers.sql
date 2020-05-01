/*adaptat dupa cursul lui Jennifer Widom de Baze de date de la Stanford 
  Declansatoare
  functioneaza in SQLite (cu modificarea dispare ':' din :OLD si :NEW - necesare pt. Oracle) 
  functioneaza in Postgres daca actiunea din trigger e specificata ca procedura stocata
  MySQL nu suporta WHEN, evenimentul UPDATE cu atribute, mai multe declansatoare pt.acelasi eveniment, inlantuirea declansatoarelor
  Oracle nu suporta interogari in clauza WHEN, nici interogari asupra tabelului la care e asociat triggerul in campul actiune
**************************************************************/

/**************************************************************
  AFTER-INSERT TRIGGER
  studentii noi cu media intre 9.00 si 9.66 aplica automat la
  Geologie la Cuza si la Biologie la Petre Andrei
**************************************************************/
drop trigger R1;
create trigger R1
after insert on Student
for each row
when (New.medie > 9.00 and New.medie <= 9.66)
begin
  insert into Aplica values (:New.sID, 'Cuza', 'Geologie', null);
  insert into Aplica values (:New.sID, 'Petre Andrei', 'Biologie', null);
end;

insert into Student values ('111', 'Constantin', 9.50, 1000);
insert into Student values ('222', 'Loredana', 9.80, 1000);
select * from Student;
select * from Aplica;



insert into Student select sID+1, sNume, medie, dimLiceu from Student;
select * from Student;
select * from Aplica;

/**************************************************************
  AFTER-DELETE TRIGGER
  Cascaded delete pentru Aplica(sID) references Student(sID)
**************************************************************/

create trigger R2
after delete on Student
for each row
begin
  delete from Aplica where sID = :Old.sID;
end;

delete from Student where sID > 200;
select * from Student;
select * from Aplica;

/**************************************************************
  AFTER-UPDATE TRIGGER
  Cascaded update pentru Aplica(uNume) references Universitate(uNume)
**************************************************************/

create trigger R3
after update of uNume on Universitate
for each row
begin
  update Aplica
  set uNume = :New.uNume
  where uNume = :Old.uNume;
end;

update Universitate set uNume = 'Al.I.Cuza' where uNume = 'Cuza';
update Universitate set uNume = 'Spiru-Haret' where uNume = 'Spiru Haret';
select * from Universitate;
select * from Aplica;

/**************************************************************
  mai multe triggere pe acelasi eveniment
**************************************************************/

delete from Student;
delete from Aplica;
 drop trigger R7;
create trigger R7
before insert on Student
for each row
when (New.dimLiceu < 100 or New.dimLiceu > 5000)
begin
  --select raise(ignore); --in SQLite
  raise_application_error (-20999,'dimensiune nepermisa'); --in Oracle
end;

insert into Student values ('444', 'Nancy', 9.50, 500);
insert into Student values ('555', 'Otis', 9.50, 50);
insert into Student values ('666', 'Peter', 9.50, 8000);
select * from Student;
select * from Aplica;

drop trigger R7;

create trigger R7
after insert on Student
for each row
when (New.dimLiceu < 100 or New.dimLiceu > 5000)
begin
  delete from Student where sID = :New.sID;
end;

insert into Student values ('777', 'Quincy', 9.50, 1000);
insert into Student values ('888', 'Rita', 9.50, 10000); --eroare de tip mutating table in Oracle
select * from Student;
select * from Aplica;

--find triggers
select * from user_triggers;-- where table_name = 'STUDENT';

drop trigger R1;
drop trigger R2;
drop trigger R3;
drop trigger R4;
drop trigger R5;
drop trigger R6;
drop trigger R7;
delete from Student;
delete from Aplica;


/**************************************************************
  cand numarul de inscrieri creste de la 16000 la peste 16000, elimina aplicatiile la
    'Fizica' si modifica deciziile pe 'U' (undecided)
**************************************************************/
drop trigger TooMany;
create trigger TooMany
after update of inscrieri on Universitate
for each row
when (Old.inscrieri <= 16000 and New.inscrieri > 16000)
begin
  delete from Aplica
    where uNume = :New.uNume and specializare = 'Fizica';
  update Aplica
    set decizie = 'U'
    where uNume = :New.uNume
    and decizie = 'DA';
end;

select * from Aplica;
select * from Universitate;
update Universitate set inscrieri = inscrieri + 2000;
select * from Aplica;

