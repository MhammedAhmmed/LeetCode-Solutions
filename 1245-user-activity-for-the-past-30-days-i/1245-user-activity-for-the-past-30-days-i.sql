# Write your MySQL query statement below
SELECT activity_date AS day, count(distinct user_id) AS active_users
from activity
where activity_date <= '2019-07-27' and activity_date > '2019-06-27'
group by activity_date;