fun infectPopulation  (infectedPeople:int list, population) = 
  if infectedPeople = [] then population
  else 
    let
      (* found member in contaminated (the group of people) *) 
      (* matches to the PID of a poluation list and gets a location *)
      (* so that way the list can be returned in normall order *)
      val locationOfPerson = foundMember( [hd infectedPeople], population, 1)
      val front = getFrontOfPopulation(locationOfPerson-1, population, []);
      val back = backOfPopulation(locationOfPerson, population,[]); 
      val infectedPerson  =  infectIndividual(locationOfPerson-1, population);
      val infectedPopulation = front@infectedPerson@back;
      val remaining = tl infectedPeople
    in infectPopulation(remaining, infectedPopulation)
    end;   
      
      