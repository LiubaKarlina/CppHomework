#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "clist.h"

#define container_of(ptr, type, member)(type*)((char*)(ptr) - offsetof(type,member) )

void remove_position ( list_s *L, int x, int y )
{
  node_s *p = L->head.next;
  pos_node_s *val;
  while(p != &(L->head))
  {
    val = container_of(p, pos_node_s, node);
    if (val->x == x && val->y == y)
    {
      remove_node(L, p);
      free(val);
    }
    p = p->next;
  }
}

void add_position ( list_s *L, int x, int y )
{
  pos_node_s *new_pos = (pos_node_s *)malloc(sizeof(pos_node_s));
  new_pos->x = x;
  new_pos->y = y;
  add_node(L, &(new_pos->node));
}

void show_all_positions ( list_s *L )
{
  if (get_length(L) == 0)
  {
    printf("None\n");
    return;
  } 
  node_s *p = L->head.next;
  pos_node_s *val;
  while(p != &(L->head))
  {
    val = container_of(p, pos_node_s, node);
    printf("x = %d, y = %d \n", val->x, val->y);
    p = p->next;
  }
}

void remove_all ( list_s *L )
{
  node_s *p = L->head.next, *del;
  pos_node_s *val;
  while(p != &(L->head))
  {
    del = p;
    val = container_of(p, pos_node_s, node);
    p = p->next;
    remove_node(L, del);
    free(val);
  }
}

int main( void )
{
  list_s MyList;
  init_list(&MyList);
  printf("length of list %d\n", get_length(&MyList));
  add_position(&MyList, 1, 2);
  add_position(&MyList, 3, 4);
  add_position(&MyList, 56, 6);
  show_all_positions(&MyList);
  printf("length of list %d\n", get_length(&MyList));
  printf("\n");
  printf("delete (1,2)\n");
  remove_position(&MyList, 1, 2);
  show_all_positions(&MyList);
  remove_all(&MyList);
  show_all_positions(&MyList);
  return 0;
}
