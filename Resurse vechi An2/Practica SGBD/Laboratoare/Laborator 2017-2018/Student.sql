set serveroutput on;
CREATE TABLE minions (culoare varchar2(20), numar_ochi number(3), nume varchar2(20));
 /
DECLARE
   TYPE minion IS RECORD(
      culoare varchar2(20) := 'Galben', 
      numar_ochi number(3), 
      nume varchar2(20)
      );
   v_minion minion;   
BEGIN      
   v_minion.culoare:='Galben';
   v_minion.numar_ochi := 2;
   v_minion.nume:='Kevin';
   INSERT INTO MINIONS VALUES V_MINION;
   DBMS_OUTPUT.PUT_LINE(v_minion.culoare);
END;


create table STUDENTI_COPY as select * from STUDENTI where 1=0;