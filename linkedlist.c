#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

void Insert(struct node**, int x);
void Print(struct node*);
void reverse(struct node**);
void InsertNth(struct node**,int,int);
void PrintUsingRecursion(struct node* p);
void Delete(struct node**,int);


int main () {

  struct node* head;
  Insert(&head,1);
  Insert(&head,2);
  Insert(&head,3);
  Insert(&head,4);
  InsertNth(&head,3,7);
  Print(head);

  printf("After Reverse\n");
  reverse(&head);
  PrintUsingRecursion(head);


  puts("After Delete: ");
  Delete(&head,3);
  PrintUsingRecursion(head);

  return 0;
}

void Insert(struct node** PointerOfHead,int x) {
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->data = x;
  temp->next = *PointerOfHead;
  *PointerOfHead = temp;
}

void Print (struct node* head) {
   struct node* temp = head;
   printf("List is: ");
   while (temp != NULL) {
     printf(" %d ",temp->data);
     temp = temp->next;
   }

   printf("\n\n");
}

void reverse (struct node** PointerOfHead) {
   struct node *current,*prev,*next;
   current = *PointerOfHead;
  // printf("%d",*current->data);
  // return;
   while ( current != NULL) {
     // set next
     next = current->next;
    // reverse link
     current->next = prev;
     // set prevous link
     prev = current;
     current = next;
   }

    *PointerOfHead = prev;

}

void InsertNth(struct node** PointerOfHead,int n, int x) {
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = NULL;
  struct node* tmp_head = *PointerOfHead;
  if (n == 1) {
     temp->next = tmp_head;
     tmp_head = temp;
     return;
  }
   int i;
   for (i = 0 ; i < n-2; i++)  {
      tmp_head = tmp_head->next;
    }
    temp->next = tmp_head->next;
    tmp_head->next = temp;
}

void PrintUsingRecursion (struct node* PointerOfHead) {

   struct node *ptr_head = PointerOfHead;

   if (ptr_head == NULL) {
     return;
  }

  printf(" %d ",ptr_head->data);
  PrintUsingRecursion(ptr_head->next);
  printf("\n");
}

void Delete (struct node** PointerOfHead, int n) {
    struct node* temp = *PointerOfHead;
    int i;

    for (i = 0; i < n-2; i++) {
       temp = temp->next;
    }
    struct node* temp_next = temp->next;
    temp->next = temp_next->next;
    free(temp_next);
    //printf("-- %d -- ",temp_next->data);
}
