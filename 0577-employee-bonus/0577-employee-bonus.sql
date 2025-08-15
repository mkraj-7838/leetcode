# Write your MySQL query statement below
select name, bonus from Employee e
left join Bonus b
ON e.empId=b.empId
Where b.bonus<1000 OR b.bonus is NULL;