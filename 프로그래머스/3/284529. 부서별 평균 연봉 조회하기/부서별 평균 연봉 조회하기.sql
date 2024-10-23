select
    hd.dept_id, dept_name_en, round(avg(SAL), 0) as AVG_SAL
from
    hr_department as hd
    inner join hr_employees as he
    on hd.dept_id = he.dept_id
group by
    hd.dept_id
order by
    AVG_SAL desc;