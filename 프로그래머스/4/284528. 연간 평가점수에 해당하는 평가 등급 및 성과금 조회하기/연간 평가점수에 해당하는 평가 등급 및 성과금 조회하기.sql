select
    he.emp_no, emp_name,
    case
        when average >= 96
        then 'S'
        when average >= 90
        then 'A'
        when average >= 80
        then 'B'
        else 'C'
    end as grade,
    case
        when average >= 96
        then sal * 0.2
        when average >= 90
        then sal * 0.15
        when average >= 80
        then sal * 0.1
        else 0
    end as bonus
from
    hr_employees as he
    inner join (select
                    emp_no, avg(score) as average
                from
                    hr_grade
                group by
                    emp_no
                ) as tmp
    on he.emp_no = tmp.emp_no
order by
    he.emp_no
;