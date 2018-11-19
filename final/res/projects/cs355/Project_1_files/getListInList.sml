fun getListInList (position:int, aList) =
  if position = 0 then hd(aList) 
  else
    let  
     val x = position - 1;
     val remaining= tl(aList); 
     in getListInList (x, remaining)
  end;   

