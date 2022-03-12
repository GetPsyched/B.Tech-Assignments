drop database if exists university;
create database university;
use university;

drop table if exists department;
create table department (
    dept_name  char(20)  primary key,
    building   char(20),
    budget     int
);

drop table if exists instructor;
create table instructor (
    ID         int          primary key,
    name       varchar(40)  not null,
    dept_name  char(20)     references department(dept_name),
    salary     int
);

drop table if exists student;
create table student (
    ID         int          primary key,
    name       varchar(40)  not null,
    dept_name  char(20)     references department(dept_name),
    tot_cred   int
);

drop table if exists course;
create table course (
    course_id  char(7)      primary key check (course_id like '____-__'),
    title      varchar(40)  not null,
    dept_name  char(20)     references department(dept_name),
    credits    int
);

drop table if exists prereq;
create table prereq (
    course_id  char(7)  references course(course_id),
    prereq_id  int      not null
);

drop table if exists classroom;
create table classroom (
    building  char(20)  unique,
    room_no   char(7)   unique check (room_no like '___-___'),
    capacity  int
);

drop table if exists time_slot;
create table time_slot (
    time_slot_id  int primary key,
    day           char(9)
    check (
        day = "Sunday"
        or day = "Monday"
        or day = "Tuesday"
        or day = "Wednesday"
        or day = "Thursday"
        or day = "Friday"
        or day = "Saturday"
    ),
    start_time    time,
    end_time      time
);

drop table if exists section;
create table section (
    course_id     char(7)   primary key references course(course_id),
    sec_id        int       unique not null,
    semester      int       unique not null,
    year          int       unique not null,
    building      char(20)  references classroom(building),
    room_no       char(7)   references classroom(room_no),
    time_slot_id  int       references time_slot(time_slot_id)
);

drop table if exists takes;
create table takes (
    ID         int      primary key references student(ID),
    course_id  char(7)  references section(course_id),
    sec_id     int      references section(sec_id),
    semester   int      references section(semester),
    year       int      references section(year),
    grade      int
);

drop table if exists advisor;
create table advisor (
    s_id  int primary key references student(ID),
    i_id  int references instructor(ID)
);

drop table if exists teaches;
create table teaches (
    ID         int      primary key references instructor(ID),
    course_id  char(7)  references section(course_id),
    sec_id     int      references section(sec_id),
    semester   int      references section(semester),
    year       int      references section(year)
);

-- Insert values
insert into department values ("Civil Engg.",            "Building 1", 123);
insert into department values ("Computer Engg.",         "Building 2", 123);
insert into department values ("Electronics Engg.",      "Building 3", 123);
insert into department values ("Electrical Engg.",       "Building 4", 123);
insert into department values ("Information Technology", "Building 5", 123);
insert into department values ("Mechanical Engg.",       "Building 6", 123);
insert into department values ("Production Engg.",       "Building 7", 123);

insert into instructor values (1, "S.K. Jain",      "Inforamation Technology", 100000);
insert into instructor values (2, "J.K. Chhabra",   "Computer Engg.",          100000);
insert into instructor values (3, "Mayank Dave",    "Computer Engg.",          100000);
insert into instructor values (4, "Pankaj Chandna", "Mechanical Engg.",        100000);

insert into student values (1, "Chetan Meena",           "Civil Engg.",            15);
insert into student values (2, "Gaurav Kumar Verma",     "Information Technology",  5);
insert into student values (3, "Aditi Sharma",           "Mechanical Engg.",        4);
insert into student values (4, "Satvik Verma",           "Computer Engg.",          3);
insert into student values (5, "Yash Kumar",             "Comupter Engg.",          9);
insert into student values (6, "Mondi Lavanya Rishitha", "Mechanical Engg.",       12);
insert into student values (7, "Dibya Bharali",          "Electrical Engg.",       14);
insert into student values (8, "Jatin Sharma",           "Electronics Engg.",       8);
insert into student values (9, "Rahul Maurya",           "Civil Engg.",             6);
insert into student values (10, "Nekiram Nehra",         "Information Technology",  9);
insert into student values (11, "Akash Pandey",          "Production Engg.",       10);

