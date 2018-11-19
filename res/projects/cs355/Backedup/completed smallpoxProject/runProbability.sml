(* runs the probability that a person may become infected given a list of infected peopl *)
fun runProbability(aPerson:int, aGroup, riskOfInfection) = 
if aGroup = [] then riskOfInfection 
else 
	let 
	val personInGroup = hd aGroup; 
	val aFullPerson = PIDtoPerson (aPerson, population);
	val personInGroup = PIDtoPerson (personInGroup, population);
	val isPersonFamilyMember = isInFamily( aFullPerson, personInGroup);
	val child = getAge personInGroup  < 18;  
	val remaining =  (tl (aGroup));
	val riskOfInfection =  (if isPersonFamilyMember = true then 
								if child = true then riskOfInfection+0.03520
								else riskOfInfection +0.01240
							else riskOfInfection+ 0.01000);
in runProbability(aPerson, remaining, riskOfInfection)
end;