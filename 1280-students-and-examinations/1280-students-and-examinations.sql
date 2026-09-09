select 
a.student_id ,
a.student_name ,
sub.subject_name ,
count(e.student_id) as attended_exams 
from Students as a
cross join Subjects as sub
left join Examinations as e
on  a.student_id   = e.student_id 
and sub.subject_name = e.subject_name 
group by 
 a.student_id,
 a.student_name,
 sub.subject_name
order by 
 a.student_id,
 sub.subject_name;;