// Double Linked list implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
};

struct node* head;


bool isEmpty() {
   return head == NULL;
}

int countNodes() {
   struct node* counter_node = head;

   int i = 0;
   while (counter_node != NULL) {
      i++;
      counter_node = counter_node->next;
   }

   return i;
}

struct node* GetNewNode(int x) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;

}

void InsertAtHead( int x ) {
   struct node* temp = GetNewNode(x);
   if (head == NULL) {
      head = temp;
      return;
   }
     head->prev = temp;
     temp->next = head;
     head       = temp;
 }

 void InsertAtTail (int x) {
     struct node* newNode = GetNewNode(x);
     struct node* temp    = head;

     if (head == NULL) {
        head = newNode;
        return;
     }

     //Iterate right
    while (temp->next != NULL) {
       temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;


 }

void ReversePrint() {
	struct node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void Print () {
  struct node* temp = head;
  printf("Forward: ");
  while (temp != NULL) {
    printf("%d, ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void DeleteHead () {
  if (head->next == NULL) {
     head = NULL;
     return;
  }


  head = head->next;
  head->prev = NULL;

}

void DeleteNth(int n){
  if(n > countNodes()){
     return;
  }
  struct node* temp = head;
  int i;
  for (i = 0; i <  n-2; i++) {
     temp = temp->next;
  }
   struct node* temp2 = temp->next;
   temp->next  = temp2->next;
   temp2->next->prev = temp;
   free(temp2);


}

void InsertNth (int x,int n) {
  if(n > countNodes()){
     return;
  }
  struct node* newNode = GetNewNode(x);
  if (n == 1) {

     head->prev    = newNode;
     newNode->next = head;
     head = newNode;
     return ;
  }

  int i;
  struct node* tmp_head = head;
  for (i = 0; i < n-2; i++) {
     tmp_head = tmp_head->next; // 2th node
  }

  newNode->next = tmp_head->next;
  tmp_head->next->prev = newNode;
  tmp_head->next = newNode;
  newNode->prev  = tmp_head;


}


void DeleteByValue(){}
void DeleteLast(){}


int main () {
  InsertAtHead(1);
  InsertAtHead(2);
  InsertAtHead(3);
  InsertAtHead(4);
  InsertAtHead(5);
  InsertAtHead(6);
  InsertAtHead(7);
 ////

 Print();

 InsertAtTail(9);
 Print();
 ReversePrint();
 Print();
 DeleteHead();
 printf("After Delete Head: \n");
 Print();
 printf("Delete 3-th element: \n\n");
 DeleteNth(3);
 Print();


 printf("Insert 3-th element: \n\n");
 InsertNth(77,2);
 Print();





  return 0;
}