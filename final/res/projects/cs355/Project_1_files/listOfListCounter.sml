fun listOfListCounter (input:int list list, x:int) = 
  if input =  []  then x
  else 
  	let 
    	val input = (tl (input));
    	val x =x+1

    in listOfListCounter(input, x)
    end; 
