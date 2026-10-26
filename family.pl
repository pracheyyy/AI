%facts
male(shashikant).
male(prabhaker).
male(deepak).
male(sarthak).
female(vaishali).
female(sushama).
female(chhaya).
female(prachi).

parent(shashikant,deepak).
parent(vaishali,deepak).
parent(prabhaker,chhaya).
parent(sushama,chhaya).
parent(deepak,prachi).
parent(deepak,sarthak).
parent(chhaya,prachi).
parent(chhaya,sarthak).

% rules

father(X,Y) :- male(X) , parent(X,Y).
mother(X,Y) :- female(X) , parent(X,Y).
sibling(X,Y) :- parent(Z,X) , parent(Z,Y) , X\=Y.
grandfather(X,Y) :- male(X) , parent(X,Z) , parent(Z,Y).
grandmother(X,Y) :- female(X) , parent(X,Z) , parent(Z,Y).
