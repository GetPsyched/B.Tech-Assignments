drop database if exists EXP_3;
create database EXP_3;
use EXP_3;

-- STUDENT (Roll-No, Name, Gender, Degree, Semester, Contact-No, Email-id, Guide-No, Group-Code, Project-No)
drop table if exists student;
create table student (
    Roll_No int primary key,
    Name varchar(40),
    Gender char(1) check (Gender="M" or Gender="F"),
    Degree char(6) not null,
    Semester int,
    Contact_No char(15),
    Email_Id varchar(25),
    Guide_No int,
    Group_Code char(2),
    Project_No int
);

-- GUIDE (Guide-No, Guide-name, Guide-research-area, Email-id)
drop table if exists guide;
create table guide (
    Guide_No int primary key,
    Guide_Name varchar(30),
    Guide_Research_Area varchar(30),
    Email_Id varchar(30)
);

-- PROJECT (Project-No, Project-title, Project-area, Project-Year-Month, Guide-No, Group-Code)
drop table if exists project;
create table project (
    Project_No int primary key,
    Project_Title varchar(30) ,
    Project_Area varchar(30),
    Project_Year_Month date,
    Guide_No int,
    Group_Code char(2)
);

-- GROUPS (Group-Code, No-of -Students)
drop table if exists groupss;
create table groupss (
    Group_Code char(2) primary key,
    No_Of_Students int check(No_Of_Students < 5 and No_Of_Students > 2)
);

delimiter //
create trigger max_projects_for_one_guide
before insert on project
for each row
begin
    if (select count(*) from project where Guide_No = new.Guide_No) = 3 then
        signal sqlstate '45000' set message_text = "A teacher can supervise a maximum of 3 projects in a semester";
    end if;
end; //

-- Add foreign keys
alter table student
add foreign key (Guide_No) references guide(Guide_No) on update cascade,
add foreign key (Group_Code) references groupss(Group_Code),
add foreign key (Project_No) references project(Project_No);

alter table project
add foreign key (Guide_No) references guide(Guide_No) on update cascade,
add foreign key (Group_Code) references groupss(Group_Code);

-- Insert values
insert into guide values (12, "Ms. Someone", "Cyber Security", "email@nitkkr.ac.in");
insert into guide values (15, "Dr. S K Jain", "Information Practices", "email@nitkkr.ac.in");
insert into guide values (23, "Mr. Hello world", "Artificial Intelligence", "email@nitkkr.ac.in");

insert into groupss values ("G1", 3);
insert into groupss values ("G2", 3);
insert into groupss values ("G3", 4);
insert into groupss values ("G4", 3);

insert into project values (1, "Project 1", "Programming", "2021-03-26", 12, "G1");
insert into project values (2, "Project 2", "Network", "2021-02-14", 12, "G2");
insert into project values (3, "Project 3", "Cyber Security", "2021-04-01", 12, "G3");
insert into project values (4, "Project 4", "Information Practices", "2021-07-30", 15, "G4");

insert into student values (12012012, "ISHIKA BANSAL", "F", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 12, "G1", 1);
insert into student values (12012013, "MUSKAN BIDANI", "F", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 12, "G1", 1);
insert into student values (12012033, "KARLAPUDI GURU MAHESH", "M", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 12, "G1", 1);
insert into student values (12012036, "RAHUL RATHORE", "M", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 12, "G2", 2);
insert into student values (12012037, "CHIRAG SINGH", "M", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 12, "G2", 2);
insert into student values (12012039, "HEMANT", "M", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 12, "G2", 2);
insert into student values (12012040, "SHUBHAM KUMAR SAH", "M", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 12, "G3", 3);
insert into student values (12012041, "YUVANSH BANSAL", "M", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 12, "G3", 3);
insert into student values (12012042, "SREEJAN", "M", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 12, "G3", 3);
insert into student values (12012047, "HARSHIT KANSAL", "M", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 12, "G3", 3);
insert into student values (12012053, "YOGITA MEENA", "F", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 15, "G4", 4);
insert into student values (12012056, "ANIKET BHATIA", "M", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 15, "G4", 4);
insert into student values (12012090, "MAYANK SURYA", "M", "B.Tech", 3, "+91XXXXXXXXXX", "email@nitkkr.ac.in", 15, "G4", 4);

-- Queries

-- 1
update guide set Guide_Name = "Ram Mohan", Guide_No = 11 where Guide_No = (select Guide_No from student where Roll_No = 110011);
-- 2
update guide set Guide_No = 10 where Guide_No = 15;
-- 3
select * from guide where Guide_No in (select Guide_No from student group by Guide_No having count(Guide_No) > 8);
-- 4
select Project_No,Project_Title,guide.Guide_Name from project,guide where Project_Area = "Database" and project.Guide_No = guide.Guide_No;
-- 5
select Project_Title from project where Project_No = 5;
-- 6
select Name from student where Project_No = 5;
-- 7
select Project_Title from project where Guide_No = (select Guide_No from guide where Guide_Name = "Dr. S K Jain");
-- 8
select Name from student where Guide_No = (select Guide_No from guide where Guide_Name = "Dr. S K Jain");
-- 9
select Project_Title from project where year(Project_Year_Month) = 2019 and monthname(Project_Year_Month) = "June";
-- 10
select Project_Title from project where year(Project_Year_Month) = 2019;
-- 11
select Roll_No,Name from student where Project_No = (select Project_No from project where Project_Area = "Programming");
-- 12
select Guide_Name from guide where Guide_No = (select Guide_No from project where Project_Area = "Network");
-- 13
select Name from student where Project_No = (select Project_No from project where Project_Area = "Artificial Intelligence");
-- 14
select project.Project_Area,guide.Guide_Name from project,guide where project.Guide_No = guide.Guide_No;
-- 15
select if(count(project.Project_No) > 1, "True", "False") from project where Project_No = 7
and year(Project_Year_Month) = 2020 and monthname(Project_Year_Month) = "December" 
and Guide_No = (select Guide_No from guide where Guide_Name = "Dr. S K Jain");
-- 16
select Name from student where Group_Code = "G3";
-- 17
select Guide_Name from guide where Guide_No =  (select Guide_No from project where Group_Code = "G5");
-- 18
select Name,Group_Code from student where Guide_No = (select Guide_No from guide where Guide_Name = "Dr. S K Jain");
