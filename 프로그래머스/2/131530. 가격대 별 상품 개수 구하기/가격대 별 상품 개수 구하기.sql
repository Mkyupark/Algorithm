select floor(price/10000) * 10000 as price_group,
        count(floor(price/10000)*10000) as products
from product
group by floor(price/10000)*10000
order by price_group