fun infectWithInfectious(count, population, infectiousPeople) = 
if count >= (listCounter population)  then population 
else 
	if getExposure(getToSpot(count, population)) = "notex" 
	then 
	let 
		val person = getToSpot(count, population);
		val mixingGroups = getGroup person;
		val peopleInThoseGroups = sharedGroups(getPID person,infectiousPeople,[]);
		(* will return a bool *)
		val infectiousPeopleInMixingGroup = isInMixingGroup2(peopleInThoseGroups, infectiousPeople);
		val population = 
			(if infectiousPeopleInMixingGroup = true
			then 
			let 
				val front = getFrontOfPopulation(count, population, []);
				val back = backOfPopulation(count+1, population, []);
				val current = contaminatePerson(count, population); 
				val population = front@current@back;
				val count =count+1 
			in population
		end
			else
				population);
		in infectWithInfectious(count+1,population, infectiousPeople)
		end
	else infectWithInfectious(count+1, population, infectiousPeople);