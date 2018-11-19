fun addList nil = nil
   |   addList (first::rest) =   
       addList rest @ [first];
