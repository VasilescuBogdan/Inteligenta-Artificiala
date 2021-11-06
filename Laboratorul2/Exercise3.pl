prefix(_A,[]).
prefix([C|T],[C|T1]):-prefix(T,T1).

sufix(S,S).
sufix([H|T],A):-sufix(T,A).