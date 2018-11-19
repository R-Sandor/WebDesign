fun contaminatePeopleInGroups (contGrps:int list, mixGrps, contPpl) = 
  if  contGrps = [] then contPpl
  else 
    let 
      val findGrp = hd contGrps; 
      val remaining = tl contGrps; 
      val pos = lookupList(findGrp,1,hd mixGrps);   
      val contPpl = hd (tl contaminated)@getListInList(2, mixingGroups);
    in contaminatePeopleInGroups( remaining, mixGrps, contPpl)
    end; 
