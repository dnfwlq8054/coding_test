SELECT animal_id, name,
case
when sex_upon_intake like '%Spayed%' or sex_upon_intake like '%Neutered%' then 'O'
else 'X'
end
from animal_ins