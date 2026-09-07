# Write your MySQL query statement below
select distinct(num) as ConsecutiveNums 
from (
    select num,
    Lag(num,1) over (order by id) as prev1,
    Lag(num,2) over (order by id) as prev2
    from Logs
)t
where prev1=num and prev2=num;