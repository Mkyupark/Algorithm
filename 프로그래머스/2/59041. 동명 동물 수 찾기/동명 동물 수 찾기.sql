-- 코드를 입력하세요
SELECT name, count(name) as count
from animal_ins
where name is not null
group by name
having count(name) > 1
order by name