SELECT
    CAR_ID, C.CAR_TYPE, ROUND(DAILY_FEE * (1 - DISCOUNT_RATE / 100) * 30, 0) AS FEE
FROM
    CAR_RENTAL_COMPANY_CAR AS C
    INNER JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS H
    ON C.CAR_TYPE = H.CAR_TYPE
WHERE
    (C.CAR_TYPE = '세단' OR C.CAR_TYPE = 'SUV') AND
    DURATION_TYPE = '30일 이상' AND
    CAR_ID NOT IN (SELECT
                        CAR_ID
                    FROM
                        CAR_RENTAL_COMPANY_RENTAL_HISTORY
                    WHERE
                        END_DATE >= '2022-11-01' AND START_DATE <= '2022-11-30')
HAVING
    FEE >= 500000 AND FEE < 2000000
ORDER BY
    FEE DESC,
    C.CAR_TYPE ASC,
    CAR_ID DESC
;
