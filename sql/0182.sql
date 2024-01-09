-- ? 182. Duplicate Emails
-- ? https://leetcode.com/problems/duplicate-emails/description/
-- 
SELECT P.email
FROM Person P
GROUP BY P.email
HAVING count(P.email) > 1;