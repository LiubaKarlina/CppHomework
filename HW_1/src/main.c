#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "msg.h"

int main( int argc, char **argv ) {
    PICTURE picture;
    PICTURE small;

    if (!strcmp(argv[1], "crop-rotate")) {
      int res_load, res_crop;
      res_load = loadBMP(argv[2], &picture);
      
      if (!res_load)
        return 1;
      
      res_crop = cropBMP(&picture, &small, atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]));
      if (!res_crop)
        return 1;

      rotateBMP(&small);
      saveBMP(argv[3], &small);

      freeBMP(&picture);
      freeBMP(&small);
    }
    else if (!strcmp(argv[1], "insert")) {
      int res_insert = insertMSG(argv[2], argv[3], argv[4], argv[5]); 
      
      if (!res_insert)
        return 1;
    }
    else if(!strcmp(argv[1], "extract")) {
    int res_extract = extractMSG(argv[2], argv[3], argv[4]); 
      
    if (!res_extract)
        return 1;
    } 
    else {
      printf("Incorrect input \n"); 
    }

    return 0;
}
