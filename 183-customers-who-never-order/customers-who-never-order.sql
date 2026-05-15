# Write your MySQL query statement below
select name as Customers
from 
Customers as c Left join Orders as o
on o.customerId=c.id
where (c.id is NOT NULL) && (o.id is NULL);
