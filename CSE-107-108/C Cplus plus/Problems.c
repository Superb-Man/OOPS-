/*
A string that contains only 0s, 1s, and 2s is called a ternary
string.
13. a) Find a recurrence relation for the number of ternary
strings of length n that do not contain two consecutive
0.
Sol->{
    putting 1 or 2 at last -> 2f(n-1) ;
    putting 10 or 20 at last -> 2f(n-2) ;

    f(0)=1;
    f(1) =3 ;
}

Find a recurrence relation for the number of
ternary strings of length n that contain two
consecutive 0s.

Sol->{
    f(n) = 2f(n-1)+2f(n-2)+3^(n-2) ;
    f(0) =0 ;
    f(1) = 0 ;
    f(2) = 1 
}



*/