fun goThroughGroups (population, x:int, mixgrps:int list) = 
  if x <= 0 then mixgrps
  else 
let
  val person = (hd population)
  val aGroup = getGroup person
  val remaining = (tl population)
  val mixingGroups = aGroup@mixgrps
  val newX= x-1
in 
  goThroughGroups (remaining, newX, mixingGroups)
end;
  
