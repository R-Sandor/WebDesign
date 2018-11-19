fun createGroups (i:int , listOfGroups )= 
if  i = 0   then listOfGroups  
else
        let
        val listOfGroups =listOfGroups@[[]]; 
        
        val i = i -1;    
        in  createGroups(i, listOfGroups)
end;
    
