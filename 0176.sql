-- ? 176. Second Highest Salary
-- ? https://leetcode.com/problems/second-highest-salary/description/
--
SELECT MAX(E.salary) AS SecondHighestSalary
FROM Employee E
WHERE E.salary < (
        SELECT MAX(F.salary)
        FROM Employee F
    );
-- 
-- Another Solution
--
SELECT MAX(E.salary) AS SecondHighestSalary
FROM Employee E
WHERE E.salary NOT IN (
        SELECT MAX(D.salary)
        FROM Employee D
    )