fun survivedSmallpox(population, count)= 
if count >= listCounter population then population
else 
	if getExposure (getToSpot(count, population))= "Infected" andalso getDaysOfIncubation(getToSpot(count, population))>14 
	then 
		let
		val front = getFrontOfPopulation(count, population, []);
		val back = backOfPopulation(count+1, population, []);
		val current = immune(count, population); 
		val population = front@current@back;
		val count =count+1
	in survivedSmallpox (population, count)
end
else 
	survivedSmallpox(population, (count+1))