fun changeContaminatedStatus(population, count)= 
if count >= listCounter population then population
else 
	if getExposure (getToSpot(count, population))= "Exposed" andalso getDaysSinceExposure(getToSpot(count, population))>3 
	then 
		let
		val front = getFrontOfPopulation(count, population, []);
		val back = backOfPopulation(count+1, population, []);
		val current = decontaminatePerson(count, population); 
		val population = front@current@back;
		val count =count+1
	in changeContaminatedStatus(population, count)
end
else 
	changeContaminatedStatus(population, count+1)

