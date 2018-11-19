(* returns all the people that a person shares a group with that are also contaminated and  *)
fun sharedGroups(aPerson:int, contaminated, returnedList:int list)=
if contaminated = [] then returnedList
else 
  let
  	(* First person in the list of contamianted people *)
  	val contaminatedPerson = hd contaminated
  	(* remaininng the list group of contaminated poeple*)
  	val remaining = tl(contaminated)  
  	(* Convert the personal id passed in to the PIDtoPerson and return the whole person *)
  	val convertedPID = PIDtoPerson (aPerson, population);
  	(* Gets the groups from the person *)
  	val personalGroups = getGroup convertedPID;
  	(* Takes in the persons groups and gets a list of people *)
  	val peopleInGroups = peopleInGroups(personalGroups, contaminated, [])
  	(* sees if any of them are a contaminated person *)
    val inMixingGroups = isInMixingGroup(peopleInGroups, [contaminatedPerson]);
    (* List of people who are contaminated that share a group with the contaminated person *)
    val aReturnedList = returnedList@inMixingGroups;
  in sharedGroups(aPerson, remaining, aReturnedList)
end;

     