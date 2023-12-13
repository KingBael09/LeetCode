-- ? 183. Customers Who Never Order
-- ? https://leetcode.com/problems/customers-who-never-order/description/
--
SELECT A.name AS Customers
FROM Customers A
    LEFT JOIN Orders B ON A.id = B.customerId
WHERE B.customerId IS NULL;
-- 
-- 
-- 
-- OR
--
--
--
SELECT A.name AS Customers
FROM Customers A
WHERE A.id NOT IN(
        SELECT B.customerId
        FROM Orders B
    );