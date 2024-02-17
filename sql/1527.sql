select *
from patients p
where p.conditions like '% DIAB1%'
    OR p.conditions like 'DIAB1%'