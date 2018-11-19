val r = Random.rand(0,100);

fun randoms0to100 (r) =
let 
		val nextInt = Random.randRange(0, 100);
in
		(nextInt r)
end;