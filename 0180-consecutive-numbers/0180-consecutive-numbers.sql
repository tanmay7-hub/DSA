# Write your MySQL query statement below
select  distinct num  as ConsecutiveNums
from (
    select 
    id , num ,
    lag(num , 1) over(order by id) as prev1,
    lag(num , 2) over(order by id) as prev2
    from Logs
)t
where num = t.prev1 and num = t.prev2;
