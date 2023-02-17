use stumanage;

create table student
(
id int not null unique auto_increment,
sno int not null unique,
sname varchar(100) not null,
sex varchar(100) not null,
school varchar(100) not null,
major varchar(100) not null,
sclass int not null,
date int not null,
check (sex in ('男','女'))
)