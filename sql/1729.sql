select f.user_id,
    COUNT(f.follower_id) followers_count
from followers f
group by f.user_id
order by f.user_id