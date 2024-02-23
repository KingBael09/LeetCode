select e.event_day day,
    e.emp_id,
    (sum(e.out_time) - sum(e.in_time)) total_time
from Employees e
group by e.emp_id,
    e.event_day
order by e.emp_id;