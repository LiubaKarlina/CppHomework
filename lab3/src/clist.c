#include "clist.h"

void init_list ( list_s *L )
{
  L->head.next = &(L->head);
  L->head.prev = &(L->head);
}

void add_node ( list_s *L, node_s *N )
{
  N->next = L->head.next;
  N->prev = &(L->head);
  L->head.next->prev = N;
  L->head.next = N;
}

void remove_node ( list_s *L, node_s *N )
{
  node_s *p = N->prev;
  node_s *n = N->next;
  n->prev = p;
  p->next = n;
}

int get_length ( list_s *L )
{
  int len = 0;
  node_s *p = L->head.next;
  while(p != &(L->head))
    p = p->next, len++;
  return len;
}
