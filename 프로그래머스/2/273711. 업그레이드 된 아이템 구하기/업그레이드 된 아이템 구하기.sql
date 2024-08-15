-- 코드를 작성해주세요

SELECT ti.ITEM_ID, ti.ITEM_NAME, ti.RARITY from ITEM_INFO AS ti inner join ITEM_TREE as it
on ti.ITEM_ID = it.ITEM_ID where it.PARENT_ITEM_ID IN
(select ITEM_ID from ITEM_INFO where RARITY = "RARE")
ORDER by ti.ITEM_ID DESC;
