#include <expat.h>
#include <stdio.h>
#include <string.h>

#include "phonebook.h"

#define BUFFER_SIZE 100000

void start_element(void *data, const char *element, const char **attribute) {
   context_t *con = (context_t *) data; 
   if(!strcmp(element, "human"))
    {
      human_t Human;
      char str[256 * 3];
      strcpy(str, attribute[1]); 
      char *pch = strtok(str, " ");
      strcpy(Human.name, pch);
      pch = strtok(NULL, " ");
      strcpy(Human.middle_name, pch);
      pch = strtok(NULL, " ");
      strcpy(Human.family_name, pch);
      pch = strtok(NULL, " "); 
      push_back_human(con->book, &Human); 
    }
    if(!strcmp(element, "phone"))
      con->book->humans[con->last_human].phones[con->last_phone][0] = '\0';
}

void end_element(void *data, const char *element) {
  context_t *con = (context_t *) data;  
  if(!strcmp(element, "human"))
  {
    con->book->humans[con->last_human].phone_size = con->last_phone; 
    con->last_human++;
    con->last_phone = 0;
  }
}

void handle_data(void *data, const char *content, int length) {
    if (content[0] >= '0' && content[0] <= '9')
    {
	    context_t *con = (context_t *)data;
	    phonebook_t *book = con->book;
            human_t *h = &(book->humans[con->last_human]);
            strncat(h->phones[con->last_phone], content, length);
	    //strncpy(h->phones[con->last_phone], content, length);
	    h->phones[con->last_phone][length] = '\0';
	    con->last_phone++;  
    }
}

int parse_xml(phonebook_t *book, const char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
 
    context_t con;
    con.book = book;
    con.last_human = 0;
    con.last_phone = 0;
    char buff[BUFFER_SIZE];

    XML_Parser  parser = XML_ParserCreate(NULL);
    XML_SetUserData(parser, &con); 
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
    print_phonebook(&Book);
    
    gen_phonebook(&Book, 10);
    result = save_phonebook_xml(argv[2], &Book);
    
    clear_phonebook(&Book);
    return 0;
}
