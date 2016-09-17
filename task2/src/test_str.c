#include <stdbool.h>

#include "test_str.h"
#include "str.h"

bool test_strcat( void )
{
  char s[] = "loly";
  if (strcmp(strcat(s, "pop"), "lolypop"))
    return false;
  return true;
}

bool test_strcmp( void )
{
  if (strcmp("aa", "ab") == -1 && strcmp("ab", "ab") == 0 && strcmp("aacd", "aaa") == 1)
    return true;
  return false;
}

bool test_strcpy( void )
{
  char s[100];
  strcpy(s, "sunday");
  if (strcmp("sunday" , s) != 0)
    return false;
  return true;
}

bool test_strlen( void )
{
  if (strlen("dady") != 4)
    return false;
  return true;
}