insert into course values ("MAIR-24", "Discrete Mathematics", "Information Technology", 4);
insert into course values ("ITPC-21", "Design and Analysis of Algorithms", "Information Technology", 5);
insert into course values ("ITPC-23", "Java Programming", "Information Technology", 4);
insert into course values ("ITPC-25", "Database Systems", "Information Technology", 5);
insert into course values ("ITPC-27", "Software Engnireeing", "Information Technology", 4);
insert into course values ("ITPC-29", "Computer Organisation", "Information Technology", 4);
insert into course values ("CSPC-27", "Software Engineering", "Computer Engg.", 4);
insert into course values ("CSPC-25", "Database Systems", "Computer Engg.", 4);
insert into course values ("MEPC-16", "Strength of Materials – I", "Mechanical Engg.", 4);

insert into prereq values ("MAIR-24", 2);
insert into prereq values ("ITPC-21", 1);
insert into prereq values ("ITPC-23", 3);
insert into prereq values ("ITPC-27", 5);
insert into prereq values ("ITPC-29", 8);
insert into prereq values ("CSPC-27", 4);
insert into prereq values ("CSPC-25", 9);
insert into prereq values ("MEPC-16", 6);

insert into classroom values ("Lecture Hall Complex", "LHC-101", 130);
insert into classroom values ("Lecture Hall Complex", "LHC-102", 120);
insert into classroom values ("Lecture Hall Complex", "LHC-103", 150);
insert into classroom values ("Lecture Hall Complex", "LHC-104", 140);
insert into classroom values ("Lecture Hall Complex", "LHC-105", 155);
insert into classroom values ("Lecture Hall Complex", "LHC-106", 180);

insert into time_slot values (, "", "", "");
insert into time_slot values (, "", "", "");
insert into time_slot values (, "", "", "");
insert into time_slot values (, "", "", "");
insert into time_slot values (, "", "", "");

insert into section values ("MAIR-24", 4, 3, 2, "Lecture Hall Complex", "LHC-101", 1);
insert into section values ("ITPC-21", 8, 3, 2, "Lecture Hall Complex", "LHC-101", 2);
insert into section values ("ITPC-23", 8, 3, 2, "Lecture Hall Complex", "LHC-104", 3);
insert into section values ("ITPC-27", 9, 3, 2, "Lecture Hall Complex", "LHC-101", 4);
insert into section values ("ITPC-29", 9, 3, 2, "Lecture Hall Complex", "LHC-102", 5);
insert into section values ("CSPC-27", 4, 3, 2, "Lecture Hall Complex", "LHC-104", 6);
insert into section values ("CSPC-25", 4, 3, 2, "Lecture Hall Complex", "LHC-104", 7);
insert into section values ("MEPC-16", 12, 3, 2, "Lecture Hall Complex", "LHC-106", 8);

insert into takes values (, , , , , );
insert into takes values (, , , , , );
insert into takes values (, , , , , );
insert into takes values (, , , , , );
insert into takes values (, , , , , );
insert into takes values (, , , , , );
insert into takes values (, , , , , );
insert into takes values (, , , , , );
insert into takes values (, , , , , );

insert into advisor values (, );
insert into advisor values (, );
insert into advisor values (, );
insert into advisor values (, );
insert into advisor values (, );
insert into advisor values (, );
insert into advisor values (, );
insert into advisor values (, );
insert into advisor values (, );

insert into teaches values (1, "ITPC-25", 8, 3, 2);
insert into teaches values (2, "CSPC-27", 4, 3, 2);
insert into teaches values (3, "CSPC-25", 4, 3, 2);
insert into teaches values (4, "MEPC-16", 12, 3, 2);
