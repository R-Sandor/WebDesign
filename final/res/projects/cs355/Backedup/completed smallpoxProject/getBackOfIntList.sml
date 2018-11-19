fun getBackOfIntList (position:int , inputlist:int list  , outputList:int list   ) =
	if position >= listCounter(inputlist) then outputList  
	else
		let  
			val addList = lookupList(hd inputlist,position, inputlist);
			val returnedPerson = List.nth(inputlist, position); 
			val outputList = outputList@[returnedPerson];
			val position = position +1; 


		in getBackOfIntList(position, inputlist, outputList)
	end; 