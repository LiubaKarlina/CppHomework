#include <stdio.h>
#include <stdbool.h>
#include "test_str.h"

int main( void )
{
  if (!test_strcat() || !test_strcmp() || !test_strlen() || !test_strcpy())
    printf("ERROR\n");
  else
    printf("Eee, All Right\n");
  return 0;
}
