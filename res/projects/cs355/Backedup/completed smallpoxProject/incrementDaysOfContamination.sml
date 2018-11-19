fun incrementDaysOfContamination(population, count)= 
if count >= listCounter population then population
else 
	if getExposure (getToSpot(count, population))= "Exposed"   
	then 
		let
		val front = getFrontOfPopulation(count, population, []);
		val back = backOfPopulation(count+1, population, []);
		val current = addToDaysOfExposure(count, population); 
		val population = front@current@back;
		val count =count+1
	in incrementDaysOfContamination(population, count)
end
else 
	incrementDaysOfContamination(population, count+1)
