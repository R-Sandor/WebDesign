fun contaminatePopulation(population, localContaminatedList:int list )= 
if tl population = [] then localContaminatedList
else 
  if getExposure(hd(tl(population))) = "Exposed" then 
  let 
    val person = hd(tl(population)); 
    val status = (getExposure person);
    val personalGroups = (getMixGroups person);
    val contaminatedReturn = personalGroups@localContaminatedList;
    val remaining = tl population;    
  in contaminatePopulation(remaining, contaminatedReturn)
  end
  else 
  contaminatePopulation(tl population, localContaminatedList)
