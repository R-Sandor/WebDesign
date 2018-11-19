fun contaminatedList (status: string, personalGroups: int list,
  contaminated:int list ) = 
  if status = "Infectious" then personalGroups
  else 
    []
