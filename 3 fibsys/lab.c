#include <stdio.h>
#include <stdlib.h>

const short MAX_FIB_NUM = 91;

void fibsys( long x, long* fibarr, short i ) 
{
    while ( i >= 0 ) 
    {
        if ( x >= fibarr[i] ) 
        {
            printf("1");
            x -= fibarr[ i-- ];
        }
        else 
        { 
            printf("0");
            i--;
        }
    }
}

int main()
{
    short i = 1;
    long  x, *fibarr;

    scanf( "%li", &x );

    if ( x < 2 ) { printf( "%li", x ); }
    else
    {
        fibarr = malloc( MAX_FIB_NUM * sizeof(long) );

        fibarr[0] = 1;
        fibarr[1] = 2;

        while ( x > fibarr[i] && ++i < MAX_FIB_NUM )
        {
            fibarr[ i ] = fibarr[ i - 2 ] + fibarr[ i - 1 ];
        }

        fibsys( x, fibarr, ( i < MAX_FIB_NUM && x == fibarr[i] ) ? i : i - 1 );
        free( fibarr );
    }
    
    return 0;
}
