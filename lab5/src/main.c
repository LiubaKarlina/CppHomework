#include <stdio.h>
#include <string.h>
#include "position.h"
#include "apply.h"

//void getcount(intrusive_node* node, void *count);


int main(char argc, char* argv[]) {
    intrusive_list list;
    intrusive_list* l = &list;
    init_list(l);
    char format[2];
    format[0] = 'r';
    
    if(!strcmp(argv[1], "loadtext"))
      format[1] = 't';
    else
      format[1] = 'b';
    
    char infile[strlen(argv[2])];
    strcpy(infile, argv[2]);

    LoadPosition(l, infile, format);
 
    if(!strcmp(argv[3], "print"))
      apply(l, get_print, argv[4]);
    else if(!strcmp(argv[3], "count"))
    { 
      int cnt = 0;
      apply(l, get_count, &cnt);
      printf("%d\n", cnt);
    }
    else
    {
      format[0] = 'w';
      if(!strcmp(argv[3], "savetext"))
        format[1] = 't';
      else
        format[1] = 'b';
      
      char outfile[strlen(argv[4])];
      strcpy(outfile, argv[4]); 

      SavePosition(l, outfile, format);  
    }
    
    show_all_positions(l);
    remove_all(l);
    
    return 0;
}
