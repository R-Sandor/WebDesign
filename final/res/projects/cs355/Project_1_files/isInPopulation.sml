fun isInPopulation(aPID:int , population) =
if population = [] then false 
else 
if aPID = getPID(hd population) then true
	else  
	let val population = tl(population)
	in isInPopulation(aPID, population) 
end; 