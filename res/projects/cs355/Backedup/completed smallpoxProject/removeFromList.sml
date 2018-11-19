fun removeFromList (affectedList, listToCheckAgainst, returnList ) = 
if  listToCheckAgainst = [] then returnList
else 
	if 
	(isSome (List.find (fn x => x = hd listToCheckAgainst)affectedList)) = true  
	then 
	let
	(* returns the location of the PID in the list of contaminated *)
	val location = lookupList( hd listToCheckAgainst, 0, affectedList);
	val front = getFrontOfIntList(location, affectedList, []);
	val back = getBackOfIntList(location+1, affectedList, []);
	val returnList = front@back;
	val affectedList = returnList;
	val listToCheckAgainst= tl listToCheckAgainst
	in removeFromList(affectedList  ,listToCheckAgainst, returnList)
	end 
	else 
		removeFromList(returnList, tl listToCheckAgainst, returnList)


