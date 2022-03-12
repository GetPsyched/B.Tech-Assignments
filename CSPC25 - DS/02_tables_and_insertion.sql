create database if not exists EXP_2;
use EXP_2;

-- CAR (Registration-No, Chassis-No, Engine-No, Company-Name, Model, Year-Model, Price)
drop table if exists car;
create table car (
    Registration_No int,
    Chassis_No int,
    Engine_No int,
    Company_Name varchar(30),
    Model varchar(20),
    Year_Model year,
    Price int
);
-- Insert values
insert into car values (1, 123, 324, "Company ABC", "ASCX-23", 2003, 89000);
insert into car values (2, 268, 546, "Company XYZ", "GKSR-54", 2010, 130000);
insert into car values (3, 223, 837, "Company PQR", "FSEH-72", 2007, 105000);
insert into car values (4, 437, 352, "Company XYZ", "DGBK-18", 2020, 275000);

-- PERSON (Aadhar-No, Name, Address, City)
drop table if exists person;
create table person (
    Aadhar_No char(12),
    Name varchar(40),
    Address varchar(100),
    City varchar(20)
);
-- Insert values
insert into person values ("123456789123", "John Doe", "address line 1, address line 2", "City 1");
insert into person values ("345623452633", "Anjali Mishra", "address line 1, address line 2", "City 4");
insert into person values ("236536823235", "Pooja Yadav", "address line 1, address line 2", "City 2");
insert into person values ("426647536584", "Chris Morphew", "address line 1, address line 2", "City 7");

-- OWN-BY (Registration-No, Aadhar-No)
drop table if exists own_by;
create table own_by (
    Registration_No int,
    Aadhar_No char(12)
);
-- Insert values
insert into own_by values (1, "123456789123");
insert into own_by values (2, "345623452633");
insert into own_by values (3, "236536823235");
insert into own_by values (4, "426647536584");

-- DRIVER (License-No., Date-of-Issue, Valid-up-to, Aadhar-No.)
drop table if exists driver;
create table driver (
    License_No int,
    Date_of_Issue date,
    Valid_upto date,
    Aadhar_No char(12)
);
-- Insert values
insert into driver values (1546224, "2020-03-20", "2024-03-19", "123456789123");
insert into driver values (2418138, "2018-02-12", "2024-02-11", "345623452633");
insert into driver values (2483298, "2021-08-16", "2024-08-15", "236536823235");
insert into driver values (3964878, "2016-12-25", "2024-12-24", "426647536584");
