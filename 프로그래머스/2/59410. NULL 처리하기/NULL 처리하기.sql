-- 코드를 입력하세요
SELECT animal_type, NVL(name, 'No name'), sex_upon_intake
from animal_ins
order by animal_id