SELECT ANIMAL_TYPE, COUNT(ANIMAL_TYPE) AS 'count' 
FROM ANIMAL_INS 
where ANIMAL_TYPE in ('Cat', 'Dog')
group by animal_type
order by animal_type