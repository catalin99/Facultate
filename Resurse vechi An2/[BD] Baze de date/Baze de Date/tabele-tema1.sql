DROP TABLE CONTRACTE
/
CREATE TABLE CONTRACTE 
   (CODC NUMBER(2) NOT NULL PRIMARY KEY, 
	DATAC DATE NULL, 
	CODB NUMBER(2) NOT NULL, 
	CODF NUMBER(2) NOT NULL, 
	DATAF DATE NULL,) 
/
DROP TABLE SOCIETATI
/
CREATE TABLE SOCIETATI 
   (CODS NUMBER(2) NOT NULL PRIMARY KEY, 
	DENS CHAR(10) NULL, 
	CAPITAL NUMBER(7,2) NULL, 
	TIPSOC CHAR(10),)
/
DROP TABLE ARTICOLE
/
CREATE TABLE ARTICOLE 
   (CODCA NUMBER(2) NOT NULL, 
	CODPA NUMBER(2) NOT NULL,
	CANT NUMBER(2) NOT NULL, 
	PRET NUMBER(2) NOT NULL,
	CONSTRAINT pk_ARTICOLEID PRIMARY KEY (CODCA,CODPA))
/
DROP TABLE PRODUSE
/
CREATE TABLE PRODUSE 
   (CODP NUMBER(2) NOT NULL PRIMARY KEY, 
	DENP CHAR(10) NULL, 
	TIPP CHAR(10) NULL,) 
/
DROP TABLE LIVRARI
/
CREATE TABLE LIVRARI 
   (CODCL NUMBER(2) NOT NULL,
	CODPL NUMBER(2) NOT NULL,
	CANTL NUMBER(2) NOT NULL,
	DATAL DATE NULL,) 
/
INSERT INTO CONTRACTE VALUES 
	(1, TO_DATE('19/12/2012', 'dd/mm/yyyy'),1,1, TO_DATE('10/09/2013', 'dd/mm/yyyy'))
/
INSERT INTO CONTRACTE VALUES 
	(2, TO_DATE('17/12/2012', 'dd/mm/yyyy'),2,2, TO_DATE('13/05/2013', 'dd/mm/yyyy'))
/
INSERT INTO CONTRACTE VALUES 
	(3, TO_DATE('25/10/2012', 'dd/mm/yyyy'),3,3, TO_DATE('17/01/2013', 'dd/mm/yyyy'))
/
INSERT INTO CONTRACTE VALUES 
	(4, TO_DATE('17/10/2011', 'dd/mm/yyyy'),4,4, TO_DATE('12/12/2012', 'dd/mm/yyyy'))
/
INSERT INTO CONTRACTE VALUES 
	(5, TO_DATE('17/12/2011', 'dd/mm/yyyy'),5,5, TO_DATE('17/11/2012', 'dd/mm/yyyy'))
/
INSERT INTO SOCIETATI VALUES 
	(1, 'DIXON',1000,'SRL')
/
INSERT INTO SOCIETATI VALUES 
	(2, 'AXELMA',15000,'SRL')
/
INSERT INTO SOCIETATI VALUES 
	(3, 'XILON',1439,'SA')
/
INSERT INTO SOCIETATI VALUES 
	(4, 'IXLOPOLIX',145576,'IF')
/
INSERT INTO SOCIETATI VALUES 
	(5, 'COAXIS',1876,'SA')
/
INSERT INTO ARTICOLE VALUES 
	(1, 1,2,10)
/
INSERT INTO ARTICOLE VALUES 
	(1, 2,4,5)
/
INSERT INTO ARTICOLE VALUES 
	(2, 1,10,1)
/
INSERT INTO ARTICOLE VALUES 
	(4, 1,3,2)
/
INSERT INTO ARTICOLE VALUES 
	(5, 4,5,6)
/
INSERT INTO ARTICOLE VALUES 
	(3, 2,1,1)
/
INSERT INTO ARTICOLE VALUES 
	(5, 2,4,5)
/
INSERT INTO PRODUSE VALUES 
	(1, 'PAPER','LIBRARY')
/
INSERT INTO PRODUSE VALUES 
	(2, 'BIC','LIBRARY')
/
INSERT INTO PRODUSE VALUES 
	(1, 'WANDG','DETERG')
/
INSERT INTO PRODUSE VALUES 
	(4, 'BREAD','ALIM')
/
INSERT INTO PRODUSE VALUES 
	(2, 'STIKERS','LIBRARY')
/
INSERT INTO LIVRARI VALUES 
	(1,1,1, TO_DATE('17/10/2012', 'dd/mm/yyyy'))
/
INSERT INTO LIVRARI VALUES 
	(2,2,3, TO_DATE('11/09/2012', 'dd/mm/yyyy'))
/
INSERT INTO LIVRARI VALUES 
	(3,1,2, TO_DATE('17/06/2011', 'dd/mm/yyyy'))
/
INSERT INTO LIVRARI VALUES 
	(4,4,3, TO_DATE('11/11/2012', 'dd/mm/yyyy'))
/
INSERT INTO LIVRARI VALUES 
	(5,2,2, TO_DATE('02/01/2012', 'dd/mm/yyyy'))
/
COMMIT;