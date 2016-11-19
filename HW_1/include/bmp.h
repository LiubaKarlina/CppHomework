#ifndef LAB_BMP_BMP_H
#define LAB_BMP_BMP_H

typedef unsigned short WORD;
typedef signed int LONG;
typedef unsigned int DWORD;

#pragma pack(push, 1)
typedef struct { 
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} BMPFILEHEADER;
#pragma pack(pop)

typedef struct {
  DWORD bcSize;
  LONG bcWidth;
  LONG bcHeight;
  WORD bcPlanes;
  WORD bcBitCount;

  DWORD biCompression; 
  DWORD biSizeImage; 
  LONG biXPelsPerMeter; 
  LONG biYPelsPerMeter; 
  DWORD biClrUsed; 
  DWORD biClrImportant; 
} BMPINFOHEADER;

#pragma pack(push, 1)
typedef struct{
    char B, G, R;
} PIXEL;
#pragma pack(pop)

typedef struct
{
    BMPFILEHEADER bhFile;
    BMPINFOHEADER bhInfo;
    LONG width, height;
    PIXEL **pixels;
} PICTURE;

int loadBMP( const char *fname, PICTURE *picture );
int saveBMP( const char *fname, PICTURE *picture );

int cropBMP( PICTURE *picture, PICTURE *Small, size_t x, size_t y, size_t w, size_t h );
int rotateBMP( PICTURE *picture );

void freeBMP(  PICTURE *picture  );

#endif //LAB_BMP_BMP_H
