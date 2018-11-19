fun incrementInfectionDays(population, count)= 
if count >= listCounter population then population
else 
	if getExposure (getToSpot(count, population))= "Infected"  
	then 
		let
		val front = getFrontOfPopulation(count, population, []);
		val back = backOfPopulation(count+1, population, []);
		val current = addToDaysOfIncubation(count, population); 
		val population = front@current@back;
		val count =count+1
	in incrementInfectionDays(population, count)
end
else 
	incrementInfectionDays(population, count+1)

