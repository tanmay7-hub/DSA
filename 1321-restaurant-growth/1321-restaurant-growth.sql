with daily as(
    select visited_on , sum(amount) as amount
    from Customer
    group by visited_on
),
results as(
    select visited_on , 
    sum(amount) 
    over( 
        order by visited_on 
        ROWS between 6 preceding  and current row
    )
    as amount 
    from daily
)
select visited_on , amount , round(amount / 7.0 , 2) as average_amount
from results
where visited_on >= (
    select Date_add(min(visited_on) , interval 6 day)
    from daily
)
order by visited_on;