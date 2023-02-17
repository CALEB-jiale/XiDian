use stumanage;

create table login
(
id int not null unique auto_increment,
username varchar(100) not null unique,
password varchar(100) not null,
role tinyint not null default 0
)