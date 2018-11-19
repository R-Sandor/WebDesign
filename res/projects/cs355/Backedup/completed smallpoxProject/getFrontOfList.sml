fun getFrontOfList (position:int , inputlist:int list list , outputList:int list list  ) =
	if position < 1 then outputList  
	else
		let  
			val addToOutPut = hd(tl(inputlist));
			val inputlist = tl(inputlist); 
			val outputList = outputList@[addToOutPut];
			val position = position -1; 
		in getFrontOfList(position, inputlist, outputList)
	end; 