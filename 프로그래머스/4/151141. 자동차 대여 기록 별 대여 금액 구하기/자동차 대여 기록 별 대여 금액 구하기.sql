SELECT h.history_id,
       TRUNC(c.DAILY_FEE * ((TO_NUMBER(h.END_DATE - h.START_DATE)) + 1) *
       (100 - NVL((
       SELECT p.DISCOUNT_RATE FROM car_rental_company_discount_plan p
           WHERE p.car_type = c.car_type
           AND p.DURATION_TYPE = 
           CASE 
                WHEN (TO_NUMBER(h.END_DATE - h.START_DATE) + 1) <7 THEN '1'
                WHEN (TO_NUMBER(h.END_DATE - h.START_DATE) + 1) <30 THEN '7일 이상'
                WHEN (TO_NUMBER(h.END_DATE - h.START_DATE) + 1) <90 THEN '30일 이상'
                ELSE '90일 이상'
            END
       ),0))/100) AS fee
FROM   car_rental_company_car c, car_rental_company_rental_history h
WHERE h.car_id = c.car_id
AND   c.car_type = '트럭'
ORDER BY fee DESC, HISTORY_ID DESC;