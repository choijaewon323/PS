SELECT
    YEAR(SALES_DATE), MONTH(SALES_DATE), COUNT(DISTINCT USER_ID) AS PUCHASED_USERS,
    (ROUND(
        COUNT(DISTINCT USER_ID) / (SELECT
                                    COUNT(*)
                                FROM
                                    USER_INFO
                                WHERE
                                    YEAR(JOINED) = 2021), 1)) AS PUCHASED_RATIO
FROM
    ONLINE_SALE
WHERE
    USER_ID IN (SELECT
                    USER_ID
               FROM
                    USER_INFO
               WHERE
                    YEAR(JOINED) = 2021)
GROUP BY
    YEAR(SALES_DATE), MONTH(SALES_DATE)
ORDER BY
    YEAR(SALES_DATE) ASC,
    MONTH(SALES_DATE) ASC
;