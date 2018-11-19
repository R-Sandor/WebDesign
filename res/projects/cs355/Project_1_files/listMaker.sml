fun listMaker listOfGroups = 
  if listOfGroups = [] then listOfGroups  
  else 
  let val aElement = hd(listOfGroups)
  in aElement::[]
  end
