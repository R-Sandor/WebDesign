fun populationListCounter(input, x:int) = 
  if input =  []  then x
  else 
  	let 
    	val input = (tl (input));
    	val x =x+1

    in populationListCounter(input, x)
    end; 
