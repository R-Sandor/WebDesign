fun getFrontOfPopulation (position:int , inputlist:(int * int * int * string * int * int * 
	string * int * string * int list) list, outputList ) =
	if position < 1 then outputList  
	else
		let  
			val addToOutPut = hd(inputlist);
			val inputlist = tl(inputlist); 
			val outputList = outputList@[addToOutPut];
			val position = position -1; 
		in getFrontOfPopulation(position, inputlist, outputList)
	end; 