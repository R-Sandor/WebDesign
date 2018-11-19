remove_duplicates([H | T], List) :- 
      member(H, T),
      remove_duplicates( T, List).
