# Write your MySQL query statement below
SELECT MAX(num) AS num
FROM (SELECT num, COUNT(num) AS C 
FROM MyNumbers 
GROUP BY(num)) AS TEMP
WHERE C = 1;