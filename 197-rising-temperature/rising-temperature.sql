# Write your MySQL query statement below
select today.id from weather as today
where exists

(select 1 from weather as yesterday
where yesterday.temperature<today.temperature

AND DATEDIFF(today.recordDate, yesterday.recordDate) = 1
)