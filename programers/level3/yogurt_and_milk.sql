-- 코드를 입력하세요
SELECT DISTINCT b.cart_id
from (select cart_id
     from cart_products
     where name = 'milk')a, cart_products b
where a.cart_id = b.cart_id
and b.name = 'yogurt'
