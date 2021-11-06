addone([],[]).
addone([H|L],[H1|L1]):-H1 is H + 1,addone(L,L1).