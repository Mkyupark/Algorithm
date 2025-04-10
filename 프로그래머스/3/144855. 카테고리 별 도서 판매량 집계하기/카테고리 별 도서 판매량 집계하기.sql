-- 코드를 입력하세요
SELECT DISTINCT b.CATEGORY, SUM(s.sales) OVER (PARTITION BY b.CATEGORY) AS TOTAL_SALES
FROM BOOK b, book_sales s
WHERE b.book_id = s.book_id
AND TO_CHAR(s.sales_date, 'YYYYMM') = '202201'
ORDER BY category