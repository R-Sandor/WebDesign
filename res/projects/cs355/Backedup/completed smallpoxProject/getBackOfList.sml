fun getBackOfList (position:int , inputlist:int list list , outputList:int list list  ) =
	if position >= listOfListCounter(inputlist, 0) then outputList  
	else
		let  
			val addList = getListInList(position, inputlist);
			val outputList = outputList@[addList];
			val position = position +1; 


		in getBackOfList(position, inputlist, outputList)
	end; 