use stumanage;

create table course
(
id int not null unique auto_increment,
cno varchar(100) not null unique,
cname varchar(100) not null,
credit int not null,
semester int not null,
feature varchar(100) not null,
tname varchar(100) not null,
check (credit>=0 and semester>=1 and semester<=8 and feature in ('必修课','选修课'))
)