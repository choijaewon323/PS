-- 코드를 입력하세요
SELECT
    CONCAT('/home/grep/src/', F.BOARD_ID, '/', FILE_ID, FILE_NAME, FILE_EXT) 
    AS FILE_PATH
FROM
    USED_GOODS_BOARD AS B
    INNER JOIN USED_GOODS_FILE AS F
    ON B.BOARD_ID = F.BOARD_ID
WHERE
    B.VIEWS = (SELECT
                    MAX(VIEWS)
                FROM
                    USED_GOODS_BOARD)
ORDER BY
    FILE_ID DESC
;
