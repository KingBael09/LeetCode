-- ? 1407. Top Travellers
-- ? https://leetcode.com/problems/top-travellers/description/
;
select u.name,
    isnull(sum(r.distance), 0) travelled_distance
from users u
    left join rides r on r.user_id = u.id
group by r.user_id,
    u.name
order by travelled_distance desc