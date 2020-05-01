--1
/*select nr_matricol from studenti 
                 minus 
                 select s.nr_matricol from studenti s, note n where s.nr_matricol=n.nr_matricol and valoare=4;
                   
select count(s.nr_matricol) from studenti s, note n
    where s.nr_matricol=n.nr_matricol and valoare>4 and an=3; 
    
select count(bursa), avg(valoare) from studenti s, note n where s.nr_matricol=n.nr_matricol
             group by s.nr_matricol,nume,an
                 having avg(valoare)>4 and an=2;*/
    
drop trigger integralist;
create trigger integralist after delete or insert or update on note
declare
nr_burse_2 number;
nr_burse_3 number;
avg_2 number;
avg_3 number;
suma number:=500;
begin
  select count(s.nr_matricol) into nr_burse_2 from studenti s, note n
        where s.nr_matricol=n.nr_matricol and valoare>4 and an=2;
  update studenti set bursa=suma/nr_burse_2 where an=2;
  
  select count(s.nr_matricol) into nr_burse_3 from studenti s, note n
          where s.nr_matricol=n.nr_matricol and valoare>4 and an=3;
  update studenti set bursa=suma/nr_burse_3 where an=3;
end;

delete from note where nr_matricol='112';

update note set valoare=5 where nr_matricol='112';
update note set valoare=4;

select nume, bursa, an from studenti;

--2
drop trigger timestamp_job;
create trigger timestamp_job before delete or insert or update on note_t
for each row
begin
   :new.createT := sysdate;
end;

select * from note_t;  
update note_t set valoare=7;
select * from note_t;



DROP TABLE studenti cascade constraints
/
DROP TABLE cursuri cascade constraints
/
DROP TABLE note cascade constraints
/
DROP TABLE note_t cascade constraints
/
DROP TABLE profesori cascade constraints
/

DROP TABLE didactic cascade constraints
/


CREATE TABLE studenti(
  nr_matricol CHAR(3) NOT NULL PRIMARY KEY,
  nume VARCHAR2(10) not null,
  prenume VARCHAR2(10) not null,
  an NUMBER(1),
  grupa CHAR(2),
  bursa NUMBER(6,2),
  data_nastere DATE
  )
/

CREATE TABLE cursuri(
  id_curs CHAR(4) PRIMARY KEY,
  titlu_curs VARCHAR2(15) not null,
  an NUMBER(1),
  semestru NUMBER(1),
  credite NUMBER(2)
  )
/

CREATE TABLE note(
  nr_matricol CHAR(3),
  id_curs CHAR(4),
  valoare NUMBER(2),
  data_notare DATE
  )
/

CREATE TABLE profesori(
  id_prof CHAR(4) not null PRIMARY KEY,
  nume CHAR(10),
  prenume CHAR(10),
  grad_didactic VARCHAR2(5)
  )
/

CREATE TABLE didactic(
  id_prof CHAR(4) ,
  id_curs CHAR(4),
  PRIMARY KEY(id_prof,id_curs)
  )
/
CREATE TABLE note_t(
  createT timestamp,
  nr_matricol CHAR(4) NOT NULL,
  id_curs CHAR(4),
  valoare NUMBER(2),
  data_notare DATE
  )
/

alter table note add FOREIGN KEY(nr_matricol) references studenti(nr_matricol);
alter table note add FOREIGN KEY (id_curs) references cursuri(id_curs);
alter table note_t add FOREIGN KEY(nr_matricol) references studenti(nr_matricol);
alter table note_t add FOREIGN KEY (id_curs) references cursuri(id_curs);
alter table didactic add FOREIGN KEY (id_curs) references cursuri(id_curs);
alter table didactic add FOREIGN KEY (id_prof) references profesori(id_prof);


