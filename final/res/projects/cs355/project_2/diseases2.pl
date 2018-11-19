symptom('Typhoid', 'muscle_pain').
symptom('Typhoid', 'bloating').
symptom('Typhoid', 'constipation').
symptom('Typhoid', 'nausea').
symptom('Typhoid', 'vomiting').
symptom('Typhoid', 'fatigue').
symptom('Typhoid', 'fever').
symptom('Typhoid', 'chills').
symptom('Typhoid', 'loss_of_appetite').
symptom('Typhoid', 'malaise' ).








run_opt(1) :- 
	list_disease_with_symptom(_, D),
	write(D), nl,
	sort(D,X), nl,
	printlist(X),
	write('List has been printed').

	%write(X), main.   	

run_opt(2) :- 
	findall(X, symptom(_,X),X),
	sort(X,D), nl, 
	printlist(D), nl,
	write('All diseased displayed').
	%main.

run_opt(3) :- write('Opt 3'), main.
run_opt(4) :- write('Opt 4'), main.
run_opt(5) :- write('Opt 5'), main.
run_opt(6) :- write('Goodbye'), nl, halt. 

run_opt(_) :- write('Invalid option'), nl, halt.  

main :-
    nl,
    write('>   Enter a selection followed by a period.'), nl,
	write('>   1. All diseases'), nl, 
	write('>   2. Print list of symptoms'),nl,
    write('>   3. Add a symptom'), nl,
	write('>   4. Tests options'),nl,
	write('>   5. Available treaments'),nl,
    write('>   6. Exit'), nl, nl,
    read(Choice),
    run_opt(Choice), main.
:- initialization(main).

parent(pam, bob). %pam is a parent of bob
parent(george, bob). %george is a parent of bob
list_disease_with_symptom(D, S) :-
findall(Symptom, symptom(Symptom, D), S).

clear:-
format('~c~s~c~s', [0x1b, "[H", 0x1b, "[2J"]). 
/*
This works well to return a list for a given parent 
example:
list_diseases(D, S) :-
findall(Symptom, symptom(symptom, D), S).
?- list_parents(bob, L).
L = [pam, george].

But I want it to return something a little different.
list_diseases(P, L) :-
findall(symptom, symptom(X, _), _).
*/


 printlist([X|List]) :-
        write(X),nl,
        printlist(List).
printlist([]):- 
	write(' ').
	

