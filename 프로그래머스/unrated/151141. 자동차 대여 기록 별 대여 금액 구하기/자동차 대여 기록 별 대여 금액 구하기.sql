SELECT
    HISTORY_ID,
    CASE
        WHEN 
            DATEDIFF(END_DATE, START_DATE) + 1 >= 90
        THEN 
            TRUNCATE(DAILY_FEE * 
            (1 - (SELECT 
                        DISCOUNT_RATE 
                    FROM 
                        CAR_RENTAL_COMPANY_DISCOUNT_PLAN
                    WHERE
                        CAR_TYPE = '트럭' AND 
                        DURATION_TYPE = '90일 이상') / 100) * 
            (DATEDIFF(END_DATE, START_DATE) + 1), 0)
        WHEN 
            DATEDIFF(END_DATE, START_DATE) + 1 >= 30
        THEN 
            TRUNCATE(DAILY_FEE * 
            (1 - (SELECT 
                        DISCOUNT_RATE 
                    FROM 
                        CAR_RENTAL_COMPANY_DISCOUNT_PLAN
                    WHERE
                        CAR_TYPE = '트럭' AND 
                        DURATION_TYPE = '30일 이상') / 100) * 
            (DATEDIFF(END_DATE, START_DATE) + 1), 0)
        WHEN 
            DATEDIFF(END_DATE, START_DATE) + 1 >= 7
        THEN 
            TRUNCATE(DAILY_FEE * 
            (1 - (SELECT 
                        DISCOUNT_RATE 
                    FROM 
                        CAR_RENTAL_COMPANY_DISCOUNT_PLAN
                    WHERE
                        CAR_TYPE = '트럭' AND 
                        DURATION_TYPE = '7일 이상') / 100) * 
            (DATEDIFF(END_DATE, START_DATE) + 1), 0)
        ELSE 
            (DATEDIFF(END_DATE, START_DATE) + 1) * DAILY_FEE
    END AS FEE
FROM
    CAR_RENTAL_COMPANY_CAR AS C
    INNER JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY AS H
    ON C.CAR_ID = H.CAR_ID
WHERE
    CAR_TYPE = '트럭'
ORDER BY
    FEE DESC,
    HISTORY_ID DESC
;