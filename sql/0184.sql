-- ? 196. Delete Duplicate Emails
-- ? https://leetcode.com/problems/delete-duplicate-emails/description/
;
DELETE P1
FROM PERSON P1,
    PERSON P2
WHERE P1.email = P2.email
    AND P1.id > P2.id;