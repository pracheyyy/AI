%facts
% bike(name,price)
bike(ktm,200000).
bike(honda,100000).
bike(royels,250000).
bike(wego,75000).
bike(activa,100000).

% rules
costlier_bike(X,Y) :- bike(X,P1) , bike(Y,P2) , P1>P2.
cheaper_bike(X,Y) :- bike(X,P1) , bike(Y,P2) , P1<P2.
sameprice_bike(X,Y) :- bike(X,P1) , bike(Y,P2) , P1=:=P2.