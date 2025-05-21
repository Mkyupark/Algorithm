SELECT NAME
      ,datetime
FROM   (SELECT i.name
              ,i.datetime
              ,RANK() over(ORDER BY i.datetime) AS rn
        FROM   animal_ins i
        LEFT   JOIN animal_outs o
        ON     i.animal_id = o.animal_id
        WHERE  o.datetime IS NULL)
where rn <=3