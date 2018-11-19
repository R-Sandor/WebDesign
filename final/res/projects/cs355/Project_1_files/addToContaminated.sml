fun addToContaminated(contaminatedGroup:int list, population, localcontaminated) = 
  if  contaminatedGroup = [] then localcontaminated
  else 
    let 
      val locationInMixingGroup = foundGroup(hd mixingGroups,hd  contaminatedGroup ,1 );
      val localcontaminated = localcontaminated@getListInList(locationInMixingGroup,  mixingGroups);
    in addToContaminated(tl contaminatedGroup, population, localcontaminated)
    end;  
       
