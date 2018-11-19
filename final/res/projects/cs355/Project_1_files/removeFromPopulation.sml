fun removeFromPopulation (aList:int list, population) = 
if  aList = [] then population
else 
	if 
	isInPopulation(hd aList, population) = true   
	then 
	let
	(* returns the location of the PID in the list of contaminated *)
	val location = foundMember(aList, population,0);
	val front = getFrontOfPopulation(location, population, []);
	val back = backOfPopulation(location+1, population, []);
	val population = front@back;
	in removeFromPopulation(aList, population)
	end 
	else 
		removeFromPopulation(tl aList, population)


