fun infectedNotInfectiousPerson (location , population) = 
  if location< 0 then population
  else 
    let 
      val person = getListInList(location, population);
      val person = (getPID person, getAge person, getFID person,
      "Infected", 0, getDaysOfIncubation person,
      getDiagnosed person, getDaysUntilDead person, "NotInfectious", getGroup  person);
      val x = ~1;
    in infectedNotInfectiousPerson(x,[ person]) 
    end; 