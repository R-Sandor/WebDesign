fun foundMember (contaminatedPpl:int list, population, location:int)=
  if (getPID(hd( population))) = (hd (contaminatedPpl)) then location
  else 
    let 
      val location = location +1;
      val population = tl(population); 
    in foundMember(contaminatedPpl, population, location)
  end; 

      
      
