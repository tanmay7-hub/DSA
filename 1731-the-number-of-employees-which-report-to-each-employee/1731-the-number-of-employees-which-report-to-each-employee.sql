# Write your MySQL query statement below
select 
a.employee_id ,
a.name ,
b.reports_count ,
b.average_age
from Employees as a
join (select reports_to as id , count(*)  as reports_count , ROUND(avg(age)) as average_age from Employees group by id )
as b
where a.employee_id = b.id 

order by employee_id;

