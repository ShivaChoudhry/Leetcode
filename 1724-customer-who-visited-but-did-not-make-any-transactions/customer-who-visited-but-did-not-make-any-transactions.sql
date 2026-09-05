# Write your MySQL query statement below
select v.customer_id, count(v.visit_id) as count_no_trans from Visits as v left join Transactions as t 
ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
group by customer_id;