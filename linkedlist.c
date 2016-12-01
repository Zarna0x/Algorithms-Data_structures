#include <stdlib.h>
#include <stdio.h>

struct node{
  int data;
  struct node *next;
};

 //Head node
// struct node* head;
void InsertNth(int, int); // InserthNth(2,1)
void Insert(struct node**,int);
void Print(struct node*);
void delete(int);

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
  // delete(3);

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

void InsertNth (int data, int n) {
  struct node* temp1  = (struct node*)malloc (sizeof(struct node)) ;
  temp1->data = data;
  temp1->next = NULL;
  if (n == 1) {
    temp1->next = head;
    head = temp1;
    return;
  }

  struct node* temp2 = (struct node*)malloc (sizeof(struct node)) ;
  temp2 = head;
  int i;
  for ( i = 0; i < n-2; i++) {
      temp2 = temp2->next;
  }

  temp1->next = temp2->next;
  temp2->next = temp1;


}

void Delete (int n) {
  struct node* temp1 = head;
   if (n == 1) {
     head = temp1->next;
     free(temp1);
     return;
   }
  int i;
  for (i = 0; i <= n-1; i++) {
     temp1 = temp1->next;
   }

   struct node* temp2 = temp1->next; // temp2 = 0x3
   temp1->next = temp2->next;
   free(temp2);

}
