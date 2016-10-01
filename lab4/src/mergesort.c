#include <stdio.h>
#include "mergesort.h"


void copy_f( void *dest, const void * src, size_t Size )
{
  char *ptr = (char *)src;
  char *s = (char *)dest;
  int i = 0;

  for (i = 0;i < Size;i++)
  {
    //printf("%c", *ptr);
    *s++ = *ptr++;
  }
  //printf("\n");
}

void sel_sort( void * base, size_t Size, size_t elem_size, int (* compar)(const void *, const void *))
{
  if (Size < 2)
    return;

  int size_a = Size / 2;
  int size_b = Size - size_a;

  char *A = (char *)base;
  char *B = A + size_a * elem_size;

  sel_sort(A, size_a, elem_size, compar);
  sel_sort(B, size_b, elem_size, compar);

  int i = 0, j = 0;
  char *Res = (char *)malloc(elem_size * Size);
  char *ptr = Res;

  while(i < size_a && j < size_b)
  {
    if(compar(&A[i * elem_size], &B[j * elem_size]) < 0)
      copy_f(ptr, &A[(i++) * elem_size], elem_size);
    else
      copy_f(ptr, &B[(j++) * elem_size], elem_size);
    ptr = ptr + elem_size;
  }

  while(i < size_a)
    copy_f(ptr, &A[(i++) * elem_size], elem_size),ptr = ptr + elem_size;
  while(j < size_b)
    copy_f(ptr, &B[(j++) * elem_size], elem_size),ptr = ptr + elem_size;

  for(i = 0;i < Size;i++)
    copy_f(&A[i * elem_size], &Res[i * elem_size], elem_size);

  free(Res);
}

