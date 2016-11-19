#include <stdio.h>
#include <stdlib.h>

#include "msg.h"

#define MAX_STR 2048

/* Convert code to symbol function */

char toSymbol( char x )
{
    switch(x) {
        case 26:
            return ' ';
        case 27:
            return '.';
        case 28:
            return ',';
        default:
            return 'A' + x;
    }
}

/* Convert symbol to special code function */

char toCode(char x)
{
    switch(x) {
        case ' ':
            return 26;
        case '.':
            return 27;
        case ',':
            return 28;
        default:
            return x - 'A';
    }
}

/* Read symbols from file, convert them using special keys and insert in a picture function */

int ParserMSG( PICTURE *picture, const char *key_txt, const char *msg_txt )
{
    FILE *f_key = fopen( key_txt, "rt" );
    FILE *f_msg = fopen( msg_txt, "rt");

    if( f_key == NULL ) {
        printf("File doesn't open %s \n", key_txt);
        return 0;
    }

    if( f_msg == NULL ) {
        printf("File doesn't open %s \n", key_txt);
        return 0;
    }

    int x, y;
    char component, exp, symbol;
    char *to_change;

    while( fscanf(f_msg, "%c", &symbol) != -1 && symbol != '\n')
    {
        symbol = toCode(symbol);
        exp = 1;
        for (int i = 0;i < 5;i++)
        {
            fscanf(f_key,"%i %i %c", &x, &y, &component);
            y = picture->height - 1 - y;
            switch (component) {
                case 'B':
                    to_change = &picture->pixels[x][y].B;
                    break;
                case 'G':
                    to_change = &picture->pixels[x][y].G;
                    break;
                case 'R':
                    to_change = &picture->pixels[x][y].R;
                    break;
            }
            *to_change = *to_change & 254; // set last bit zero
            if (exp & symbol)
                *to_change = *to_change | 1; // change bit if need
            exp *= 2;
        }
    }
    fclose(f_key);
    fclose(f_msg);

    return 1;
}

/* Insert message in BMP file using special keys function */

int insertMSG( const char *input_bmp, const char *output_bmp, const char *key_txt, const char *msg_txt )
{
    PICTURE picture;

    if ( !loadBMP(input_bmp, &picture)) {
        return 0;
    }

    if ( !ParserMSG( &picture, key_txt, msg_txt )) {
        freeBMP(&picture);
        return 0;
    }
    if ( !saveBMP(output_bmp, &picture)) {
        return 0;
    }
    freeBMP(&picture);

    return 1;
}

/* Extract message from BMP file using special keys function */

int extractMSG( const char *input_bmp, const char *key_txt, const char *msg_txt )
{
    PICTURE picture;
    if (!loadBMP(input_bmp, &picture)){
        return 0;
    }

    FILE *fin = fopen( key_txt, "rt" );
    FILE *fout = fopen( msg_txt, "wt");

    if( fin == NULL ) {
        printf("File doesn't open %s \n", key_txt);
        return 0;
    }

    if( fout == NULL ) {
        printf("File doesn't open %s \n", msg_txt);
        return 0;
    }
    
    int x, y;
    char component;
    char bit, exp, code;
    int time;

    code = 0;
    exp = 1;
    time = 0;

    while(fscanf(fin , "%i %i %c", &x, &y, &component) != -1) {
        y = picture.height - 1 - y;
        switch (component) {
            case 'B':
                bit = (picture.pixels[x][y].B & 1);
                break;
            case 'G':
                bit = (picture.pixels[x][y].G & 1);
                break;
            case 'R':
                bit = (picture.pixels[x][y].R & 1);
                break;
        }
        if (bit)
            code += exp;

        exp *= 2;
        time++;
        if (time == 5) {
            time = 0;
            fprintf(fout, "%c", toSymbol(code));
            code = 0;
            exp = 1;
        }
    }

    fclose(fout);
    fclose(fin);

    freeBMP(&picture);
    return 1;
}


