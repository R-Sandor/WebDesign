fun lookupList (orgGrpNumber:int, counter:int, mixingGroups:int
  list ) =  
  if orgGrpNumber = (hd mixingGroups)  then counter  
  else 
    let 
    val counter = counter + 1
    val current = hd mixingGroups
    in lookupList(orgGrpNumber,  counter, (tl mixingGroups)) 
    end;
