WITH review_cnt AS (
    SELECT DISTINCT MEMBER_ID,
           COUNT(MEMBER_ID) OVER (PARTITION BY MEMBER_ID) AS CNT
    FROM REST_REVIEW
)
SELECT m.MEMBER_NAME, b.REVIEW_TEXT, TO_CHAR(b.REVIEW_DATE, 'YYYY-MM-DD') AS REVIEW_DATE
FROM MEMBER_PROFILE m, REST_REVIEW b
WHERE m.MEMBER_ID = b.MEMBER_ID(+)
AND b.Member_id IN (
SELECT MEMBER_ID 
    FROM REVIEW_CNT
    WHERE CNT = (
    SELECT MAX(CNT) FROM REVIEW_CNT )
)
ORDER BY REVIEW_DATE, REVIEW_TEXT;
