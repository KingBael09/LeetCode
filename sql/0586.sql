-- ? 586. Customer Placing the Largest Number of Orders
-- ? https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/description/
;
SELECT TOP 1 O.customer_number
FROM Orders O
GROUP BY O.customer_number
ORDER BY COUNT(O.order_number) DESC