-- 코드를 입력하세요
select datetime 
from(
SELECT DATETIME
from animal_ins
order by DATETIME
)
where ROWNUM <=1