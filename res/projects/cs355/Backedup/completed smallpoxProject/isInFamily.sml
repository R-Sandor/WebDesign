(* Takes two people (p1-p2) and decides if they are in a family and returns the person if they are in a family *)
fun isInFamily(p1, p2) =
if getPID p1 = getPID p2 then true
else false 