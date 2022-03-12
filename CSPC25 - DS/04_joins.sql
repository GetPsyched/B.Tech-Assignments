create database if not exists exp_4;
use exp_4;

-- Employee (Emp_ID(pk),Name,DeptName(fk))
drop table if exists employee;
create table employee (
	  Emp_ID int primary key,
    Name varchar(20) not null,
    DeptName varchar(20)
);

-- Department (DeptName(pk),Manager)
drop table if exists department;
create table department (
	  DeptName varchar(20) primary key,
    Manager varchar(20)
);

-- foreign key
alter table employee add constraint fk_DeptName foreign key (DeptName) references department(DeptName) on update cascade;

-- insert values
insert into department values("Sales", "Ram");
insert into department values("Finance", "Sita");
insert into department values("Accounts", "Rohit");
insert into department values("Inventory", "Gatgi");
insert into department values("Office", "Mohit");

insert into employee values(1101, "Ramesh", "Sales");
insert into employee values(2241, "Suresh", "Finance");
insert into employee values(2242, "Kamal", "Sales");
insert into employee values(2243, "Ankur", "Inventory");
insert into employee values(2244, "Vikas", "Office");
insert into employee values(2245, "Amir", "Sales");

-- cartesian product
select * from employee cross join department;
-- natural join
select * from employee natural join department;
-- left outer join
select * from employee left join department on employee.DeptName = department.DeptName;
-- right outer join
select * from employee right join department on employee.DeptName = department.DeptName;
-- full outer join
-- MySQL does not support full join
-- hence to perform this, take union of left join and right join
select * from employee left join department on employee.DeptName = department.DeptName
union all
select * from employee right join department on employee.DeptName = department.DeptName;
-- left semi join
select * from employee where employee.DeptName in (select DeptName from department);
-- right semi join
select * from department where department.DeptName in (select DeptName from employee);

-- drop foreign key
alter table employee drop foreign key fk_DeptName;

-- cartesian product
select * from employee cross join department;
-- natural join
select * from employee natural join department;
-- left outer join
select * from employee left join department on employee.DeptName = department.DeptName;
-- right outer join
select * from employee right join department on employee.DeptName = department.DeptName;
-- full outer join
select * from employee left join department on employee.DeptName = department.DeptName
union all
select * from employee right join department on employee.DeptName = department.DeptName;
-- left semi join
select * from employee where employee.DeptName in (select DeptName from department);
-- right semi join
select * from department where department.DeptName in (select DeptName from employee);

-- no change occured on any join even after dropping the foreign key
