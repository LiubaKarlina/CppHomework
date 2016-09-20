#include <stdio.h>
#include "str.h"

char * my_strcpy( char * destination, const char * source)
{
  char *d = destination;
  while ((*d++ = *source++) != 0)
    ;
  return destination; 
}
char * my_strcat( char * destination, const char * source)
{
  char *d = destination;
  while (*d != 0)
    d++;
  while ((*d = *source) != 0)
  {
    d++;
    source++;
  } 
  return destination;
}
int my_strcmp( const char * str1, const char *str2 )
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
size_t my_strlen( const char * str )
{
  int len = 0;
  const char *p = str;
  while(*(p++) != 0)
   len++;
  return len;
}
