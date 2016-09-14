#include "../include/io.h"
#include "../include/util.h"  
#include "../include/algorithm.h" 

void main( void ) {
  int a = doComputation(5, 7.0);
  int b = 5;
  max(a, b);
  logDebug('!');
}
