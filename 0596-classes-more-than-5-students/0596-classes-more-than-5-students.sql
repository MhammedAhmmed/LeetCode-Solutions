# Write your MySQL query statement below

SELECT class 
FROM
(SELECT class, COUNT(class) AS C 
FROM Courses
GROUP BY(class)) AS temp
WHERE C >= 5;