select distinct l1.num ConsecutiveNums
from logs l1,
    logs l2,
    logs l3
where l1.num = l2.num
    and l1.num = l3.num
    and l2.id = l1.id + 1
    and l3.id = l1.id + 2;
;
-- same solution but more readable
;
select distinct a.num ConsecutiveNums
from logs a
    join logs b on a.id + 1 = b.id
    join logs c on b.id + 1 = c.id
where a.num = b.num
    and c.num = b.num