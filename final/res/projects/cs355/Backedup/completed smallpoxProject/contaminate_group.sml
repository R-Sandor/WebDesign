fun contaminateGroup (contaminatedGroup:int list, population) = 
  if contaminatedGroup = [] then population
  else 
    let 
      val foundLocationOfGroup = foundMember(contaminatedGroup, population, 1);
      val contaminatedPerson  =
        contaminatePerson(foundLocationOfGroup-1,population);
      val front = frontPopulation(foundLocationOfGroup, population);
      val back = backPopulation(foundLocationOfGroup, population); 
      val contaminatedPopulation = front@contaminatedPerson@back;
    in contaminateGroup((tl contaminatedGroup), contaminatedPopulation)
    end;   
      
      

       
