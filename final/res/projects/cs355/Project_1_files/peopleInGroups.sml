fun peopleInGroups(groups:int list , people, returnList) =
if  groups = [] then returnList 
else 
	let  
	(* Next group to search for *)
	  val searchFor = hd groups;
	  (* location of group in the list of mixing groups *)
	  (* used to find people in a mixingGroup *)
	  (* starting at 1 at one so that the list of mixing groups is not counted 
	  that contains people inside *)
	  val location = lookupList( searchFor, 1,hd mixingGroups);
	  (* returns the list at a location //The location in the mixingroups where 
	  a group was found *)
	  val foundList = getListInList(location, mixingGroups);
	  val returnList = foundList@returnList;
	  val groups = tl groups;
	in peopleInGroups(groups, people, returnList)
end; 