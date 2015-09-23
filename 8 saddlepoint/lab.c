#include <stdlib.h>
#include <stdio.h>

char seddle( int* min, int* max, int n, int m )
{
    int i, j;

    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < m; j++ )
        {
            if ( max[i] == min[j] )
            {
                printf("%i %i\n", i, j);
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int n, m, i, j, *min, *max, a;

    scanf( "%i%i", &n, &m );

    max = malloc( n * sizeof(int) );
    min = malloc( m * sizeof(int) );

    for ( j = 0; j < m; j++ ) { min[j] =  2147483647; }
    for ( i = 0; i < n; i++ ) 
    { 
        max[i] = -2147483648;
            
        for ( j = 0; j < m; j++ )
        {
            scanf( "%i", &a );

            if ( a > max[i] ) { max[i] = a; }
            if ( a < min[j] ) { min[j] = a; }
        }
    }

    if ( !seddle( min, max, n, m ) ) { printf("none"); }

    free( max );
    free( min );

    return 0;
}