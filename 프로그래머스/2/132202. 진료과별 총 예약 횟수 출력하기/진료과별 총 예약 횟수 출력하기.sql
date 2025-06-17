-- 코드를 입력하세요
SELECT MCDP_CD as "진료과코드", count(MCDP_CD) as "5월예약건수"
FROM APPOINTMENT
WHERE TO_CHAR(APNT_YMD, 'YYYYMM') = '202205'
group by MCDP_CD
ORDER BY "5월예약건수" , MCDP_CD