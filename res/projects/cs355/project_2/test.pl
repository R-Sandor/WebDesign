tryTreatment:-
	testTaken(TestTaken),
	write(TestTaken), nl, 
	findall(Z, test(Z,TestTaken), Z),
	write(Z),nl,
	write('Here are all the possible disease and we need scratch the ones that do not match off'),nl,
	findall(Q,patient(Q),List), findall(Q, (member(Y,List), symptom(Q,Y)), PossibleDiseases ),
	write(PossibleDiseases),nl,nl,
	intersection(PossibleDiseases, Z, CommonElements), 
	write('Given the test: '), write(TestTaken), write(' we can discover the treatments for these possible illness:'), nl, 
	printlist(CommonElements),nl
	findall(X1, (member(Y1, CommonElements), treatment(Y1, X1)), Xs),
	printlist(Xs).
	

intersection([], _, []).
intersection([Head|L1tail], L2, L3) :-
        memberchk(Head, L2),
        !,
        L3 = [Head|L3tail],
        intersection(L1tail, L2, L3tail).
intersection([_|L1tail], L2, L3) :-
        intersection(L1tail, L2, L3).

% We already know what possible diseas somoeone may have
% We run a test that belong to those disease 
% Then we 
%
%
