select
    count(*) as FISH_COUNT,
    max(length) as MAX_LENGTH,
    fish_type
from
    (select
        id, fish_type, time,
        case
            when length > 10
            then length
            else 10
        end as length
    from 
        fish_info) as temp
group by
    fish_type
having
    avg(length) >= 33
order by
    fish_type asc
;