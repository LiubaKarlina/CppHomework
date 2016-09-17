#include "str.h"

char * strcpy( char * destination, const char * source)
{
  char *d = destination;
  while ((*d++ = *source++) != 0)
    ;
  return destination; 
}
char * strcat( char * destination, const char * source)
{
  char *d = destination;
  while (*d++ != 0)
    ;
  while ((*d++ = *source++) != 0)
    ;
  return destination;
}
int strcmp( const char * str1, const char *str2 )
{
  const char *p1 = str1;
  const char *p2 = str2;
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
size_t strlen( const char * str )
{
  int len = 0;
  const char *p = str;
  while(*(p++) != 0)
   len++;
  return len;
}
