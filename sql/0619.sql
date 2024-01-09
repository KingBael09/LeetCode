-- ? 619. Biggest Single Number
-- ? https://leetcode.com/problems/biggest-single-number/description/
-- 
SELECT MAX(num) as num
FROM MyNumbers
WHERE num IN (
        SELECT num
        FROM MyNumbers
        GROUP BY num
        HAVING COUNT(num) = 1
    );