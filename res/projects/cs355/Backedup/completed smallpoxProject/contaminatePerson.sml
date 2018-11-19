fun contaminatePerson (location , population) = 
  if location< 0 then population
  else 
    let 
      val person = getListInList(location, population);
      val person = (getPID person, getAge person, getFID person,
      "Exposed", 0, getDaysOfIncubation person,
      getDiagnosed person, getDaysUntilDead person, "Infectious", getGroup  person);
      val x = ~1;
    in contaminatePerson(x,[ person]) 
    end; 

