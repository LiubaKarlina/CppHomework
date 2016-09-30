#include <stdio.h>

#include "ms_cli.h"
#include "mergesort.h"

int main( int argc, char* argv[] )
{
    int i, Size = argc - 1;
    //printf("%i", sizeof(*argv[1]));
    printf("%i\n", (int)sizeof(*argv[1]));
    if(sizeof(*argv[1]) == sizeof(char))
    {
      char *Array = (char *)malloc(sizeof(char) * Size);
      for ( i = 0 ; i < Size;i++)
        copy_f(&Array[i], argv[i + 1], sizeof(char)); 
      sel_sort(Array, Size, sizeof(char), cmp_c);
      for ( i = 0 ; i < Size;i++)
        printf("%c ", Array[i]);  
      free(Array);             
    }
    /*int a = 1, b = 2;
    int Ar[10] = {2, 1, 0, 4, 456, 23, 40, 13, -30, 1};
    char Ar1[3] = {'z', 'y', 'x'};
    //copy_f(&a, &b, 4);
    //printf("%i %i", a, b);
    sel_sort(Ar1, 3, sizeof(char), cmp_c);
    for(a = 0;a < 3;a++)
      printf("%c ", Ar1[a]);*/
    return 0;
}
