add(X, Y, Result) :- Result is X + Y.
subtract(X, Y, Result) :- Result is X - Y.
multiply(X, Y, Result) :- Result is X * Y.
divide(X, Y, Result) :- Y =\= 0, Result is X / Y.
power(X, Y, R) :- R is X ** Y.
square(X, R) :- R is X * X.
cube(X, R) :- R is X * X * X.
maximum(X, Y, R) :- R is max(X, Y).
minimum(X, Y, R) :- R is min(X, Y).