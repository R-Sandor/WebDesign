fun getFrontOfIntList (position:int , inputlist:int list , outputList:int list   ) =
	if position <1 then outputList  
	else
		let  
			val addToOutPut = hd(inputlist);
			val inputlist = tl(inputlist); 
			val outputList = outputList@[addToOutPut];
			val position = position -1; 
		in getFrontOfIntList(position, inputlist, outputList)
	end; 