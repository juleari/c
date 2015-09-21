#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int max( int a, int b, int c )
{
    return ( a > b ) ? 
                ( ( a > c ) ? a : c ) :
                ( ( b > c ) ? b : c );
}

int maxprime(int p, int q, int k, char* xs)
{
    int i;

    for (i = 1; i < k; i++)
    {
        if ( xs[i] && ( q % (i + 1) == 0 ) ) 
        {
            p = max(p, i + 1, maxprime( p, q / (i + 1), k, xs ));
        }
    }

    return ( p == 1 ) ? q : p; 
}

int eratosphen( int x )
{
    int i, j, k = floor( sqrt(x) ), l = floor( sqrt(k) ), p, q;
    char *xs;

    xs = malloc( k * sizeof(char) );

    for ( i = 1; i < k; i++ ) { xs[i] = 1; }

    for ( i = 1; i < l; i++ )
    {
        if ( xs[i] ) 
        {
            for ( j = (i + 1) * (i + 1) - 1; j < k; j += (i + 1) ) { xs[j] = 0; }
        }
    }

    p = maxprime(1, x, k, xs);

    free( xs );
    return p;
}

int main()
{
    int x;

    scanf( "%i", &x );

    printf("%i", eratosphen( abs(x) ));
    return 0;
}