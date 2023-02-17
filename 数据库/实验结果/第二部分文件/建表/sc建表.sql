use stumanage;

create table sc
(
id int not null unique auto_increment,
sno int not null,
cno varchar(100) not null,
exam int not null default 0,
grade int not null default 0,
foreign key (sno) references student(sno),
foreign key (cno) references course(cno),
check (exam>=0 and exam<=2 and grade>=0 and grade<=100)
)