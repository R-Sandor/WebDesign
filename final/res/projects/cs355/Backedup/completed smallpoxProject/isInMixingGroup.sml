fun isInMixingGroup(aPersonsGroups:int list , contaminatedPerson:int list) = 
if  hd aPersonsGroups= hd contaminatedPerson then  [hd contaminatedPerson] 
else 
	if tl aPersonsGroups = [] then []
	else 
		let
		val remaining = tl(aPersonsGroups)
		in isInMixingGroup(remaining, contaminatedPerson)
	end;