#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bmp.h"

/* In respect that paddings in BMP file */

size_t rounding( size_t x ) {
    return (x * 3 + 3) -  ((x * 3 + 3) % 4);
}

PIXEL ** mallocBMP( size_t height, size_t width )
{
    char *tmp_buf;
    PIXEL **array;
    
    width = rounding(width);
    tmp_buf = calloc(1, height * width);
    array = malloc(height * sizeof(PIXEL *));

    if ( tmp_buf == NULL || array == NULL ){
        printf("Haven't got enough memory \n");
        return NULL;
    }
    for ( size_t i = 0;i < height;i++ ) {
        array [i] = (PIXEL *)tmp_buf;
        tmp_buf += width;
    }
    return array;
}

void freeBMP( PICTURE *picture ) {
  free(*picture->pixels);
  free(picture->pixels);
}

int readHeader( FILE *f, PICTURE *picture )
{
    size_t res = fread( &picture->bhFile, 1, sizeof(BMPFILEHEADER), f );

    if( res != sizeof(BMPFILEHEADER) ) {
        printf("Incorrect file for loading \n");
        fclose(f);
        return 0;
    }

    res = fread( &picture->bhInfo, 1, sizeof(BMPINFOHEADER), f );

    if( res != sizeof(BMPINFOHEADER) ) {
        printf("Incorrect file for loading \n");
        fclose(f);
        return 0;
    }

    picture->width = picture->bhInfo.bcWidth;
    picture->height = picture->bhInfo.bcHeight;

    return 1;
}

/* Load picture from file function */

int loadBMP( const char *fname, PICTURE *picture )
{
    FILE *f = fopen( fname, "rb" );
        
    if( f == NULL ) {
        printf("File doesn't open %s \n", fname);
        return 0;
    }
    
    if (!readHeader(f, picture)) {
        fclose(f);
        return 0;  
    }

    size_t row = rounding(picture->width);
    
    picture->pixels = mallocBMP(picture->height, picture->width);
    if (picture->pixels == NULL) {
        fclose(f);
        return 0;
    }

    size_t res = fread( *picture->pixels, 1, row * picture->height, f );

    if( res != row * picture->height ) {
        printf("Incorrect file for loading \n");
        fclose(f);
        return 0;
    }

    fclose(f);

    return 1;
}

int writeHeader( FILE *f, PICTURE *picture )
{
    size_t res = fwrite( &picture->bhFile, 1, sizeof(BMPFILEHEADER), f );

    if( res != sizeof(BMPFILEHEADER) ) {
        printf("Incorrect file for saving \n");
        fclose(f);
        return 0;
    }

    res = fwrite( &picture->bhInfo, 1, sizeof(BMPINFOHEADER), f );

    if( res != sizeof(BMPINFOHEADER) ) {
        printf("Incorrect file for saving \n");
        fclose(f);
        return 0;
    }
    
    return 1;
}

/* Save picture in file function */

int saveBMP( const char *fname, PICTURE *picture )
{    
    FILE *f = fopen( fname, "wb" );

    if( f == NULL ) {
        printf("File doesn't open %s \n", fname);
        return 0;
    }

    if (!writeHeader(f, picture)) {
        fclose(f);
        return 0;
    }

    size_t row = rounding(picture->width);

    size_t res = fwrite( *picture->pixels, 1, row * picture->height, f);

    if ( res != row * picture->height ) {
        printf("Incorrect file for saving \n");
        fclose(f);
        return 0;
    }

    fclose(f);

    return 1;
}

/* Update picture size */

void updateSize( PICTURE *picture, size_t height, size_t width )
{
    size_t Size = rounding(width) * height;
    
    picture->bhInfo.biSizeImage =  Size;
    picture->bhFile.bfSize = 54 + Size;


    picture->height = height;
    picture->width = width;
    picture->bhInfo.bcHeight = height;
    picture->bhInfo.bcWidth = width;
}

/* Rotate picture function */

int rotateBMP( PICTURE *picture )
{
    size_t height, width, row;
    PIXEL **tmp_buf;

    height = picture->height;
    width = picture->width;

    row = rounding(height);

    tmp_buf = mallocBMP(width, height);
   
    if (tmp_buf == NULL) {
        return 0;
    }

    for (size_t y = 0; y < height;y++) {
        for (size_t x = 0; x < width; x++) {
            memcpy(tmp_buf[width - 1 - x] + y, picture->pixels[y] + x, 3);
        }
    }

    freeBMP(picture);

    picture->pixels = tmp_buf;

    updateSize(picture, width, height);
    
    return 1;
}

/* Make croping from bmp picture function */

int cropBMP( PICTURE *picture, PICTURE *crop, size_t start_x, size_t start_y, size_t crop_w, size_t crop_h )
{
    start_y = picture->height - start_y - crop_h;

    if (crop_w < 0 || crop_h < 0 || start_x + crop_w > picture->width || start_y + crop_h > picture->height) {
        printf("Incorrect coordinate \n ");
        return 0;
    }

    memcpy(&crop->bhFile, &picture->bhFile, sizeof(BMPFILEHEADER));
    memcpy(&crop->bhInfo, &picture->bhInfo, sizeof(BMPINFOHEADER));

    size_t crop_row = rounding(crop_w);

    crop->pixels = mallocBMP(crop_h, crop_w);

    if (crop->pixels == NULL) {
        return 0;
    }

    for (size_t j = 0;j < crop_h;j++) {
        memcpy(crop->pixels[j], picture->pixels[start_y + j] + start_x, crop_row);
    }

    updateSize(crop, crop_h, crop_w);

    return 1;
}
