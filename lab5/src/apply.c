#include <stdio.h>
#include <string.h>
#include "apply.h"

void get_count(intrusive_node* node, void *count)
{
  int *p = (int *)count;
  (*p)++;
}

void get_print(intrusive_node *node, void *format)
{
  char *s = (char *)format;
  position_node *pnode = get_position(node);
  printf(s, pnode->x, pnode->y);
}

void txt_fprint(intrusive_node *node, void *format)
{
  FILE *f = (FILE *)format;
  position_node *pnode = get_position(node);
  fprintf(f,"%d %d\n", pnode->x, pnode->y);
}

void bin_fprint(intrusive_node *node, void *file)
{
  FILE *f = (FILE *)file;
  position_node *pnode = get_position(node);
  
  fwrite(&pnode->x, sizeof(char) * 3, 1, f);
  fwrite(&pnode->y, sizeof(char) * 3, 1, f);
}

void loadBin( intrusive_list *list, char *filename )
{
  FILE *fin = fopen(filename, "rb");
  int buf[2];
  while(!feof(fin))
  {
    buf[0] = 0;
    buf[1] = 0;
    fread(&buf[0], sizeof(char) * 3, 1, fin);
    if ((buf[0] & (1 << 23)) > 0)
      buf[0] += 255 << 24; 
    fread(&buf[1], sizeof(char) * 3, 1, fin);
    if ((buf[1] & (1 << 23)) > 0)
      buf[1] += 255 << 24; 
    if(!feof(fin))
      add_position(list, buf[0], buf[1]);
  }
}

void loadText( intrusive_list *list, char *filename )
{
  FILE *fin = fopen(filename, "rt");
  int x, y;  

  while(fscanf(fin, "%d %d", &x, &y) == 2)
      add_position(list, x, y);   
}


