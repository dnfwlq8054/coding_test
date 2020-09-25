-- 코드를 입력하세요
SELECT a.animal_id, a.animal_type, a.name
from (select *
     from animal_ins
     where sex_upon_intake like '%intact%')a, animal_outs b
     where a.animal_id = b.animal_id 
     and sex_upon_outcome not like '%intact%'