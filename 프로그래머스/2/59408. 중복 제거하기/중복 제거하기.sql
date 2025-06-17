-- 코드를 입력하세요

select count(name) as count
from (
SELECT distinct(name) from ANIMAL_INS 
    )


