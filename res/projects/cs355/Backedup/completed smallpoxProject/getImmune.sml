fun getImmune(count, population, returnList) = 
if count >= listCounter population then returnList
else 
	if getExposure (getToSpot(count, population))= "Immune"
	then 
		let 
		val returnList = returnList@[getPID(getToSpot(count,population))]
		in getImmune(count+1,population, returnList)
	end
	else 
	 getImmune(count+1,population, returnList)