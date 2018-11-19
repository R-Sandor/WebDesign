fun addToDaysSinceExposure (location , population) = 
  if location< 0 then population
  else 
    let 
      val person = getListInList(location, population);
      val person = (getPID person, getAge person, getFID person,
     getExposure person+1, getDaysSinceExposure person, getDaysOfIncubation person,
      getDiagnosed person, getDaysUntilDead person, getInfected person, getGroup  person);
      val x = ~1;
    in addToDaysSinceExposure(x,[ person]) 
    end; 
