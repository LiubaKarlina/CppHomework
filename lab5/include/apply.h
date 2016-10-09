#ifndef _APPLY_H_
#define _APPLY_H_

#include "position.h"

void get_count(intrusive_node* node, void *count);

void get_print(intrusive_node *node, void *format);

void txt_fprint(intrusive_node *node, void *format);

void bin_fprint(intrusive_node *node, void *format);

void LoadPosition(intrusive_list *list, char *infile, char *format);

void SavePosition(intrusive_list *list, char *outfile, char *format);

#endif
