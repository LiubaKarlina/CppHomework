#include "ms_cli.h"

int cmp_i( const void * first, const void * second )
{
  int *a = (int *)first;
  int *b = (int *)second;
  return (*a - *b);
}

int cmp_c( const void * first, const void * second )
{
  char *a = (char *)first;
  char *b = (char *)second;
  return (*a - *b);
}

int cmp_s( const void * str1, const void * str2 )
{
  const char *p1 = (char *)str1;
  const char *p2 = (char *)str2;
  while (*p1 == *p2 && *p1 != 0)
  {
    p1++;
    p2++;
  }
  if (*p1 > *p2)
    return 1;
  if (*p1 < *p2)
    return -1;
  return 0; 
}
