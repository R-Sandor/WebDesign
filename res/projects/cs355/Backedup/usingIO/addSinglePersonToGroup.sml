fun addSinglePersonToGroup (pid:int, mixGrp:int list)=
  if mixGrp [] then = individualGroups
  else 
    let 
      val nextGroupToAdd= hd(mixGrp);
      val mixGrp = tl(mixGrp);
      val pos = lookupPositon(nextGroupToAdd, 0, mixingGroups);
      val returnedList = getListInList(pos, individualGroups);
      val individualGroups = returnedList@[pid] ;
    in 
      addSinglePersonToGroup(pid, mixGrp);
    end;      
