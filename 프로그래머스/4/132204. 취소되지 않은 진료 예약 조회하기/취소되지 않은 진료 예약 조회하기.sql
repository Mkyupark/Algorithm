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
 WHERE 1=1
   AND TO_CHAR(APNT_YMD,'YYYYMMDD') = '20220413'
   AND NVL(A.APNT_CNCL_YN,'N') != 'Y'
   AND A.MCDP_CD = 'CS'
 ORDER
    BY A.APNT_YMD ASC