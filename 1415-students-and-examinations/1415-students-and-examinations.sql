# Write your MySQL query statement below

SELECT s.student_id, s.student_name, b.subject_name, COUNT(e.subject_name) AS attended_exams
FROM Students s
CROSS JOIN Subjects b
LEFT JOIN Examinations e
ON e.student_id = s.student_id AND e.subject_name = b.subject_name
GROUP BY s.student_id, s.student_name, b.subject_name
ORDER BY s.student_id, b.subject_name;
