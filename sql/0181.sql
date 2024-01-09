-- ? 181. Employees Earning More Than Their Managers
-- ? https://leetcode.com/problems/employees-earning-more-than-their-managers/description/
-- 
SELECT E.name AS Employee
FROM Employee E
WHERE E.salary > (
        SELECT M.salary
        FROM Employee M
        WHERE E.managerId = M.id
    );
--
-- Other Solution
--
SELECT E.name AS Employee
FROM Employee E,
    Employee M
WHERE E.managerId = M.id
    AND E.salary > M.salary;