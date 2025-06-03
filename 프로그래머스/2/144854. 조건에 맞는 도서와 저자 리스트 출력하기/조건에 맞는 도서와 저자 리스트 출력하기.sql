-- 코드를 입력하세요
SELECT b.book_id, a.author_name, 
TO_CHAR(b.PUBLISHED_DATE, 'YYYY-MM-DD') as PUBLISHED_DATE
from book b
left join author a
on b.author_id = a.author_id
where b.category = '경제'
ORDER BY PUBLISHED_DATE
