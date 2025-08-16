# Write your MySQL query statement below
SELECT class FROM courses GROUP BY class Having COUNT(student)>=5;