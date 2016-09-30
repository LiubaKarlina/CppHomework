#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include <stdlib.h>

void copy_f( void * dest, const void * src, size_t Size );
void sel_sort( void * base, size_t Size, size_t elem_size, 
              int (* compar)( const void *, const void * ));
#endif
