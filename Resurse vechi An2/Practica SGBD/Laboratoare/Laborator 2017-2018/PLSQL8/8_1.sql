CREATE OR REPLACE PROCEDURE EXPORT_DATA_TABLE IS
    v_fisier UTL_FILE.FILE_TYPE;
    v_temp  VARCHAR2(10000);
    CURSOR lista_studenti IS SELECT * FROM STUDENTI;
    CURSOR lista_prieteni IS SELECT * FROM PRIETENI;
BEGIN
    v_fisier := UTL_FILE.FOPEN('MYDIR','tabela_studenti.txt','W');
    v_temp   := 'ID, NR_MATRICOL, NUME, PRENUME, AN, GRUPA, BURSA, DATA_NASTERE, EMAIL';
    UTL_FILE.put_line(v_fisier, v_temp);
    
    FOR v_std_linie IN lista_studenti
    LOOP
        v_temp := v_std_linie.ID || ',' || v_std_linie.NR_MATRICOL || ',' || v_std_linie.NUME || ',' || v_std_linie.PRENUME || ',' || v_std_linie.AN || ',' || v_std_linie.GRUPA || ',' || v_std_linie.BURSA || ',' || v_std_linie.DATA_NASTERE || ',' || v_std_linie.EMAIL;
        UTL_FILE.put_line(v_fisier, v_temp);
    END LOOP;
    UTL_FILE.FCLOSE(v_fisier);
    
    v_fisier := UTL_FILE.FOPEN('MYDIR', 'tabela_prieteni.txt', 'W');
    v_temp := 'ID, ID_STUDENT1, ID_STUDENT2';
    UTL_FILE.put_line(v_fisier, v_temp);
    
    FOR v_prt_linie IN lista_prieteni
    LOOP
        v_temp := v_prt_linie.ID || ',' || v_prt_linie.ID_STUDENT1 || ',' || v_prt_linie.ID_STUDENT2;
        UTL_FILE.put_line(v_fisier, v_temp);
    END LOOP;
    UTL_FILE.FCLOSE(v_fisier);
    
    DBMS_OUTPUT.PUT_LINE('Am exportat tabelele studenti si prieteni cu succes.');
    
    EXCEPTION WHEN OTHERS THEN
    IF UTL_FILE.IS_OPEN(v_fisier)
    THEN
    DBMS_OUTPUT.PUT_LINE('A avut loc o exceptie...');
    UTL_FILE.FCLOSE(v_fisier);
    END IF;
END;
/

BEGIN
  EXPORT_DATA_TABLE;
END;
/