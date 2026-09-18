SELECT ROUND(count(distinct a.player_id ) / (select count(distinct player_id) from Activity ) , 2)
AS fraction
FROM Activity a
JOIN (
    select player_id , min(event_date) as first_date
    from Activity 
    group by player_id
) f
ON a.player_id = f.player_id
AND a.event_date = DATE_ADD(f.first_date , INTERVAL 1 DAY);
