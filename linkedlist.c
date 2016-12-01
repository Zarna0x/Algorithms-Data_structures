#include <stdlib.h>
#include <stdio.h>

struct node{
  int data;
  struct node *next;
};

 //Head node

void Insert(struct node**,int);
void Print(struct node*);

int main () {
   struct node* head;
   head = NULL;
   printf("How many numbers ? ");
   int i,n,x;
   scanf("%d",&n);

   for (i = 0; i < n; i++) {
      printf("Enter the number: \n");
      scanf("%d",&x);
      Insert(&head,x);
      Print(head);
   }


  return 0;

}

void Insert (struct node** PointerOfHead,int x) {
  struct node* temp = (struct node*)malloc(sizeof(struct node));
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
