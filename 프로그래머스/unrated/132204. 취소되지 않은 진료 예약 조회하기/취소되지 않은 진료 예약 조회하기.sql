-- 코드를 입력하세요
SELECT
    APNT_NO, PT_NAME, A.PT_NO, A.MCDP_CD, DR_NAME, APNT_YMD
FROM
    PATIENT AS P
    INNER JOIN APPOINTMENT AS A
    ON P.PT_NO = A.PT_NO
    INNER JOIN DOCTOR AS D
    ON A.MDDR_ID = D.DR_ID
WHERE
    A.MCDP_CD = 'CS' AND
    A.APNT_CNCL_YN = 'N' AND
    DATE(A.APNT_YMD) = '2022-04-13'
ORDER BY
    A.APNT_YMD ASC
;