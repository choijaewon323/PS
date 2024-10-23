select
    ID, FISH_NAME, LENGTH
from
    (select
        ID, FISH_NAME,
        max(LENGTH) over(partition by FI.FISH_TYPE) as LENGTH,
        rank() over(partition by FI.FISH_TYPE order by LENGTh desc) as rnk
    from
        FISH_INFO as FI
        inner join FISH_NAME_INFO as FNI
        on FI.FISH_TYPE = FNI.FISH_TYPE) as temp
where
    rnk = 1
order by
    ID asc
;
    