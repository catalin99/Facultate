set serveroutput on;
DROP TABLE problema_1;
CREATE TABLE problema_1(A number, B number);
DECLARE
   g_c_number CONSTANT INTEGER := &conts_number;
   v_contor INTEGER := 1;
   v_a_contor INTEGER := 0;
   v_contor_temp_1 INTEGER := 0;
   v_contor_temp_2 INTEGER := 0;
BEGIN
   FOR v_a_contor in 1..10000 LOOP
       v_contor_temp_1 := length(v_a_contor);
       FOR v_contor IN 1..v_contor_temp_1 LOOP
           v_contor_temp_2 :=  v_contor_temp_2 + substr(v_a_contor,v_contor,1);
       END LOOP;
     if (mod(v_contor_temp_2,9)=g_c_number)
        THEN
            DECLARE
                b number := 0;
                i number := 0;
                v_check number := 0;
            BEGIN
                b := v_a_contor;
                for i IN 1..b LOOP
                  if(mod(b,i)=0)
                    then
                      v_check := v_check + 1;
                  end if;
                end loop;
                if (v_check > 2)
                  THEN
                    b := 0;
                else
                    b := 1;
                end if;
                INSERT INTO problema_1 (A,B) VALUES (v_a_contor, b);
            end;
     end if;
     v_contor_temp_2 := 0;
   END LOOP;
END;