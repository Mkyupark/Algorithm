-- 코드를 입력하세요
SELECT to_number(to_char(datetime,'HH24')) as hour,
count(to_number(to_char(datetime,'HH24'))) as count
from animal_outs
WHERE '09:00' <= TO_CHAR(datetime,'HH24:MI') 
AND TO_CHAR(datetime,'HH24:MI') <='19:59'
group by to_number(to_char(datetime,'HH24'))
order by hour