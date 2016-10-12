#include <stdio.h>
#include <string.h>
#include "position.h"
#include "apply.h"

int main(char argc, char* argv[]) {
    intrusive_list list;
    intrusive_list* l = &list;
    init_list(l);
    FILE *f;
    

    if(!strcmp(argv[1], "loadtext"))
      loadText(l, argv[2]);
    else
      loadBin(l, argv[2]);
    
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
      if(!strcmp(argv[3], "savetext"))
      {
        f = fopen(argv[4], "wt");
        apply(l, txt_fprint, f);
        fclose(f);
      }
      else
      {
        f = fopen(argv[4], "wb");
        apply(l, bin_fprint, f);
        fclose(f);
      }
    }
    
    remove_all(l);
    
    return 0;
}
