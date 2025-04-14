SELECT '/home/grep/src/' || board_id || '/' || file_id || file_name || file_ext AS FILE_PATH
FROM   used_goods_file
WHERE  BOARD_ID = (SELECT BOARD_ID
                   FROM   USED_GOODS_BOARD 
                   ORDER  BY VIEWS DESC
                   FETCH FIRST 1 ROWS ONLY)
ORDER  BY FILE_ID DESC;