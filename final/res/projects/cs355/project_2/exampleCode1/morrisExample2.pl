         

/*
  This is a little adventure game.  There are three
  entities: you, an overload form, and a Morris.  There are six places: a campus, a covered_walkway, the_web, a hallway_juncture, the_ted, and the deans_office.  Your goal is to get the overload form without being killed first.
*/

/*
  First, text descriptions of all the places in
  the game.
*/
description(campus,
  'You are on a pleasant campus, with a trail ahead.').
description(covered_walkway,
  'You are on a covered_walkway, with grassy knolls on both sides.').
description(the_web,
  'You are teetering on the edge of the_web.').
description(hallway_juncture,
  'You are at a hallway_juncture under the covered_walkway.').
description(the_ted(_),
  'You are in the_ted of twisty trails, all alike.').
description(deans_office,
  'You are in the deans_office.').

/*
  report prints the description of your current
  location.
*/
report :-
  at(you,X),
  description(X,Y),
  write(Y), nl.
