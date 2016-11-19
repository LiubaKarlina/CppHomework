#ifndef LAB_BMP_MSG_H
#define LAB_BMP_MSG_H

#include "bmp.h"

int insertMSG( const char *input_bmp, const char *output_bmp, const char *key_txt, const char *msg_txt );
int extractMSG( const char *input_bmp, const char *key_txt, const char *msg_txt );

#endif //LAB_BMP_MSG_H

