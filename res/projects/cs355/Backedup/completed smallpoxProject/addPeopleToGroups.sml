fun addPeopleToGroups (population, allMixingGrps) = 
  if   population = [] then allMixingGrps
  else let 
    val personalMixGrp =  getGroup (hd population)
    val pid = getPID (hd population)
    val allMixingGrps =  addSinglePersonToGroup (pid, personalMixGrp, allMixingGrps)
    val remaining = tl(population);
    in addPeopleToGroups (remaining, allMixingGrps)
   end;  
