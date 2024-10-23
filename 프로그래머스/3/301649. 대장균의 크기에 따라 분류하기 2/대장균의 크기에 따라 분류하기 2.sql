select
    ID,
    case
        when rnk between 1 and total * 0.25
        then 'CRITICAL'
        when rnk > total * 0.25 and rnk <= total * 0.5
        then 'HIGH'
        when rnk > total * 0.5 and rnk <= total * 0.75
        then 'MEDIUM'
        else 'LOW'
    end as COLONY_NAME
from
    (select
        ID, SIZE_OF_COLONY,
        row_number() over(order by SIZE_OF_COLONY desc) as rnk,
        count(*) over() as total
     from
        ECOLI_DATA as ED
    order by
        SIZE_OF_COLONY desc) as TEMP
order by
    id asc
;