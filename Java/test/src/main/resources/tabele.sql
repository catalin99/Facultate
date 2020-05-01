drop table persons cascade constraints
/
drop table movies cascade constraints
/
create table persons
(
    id   integer PRIMARY KEY not null,
    name varchar2(100)       not null
);
/
create table movies
(
    id          integer PRIMARY KEY not null,
    name        varchar2(100)       not null,
    director_id integer             not null
);
/