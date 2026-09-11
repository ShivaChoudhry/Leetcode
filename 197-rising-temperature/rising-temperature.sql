# Write your MySQL query statement below
select w1.id as Id
from Weather w2
inner join Weather w1 
where Datediff(w1.recordDate, w2.recordDate)=1
AND w1.temperature>w2.temperature;