#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "phonebook.h"
#include "names.h"

int parse_xml(phonebook_t *book, const char *filename);

int cmp (const void *a, const void *b)
{
  human_t *h1 = (human_t *)a;
  human_t *h2 = (human_t *)b;
  return strcmp(h1->family_name, h2->family_name);	
}

int load_phonebook_xml(const char *filename, phonebook_t *book)
{
   book->humans = malloc(50 * sizeof(human_t));
   book->size = 0;
   book->capacity = 50;
    
   int result = parse_xml(book, filename);

   if (result)
     return result;
   
   qsort(book->humans, book->size, sizeof(human_t), cmp);
   return 0;
}

void tab(FILE *f, int num)
{
  for(int i = 0; i < num * 4;i++)
    fprintf(f," ");
}

int save_phonebook_xml(const char *filename, phonebook_t *book)
{
  FILE *f = fopen(filename, "wt");
  if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
  int i, tabul = 1;
  human_t *h;
  
  fprintf(f,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  fprintf(f,"<phonebook>\n");

  for(i = 0;i < book->size;i++)
  {
    tab(f, tabul);
    h = &book->humans[i];
    fprintf(f, "<human name=\"%s %s %s\">\n", h->name, h->middle_name, h->family_name);
    tabul++;
    for (int j = 0;j < h->phone_size;j++)
    {
      tab(f, tabul);
      fprintf(f, "<phone>%s</phone>\n",h->phones[j]);
    }
    tabul--;
    tab(f, tabul);
    fprintf(f, "</human>\n"); 
  }
  fprintf(f, "</phonebook>");
  fclose(f);
  return 0;    
}

void print_phonebook(phonebook_t *book)
{
  size_t size = book->size, i, j; 
  human_t *h;
  printf("%lu\n", size);
  
  for (i = 0; i < size;i++)
  {
    h = &book->humans[i];
    printf("Name: %s\n", h->name);
    printf("Middle name: %s\n", h->middle_name);
    printf("Family name: %s\n", h->family_name);
    for(j = 0;j < h->phone_size;j++)
      printf("phone: %s\n", h->phones[j]);
  }  
}
void gen_phonebook(phonebook_t *book, size_t size)
{
  clear_phonebook(book);
  int i, j, l;
  for (i = 0;i < size;i++)
  {
    human_t H;
    H.phone_size = rand() % 9;
    H.phone_size++;
    for (j =0;j < H.phone_size;j++)
    {
      H.phone_size =  rand() % 20;
      for(l = 0;l < H.phone_size;l++)
        H.phones[j][l] = '0' + (rand() % 9); 
      H.phones[j][l] = '\0'; 
    }
    strcpy(H.name, kNames[rand() % NAMES_CNT]);
    strcpy(H.family_name, kFamilyNames[rand() % FAMILY_NAMES_CNT]);
    strcpy(H.middle_name, kMiddleNames[rand() % MIDDLE_NAMES_CNT]);
    push_back_human(book, &H);  
  }
}
void clear_phonebook(phonebook_t *book)
{
  human_t *h;
  free(book->humans);
  book->capacity = 0;
  book->size = 0;   
}
human_t get_human(phonebook_t *book, char* family_name);
void push_back_human(phonebook_t *book, human_t *human)
{
  if (book->size == book->capacity)
  {
    if (book->capacity != 0)
    {
      book->humans = realloc(book->humans, book->capacity * 2 * sizeof(human_t));
      book->capacity *= 2;     
    }
    else
    {
      book->humans = malloc(2 * sizeof(human_t));
      book->capacity = 2;
    }
  }
  book->humans[book->size++] = *human;
}
