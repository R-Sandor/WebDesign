fun foundPerson (contaminatedGroup:int list, population, location:int)=
  if (getPID(hd( population))) = (hd (contaminatedGroup)) then location
  else 
    let 
      val location = location +1;
      val population = tl(population); 
    in foundPerson(contaminatedGroup, population, location)
  end; 
