#include <stdbool.h>

#include "test_str.h"
#include "str.h"

bool test_strcat( void )
{
  char s[10] = "loly", s1[10] = "pop";
  char *p = s, *p1 = s1;
  my_strcat(p, p1);
  if (my_strcmp( s, "lolypop"))
    return false;
  return true;
}

bool test_strcmp( void )
{
  if (my_strcmp("aa", "ab") == -1 && my_strcmp("ab", "ab") == 0 && my_strcmp("aacd", "aaa") == 1)
    return true;
  return false;
}

bool test_strcpy( void )
{
  char s[100];
  my_strcpy(s, "sunday");
  if (my_strcmp("sunday" , s) != 0)
    return false;
  return true;
}

bool test_strlen( void )
{
  if (my_strlen("dady") != 4)
    return false;
  return true;
}

