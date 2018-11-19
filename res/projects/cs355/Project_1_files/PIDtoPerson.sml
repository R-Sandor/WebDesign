fun PIDtoPerson(aPID:int , population) =
if aPID = getPID(hd population) then hd population
else 
	let val population = tl(population)
in PIDtoPerson(aPID, population) 
end; 