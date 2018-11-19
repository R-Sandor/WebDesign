fun selectGroupToInfect(aRand:int) = 
if listCounter((getListInList(aRand, mixingGroups))) >= population_size div 100 then aRand
else 
	let
			val aRand = getRandom r; 
		in (aRand)
	end; 