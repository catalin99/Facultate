CREATE OR REPLACE PACKAGE manager_facultate IS
    g_today_date  DATE:= SYSDATE;
    PROCEDURE student_varsta (stud_id STUDENTI.ID%type);
END manager_facultate;

CREATE OR REPLACE PACKAGE BODY manager_facultate IS

    FUNCTION afiseaza_varsta(data_nastere DATE)
    RETURN VARCHAR2 AS
        g_today_date   DATE:= SYSDATE;
        v_today_years        NUMBER:= FLOOR((g_today_date - data_nastere)/365);
        v_today_months       NUMBER:= trunc(months_between(g_today_date,data_nastere)) - (trunc(months_between(g_today_date,data_nastere) / 12) * 12);
        v_today_days         NUMBER:= trunc(g_today_date) - add_months(data_nastere, trunc(months_between(g_today_date,data_nastere)));
        v_rezultat varchar2(1000) := '';
    BEGIN
        v_rezultat := v_rezultat || v_today_years || ' de ani, ' || v_today_months || ' de luni si ' || v_today_days || ' zile.';
        RETURN v_rezultat;
    END afiseaza_varsta;
    
    PROCEDURE student_varsta (stud_id STUDENTI.ID%type) IS
      v_data_nastere studenti.data_nastere%TYPE;
    BEGIN
        SELECT data_nastere INTO v_data_nastere FROM STUDENTI where id=stud_id;
        DBMS_OUTPUT.PUT_LINE('Studentul nascut pe data de ' || v_data_nastere || ' are: ' ||  afiseaza_varsta(v_data_nastere));
    END student_varsta;
    
END manager_facultate;

set serveroutput on;
BEGIN
   manager_facultate.student_varsta(3);
END;