fun tryToInfect (localContaminated:int list, infectedPeople:int list, days  ) = 
if localContaminated = [] then infectedPeople 
	else
		let 
			val aPerson = hd (localContaminated);
			val remaining = tl (localContaminated);  
			(* returns people who share groups with a person that is contaminated *)
			val sharedPersonalGroups = sharedGroups(aPerson, contaminated, []);
			val probablity = runProbability(aPerson, sharedPersonalGroups, 0.0);
			val nextInt = Random.randRange(0,100)
			val chance = Real.fromInt(nextInt r); 
			val infectedPeople = infectedPeople@(if (probablity*100.0) < chance+chance*days/12.0 then [aPerson] else [])
		in tryToInfect(remaining, infectedPeople, days)
	end; 