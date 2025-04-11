SELECT FLAVOR
FROM   (
        
        SELECT j.FLAVOR
               ,SUM(J.TOTAL_ORDER + o.TOTAL_ORDER) AS TOTAL_ORDER
        FROM   JULY       J
               ,FIRST_HALF o
        WHERE  J.FLAVOR = o.FLAVOR
        GROUP  BY j.flavor
        ORDER  BY TOTAL_ORDER DESC)
WHERE  ROWNUM <= 3;