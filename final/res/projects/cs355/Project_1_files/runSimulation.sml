fun runSimulation (days:int, population, deadPeople, infectedPeople, infectiousPeople, contaminated, immuneList) = 
if days > 30 then population
else 
	let 
	val stringDays = Int.toString(days);
	val stringContaminatedCount = Int.toString(listCounter contaminated); 
	val stringInfectedCount = Int.toString(listCounter infectedPeople); 
	val stringImmune = Int.toString(listCounter immuneList); 
	val stringDead = Int.toString(listCounter deadPeople); 
	val no= writeFile path "_______________________________________________________\n";
	val non= writeFile path "Day:"; 
	val non= writeFile path stringDays; 
	val nonReturn = writeFile path " ";
	val nonReturn = writeFile path "contaminated:";
	val nonReturn = writeFile path 	stringContaminatedCount;
	val nonReturn = writeFile path " ";
	val nonReturn = writeFile path 	"Infected:";
	val nonReturn = writeFile path 	stringInfectedCount; 
	val nonReturn = writeFile path " ";
	val nonReturn = writeFile path  "Dead:" ;
	val nonReturn = writeFile path  stringDead;
	val nonReturn = writeFile path " ";
	val nonReturn = writeFile path  "Immune:" ;
	val nonReturn = writeFile path  stringImmune;
	val nonReturn = writeFile path "\n_______________________________________________________\n";
	val days = days +1; 

	(* Do the basic adding to peoples states *)

	val population = incrementInfectionDays(population, 0 ); 
	val population = incrementDaysOfContamination(population, 0);
	val population = infectedNotInfectious(population,0); 	
	val population = survivedSmallpox(population, 0); 
	val population = changeContaminatedStatus(population, 0);
	val contaminated = stillContaminated(0, population, []);
	val immuneList = getImmune(0, population, [])@immuneList;
	val population = infectedAndInfectious(population,0); 
	val deadPeople = updateListOfDead(population, [])@deadPeople; 
	val deadPeople = isolate deadPeople; 
	val population = removeFromPopulation(deadPeople, population);
	val infectiousPeople = getInfectious(0, population, infectiousPeople)@contaminated; 


	(* moving the virus*) 
	val infectedPeople = tryToInfect(contaminated, [], Real.fromInt(days))@infectedPeople;
	val infectedPeople = isolate infectedPeople;
	val infectedPeople = removeFromList(infectedPeople,deadPeople, infectedPeople);
	val population = infectWithInfectious(0,population, infectiousPeople);
	val population = infectPopulation(infectedPeople, population); 
	
in runSimulation(days, population, deadPeople, infectedPeople, infectiousPeople, contaminated, immuneList) 
end; 