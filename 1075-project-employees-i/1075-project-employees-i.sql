# Write your MySQL query statement below
select p.project_id, AVG(e.experience_years) as average_years
from Project p
Left Join Employee e
    ON p.employee_id=e.employee_id
group by p.project_id;

