#include <stdio.h>

void printpack( int x )
{
    int i;

    for ( i = 0; i < 32; i++ ) 
    {
        if ( x == ( x | ( 1 << i )) )
        {
            printf( "%i ", i );
        }
    }
}

int readpack()
{
    int len, x = 0, i, xi;

    scanf("%i", &len);

    for ( i = 0; i < len; i++ )
    {
        scanf("%i", &xi);
        x |= 1 << xi;
    }

    return x;
}

int main()
{
    int a, b;

    a = readpack();
    b = readpack();

    b &= a;

    printpack(b);
    return 0;
}