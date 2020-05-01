SET SERVEROUTPUT ON;

DROP TABLE ERASMUS;

CREATE TABLE ERASMUS(
    NR_MATRICOL VARCHAR2(6) NOT NULL, 
	NUME VARCHAR2(30) NOT NULL, 
	PRENUME VARCHAR2(30) NOT NULL,
    TARA NUMBER(5) NOT NULL
);

DROP INDEX UNIC;
CREATE UNIQUE INDEX UNIC ON ERASMUS(NR_MATRICOL);
 
DECLARE 
   v_i number(3) := 0;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Studenti ce nu au putut fi copiati: ');
    DBMS_OUTPUT.PUT_LINE('');
    WHILE v_i < 100 LOOP
        DECLARE
            v_aux NUMBER(5);
            mesaj VARCHAR2(100);
            CURSOR lista_studenti IS
                SELECT NR_MATRICOL,NUME,PRENUME FROM (SELECT NR_MATRICOL,NUME,PRENUME FROM STUDENTI ORDER BY DBMS_RANDOM.VALUE) WHERE ROWNUM = 1;
        BEGIN
            FOR v_std_linie IN lista_studenti LOOP
                v_aux := dbms_random.value(1,20);
                mesaj := 'Studentul ' || v_std_linie.nr_matricol || ' cu numele ' || v_std_linie.NUME || ' ' || v_std_linie.PRENUME || ' nu a fost copiat.';
                INSERT INTO ERASMUS(NR_MATRICOL,NUME,PRENUME,TARA) VALUES(v_std_linie.NR_MATRICOL,v_std_linie.NUME,v_std_linie.PRENUME,v_aux);
            END LOOP;
            EXCEPTION 
            WHEN DUP_VAL_ON_INDEX THEN
                DBMS_OUTPUT.PUT_LINE(mesaj);
        END;
        SELECT COUNT(NR_MATRICOL) INTO v_i FROM ERASMUS;
    END LOOP;
    DECLARE
        cursor studenti_copiati IS
            SELECT NR_MATRICOL,NUME,PRENUME FROM ERASMUS;
    BEGIN
        DBMS_OUTPUT.PUT_LINE('');
        DBMS_OUTPUT.PUT_LINE('Studenti copiati: ');
        DBMS_OUTPUT.PUT_LINE('');
        FOR v_std_linie IN studenti_copiati
        LOOP
            DBMS_OUTPUT.PUT_LINE('Studentul ' || v_std_linie.nr_matricol || ' cu numele ' || v_std_linie.NUME || ' ' || v_std_linie.PRENUME || ' a fost copiat cu succes.');
        END LOOP;
    END;
END;