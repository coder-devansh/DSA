# Write your MySQL query statement below
select Email from (select Email,count(*) as cnt
 from Person
 Group by Email
 having cnt>1
) as cm;