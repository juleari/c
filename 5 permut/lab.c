#include <stdio.h>

const short LENGTH = 8;

short count( int x, int* xs )
{
    short i, k = 0;

    for ( i = 0; i < LENGTH; i++ )
    {
        k += ( x == xs[i] ) ? 1 : 0;
    }

    return k;
}

char* permut( int* a, int* b )
{
    short i;

    for ( i = 0; i < LENGTH; i++ )
    {
        if ( count( a[i], a ) != count( a[i], b ) ) { return "no"; }
    }

    return "yes";
}

int main()
{
    int a[8], b[8], i;

    scanf("%i%i%i%i%i%i%i%i", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]);
    scanf("%i%i%i%i%i%i%i%i", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7]);

    printf("%s\n", permut(a, b) );

    return 0;
}