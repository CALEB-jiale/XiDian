select sno
from sc
join course on course.id=sc.cno
where grade<60 and exam>0 and feature="必修课"
group by sno
having sum(credit)>30
union
select sno
from sc
join course on course.id=sc.cno
where grade<60 and exam>0 and feature="必修课"
group by sno,semester
having sum(credit)>10
union
select sno
from sc
join course on course.id=sc.cno
where grade<60 and exam>0 and feature="选修课"
group by sno
having sum(credit)>20