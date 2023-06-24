WITH RECURSIVE TEMP (N) AS (
    SELECT
        0
    UNION ALL
    SELECT
        N + 1
    FROM
        TEMP
    WHERE
        N < 23
)

SELECT
    N AS HOUR, IFNULL(COUNT, 0) AS COUNT
FROM
    (SELECT
            HOUR(DATETIME) AS HOUR, COUNT(*) AS COUNT
        FROM
            ANIMAL_OUTS
        GROUP BY
            HOUR(DATETIME)) AS T
    RIGHT JOIN TEMP
    ON T.HOUR = TEMP.N
