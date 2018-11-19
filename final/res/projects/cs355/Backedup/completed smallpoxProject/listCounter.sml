fun listCounter (mixingGroups) = 
  if mixingGroups = []  then 0
  else 
    1 + listCounter(tl mixingGroups); 

