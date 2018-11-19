fun stillContaminated(count, population, returnList) = 
if count >= listCounter population then returnList
else 
	if getExposure (getToSpot(count, population))= "Exposed" andalso getDaysSinceExposure(getToSpot(count, population))<= 3 
	then 
		let 
		val returnList = returnList@[getPID(getToSpot(count,population))]
		in stillContaminated(count+1,population, returnList)
	end
	else 
	 stillContaminated(count+1,population, returnList)