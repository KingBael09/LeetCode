-- ? 596. Classes More Than 5 Students
-- ? https://leetcode.com/problems/classes-more-than-5-students/description/
;
SELECT class
FROM Courses
GROUP BY class
HAVING count(student) >= 5;