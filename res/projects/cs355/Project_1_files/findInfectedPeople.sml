fun findInfectedPeople(population, count, returnList) =
if count >= listCounter population then returnList
else 
	if getExposure (getToSpot(count, population))= "Infected"  
	then 
		let
		val current = [getPID(getToSpot(count, population))]@returnList; 
		val returnList = current;
	in findInfectedPeople(population, count+1, returnList)
end
else 
	findInfectedPeople(population, count+1, returnList)
