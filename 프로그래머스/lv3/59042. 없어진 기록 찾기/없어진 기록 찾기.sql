-- 코드를 입력하세요
SELECT
    O.ANIMAL_ID, O.NAME
FROM
    ANIMAL_INS AS I
    RIGHT JOIN ANIMAL_OUTS AS O
    ON I.ANIMAL_ID = O.ANIMAL_ID
WHERE
    I.ANIMAL_ID IS NULL
ORDER BY
    O.ANIMAL_ID
;