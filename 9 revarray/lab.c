#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*double array[] = {
    0.30441,
    0.70227,
    0.67598,
    0.65228,
    0.97541,
    0.28480,
    0.87789,
    0.72672,
    0.08472,
    0.94654
};*/

long double array[] = {
    0.30441,
    0.70227,
    0.67598,
    0.65228,
    0.97541,
    0.28480,
    0.87789,
    0.72672,
    0.08472,
    0.94654
};

/*int array[] = { 
        100000000, 
        200000000, 
        300000000, 
        400000000, 
        500000000 
};*/

void revarray(void*, unsigned long, unsigned long);

void *mmemcpy(void *dst, void *src, unsigned long n)
{
    int i, m;
    unsigned long  *wdst = dst;  // текущая позиция в буфере назначения
    unsigned long  *wsrc = src;  // текущая позиция в источнике
    unsigned char  *cdst, *csrc;
     
    for(i = 0, m = n / sizeof(long); i < m; i++)  // копируем основную часть блоками по 4 или 8 байт
    {
        printf("a1");
       *(wdst++) = *(wsrc++);                     // (в зависимости от платформы)
        printf("a2");
    } 
    cdst = (unsigned char*)wdst;
    csrc = (unsigned char*)wsrc;

    for(i = 0, m = n % sizeof(long); i < m; i++)             // остаток копируем побайтно
       *(cdst++) = *(csrc++);
     
    return dst;
}

void revarray(void *base, unsigned long nel, unsigned long width) 
{ 
    void *x = malloc(width);
    unsigned long i, n = nel - 1, n2 = floor(nel / 2);

    for ( i = 0; i < n2; i++ )
    {
        memcpy( x, (char*)base + width * i, width );
        memcpy( (char*)base + width * i, (char*)base + width * (n - i), width );
        memcpy( (char*)base + width * (n - i), x, width );
    }

    free(x);
}

int main(int argc, char **argv)
{
    revarray(array, 10, sizeof(long double));

    int i;
    for (i = 0; i < 10; i++) {
        printf("%.15Lf\n", array[i]);
    }

    return 0;
}

