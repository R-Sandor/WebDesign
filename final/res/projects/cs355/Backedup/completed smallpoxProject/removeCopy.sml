fun isolate [] = []
  | isolate (l as x::xs) =
      let fun remove (x,[]) = []
            | remove (x,l as y::ys) = if x = y
                                      then remove(x,ys)
                                      else y::remove(x,ys)
      in
        x::isolate(remove(x,xs))
        end;

