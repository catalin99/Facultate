set serveroutput on;
DECLARE
  g_c_data_nastere VARCHAR2(30) := '29-02-1996';
  g_c_numar_zile NUMBER;
  g_c_numar_luni NUMBER;
  g_c_ziua_nastere VARCHAR2(30);
BEGIN
  SELECT trunc((SYSDATE-to_date(g_c_data_nastere,'dd-mm-yyyy'))/365), trunc(MONTHS_BETWEEN(SYSDATE,to_date(g_c_data_nastere,'dd-mm-yyyy'))) into g_c_numar_zile, g_c_numar_luni FROM dual;
  SELECT to_char(to_date(g_c_data_nastere,'dd-mm-yyyy'),'day', 'nls_date_language=romanian') into g_c_ziua_nastere from DUAL;
  DBMS_OUTPUT.PUT_LINE(g_c_numar_zile || ' zile si ' || g_c_numar_luni || ' luni si ziua saptamanii este ' || trim(g_c_ziua_nastere) || '.');
end;