fun addToDaysOfExposure(location , population) = 
  if location< 0 then population
  else 
    let 
      val person = getListInList(location, population);
      val person = (getPID person, getAge person, getFID person,
     getExposure person, getDaysSinceExposure person+1, getDaysOfIncubation person,
      getDiagnosed person, getDaysUntilDead person, getInfected person, getGroup  person);
      val x = ~1;
    in addToDaysOfIncubation(x,[ person]) 
    end; 