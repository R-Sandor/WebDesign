fun tryToKill(aPerson) = 
if getDaysOfIncubation aPerson >= 7  then  
	if 
		randoms0to100 r >90
		then
		let 
		val status = "dead";
	in status
end
	else let val status = "alive"
in 
	status
end
else let val status ="alive" 
in status
end;