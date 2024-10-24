select
    ITEM_ID, ITEM_NAME, RARITY
from
    ITEM_INFO as II
where
    II.ITEM_ID not in (select
                            PARENT_ITEM_ID
                        from
                            ITEM_TREE as IT
                        group by
                            PARENT_ITEM_ID
                        having
                            PARENT_ITEM_ID is not null)
order by
    ITEM_ID desc
;