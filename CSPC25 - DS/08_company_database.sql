drop database if exists EXP_9;
create database EXP_9;
use EXP_9;

create table department (
    Dname varchar(15) not null,
    Dnumber int primary key,
    Mgr_ssn int not null,
    Mgr_start_date date not null
);

create table employee (
    Fname varchar(10) NOT NULL,
    Minit varchar(1) NOT NULL,
    Lname varchar(10) NOT NULL,
    Ssn int primary key,
    Bdate date NOT NULL,
    Address varchar(50) NOT NULL,
    Sex varchar(1) NOT NULL,
    Salary int NOT NULL,
    Super_ssn int,
    Dno int NOT NULL,
    foreign key(Dno) references department(Dnumber)
);

create table dept_location (
    Dnumber int not null,
    Dlocation varchar(10) not null,
    Foreign key(Dnumber) references department(Dnumber),
    primary key(Dnumber,Dlocation)
);

create table project (
    Pname varchar(15) not null,
    Pnumber int primary key,
    Plocation varchar(15) not null,
    Dnum int not null,
    foreign key(Dnum) references department(Dnumber)
);

create table works_on (
    Essn int,
    Pno int Not null,
    Hours float,
    Foreign key(Essn) references employee(Ssn),
    Foreign key(Pno) references project(Pnumber),
    primary key(Essn,Pno)
);

create table dependent (
    Essn int,
    Dependent_name varchar(10) primary key,
    Sex varchar(1) not null,
    Bdate date not null,
    Relationship varchar(10) not null,
    foreign key(Essn) references employee(Ssn)
);

insert into department values
    ('Research',5,333445555,'1988-05-22'),
    ('Administration',4,987654321,'1995-01-01'),
    ('Headquarters',1,888665555,'1981-06-19');

insert into employee (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) values
    ('John', 'B', 'Smith', 123456789, '1965-09-01', '731 Fondren, Houston, TX', 'M', 30000, 333445555, 5),
    ('Franklin', 'T', 'Wong', 333445555, '1955-12-08', '638 Voss, Houston, TX', 'M', 40000, 888665555, 5),
    ('Alicia', 'J', 'Zelaya', 999887777, '1968-01-19', '3321 Castle, Spring, TX', 'F', 25000, 987654321, 4),
    ('Jennifer', 'S', 'Wallace', 987654321, '1941-06-20', '291 Berry, Bellaire, TX', 'F', 43000, 888665555, 4),
    ('Ramesh', 'K', 'Narayan', 666884444, '1962-09-15', '975 Fire Oak, Humble, TX', 'M', 38000, 333445555, 5),
    ('Joyce', 'A', 'English', 453453453, '1972-07-31', '5631 Rice, Houston, TX', 'F', 25000, 333445555, 5),
    ('Ahmad', 'V', 'Jabbar', 987987987, '1969-03-29', '980 Dallas, Houston, TX', 'M', 25000, 987654321, 4);

insert into employee (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Dno) values
    ('James','E','Borg',888665555,'1937-11-10','450 Stone,houston,TX','M',55000,1);

insert into project values
    ('ProductX', 1, 'Bellaire', 5),
    ('ProductY', 2, 'Sugarland', 5),
    ('ProductZ', 3, 'Houston', 5),
    ('Computerization', 10, 'Stafford', 4),
    ('Reorganization', 20, 'Houston', 1),
    ('Newbenefits', 30, 'Stafford', 4);

insert into works_on values
    (123456789, 1, 32.5),
    (123456789, 2, 7.5),
    (666884444, 3, 40.0),
    (453453453, 1, 20.0),
    (453453453, 2, 20.0),
    (333445555, 2, 10.0),
    (333445555, 3, 10.0),
    (333445555, 10, 10.0),
    (333445555, 20, 10.0),
    (999887777, 30, 30.0),
    (999887777, 10, 10.0),
    (987987987, 10, 35.0),
    (987987987, 30, 5.0),
    (987654321, 20, 15.0),
    (888665555, 20, NULL);

insert into dept_location values
    (1, 'Houston'),
    (4, 'Stafford'),
    (5, 'Bellaire'),
    (5, 'Sugarland'),
    (5, 'Houston');

insert into dependent values
    (333445555, 'Alice', 'F', '1986-04-05', 'Daughter'),
    (333445555, 'Theodore', 'M', '1983-10-25', 'Son'),
    (333445555, 'Joy', 'F', '1958-05-03', 'Spouse'),
    (987654321, 'Abner', 'M', '1942-02-28', 'Spouse'),
    (123456789, 'Michael', 'M', '1988-01-04', 'Son'),
    (123456789, 'Elizabeth', 'F', '1967-05-05', 'Spouse');
