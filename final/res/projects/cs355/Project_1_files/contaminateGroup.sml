fun contaminateGroup (contaminatedGroup:int list, population) = 
  if contaminatedGroup = [] then population
  else 
    let
      (* found member in contaminated (the group of people) *) 
      (* matches to the PID of a poluation list and gets a location *)
      (* so that way the list can be returned in normall order *)
      val foundLocationOfGroup = foundMember(contaminatedGroup, population,0 );
      val contaminatedPerson  =  contaminatePerson(foundLocationOfGroup, population);
      val front = getFrontOfPopulation(foundLocationOfGroup, population, []);
      val back = backOfPopulation(foundLocationOfGroup+1, population,[]); 
      val contaminatedPopulation = front@contaminatedPerson@back;
    in contaminateGroup((tl contaminatedGroup), contaminatedPopulation)
    end;   
      
      

      

       
