#include "../include/io.h"
#include "../include/util.h"

int max(int a, int b) {
  logDebug('m');
  if(a < b)
    return b;
  return a;
}
