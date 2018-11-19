fun getInfectious(count, population, returnList) = 
if count >= listCounter population then returnList
else 
	if getInfected (getToSpot(count, population))= "Infectious" 
	then 
	let 
		val returnList = returnList@[getPID(getToSpot(count,population))]
		in getInfectious(count+1,population, returnList)
	end
	else 
		getInfectious(count+1,population,  returnList)
