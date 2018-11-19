fun addSinglePersonToGroup (pid:int, mixGrp:int list, returnedList:int list
  list )=
  if mixGrp= [] then returnedList  
  else 
    let       
      (* This is a just a simple postion counter *) 
      val x = 1; 
      val nextGroupToAdd= hd(mixGrp);
      val mixGrp = tl(mixGrp);
      val pos = lookupList(nextGroupToAdd, x,(hd( mixingGroups)));
      val returnedList = getListInList(pos, mixingGroups)@[pid];
      val frontOfList = getFrontOfList(pos, mixingGroups);
      val backOflist = getBackOfList(pos, mixingGroups);   
    in 
      addSinglePersonToGroup(pid, mixGrp, frontOfList, backOflist, [returnedList] )
    end;      

  |
      fun (pid:int, mixGrp :int list, frontOfList:int list  list , backOflist:int list list, [returnedList]) = 
      if mixGrp = [] then returnedList
        else
          let 
            val x = 1; 
            nextGroupToAdd = hd(mixGrp); 
            pos = lookupList(nextGroupToAdd, (hd(mixingGroups))); 
      
      
    in 
      addSinglePersonToGroup(pid, mixGrp, frontOfList, backOflist, [returnedList] )
    end;      
