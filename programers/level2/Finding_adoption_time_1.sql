SELECT HOUR(datetime) as HOUR, count(datetime) from animal_outs
group by HOUR(datetime)
HAVING HOUR >= 9 and HOUR <= 19
order by HOUR asc