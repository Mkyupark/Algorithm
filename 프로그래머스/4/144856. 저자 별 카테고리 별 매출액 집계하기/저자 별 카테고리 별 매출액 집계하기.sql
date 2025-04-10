-- 코드를 입력하세요
SELECT DISTINCT a.author_id, a.author_name, b.category,
SUM(s.sales * b.price) OVER (PARTITION BY a.author_id, b.category) AS TOTAL_SALES
FROM BOOK_SALES s, book b, author a
WHERE s.book_id = b.book_id
AND b.author_id = a.author_id
AND TO_CHAR(s.SALES_DATE, 'YYYYMM') = '202201'
ORDER BY a.author_id, CATEGORY DESC;