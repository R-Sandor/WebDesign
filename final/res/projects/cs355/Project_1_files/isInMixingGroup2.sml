fun isInMixingGroup2(aPersonsGroups:int list , infectiousPersons:int list) = 
if aPersonsGroups = [] = false  then
	if (isSome (List.find (fn x => x = hd aPersonsGroups)infectiousPersons)) = true  
		then true
	else 
		isInMixingGroup2(tl aPersonsGroups, infectiousPersons)

else 
	false