pos([H|_],1,H).
pos([_A|L],N,S):-N1 is N - 1, pos(L,N1,S).