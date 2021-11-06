taller_than(bob,mike).
taller_than(mike,jim).
taller_than(jim,george).
taller_than_rule(X,Y):-taller_than(X,Y).
taller_than_rule(X,Y):-taller_than(X,Z), taller_than_rule(Z,Y).