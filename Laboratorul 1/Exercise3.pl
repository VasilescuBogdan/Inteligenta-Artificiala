parent(andrei, cristi).
parent(andrei, elena).
parent(cristi, adriana).
parent(cristi, marius).
parent(cristi, ovidiu).
parent(elena, ana).
parent(ana,george).
sibling(X,Y):-parent(Z,X),parent(Z,Y).
grandparent(X,Y):-parent(X,Z),parent(Z,Y).
cousin(X,Y):-parent(A,X),parent(B,Y),sibling(A,B).
greatgrandparent(X,Y):-grandparent(X,Z),parent(Z,Y).
children(X,Y):-parent(Y,X).
grandchildren(X,Y):-grandparent(Y,X).
greatgrandchildren(X,Y):-greatgrandparent(Y,X).