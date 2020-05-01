CREATE OR REPLACE PACKAGE plsql_lab4 IS
      TYPE info_student IS RECORD(
        id_s studenti_copy.id%type,
        bursa FLOAT
        );
      CURSOR lista_studenti IS SELECT ID, bursa FROM studenti_copy ORDER BY id;
      PROCEDURE marire_bursa (v_info_student info_student);
END plsql_lab4;

CREATE OR REPLACE PACKAGE BODY plsql_lab4 IS

    PROCEDURE marire_bursa (v_info_student info_student) AS
        v_bursa_actuala studenti_copy.bursa%TYPE;
    BEGIN
        SELECT bursa into v_bursa_actuala from studenti_copy where id=v_stud.id_s;
        DBMS_OUTPUT.PUT_LINE(info_student);
    END;
  
END plsql_lab4;

set serveroutput on;
BEGIN
    v_s1 plsql_lab4.info_student;
    v_s1 plsql_lab4.info_student.id_s := 4;
    v_s1 plsql_lab4.info_student.bursa := 0.3;
    plsql_lab4.marire_bursa(v_s1);
END;