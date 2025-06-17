-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME, GENDER, TO_CHAR(DATE_OF_BIRTH, 'yyyy-mm-dd') as date_of_birth
from member_profile
where To_char(DATE_OF_BIRTH, 'MM') ='03'
and tlno is not null
and gender = 'W'
order by member_id