(* tries to kill people who are infected and are past 7 days of incubation *)
fun updateListOfDead (population, returnList)= 
if population = [] then returnList 
else 
	 if  tryToKill(hd population) = "dead" then
	let
		val dead = getPID(hd population); 
		val deadPeople = [dead]@returnList;
		in updateListOfDead(tl population ,deadPeople)
	end
	else 
		updateListOfDead(tl population, returnList)
