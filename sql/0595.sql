-- ? 595. Big Countries
-- ? https://leetcode.com/problems/big-countries/description/
;
SELECT T.name,
    T.population,
    T.area
FROM World T
WHERE T.area >= 3000000
    OR T.population >= 25000000