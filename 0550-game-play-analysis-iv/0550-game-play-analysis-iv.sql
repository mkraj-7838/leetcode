# Write your MySQL query statement below
Select Round(Count(Distinct player_id)/(select Count(Distinct player_id) from Activity), 2) as fraction
From Activity
where (player_id, Date_sub(event_date, INTERVAL 1 Day)) IN( 
    select player_id, MIN(event_date) as first_login
    From Activity
    group by player_id
)

