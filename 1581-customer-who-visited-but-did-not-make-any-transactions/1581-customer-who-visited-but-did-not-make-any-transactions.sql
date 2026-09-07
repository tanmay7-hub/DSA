
select v.customer_id , count(*) as count_no_trans from transactions as t  right join visits as v  on v.visit_id  = t.visit_id where t.transaction_id is null group by v.customer_id;  