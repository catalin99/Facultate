SET SERVEROUTPUT ON;

drop table studenti_new;

create table studenti_new as select * from studenti where bursa is not null;

CREATE OR REPLACE PACKAGE marire_bursa IS
    PROCEDURE majorare (id_stud studenti.id%TYPE);
    exceptie EXCEPTION;
END  marire_bursa;

CREATE OR REPLACE PACKAGE BODY marire_bursa IS
    PROCEDURE majorare (id_stud studenti.id%TYPE) IS
      v_bursa studenti.bursa%TYPE;
    BEGIN
        UPDATE studenti_new SET bursa=bursa+1800 WHERE ID=id_stud;
        SELECT bursa INTO v_bursa from studenti_new WHERE ID=id_stud;
        IF(v_bursa>3000) THEN
            raise exceptie;
        END IF;
    END;
END marire_bursa;

DECLARE
    CURSOR lista_studenti IS
       SELECT * FROM studenti_new WHERE BURSA IS NOT NULL;
BEGIN
    FOR v_std_linie IN lista_studenti
    LOOP
        BEGIN
            marire_bursa.majorare(v_std_linie.id);
        EXCEPTION
        WHEN marire_bursa.exceptie THEN
            UPDATE studenti_new SET bursa=3000 WHERE ID=v_std_linie.id;
        END;
    END LOOP;
END;