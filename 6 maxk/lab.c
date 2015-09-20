#include <stdio.h>
#include <stdlib.h>

int maxk( int n, int* xs, int k )
{
    int i, sum = 0, msum = 0, im = 0, ic = 0;

    for ( i = 0; i < n; i++ )
    {
        sum += xs[i];
        if ( i - ic >= k )
        {
            if ( sum > msum ) { msum = sum; im = ic; }

            sum -= xs[ ic++ ];
        }
    }

    return msum;
}

int main()
{
    int n, k, i, *xs;

    scanf( "%i", &n );
    
    xs = malloc( n * sizeof(int) );
    
    for ( i = 0; i < n; i++ ) { scanf( "%i", &xs[i] ); }

    scanf( "%i", &k );

    printf("%i", maxk( n, xs, k - 1 ));

    free( xs );
    return 0;
}