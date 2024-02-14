-- ? 608. Tree Node
-- ? https://leetcode.com/problems/tree-node/description/
;
SELECT T.id,
    CASE
        WHEN T.p_id IS NULL THEN 'Root'
        WHEN T.p_id IS NOT NULL
        AND T.id IN (
            SELECT T.p_id
            FROM Tree T
        ) THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree T;
;
;
-- ? Other Method
;
;
SELECT DISTINCT T1.id,
    CASE
        WHEN T1.p_id IS NULL THEN 'Root'
        WHEN T2.p_id IS NOT NULL THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree T1
    LEFT JOIN Tree T2 ON T1.id = T2.p_id