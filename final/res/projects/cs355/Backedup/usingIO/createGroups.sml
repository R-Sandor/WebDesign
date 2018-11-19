fun createGroups (mixingGroups :int list )= 
if  mixingGroups = [] then [] 
else
let
 val xVal = (hd mixingGroups)
 val remaining = (tl mixingGroups);   
 val stringData = ("val grp"^(Int.toString(xVal))^"=[];\n")      
 val text =  writeFile fullpath stringData  
 in  createGroups(remaining)
end;
    
