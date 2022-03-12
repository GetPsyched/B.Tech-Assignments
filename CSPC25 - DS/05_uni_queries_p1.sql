drop database if exists EXP_5;
create database EXP_5;
use EXP_5;

-- 1
update instructor set salary = salary * 1.2 where dept_name = "Information Technology";
-- 2
select name, dept_name from instructor;
-- 3
select i.name, i.dept_name, d.building from instructor join department on i.dept_name = d.dept_name;
-- 4
select dept_name, building from department;
-- 5
update department, classroom set building = "Lecture Theatre Complex" where building = "Lecture Hall Complex";
-- 6
select dept_name from student where ID = 12022005;
-- 7
select ID, course_id from instructor natural join teaches;
-- 8
select course_id, semester, year, title from course natural join section where dept_name = "Computer Engg.";
-- 9
select salary `monthly salary` from instructor;
-- 10
select dept_name from department where building = "Fanibhushan Bhawan";
-- 11
select name from instructor where dept_name = "Computer Engg." and salary > 70000;
-- 12
select title from course where dept_name = "Information Technology" and credits = 3;
-- 13
select title, credits from course natural join section where semester = 4;
-- 14
select * from section where room_no = "LHC-102";
-- 15
select * from section where room_no = "LHC-102";
-- 16
select * from section where room_no = "LHC-102";
-- 17
select room_no, time_slot_id from section natural join course where dept_name = "Computer Engg." and semester = 7;
-- 18
select title from course natural join teaches where ID = 123;
-- 19
select name, dept_name from instructor natural join teaches;
-- 20
select name from instructor where salary > (select salary from instructor where dept_name = "Computer Engg." order by salary limit 1);
