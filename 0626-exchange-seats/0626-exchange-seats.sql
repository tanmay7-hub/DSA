SELECT 
   CASE 
      WHEN id % 2 = 1 AND id = (SELECT MAX(id) from Seat)
        THEN id
      WHEN id % 2 = 1 
        THEN id + 1 
      ELSE id - 1
   END 
as id ,
student 
FROM
Seat 
order by id;