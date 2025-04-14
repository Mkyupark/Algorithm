WITH DUMMY AS (
    SELECT CAR_ID
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE START_DATE BETWEEN DATE '2022-08-01' AND DATE '2022-10-31'
    GROUP BY CAR_ID
    HAVING COUNT(*) >= 5
)

SELECT 
    EXTRACT(MONTH FROM START_DATE) AS MONTH,
    CAR_ID,
    COUNT(*) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY a
WHERE START_DATE BETWEEN DATE '2022-08-01' AND DATE '2022-10-31'
  AND EXISTS (SELECT 1 FROM DUMMY b WHERE a.car_id = b.car_id)
GROUP BY EXTRACT(MONTH FROM START_DATE), CAR_ID
ORDER BY MONTH, CAR_ID DESC;


/
WITH FILTERED_HISTORY AS (
    SELECT 
        CAR_ID,
        EXTRACT(MONTH FROM START_DATE) AS MONTH
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE START_DATE BETWEEN DATE '2022-08-01' AND DATE '2022-10-31'
),
DUMMY AS (
    SELECT CAR_ID
    FROM FILTERED_HISTORY
    GROUP BY CAR_ID
    HAVING COUNT(*) >= 5
)

SELECT 
    FH.MONTH,
    FH.CAR_ID,
    COUNT(*) AS RECORDS
FROM FILTERED_HISTORY FH
WHERE FH.CAR_ID IN (SELECT CAR_ID FROM DUMMY)
GROUP BY FH.MONTH, FH.CAR_ID
ORDER BY FH.MONTH, FH.CAR_ID DESC;
