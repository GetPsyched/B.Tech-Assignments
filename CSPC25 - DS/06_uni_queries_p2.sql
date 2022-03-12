-- 1
select dept_name from department where building like "%Hall%";
-- 2
select name from instructor where salary between 50000 and 80000;
-- 3
select name from student where name like "Sa%";
-- 4
select name from student where dept_name = "Computer Engg." and name like "Sa%";
-- 5
select * from course where course_id where course_id in (select course_id from teaches natural join instructor where name = "S%");
-- 6
select * from course where title like "Computer%";
-- 7
select * from course where title like "%language%";
-- 8
select name from instructor natural join teaches where course_id in (select course_id from course where title like "%language%");
-- 9
select ID from student where name like "%Kumari%" and dept_name = "Information Technology";
-- 10
select avg(salary) from instructor;
-- 11
select avg(salary) from instructor where dept_name = "Computer Engg.";
-- 12
select avg(salary) from instructor group by dept_name;
-- 13
select name, avg(salary) from instructor where salary > 60000;
-- 14
select count(*) from course;
-- 15
select count(*) from course where dept_name = "Computer Engg.";
-- 16
select count(course_id) from section natural join time_slot where start_time > "01/03/2016" and end_time < "01/05/2016";
-- 17

-- 18
select max(salary) from instructor where dept_name = "Computer Engg.";
-- 19
select min(salary) from instructor where dept_name = "Computer Engg.";
-- 20
select max(salary) from instructor;
-- 21
select count(*) from student;
-- 22
select count(*) from student group by dept_name;
-- 23
select * from instructor having avg(salary) > 42000;
-- 24
select * from instructor having avg(salary) > (select avg(salary) from instructor where dept_name = "Physics");
-- 25
select count(*) from student where credits > 8;