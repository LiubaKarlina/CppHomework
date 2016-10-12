#ifndef _APPLY_H_
#define _APPLY_H_

#include "position.h"

void get_count( intrusive_node* node, void *count );

void get_print( intrusive_node *node, void *format );

void txt_fprint( intrusive_node *node, void *format );

void bin_fprint( intrusive_node *node, void *format );

void loadBin( intrusive_list *list, char *filename );

void loadText( intrusive_list *list, char *filename );

#endif
