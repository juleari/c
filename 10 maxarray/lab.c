#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
unsigned char array[] = {
    153,
    1,
    15,
    191,
    232,
    251,
    27,
    174,
    26,
    3,
    68,
    48
};
 
int compare(void *a, void *b)
{
    return (int)(*(unsigned char*)a) - (int)(*(unsigned char*)b);
}
 
int maxarray(void*, unsigned long, unsigned long, int (*)(void *a, void *b)); 
 
int maxarray(void *base, unsigned long nel, unsigned long width, int (*compare)(void *a, void *b))
{
    int i, maxi = 0;

    for (i = 1; i < nel; i++)
    {
        if ( compare( (char*)base + (i * width), (char*)base + (maxi * width) ) > 0 ) 
        {
            maxi = i;
        }
    }

    return maxi;
}

int main(int argc, char **argv) 
{ 
    printf("%d\n", maxarray(array, 12, sizeof(unsigned char), compare)); 
    return 0; 
}
