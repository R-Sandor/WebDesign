fun infectedNotInfectious(population, count) = 
if count >= listCounter population then population
else 
	if getExposure (getToSpot(count, population))= "Infected" andalso getDaysOfIncubation(getToSpot(count, population))<7 
	then 
		let
		val front = getFrontOfPopulation(count, population, []);
		val back = backOfPopulation(count+1, population, []);
		val current = infectedNotInfectiousPerson(count, population); 
		val population = front@current@back;
		val count =count+1
	in infectedNotInfectious(population, count)
end
	else 
	infectedNotInfectious(population, count+1)
