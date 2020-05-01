SET SERVEROUTPUT ON;

DROP TABLE facebook_user;
DROP type fb_users FORCE;
DROP type pro_users FORCE;

CREATE OR REPLACE TYPE fb_users FORCE AS OBJECT
(username varchar2(10),
 nume varchar2(10),
 prenume varchar2(10),
 sex varchar2(1),
 oras varchar2(10),
 telefon number(11), 
 data_nastere date,
 member procedure editeaza_user(telefon number),
 member procedure editeaza_user(oras varchar2, telefon number),
 NOT FINAL member procedure afiseaza_user,
 map member FUNCTION afiseaza_oras RETURN VARCHAR2,
 CONSTRUCTOR FUNCTION fb_users(username varchar2, nume varchar2, prenume varchar2, data_nastere date)
   RETURN SELF AS RESULT
) NOT FINAL;
/ 

CREATE OR REPLACE TYPE BODY fb_users AS

   MAP MEMBER FUNCTION afiseaza_oras RETURN VARCHAR2 IS
   BEGIN
    RETURN oras;
   END;

   MEMBER PROCEDURE editeaza_user(telefon number) IS
   BEGIN
       SELF.telefon := telefon;
   END editeaza_user;
   
   MEMBER PROCEDURE editeaza_user(oras varchar2, telefon number) IS
   BEGIN
       SELF.telefon := telefon;
       SELF.oras := oras;
   END editeaza_user;
   
   MEMBER PROCEDURE afiseaza_user IS
   BEGIN
       DBMS_OUTPUT.PUT_LINE('Nume: ' || SELF.nume || ' , Prenume: ' || SELF.prenume || ' , Sex: ' || SELF.sex || ' , Oras: ' || SELF.oras || ' , Telefon: ' || SELF.telefon || ' , Data Nastere: ' || SELF.data_nastere);
   END afiseaza_user;
   
   CONSTRUCTOR FUNCTION fb_users(username varchar2, nume varchar2, prenume varchar2, data_nastere date)
    RETURN SELF AS RESULT
   AS
   BEGIN
    SELF.username := username;
    SELF.nume := nume;
    SELF.prenume := prenume;
    SELF.data_nastere := sysdate;
    SELF.sex := NULL;
    SELF.oras := NULL;
    SELF.telefon := NULL;
    RETURN;
   END;
END;
/

CREATE OR REPLACE TYPE pro_users FORCE UNDER fb_users
(    
   no_ads VARCHAR2(3),
   OVERRIDING member procedure afiseaza_user
)
/

CREATE OR REPLACE TYPE BODY pro_users AS
    OVERRIDING MEMBER PROCEDURE afiseaza_user IS
    BEGIN
       dbms_output.put_line('User ' || SELF.username || ' is a premium user, no_ads function is: ' || no_ads);
    END afiseaza_user;
END;
/

CREATE TABLE facebook_user (id VARCHAR2(4), obiect fb_users);

DECLARE
   v_user1 fb_users;
   v_user2 fb_users;
   v_user3 fb_users;
   v_user4 pro_users;
BEGIN
   v_user1 := fb_users('pop2', 'Popescu', 'Ionut', 'M', 'Suceava', 0000000000, TO_DATE('11/04/1994', 'dd/mm/yyyy'));
   v_user2 := fb_users('vasy2019', 'Vasilescu', 'George', 'M', 'Moldova', 0134521674, TO_DATE('22/03/1995', 'dd/mm/yyyy'));
   v_user3 := fb_users('logalex96', 'Alex', 'Loghin', TO_DATE('02/02/1996', 'dd/mm/yyyy'));
   v_user4 := pro_users('firelion', 'Stefan', 'Gigel', 'F', 'Bucuresti', 0423521674, TO_DATE('22/07/1992', 'dd/mm/yyyy'), 'on');
   
   
   dbms_output.put_line('user1 -- username: ' || v_user1.username);
   dbms_output.put_line('user1 -- nume si prenume: ' || v_user1.nume || ' ' || v_user1.prenume || ' , ' || v_user1.telefon || ' , ' || v_user1.oras);
   v_user1.editeaza_user('Bacau', 0747295142);
   dbms_output.put_line('user1 -- nume si prenume: ' || v_user1.nume || ' ' || v_user1.prenume || ' , ' || v_user1.telefon || ' , ' || v_user1.oras);
   v_user2.afiseaza_user();
   v_user4.afiseaza_user();
   
   
   insert into facebook_user values ('100', v_user1);
   insert into facebook_user values ('101', v_user2);
   insert into facebook_user values ('102', v_user3);
   insert into facebook_user values ('103', v_user4);

END;

--select * from facebook_user order by obiect;