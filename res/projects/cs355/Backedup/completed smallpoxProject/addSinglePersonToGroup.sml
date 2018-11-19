fun addSinglePersonToGroup (pid:int, mixGrp:int list, returnedList:int list
  list )=
  if mixGrp= [] then returnedList  
  else 
    let 
      val nextGroupToAdd= hd(mixGrp);
      val mixGrp = tl(mixGrp);
      val x = 1; 
      val pos = lookupList(nextGroupToAdd, x,(hd( returnedList)));
      val frontPrt = getFrontOfList (pos-1, returnedList, [getListInList(0,returnedList)]);
      val backPrt = getBackOfList (pos+1, returnedList, []); 
      val returnedList = getListInList(pos, returnedList)@[pid];
      val returnedList = frontPrt@[returnedList]@backPrt;
    in 
      addSinglePersonToGroup(pid, mixGrp, returnedList )
    end;      
