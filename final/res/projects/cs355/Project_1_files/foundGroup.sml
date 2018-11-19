fun foundGroup(searchThroughGroup:int list , contaminatedGroup:int  , location)=
  if hd searchThroughGroup = contaminatedGroup then location
  else 
    let 
      val location = location +1;
      val searchThroughGroup = tl(searchThroughGroup); 
    in foundGroup(searchThroughGroup, contaminatedGroup, location)
  end; 



      
      
