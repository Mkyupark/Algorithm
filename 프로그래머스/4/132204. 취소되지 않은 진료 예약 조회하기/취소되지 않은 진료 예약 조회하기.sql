SELECT
       A.APNT_NO      -- 진로예약번호
       , P.PT_NAME    -- 환자이름
       , P.PT_NO      -- 환자번호
       , A.MCDP_CD    -- 진료과코드
       , D.DR_NAME    -- 의사이름
       , A.APNT_YMD   -- 진로예약일시
  FROM APPOINTMENT A
  JOIN PATIENT P
    ON P.PT_NO = A.PT_NO
  JOIN DOCTOR D
    ON D.DR_ID = A.MDDR_ID
 WHERE TO_CHAR(APNT_YMD,'YYYYMMDD') = '20220413'
   AND NVL(A.APNT_CNCL_YN,'N') != 'Y'
   AND A.MCDP_CD = 'CS'
 ORDER
    BY A.APNT_YMD ASC
/
-- 채점 기준에서 ANSI JOIN을 쓰지 않으면 안되는 것 같음
-- 아래는 틀렸다고 나옴
SELECT a.APNT_NO
      ,p.PT_NAME
      ,a.PT_NO
      ,a.MCDP_CD
      ,d.DR_NAME
      ,a.APNT_YMD
FROM   APPOINTMENT a
      ,patient     p
      ,DOCTOR      d
WHERE  a.PT_NO = p.PT_NO
       AND a.MDDR_ID = d.DR_ID
       AND a.MCDP_CD = 'CS'
       AND a.APNT_CNCL_YN = 'N'
       AND TO_CHAR(a.APNT_YMD, 'YYYYMMDD') = '20220413'
ORDER  BY a.APNT_NO;
