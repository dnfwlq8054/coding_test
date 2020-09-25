SELECT B.animal_id, B.name
from Animal_ins A 
right join Animal_outs B on A.animal_id = B.animal_id
where B.datetime < A.datetime
order by A.datetime