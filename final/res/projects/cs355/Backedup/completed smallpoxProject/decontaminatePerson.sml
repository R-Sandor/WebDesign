fun decontaminatePerson(location , population) = 
  if location< 0 then population
  else 
    let 
      val person = getListInList(location, population);
      val person = (getPID person, getAge person, getFID person,
      "notex", 0, 0,
      getDiagnosed person, getDaysUntilDead person, "NotInfectious", getGroup  person);
      val x = ~1;
    in decontaminatePerson(x,[ person]) 
    end; 