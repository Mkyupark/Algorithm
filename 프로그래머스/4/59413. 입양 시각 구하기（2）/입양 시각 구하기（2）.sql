WITH dummy AS (SELECT LEVEL - 1 AS HOUR
FROM DUAL
CONNECT BY LEVEL <=24)
SELECT d.hour, count(TO_NUMBER(TO_CHAR(a.datetime,'hh24'))) as count 
FROM dummy d LEFT JOIN ANIMAL_OUTS a
on d.hour = TO_NUMBER(TO_CHAR(a.datetime,'hh24'))
GROUP BY d.hour
order by d.hour