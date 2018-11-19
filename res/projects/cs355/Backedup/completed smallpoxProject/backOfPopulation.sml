fun backOfPopulation(position:int , inputlist:(int * int * int * string * int * int * 
	string * int * string * int list) list, outputList ) = 
	if position >= populationListCounter(inputlist, 0) then outputList  
	else
		let  
			val addList = getListInList(position, inputlist);
			val outputList = outputList@[addList];
			val position = position +1; 
		in backOfPopulation(position, inputlist, outputList)
	end; 