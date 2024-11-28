select
    distinct ID, EMAIL, FIRST_NAME, LAST_NAME
from
    DEVELOPERS as D
    left join SKILLCODES as S
    on (D.SKILL_CODE & S.CODE) > 0
where
    CATEGORY = 'Front End'
order by
    ID asc
;