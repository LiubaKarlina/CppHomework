#include <expat.h>
#include <stdio.h>
#include <string.h>

#include "phonebook.h"

#define BUFFER_SIZE 100000

void start_element(void *data, const char *element, const char **attribute) {
    if(!strcmp(element, "human"))
    {
      human_t Human;
      char str[256 * 3];
      strcpy(str, attribute[1]); 
      printf(" %s\n ", str);
      char *pch = strtok(str, " ");
      strcpy(Human.name, pch);
      pch = strtok(NULL, " ");
      strcpy(Human.middle_name, pch);
      pch = strtok(NULL, " ");
      strcpy(Human.family_name, pch);
      pch = strtok(NULL, " ");
      Human.phone_size = 0;
      push_back_human(data, &Human);    
    }
}

void end_element(void *data, const char *element) {
}

void handle_data(void *data, const char *content, int length) {
    if (content[0] >= '0' && content[0] <= '9')
    {
	    phonebook_t *book = (phonebook_t *)data;
	    human_t *h = &(book->humans[book->size - 1]);
	    strncpy(h->phones[h->phone_size], content, length);
	    h->phones[h->phone_size][length] = '\0';
	    h->phone_size++;
    }
}

int parse_xml(phonebook_t *book, const char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
 
    char buff[BUFFER_SIZE];

    XML_Parser  parser = XML_ParserCreate(NULL);
    XML_SetUserData(parser,book); 
    XML_SetElementHandler(parser, start_element, end_element);
    XML_SetCharacterDataHandler(parser, handle_data);

    memset(buff, 0, BUFFER_SIZE);

    size_t len = 0;
    int done = 0;
    do {
        len = fread(buff, sizeof(char), BUFFER_SIZE, fp);
        done = len < BUFFER_SIZE;

        if (XML_Parse(parser, buff, len, done) == XML_STATUS_ERROR) {
            printf("Error: %s\n", XML_ErrorString(XML_GetErrorCode(parser)));
            return 2;
        }
    } while (!done);

    XML_ParserFree(parser);
    fclose(fp);

    return 0;
}

int main(int argc, char **argv) {
    int result;
    phonebook_t Book;
    result = load_phonebook_xml(argv[1], &Book);
    printf("Result of loading is %i\n", result);
    result = save_phonebook_xml(argv[2], &Book);
    printf("Result of saving is %i\n", result);  
    /*   
    gen_phonebook(&Book, 3);
    save_phonebook_xml(argv[3], &Book); 
    */
    clear_phonebook(&Book);
    return 0;
}