--anul 3 de studiu 
INSERT INTO studenti VALUES ('111', 'Popescu', 'Bogdan',3, 'A2',NULL, TO_DATE('17/02/1995', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('112', 'Prelipcean', 'Radu',3, 'A2',NULL, TO_DATE('26/05/1995', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('113', 'Antonie', 'Ioana',3, 'A2',450, TO_DATE('3/01/1995', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('114', 'Arhire', 'Raluca',3, 'A4',NULL, TO_DATE('26/12/1995', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('115', 'Panaite', 'Alexandru',3, 'B3',NULL, TO_DATE('13/04/1995', 'dd/mm/yyyy'));

-- anul 2 de studiu
INSERT INTO studenti VALUES ('116', 'Bodnar', 'Ioana',2, 'A1',NULL, TO_DATE('26/08/1996', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('117', 'Archip', 'Andrada',2, 'A1',350, TO_DATE('03/04/1996', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('118', 'Ciobotariu', 'Ciprian',2, 'A1',350, TO_DATE('03/04/1996', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('119', 'Bodnar', 'Ioana',2, 'B2',NULL, TO_DATE('10/06/1996', 'dd/mm/yyyy'));

-- anul 1 de studiu
INSERT INTO studenti VALUES ('120', 'Pintescu', 'Andrei',1, 'B1',250, TO_DATE('26/08/1997', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('121', 'Arhire', 'Alexandra',1, 'B1',NULL, TO_DATE('02/07/1997', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('122', 'Cobzaru', 'George',1, 'B1',350, TO_DATE('29/04/1997', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('123', 'Bucur', 'Andreea',1, 'B2',NULL, TO_DATE('10/05/1997', 'dd/mm/yyyy'));

-- populare tabela cursuri - cate 3 pt fiecare an
INSERT INTO cursuri VALUES ('21', 'Logica', 1, 1, 5);
INSERT INTO cursuri VALUES ('22', 'Matematica', 1, 1, 4);
INSERT INTO cursuri VALUES ('23', 'OOP', 1, 2, 5);
INSERT INTO cursuri VALUES ('24', 'BD', 2, 1, 8);
INSERT INTO cursuri VALUES ('25', 'Java', 2, 2, 5);
INSERT INTO cursuri VALUES ('26', 'Tehnologii Web', 2, 2, 5);
INSERT INTO cursuri VALUES ('27', 'Sec. Info.', 3, 1, 5);
INSERT INTO cursuri VALUES ('28', 'DSFUM', 3, 1, 6);
INSERT INTO cursuri VALUES ('29', 'Limbaje formale', 2, 1, 5);
-- inca una din anu 3 :D


-- populare tabela profesori
INSERT INTO profesori VALUES ('p1', 'Masalagiu', 'Cristian', 'Prof');
INSERT INTO profesori VALUES ('p2', 'Buraga', 'Sabin', 'Conf');
INSERT INTO profesori VALUES ('p3', 'Lucanu', 'Dorel', 'Prof');
INSERT INTO profesori VALUES ('p4', 'Tiplea', 'Laurentiu', 'Prof');
INSERT INTO profesori VALUES ('p5', 'Iacob', 'Florin', 'Lect');
INSERT INTO profesori VALUES ('p6', 'Breaban', 'Mihaela', 'Conf');
INSERT INTO profesori VALUES ('p7', 'Varlan', 'Cosmin', 'Lect');
INSERT INTO profesori VALUES ('p8', 'Frasinaru', 'Cristian', 'Prof');
INSERT INTO profesori VALUES ('p9', 'Ciobaca', 'Stefan', 'Conf');
INSERT INTO profesori VALUES ('p10', 'Captarencu', 'Oana', 'Lect');
INSERT INTO profesori VALUES ('p11', 'Moruz', 'Alexandru', 'Lect');


-- populare tabela didactic
INSERT INTO didactic VALUES ('p1','21');
INSERT INTO didactic VALUES ('p9','21');
INSERT INTO didactic VALUES ('p5','22');
INSERT INTO didactic VALUES ('p3','23');
INSERT INTO didactic VALUES ('p6','24');
INSERT INTO didactic VALUES ('p7','24');
INSERT INTO didactic VALUES ('p8','25');
INSERT INTO didactic VALUES ('p2','26');
INSERT INTO didactic VALUES ('p4','27');
INSERT INTO didactic VALUES ('p11','28');


-- populare tabel note - studentii din anul 3 au toate examenele date, cei din anul 2 doar pe cele din anul 1, cei din 1 - nimic
INSERT INTO note VALUES ('111', '21',  8, TO_DATE('17/02/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('111', '22',  9, TO_DATE('19/02/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('111', '23', 10, TO_DATE('24/06/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('111', '24',  9, TO_DATE('17/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('111', '25',  7, TO_DATE('20/06/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('111', '26',  8, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note VALUES ('112', '21',  7, TO_DATE('25/02/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('112', '22',  6, TO_DATE('19/02/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('112', '23',  5, TO_DATE('24/06/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('112', '24',  6, TO_DATE('17/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('112', '25',  7, TO_DATE('20/06/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('112', '26',  4, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note VALUES ('113', '21',  9, TO_DATE('17/02/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('113', '22',  9, TO_DATE('19/02/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('113', '23',  7, TO_DATE('24/06/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('113', '24', 10, TO_DATE('17/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('113', '25',  4, TO_DATE('20/06/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('113', '26',  7, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note VALUES ('114', '21',  6, TO_DATE('17/02/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('114', '22',  9, TO_DATE('19/02/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('114', '23', 10, TO_DATE('24/06/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('114', '24',  4, TO_DATE('17/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('114', '25',  5, TO_DATE('20/06/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('114', '26',  4, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note VALUES ('115', '21', 10, TO_DATE('17/02/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('115', '22',  7, TO_DATE('19/02/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('115', '23', 10, TO_DATE('24/06/2014', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('115', '24', 10, TO_DATE('17/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('115', '25',  8, TO_DATE('20/06/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('115', '26',  9, TO_DATE('21/06/2015', 'dd/mm/yyyy'));


INSERT INTO note VALUES ('116', '21', 10, TO_DATE('18/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('116', '22', 10, TO_DATE('20/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('116', '23',  9, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note VALUES ('117', '21',  7, TO_DATE('18/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('117', '22',  6, TO_DATE('20/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('117', '23',  4, TO_DATE('25/06/2015', 'dd/mm/yyyy'));

INSERT INTO note VALUES ('118', '21',  7, TO_DATE('22/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('118', '22',  7, TO_DATE('24/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('118', '23',  7, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note VALUES ('119', '21',  7, TO_DATE('18/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('119', '22',  8, TO_DATE('20/02/2015', 'dd/mm/yyyy'));
INSERT INTO note VALUES ('119', '23',  9, TO_DATE('21/06/2015', 'dd/mm/yyyy'));




-- populare tabel note - studentii din anul 3 au toate examenele date, cei din anul 2 doar pe cele din anul 1, cei din 1 - nimic
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '21',  8, TO_DATE('17/02/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '22',  9, TO_DATE('19/02/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '23', 10, TO_DATE('24/06/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '24',  9, TO_DATE('17/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '25',  7, TO_DATE('20/06/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '26',  8, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('112', '21',  7, TO_DATE('25/02/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('112', '22',  6, TO_DATE('19/02/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('112', '23',  5, TO_DATE('24/06/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('112', '24',  6, TO_DATE('17/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('112', '25',  7, TO_DATE('20/06/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('112', '26',  4, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '21',  9, TO_DATE('17/02/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '22',  9, TO_DATE('19/02/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '23',  7, TO_DATE('24/06/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '24', 10, TO_DATE('17/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '25',  4, TO_DATE('20/06/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '26',  7, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '21',  6, TO_DATE('17/02/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '22',  9, TO_DATE('19/02/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '23', 10, TO_DATE('24/06/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '24',  4, TO_DATE('17/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '25',  5, TO_DATE('20/06/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '26',  4, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '21', 10, TO_DATE('17/02/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '22',  7, TO_DATE('19/02/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '23', 10, TO_DATE('24/06/2014', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '24', 10, TO_DATE('17/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '25',  8, TO_DATE('20/06/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '26',  9, TO_DATE('21/06/2015', 'dd/mm/yyyy'));


INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('116', '21', 10, TO_DATE('18/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('116', '22', 10, TO_DATE('20/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('116', '23',  9, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('117', '21',  7, TO_DATE('18/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('117', '22',  6, TO_DATE('20/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('117', '23',  4, TO_DATE('25/06/2015', 'dd/mm/yyyy'));

INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('118', '21',  7, TO_DATE('22/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('118', '22',  7, TO_DATE('24/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('118', '23',  7, TO_DATE('21/06/2015', 'dd/mm/yyyy'));

INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('119', '21',  7, TO_DATE('18/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('119', '22',  8, TO_DATE('20/02/2015', 'dd/mm/yyyy'));
INSERT INTO note_t(nr_matricol, id_curs, valoare, data_notare) VALUES ('119', '23',  9, TO_DATE('21/06/2015', 'dd/mm/yyyy'));



INSERT INTO profesori VALUES('p20', 'PASCARIU', 'GEORGIANA', null);
INSERT INTO profesori VALUES('p21', 'LAZAR', 'LUCIAN', null);
INSERT INTO profesori VALUES('p22', 'Kristo', 'ROBERT', null);
INSERT INTO profesori VALUES('p23', 'Nastasa', 'Laura', null);
INSERT INTO profesori VALUES('p24', 'PASAT', 'Tiberiu', null);

COMMIT;