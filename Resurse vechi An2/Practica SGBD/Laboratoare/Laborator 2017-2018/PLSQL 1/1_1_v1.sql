set serveroutput on;
DECLARE
  g_v_nume_familie VARCHAR2(20) := &i_nume_familie;
  l_v_nume_temp number;
  l_v_id_temp STUDENTI.ID%TYPE;
  l_v_prenume_temp STUDENTI.PRENUME%TYPE;
  l_v_nota_min_temp NOTE.valoare%TYPE;
  l_v_nota_max_temp NOTE.valoare%TYPE;
BEGIN
  DBMS_OUTPUT.PUT_LINE('Numele introdus este: ' || g_v_nume_familie || '.');
  SELECT COUNT(*) INTO l_v_nume_temp FROM STUDENTI where nume=g_v_nume_familie group by nume order by 1;
  IF(l_v_nume_temp < 1)
    THEN
      DBMS_OUTPUT.PUT_LINE('Numele ' || g_v_nume_familie || ' nu exista in tabela!');
  ELSE
    DBMS_OUTPUT.PUT_LINE('Exista ' || l_v_nume_temp || ' studenti cu acest nume.');
    SELECT id, prenume INTO l_v_id_temp, l_v_prenume_temp from (SELECT * FROM (SELECT id, prenume from studenti where nume = 'Lupu' order by 2 asc) WHERE ROWNUM<2);
    DBMS_OUTPUT.PUT_LINE('Primul student are id-ul: ' || l_v_id_temp || ' si prenumele: ' || l_v_prenume_temp || '.');
    SELECT min(VALOARE) into l_v_nota_min_temp from studenti s join note n on s.id=n.ID_STUDENT where s.id like l_v_id_temp;
    SELECT max(VALOARE) into l_v_nota_max_temp from studenti s join note n on s.id=n.ID_STUDENT where s.id like l_v_id_temp;
    DBMS_OUTPUT.PUT_LINE('Nota minima: ' || l_v_nota_min_temp || ' si nota maxima: ' || l_v_nota_max_temp || '.');
    DBMS_OUTPUT.PUT_LINE('Nota maxima la puterea celei minime: ' || (power(l_v_nota_max_temp,l_v_nota_min_temp)) || '.');
  END IF;
END;