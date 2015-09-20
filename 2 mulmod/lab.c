#include <stdio.h>

short powb( long b )
{
    short p = 0;

    while ( b > 1 ) 
    {
        p++;
        b >>= 1;
    }

    return p;
}

long mulmod( long a, long b, long m, short p ) 
{
    long bp = b >> p,
         mul = a * bp;

    while ( p > 0 ) 
    {
        mul = ( mul * 2 ) % m;
        b  ^= bp << p--;
        bp  = b >> p;
        mul = ( mul + ( a * bp ) % m ) % m;
    }

    return mul % m;
}

int main()
{
    long a, b, m;

    scanf( "%li%li%li", &a, &b, &m );

    printf( "%li", mulmod( a % m, b, m, powb(b) ) );
    return 0;
}