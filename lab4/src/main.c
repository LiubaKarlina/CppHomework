#include <stdio.h>

#include "ms_cli.h"
#include "mergesort.h"

int getNum(char *ptr)
{
  int res = 0;
  char c;
  while(*ptr != 0)
  {
    c = *ptr++;
    res =res * 10 + c - '0';
  }
  return res;
}

int main( int argc, char* argv[] )
{
    int i, Size = argc - 2, j;
    
    if ( *argv[1] == 'c' )
    {
      char *Array = (char *)malloc(sizeof(char) * Size);
      
      for ( i = 0; i < Size; i++ )
        copy_f(&Array[i], argv[i + 2], sizeof(char)); 
      
      sel_sort(Array, Size, sizeof(char), cmp_c);
      
      for ( i = 0 ; i < Size; i++)
        printf("%c ", Array[i]);
      printf("\n");  
      
      free(Array);             
    }
    else if(*argv[1] == 'i')
    {
      int *Array = (int *)malloc(sizeof(int) * Size);
      for ( i = 0; i < Size; i++ )
        Array[i] = getNum(argv[i + 2]);
  
      sel_sort(Array, Size, sizeof(int), cmp_i);
      for ( i = 0; i < Size; i++)
        printf("%i ", Array[i]);
      printf("\n");  
      free(Array);             
    }
    else
    {
      int str_size = 20;
      char **Array = (char **)malloc(sizeof(char *) * Size);
      char *Mas = (char *)malloc(sizeof(char) * str_size * Size);
      char *m = Mas;
      char **p = Array;
      
      for ( i = 0; i < Size; i++)
      {
        *p = Mas;
        j = 0;
        while(argv[i + 2][j] != 0)
           Mas[j] = argv[i + 2][j++];

        Mas[j] = 0;
        Mas += str_size;
        *p++;         
      }
  
      sel_sort(*Array, Size, sizeof(char) * str_size, cmp_s); 
      for ( i = 0 ; i < Size;i++)
      {
        j = 0; 
        while(Array[i][j] != 0)  
          printf("%c", Array[i][j++]);
        printf(" ");
      }  
      printf("\n");    
     
      free(m);
      free(Array);
    }
    return 0;
}
