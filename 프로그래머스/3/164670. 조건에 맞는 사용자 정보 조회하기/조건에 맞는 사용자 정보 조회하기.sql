SELECT u.USER_ID
      ,u.NICKNAME
      ,u.CITY || ' ' || u.STREET_ADDRESS1 || ' ' ||u.STREET_ADDRESS2 AS "전체주소"
      ,SUBSTR(u.TLNO,1,3) || '-' || SUBSTR(u.TLNO,4,4) || '-' || SUBSTR(u.TLNO,8,4) AS "전화번호"
FROM   USED_GOODS_USER u
WHERE  EXISTS (
        SELECT 1
        FROM   USED_GOODS_BOARD b
        WHERE  b.WRITER_ID = u.USER_ID
        GROUP  BY b.WRITER_ID
        HAVING COUNT(b.WRITER_ID) >= 3)
ORDER BY u.USER_ID DESC;