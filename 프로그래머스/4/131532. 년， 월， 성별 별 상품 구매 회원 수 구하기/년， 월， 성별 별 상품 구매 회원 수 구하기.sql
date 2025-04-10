SELECT TO_CHAR(s.sales_date, 'YYYY')    AS year
     , TO_NUMBER(TO_CHAR(s.sales_date, 'MM'))  AS month
     , u.gender
     , COUNT(DISTINCT u.user_id) AS users  -- 중복을 제거한 유저 수
FROM   online_sale s
       JOIN user_info u
         ON s.user_id = u.user_id
WHERE  u.gender IS NOT NULL
GROUP BY TO_CHAR(s.sales_date, 'YYYY')
       , TO_NUMBER(TO_CHAR(s.sales_date, 'MM'))
       , u.gender
ORDER BY year, month, gender;