#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people_tag {
  char firstname[26];
  char lastname[26];
  unsigned int age;
  struct people_tag* next;
}people_t;

int main () {
  people_t  *head = NULL,*temp,*list;

  char *name[] = {"Andy","John","Peter","Raul",NULL};
  char *last[] = {"Mars","Doe","Mars","Gonzalez",NULL};
  unsigned int age[] = {22,34,24,18,0};

  int i = 0;

 while (name[i] != NULL) {
    temp = (people_t*)malloc(sizeof(people_t));

    if (temp == NULL) {
      fprintf(stderr,"Unable to allocate memory \n");
      exit(1);
    }

    strcpy(temp->firstname,name[i]);
    strcpy(temp->lastname,last[i]);
    temp->age = age[i];

    temp->next = head;
    head = temp;

   i++;
 }
  list = head;

  while (list != NULL) {
     printf("Firstname: %s\n",list->firstname);
     printf("Lastname: %s\n",list->lastname);
     printf("Age: %d\n",list->age);

     list = list->next;
  }

   list = head;


   //deallocate memorry
   while (list != NULL) {
      head = list->next; // head = 0x2 | head = 0x3
      free(list); // delete 0x1 | 0x2
      list = head; // list = 0x2 | 0x3
   }

  return 0;
}
