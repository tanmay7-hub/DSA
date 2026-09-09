select a.name 
from Employee as a
join (select managerId  from  Employee group by  managerId  having count(managerId) >= 5)
as b
on a.id = b.managerId;