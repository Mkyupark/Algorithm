SELECT ANIMAL_ID
      ,NAME
FROM   (
        SELECT i.animal_id
               ,i.name
               ,RANK() OVER(ORDER BY(o.DATETIME - i.DATETIME) DESC) AS RN
        FROM   ANIMAL_INS i
        LEFT   JOIN animal_outs o
        ON     i.animal_id = o.animal_id
        WHERE  o.datetime IS NOT NULL
        ORDER  BY RN ASC)
WHERE  RN <= 2
