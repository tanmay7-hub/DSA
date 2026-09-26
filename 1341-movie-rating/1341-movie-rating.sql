(select name as results
from Users u
join 
MovieRating as mr
on u.user_id = mr.user_id
group by u.user_id , u.name
order by count(*) desc , u.name
limit 1)
union all

(select  m.title as results
from Movies as m 
join MovieRating as mr
    ON m.movie_id = mr.movie_id
WHERE mr.created_at >= '2020-02-01'
   AND mr.created_at < '2020-03-01'
group by m.movie_id , m.title
order by avg(mr.rating) desc , m.title
limit 1)