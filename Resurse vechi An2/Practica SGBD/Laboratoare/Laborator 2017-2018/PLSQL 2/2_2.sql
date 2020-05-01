DECLARE
   CURSOR update_B IS
      SELECT * FROM PROBLEMA_1 FOR UPDATE OF B NOWAIT;
    v_contor_1 PROBLEMA_1.A%TYPE := 0;
    v_contor_2 PROBLEMA_1.A%TYPE := 0;
    v_sqrt_temp1 PROBLEMA_1.A%TYPE := 0;
    v_sqrt_temp2 PROBLEMA_1.A%TYPE := 0;
    v_counter NUMBER := 0;
BEGIN
   FOR v_linie IN update_B LOOP
     v_contor_1 := 5*v_linie.A*v_linie.A+4;
     v_contor_2 := 5*v_linie.A*v_linie.A-4;
     v_sqrt_temp1 := trunc(sqrt(v_contor_1))*trunc(sqrt(v_contor_1));
     v_sqrt_temp2 := trunc(sqrt(v_contor_2))*trunc(sqrt(v_contor_2));
     IF ((v_sqrt_temp1=v_contor_1) or (v_sqrt_temp2=v_contor_2))
        THEN
          IF(v_linie.B=0)
            THEN
            UPDATE PROBLEMA_1 SET B=1 WHERE CURRENT OF update_B;
            v_counter := v_counter + 1;
          END IF;
      ELSE
        IF(v_linie.B = 1)
          THEN
            UPDATE PROBLEMA_1 SET B=0 WHERE CURRENT OF update_B;
            v_counter := v_counter + 1;
        END IF;
     END IF;
   END LOOP;
   DBMS_OUTPUT.PUT_LINE('Numarul de linii modificate: ' || v_counter);
END;