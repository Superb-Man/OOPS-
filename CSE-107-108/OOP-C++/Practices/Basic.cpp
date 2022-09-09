/************************Assigning address of 2D array to pointers prblem**********************/
/*******************The Chart is taken from StackOverflow *******************************/

int a[10][10] 

it will be converted to an expression of type "pointer to 10-element array of int", or int (*)[10].
All of the following are True:



    Expression    Type                Decays to
    ----------    ----                ---------
             a    int [10][10]        int (*)[10]      
            &a    int (*)[10][10]     
            *a    int [10]            int *
          a[i]    int [10]            int *
         &a[i]    int (*)[10]         
         *a[i]    int          
       a[i][j]    int
      &a[i][j]    int *

/*************Another************/

    sizeof a        = sizeof (int) * 10 * 10
    sizeof &a       = sizeof (int (*)[10][10])
    sizeof *a       = sizeof (int) * 10
    sizeof a[i]     = sizeof (int) * 10
    sizeof &a[i]    = sizeof (int (*)[10] )
    sizeof *a[i]    = sizeof (int)
    sizeof a[i][j]  = sizeof (int)
    sizeof &a[i][j] = sizeof (int *)

/**************####**************/

    int           *x  = &a[0][0]; // equivalent to int       *x  = a[0];
    int     (*x1)[10] = &a[0];    // equivalent to int (*x1)[10] = a;
    int (*x2)[10][10] = &a;


/*************###########*************/

x,x1,x2 all have the same value at first : the address of the first element of the array .
But because of the different pointer types, the results 
operations involving pointer arithmetic will be different. 
The expression -> (x + 1) will yield the address of the next int object (&a[0][1]). 
The expression -> (x1 + 1) will yield the address of the next 10-element array of int (&a[1][0]). 
The expression -> (x2 + 1) will yield the address of the next 10-element array of 10-element array of int (effectively, &a[11][0]).
