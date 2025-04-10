/**************************************************************************
TO_CHAR로 월을 문자형으로 변환하니까 ORDER BY 절에서 정렬이 제대로 안 됐다.
숫자형(NUMBER TYPE)으로 변환해줘야 오름차순 정렬이 정확하게 된다.
***************************************************************************/
/

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


/

SELECT DISTINCT TO_CHAR(s.sales_date, 'YYYY') AS YEAR
               ,TO_NUMBER(TO_CHAR(s.sales_date, 'MM')) AS MONTH
               ,u.gender
               ,COUNT(DISTINCT u.user_id) 
               OVER(PARTITION BY GENDER, 
                    TO_NUMBER(TO_CHAR(s.sales_date, 'MM')), 
                    TO_CHAR(s.sales_date, 'YYYY')) AS USERS
FROM   ONLINE_SALE s
      ,user_info   u
WHERE  s.user_id = u.user_id
       AND u.gender IS NOT NULL
ORDER  BY YEAR
         ,MONTH
         ,GENDER
