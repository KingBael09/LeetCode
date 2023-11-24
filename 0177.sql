-- ? 177. Nth Highest Salary
-- ? https://leetcode.com/problems/nth-highest-salary/description/
-- 
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN
SET N = N - 1;
RETURN (
    # Write your MySQL query statement below.
    SELECT DISTINCT E.salary
    FROM Employee E
    ORDER BY E.salary DESC
    LIMIT N, 1
);
END