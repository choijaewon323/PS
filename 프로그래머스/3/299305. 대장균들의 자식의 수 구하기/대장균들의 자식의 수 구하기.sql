select
    o.ID, case
            when CNT is null
            then 0
            else CNT
            end as CHILD_COUNT
from
    ECOLI_DATA as o
    left join (select
                    PARENT_ID, COUNT(*) as CNT
                from
                    ECOLI_DATA
                group by
                    PARENT_ID
                having
                    PARENT_ID is not null) as t
    on o.id = t.parent_id
order by
    o.ID asc;