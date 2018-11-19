fun infectedAndInfectious(population, count)= 
if count >= listCounter population then population
else 
	if getExposure (getToSpot(count, population))= "Infected" andalso getDaysOfIncubation(getToSpot(count, population))>=7 
	then 
		let
		val front = getFrontOfPopulation(count, population, []);
		val back = backOfPopulation(count+1, population, []);
		val current = infectedInfectiousPerson(count, population); 
		val population = front@current@back;
		val count =count+1
	in infectedAndInfectious(population, count)
end
	else 
	infectedAndInfectious(population, count+1)
