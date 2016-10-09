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
  printf(format, pnode->x, pnode->y);
}

void txt_fprint(intrusive_node *node, void *format)
{
  FILE *f = (FILE *)format;
  position_node *pnode = get_position(node);
  fprintf(f,"%d %d\n", pnode->x, pnode->y);
}

void bin_fprint(intrusive_node *node, void *format)
{
  FILE *f = (FILE *)format;
  position_node *pnode = get_position(node);
  //fwrite(&pnode->x, sizeof(int), 1, f);
  //fwrite(&pnode->y, sizeof(int), 1, f);

  fwrite(&pnode->x, sizeof(char) * 3, 1, f);
  fwrite(&pnode->y, sizeof(char) * 3, 1, f);
}


void LoadPosition(intrusive_list *list, char *infile, char *format)
{
  FILE *fin = fopen(infile, format);

  if(!strcmp(format, "rt"))
  {
    int x, y;
    while(!feof(fin))
    {  
      fscanf(fin, "%d %d", &x, &y);
      add_position(list, x, y);
    }    
  }
  else
  {
    int buf[2];
    while(!feof(fin))
    {
      fread(&buf[0], sizeof(char) * 3, 1, fin);
      fread(&buf[1], sizeof(char) * 3, 1, fin);
      add_position(list, buf[0], buf[1]);
    }
  }
  fclose(fin);
}

void SavePosition(intrusive_list *list, char *outfile, char *format)
{
  FILE *fout = fopen(outfile, format);
  int x, y;  

  if(!strcmp(format, "wt"))
    apply(list, txt_fprint, fout);
  else
    apply(list, bin_fprint, fout);

  fclose(fout);
}
